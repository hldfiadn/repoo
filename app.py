import streamlit as st
import pickle
import numpy as np
import pandas as pd
import os
import urllib.request


# Load model
from joblib import load
model = load("model2.joblib")


st.title("Student Dropout Prediction")

st.markdown("Masukkan informasi mahasiswa untuk memprediksi status dropout:")

# === Mapping Dictionaries ===
marital_status_options = {
    1: "Single", 2: "Married", 3: "Widower", 4: "Divorced",
    5: "Facto Union", 6: "Legally Separated"
}

application_mode_options = {
    1: "1st phase - general contingent", 2: "Ordinance No. 612/93", 5: "1st phase - special contingent (Azores Island)",
    7: "Holders of other higher courses", 10: "Ordinance No. 854-B/99", 15: "International student (bachelor)",
    16: "1st phase - special contingent (Madeira Island)", 17: "2nd phase - general contingent",
    18: "3rd phase - general contingent", 26: "Different Plan", 27: "Other Institution",
    39: "Over 23 years old", 42: "Transfer", 43: "Change of course",
    44: "Tech specialization diploma holders", 51: "Change institution/course",
    53: "Short cycle diploma", 57: "Change institution/course (International)"
}

course_options = {
    33: "Biofuel Production Technologies", 171: "Animation and Multimedia Design",
    8014: "Social Service (evening attendance)", 9003: "Agronomy", 9070: "Communication Design",
    9085: "Veterinary Nursing", 9119: "Informatics Engineering", 9130: "Equinculture",
    9147: "Management", 9238: "Social Service", 9254: "Tourism", 9500: "Nursing",
    9556: "Oral Hygiene", 9670: "Advertising and Marketing", 9773: "Journalism",
    9853: "Basic Education", 9991: "Management (evening attendance)"
}

attendance_options = {1: "Daytime", 0: "Evening"}

previous_qualification_options = {
    1: "Secondary education", 2: "Bachelor's degree", 3: "Higher ed - degree", 4: "Master's",
    5: "Doctorate", 6: "Attending higher education", 9: "12th year - not completed",
    10: "11th year - not completed", 12: "Other - 11th year", 14: "10th year",
    15: "10th year - not completed", 19: "Basic edu 3rd cycle", 38: "Basic edu 2nd cycle",
    39: "Tech specialization course", 40: "Higher ed degree (1st cycle)",
    42: "Professional higher technical course", 43: "Master (2nd cycle)"
}

nationality_options = {
    1: "Portuguese", 2: "German", 6: "Spanish", 11: "Italian", 13: "Dutch", 14: "English",
    17: "Lithuanian", 21: "Angolan", 22: "Cape Verdean", 24: "Guinean", 25: "Mozambican",
    26: "Santomean", 32: "Turkish", 41: "Brazilian", 62: "Romanian", 100: "Moldova",
    101: "Mexican", 103: "Ukrainian", 105: "Russian", 108: "Cuban", 109: "Colombian"
}

mothers_qualification_options = {
    1: "Secondary - 12th Year", 2: "Bachelor's Degree", 3: "Higher Ed - Degree", 4: "Master's",
    5: "Doctorate", 6: "Attending Higher Ed", 9: "12th Year - Not Completed", 10: "11th Year - Not Completed",
    11: "7th Year (Old)", 12: "Other - 11th Year", 14: "10th Year", 18: "General commerce course",
    19: "Basic Ed 3rd Cycle", 22: "Technical-professional course", 26: "7th Year Schooling",
    27: "2nd Cycle General High School", 29: "9th Year - Not Completed", 30: "8th Year",
    34: "Unknown", 35: "Can't Read/Write", 36: "Read Only", 37: "Basic Ed 1st Cycle",
    38: "Basic Ed 2nd Cycle", 39: "Tech Specialization Course", 40: "Higher Ed (1st Cycle)",
    41: "Specialized Higher Studies", 42: "Prof. Higher Technical", 43: "Master (2nd cycle)",
    44: "Doctorate (3rd cycle)"
}

fathers_qualification_options = mothers_qualification_options.copy()

mothers_occupation_options = {
    0: "Student", 1: "Legislative/Exec/Directors", 2: "Intellectual/Scientific", 3: "Tech & Prof",
    4: "Admin Staff", 5: "Services & Sellers", 6: "Farmers & Fishermen", 7: "Skilled Industry Workers",
    8: "Machine Operators", 9: "Unskilled Workers", 10: "Armed Forces", 90: "Other", 99: "Unknown",
    122: "Health Professionals", 123: "Teachers", 125: "ICT Specialists", 131: "Tech - Science/Eng",
    132: "Tech - Health", 134: "Tech - Legal/Social", 141: "Office Workers", 143: "Finance Operators",
    144: "Admin Support", 151: "Service Workers", 152: "Sellers", 153: "Care Workers",
    171: "Skilled Const Workers", 173: "Printing/Jewelers/Artisans", 175: "Food/Wood/Clothing",
    191: "Cleaners", 192: "Unskilled Agri/Fish", 193: "Unskilled Industry/Transport",
    194: "Meal Prep Assistants"
}

fathers_occupation_options = {
    0: "Student", 1: "Legislative/Exec/Directors", 2: "Intellectual/Scientific", 3: "Technicians & Professions",
    4: "Administrative Staff", 5: "Personal Services & Sellers", 6: "Farmers & Fishermen",
    7: "Skilled Workers - Industry", 8: "Machine Operators", 9: "Unskilled Workers",
    10: "Armed Forces", 90: "Other Situation", 99: "Unknown", 101: "Armed Forces Officers",
    102: "Armed Forces Sergeants", 103: "Other Armed Forces Personnel", 112: "Admin/Commercial Directors",
    114: "Hotel/Trade Directors", 121: "Physical Sci/Eng Specialists", 122: "Health Professionals",
    123: "Teachers", 124: "Finance/Admin/Public Relations", 131: "Tech - Science/Eng",
    132: "Tech - Health", 134: "Tech - Legal/Social", 135: "ICT Technicians", 141: "Office/Secretaries",
    143: "Finance & Registry Operators", 144: "Admin Support", 151: "Service Workers",
    152: "Sellers", 153: "Care Workers", 154: "Security Personnel", 161: "Skilled Farmers",
    163: "Subsistence Farmers/Fishermen", 171: "Skilled Const Workers", 172: "Skilled Metalworkers",
    174: "Electric/Electronic Workers", 175: "Food/Wood/Clothing Workers", 181: "Fixed Plant Operators",
    182: "Assembly Workers", 183: "Vehicle Drivers/Operators", 192: "Unskilled Agri/Fish",
    193: "Unskilled Industry", 194: "Meal Prep Assistants", 195: "Street Vendors"
}

# === Input Fields ===
marital_status_label = st.selectbox("Marital Status", list(marital_status_options.values()))
marital_status = [k for k, v in marital_status_options.items() if v == marital_status_label][0]

application_mode_label = st.selectbox("Application Mode", list(application_mode_options.values()))
application_mode = [k for k, v in application_mode_options.items() if v == application_mode_label][0]

application_order = st.slider("Application Order (0 = first choice, 9 = last)", 0, 9, 1)

course_label = st.selectbox("Course", list(course_options.values()))
course = [k for k, v in course_options.items() if v == course_label][0]

attendance_label = st.selectbox("Daytime/Evening Attendance", list(attendance_options.values()))
daytime_evening_attendance = [k for k, v in attendance_options.items() if v == attendance_label][0]

previous_qualification_label = st.selectbox("Previous Qualification", list(previous_qualification_options.values()))
previous_qualification = [k for k, v in previous_qualification_options.items() if v == previous_qualification_label][0]

previous_qualification_grade = st.slider("Previous Qualification Grade", 0, 190, 132)

nationality_label = st.selectbox("Nationality", list(nationality_options.values()))
nationality = [k for k, v in nationality_options.items() if v == nationality_label][0]

mothers_qualification_label = st.selectbox("Mother's Qualification", list(mothers_qualification_options.values()))
mothers_qualification = [k for k, v in mothers_qualification_options.items() if v == mothers_qualification_label][0]

fathers_qualification_label = st.selectbox("Father's Qualification", list(fathers_qualification_options.values()))
fathers_qualification = [k for k, v in fathers_qualification_options.items() if v == fathers_qualification_label][0]

mothers_occupation_label = st.selectbox("Mother's Occupation", list(mothers_occupation_options.values()))
mothers_occupation = [k for k, v in mothers_occupation_options.items() if v == mothers_occupation_label][0]

fathers_occupation_label = st.selectbox("Father's Occupation", list(fathers_occupation_options.values()))
fathers_occupation = [k for k, v in fathers_occupation_options.items() if v == fathers_occupation_label][0]

admission_grade = st.slider("Admission Grade", 0, 190, 126)

displaced = st.radio("Is the student displaced?", ["No", "Yes"])
displaced = 1 if displaced == "Yes" else 0

educational_special_needs = st.radio("Special educational needs?", ["No", "Yes"])
educational_special_needs = 1 if educational_special_needs == "Yes" else 0

debtor = st.radio("Is the student a debtor?", ["No", "Yes"])
debtor = 1 if debtor == "Yes" else 0

tuition_fees_up_to_date = st.radio("Tuition fees up to date?", ["No", "Yes"])
tuition_fees_up_to_date = 1 if tuition_fees_up_to_date == "Yes" else 0

gender = st.radio("Gender", ["Female", "Male"])
gender = 1 if gender == "Male" else 0

scholarship_holder = st.radio("Scholarship holder?", ["No", "Yes"])
scholarship_holder = 1 if scholarship_holder == "Yes" else 0

age_at_enrollment = st.slider("Age at Enrollment", 17, 70, 23)

international = st.radio("Is the student international?", ["No", "Yes"])
international = 1 if international == "Yes" else 0

# Additional numerical academic features
curr_units_1st_sem_enrolled = st.slider("1st Sem Enrolled", 1, 26, 6)
curr_units_1st_sem_evaluations = st.slider("1st Sem Evaluations", 1, 45, 9)
curr_units_1st_sem_approved = st.slider("1st Sem Approved", 0, 26, 5)
curr_units_1st_sem_grade = st.slider("1st Sem Grade", 0.0, 18.87, 11.0)

curr_units_2nd_sem_enrolled = st.slider("2nd Sem Enrolled", 1, 23, 6)
curr_units_2nd_sem_evaluations = st.slider("2nd Sem Evaluations", 1, 33, 8)
curr_units_2nd_sem_approved = st.slider("2nd Sem Approved", 0, 20, 4)
curr_units_2nd_sem_grade = st.slider("2nd Sem Grade", 0.0, 18.57, 10.0)

unemployment_rate = st.slider("Unemployment Rate", 7.6, 16.2, 11.5)
inflation_rate = st.slider("Inflation Rate", -0.3, 3.7, 1.2)
gdp = st.slider("GDP", -4.06, 3.51, 0.02)

ratio_approved_1st_sem = st.slider("Ratio Approved 1st Sem", 0.0, 1.0, 0.72)
ratio_approved_2nd_sem = st.slider("Ratio Approved 2nd Sem", 0.0, 1.0, 0.68)

# === Prepare DataFrame for Prediction ===
columns = [
    "Marital_status", "Application_mode", "Application_order", "Course",
    "Daytime_evening_attendance", "Previous_qualification", "Previous_qualification_grade",
    "Nacionality", "Mothers_qualification", "Fathers_qualification",
    "Mothers_occupation", "Fathers_occupation", "Admission_grade", "Displaced",
    "Educational_special_needs", "Debtor", "Tuition_fees_up_to_date", "Gender",
    "Scholarship_holder", "Age_at_enrollment", "International",
    "Curricular_units_1st_sem_enrolled", "Curricular_units_1st_sem_evaluations", "Curricular_units_1st_sem_approved",
    "Curricular_units_1st_sem_grade", "Curricular_units_2nd_sem_enrolled", "Curricular_units_2nd_sem_evaluations",
    "Curricular_units_2nd_sem_approved", "Curricular_units_2nd_sem_grade",
    "Unemployment_rate", "Inflation_rate", "GDP",
    "Ratio_approved_1st_sem", "Ratio_approved_2nd_sem"
]

input_data = [[
    marital_status, application_mode, application_order, course,
    daytime_evening_attendance, previous_qualification, previous_qualification_grade,
    nationality, mothers_qualification, fathers_qualification,
    mothers_occupation, fathers_occupation, admission_grade, displaced,
    educational_special_needs, debtor, tuition_fees_up_to_date, gender,
    scholarship_holder, age_at_enrollment, international,
    curr_units_1st_sem_enrolled, curr_units_1st_sem_evaluations, curr_units_1st_sem_approved,
    curr_units_1st_sem_grade, curr_units_2nd_sem_enrolled, curr_units_2nd_sem_evaluations,
    curr_units_2nd_sem_approved, curr_units_2nd_sem_grade,
    unemployment_rate, inflation_rate, gdp,
    ratio_approved_1st_sem, ratio_approved_2nd_sem
]]

input_df = pd.DataFrame(input_data, columns=columns)

# === Predict ===
if st.button("Predict Dropout Status"):
    prediction = int(model.predict(input_df)[0])  # pastikan bertipe int
    label_dict = {0: "GRADUATED", 1: "ENROLLED", 2: "DROPOUT"}
    st.success(f"**Prediction Result:** {label_dict.get(prediction, 'Unknown')}")

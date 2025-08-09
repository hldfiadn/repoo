# load dataframe
df <- read.csv('D:/IPB/Metode Kuantitatif/train.csv',header=T,na.strings=c(""))

# cek missing value
sapply(df, function(x) sum(is.na(x)) )
sapply(df, function(x) length(unique(x)) )
library(Amelia)
missmap(df, main = "Missing values vs observed")

# mengurus missing value
data <- subset(df,select=c(2,3,5,6,7,8,10,12))
data$Age[is.na(data$Age)] <- mean(data$Age,na.rm=T)

contrasts(as.factor(data$Sex))
contrasts(as.factor(data$Embarked))

summary(data)
str(data)

data <- data[!is.na(data$Embarked),]
rownames(data) <- NULL

# membuat model logistic regression dari data training
train <- data[1:800,]
test <- data[801:889,]
model <- glm(Survived ~.,family=binomial(link='logit'),data=train)
summary(model)
anova(model, test="Chisq")
library(pscl)
pR2(model)

# menguji model logistic regression dengan data test
fitted.results <- predict(model,newdata=subset(test,select=c(2,3,4,5,6,7,8)),type='response')
fitted.results <- ifelse(fitted.results > 0.5,1,0)
misClasificError <- mean(fitted.results != test$Survived)
print(paste('Accuracy',1-misClasificError))


library(ROCR)
p <- predict(model, newdata=subset(test,select=c(2,3,4,5,6,7,8)), type="response")
pr <- prediction(p, test$Survived)

# ROC
prf <- performance(pr, measure = "tpr", x.measure = "fpr") # TPR = sensitivity, FPR=specificity
plot(prf)

# AUC
auc <- performance(pr, measure = "auc")
auc <- auc@y.values[[1]]
auc
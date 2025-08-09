# Lembar Kerja 2

## Deskripsi Soal
Sebuah pabrik selai membuat selai stroberi. Setiap harinya, mereka akan menerima satu kontainer buah stroberi dan Pisang dari perkebunan rekanan mereka. Akan tetapi, kualitas (*grade*) stroberi yang ada pada kontainer tersebut bermacam-macam.

![](./img/02_1.png)

Kualitas daripada stroberi dilihat dari berat (*weight*) dan warnanya (*color*). sedangkan kualitas daripada pisang dilihat dari berat (*weight*), warna (*color*), dan bercak (*speck*) di permukaan kulitnya. aturan penentuan kualitas sebagai berikut:

Tabel 1.  Penentuan kualitas stroberi

| Grade | Weight | Color |
| :---: | :---: | :---: |
| High | >18 gram | Dark Red or Medium Red |
| Medium | 12 gram > weight >= 18 gram | Dark Red or Medium Red |
| Low | 7 gram > weight >= 12 gram | Dark Red
| Reject | Others |

Tabel 2.  Penentuan kualitas pisang

| Grade | Weight | Color | Speck |
| :---: | :---: | :---: | :---: |
| High | 130 < weight <= 150 | Yellow | LOW |
| Medium | 130 < weight <= 150 | Yellow | MEDIUM |
| Medium | 100 < weight <= 130 | Yellow | LOW |
| Low | 130 < weight <= 150 | Yellow | HIGH |
| Low | 100 < weight <= 130 | Yellow | MEDIUM |
| Low | weight <= 100 | Yellow | LOW |
| Low | 150 < weight | Yellow | LOW or MEDIUM |
| Reject | Others |

Pabrik hanya akan menerima kontainer stroberi apabila jumlah kualitas *reject* paling banyak 30% dari jumlah seluruh stroberi di kontainer tersebut, sedangkan pisang 40%. Oleh karena itu, mereka membuat suatu mesin yang disebut sebagai *grader*. Grader akan menganalisis isi dari kontainer dan menentukan kualitas stroberi, sekaligus mencatat jumlah stroberi per kualitas dalam sebuah laporan. Berdasarkan hasil tersebut, *grader* akan memutuskan apakah pabrik dapat menerima atau menolak kontainer tersebut. Apabila kontainer diterima, kontainer tersebut akan diteruskan ke proses selanjutnya. Kontainer yang ditolak akan dikembalikan ke perkebunan stroberi.

Tugas kalian adalah mensimulasikan kegiatan di atas dalam suatu proyek sederhana yang dibuat dengan paradigma berorientasi objek.

### Contoh Masukan
```
Data Stroberi:
18 DARK_RED
1 DARK_RED
10 MEDIUM_RED
12 LIGHT_RED
14 DARK_RED
18 MEDIUM_RED
11 DARK_RED
10 DARK_RED
2 DARK_RED
3 DARK_RED
40 LIGHT_RED
20 DARK_RED
2 DARK_RED
7 MEDIUM_RED
12 DARK_RED
12 DARK_RED
9 DARK_RED

Data Pisang:
151 YELLOW LOW
150 YELLOW LOW
130 YELLOW LOW
129 YELLOW LOW
151 GREEN MEDIUM
121 GREEN LOW
100 YELLOW HIGH
90 YELLOW LOW
132 YELLOW HIGH
125 GREEN MEDIUM
```

### Contoh Keluaran
```
***GRADING REPORT***
Container Content: 17 Strawberry
Grading Time: Thu Feb 01 06:17:22 WIB 2024

Grading Details
High Grade : 1 Strawberry
Medium Grade: 3 Strawberry
Low Grade : 5 Strawberry
Reject : 8 Strawberry

Rejection Ratio: 0.47058823529411764
Conclusion: REJECT


***GRADING REPORT***
Container Content: 10 Banana
Grading Time: Thu Feb 01 06:17:22 WIB 2024

Grading Details
High Grade : 1 Banana
Medium Grade: 2 Banana
Low Grade : 3 Banana
Reject : 4 Banana

Rejection Ratio: 0.4
Conclusion: ACCEPT
```

---
<br>

# Format Pengerjaan
- **Cuplikan Program**: sertakan setidaknya satu buah cuplikasi program yang telah dijalankan. Apabila program yang dibuat memiliki unsur animasi, sertakan pula tautan hasil ekspor berupa rekaman atau GIF ke Google Drive yang dapat diakses oleh publik.
- **Kode Program**: sertakan kode program yang dibuat. Untuk memformat kode, pasang *Add-Ons* [Code Blocks](https://workspace.google.com/marketplace/app/code_blocks/100740430168) pada Google Docs. Gunakan pengaturan `Language = javascript` dan `Theme = tomorrow`. Setelah itu, berikan nomor baris pada kodenya. Ubah ukuran huruf menjadi 10 poin. Kalian dapat melakukan perubahan format (atau meletakkan kode program dengan cara lain) asalkan kode program dapat terbaca dengan nyaman dan diberi nomor baris. Berikan komentar pada kode untuk menandai fungsi dari suatu blok program.
- **Ulasan Kode Program**: jelaskan kode program yang telah dibuat. Penjelasan tidak perlu sangat detail (per baris). Prioritaskan penjelasan kode program yang sulit untuk dipahami.



**B. Ulasan**

Berdasarkan kode program yang telah kalian buat, identifikasilah konsep *Object Oriented* yang kalian gunakan. Deskripsi bisa berupa nama kelas dan baris tempat konsep tersebut digunakan, atau penjelasan naratif (apabila konsep tersebut sulit dijelaskan dengan nama kelas dan baris).

| No | Konsep *Object Oriented* | Digunakan? | Deskripsi |
| --- | --- | --- | --- |
| 1 | *Class* | Ya | *Class* MountainBike digunakan sebagai objek dari Bicycle yang merepresentasikan ...
| 2 | *Object* | ... | ... | ... |
| 3 | *Inheritance* | ... | ... |
| 4 | *Polymorphism* | ... | ... |
| 5 | *Abstraction* | ... | ... |
| 6 | *Encapsulation* | ... | ... |
| 7 | *Composition* | ... | ... |


<br>

---

<br>

# Petunjuk/*Clue*
<ol>
  <li>
    Jika bingung membuat solusi dari masalah dalam bentuk kode, buat <i>flow chart</i> atau <i>pseudocode</i> terlebih dahulu, atau buat terlebih dahulu dengan gaya <i>functional programming</i>
  </li>
  <li>
    Buatlah masing-masing satu fail yang merepresentasikan satu objek atau kelas, sehingga fail yang dibutuhkan adalah
    <ul>
      <li><a href="/LKP02/clue/Strawberry.java"> Strawberry.java</a> sebagai representasi objek stroberi</li>
      <li><a href="/LKP02/clue/Container.java">Container.java</a> sebagai representasi kontainer yang mewadahi stroberi</li>
      <li><a href="/LKP02/clue/Grader.java">Grader.java</a> sebagai representasi alat untuk menentukan <i>grade</i> dari stroberi yang dibawa oleh kontainer</li>
      <li><a href="/LKP02/clue/Main.java">Main.java/Driver.java</a>, program untuk mengatur apakah stroberi ditambahkan atau berhenti ditambahkan ke kontainer</li>
    </ul>
  </li>
  <li>
    Gunakan Main.java/Driver.java hanya untuk menjalankan program, jadi tidak ada objek atau kelas lain di dalamnya. Gunakan objek dengan fungsi File() untuk membaca masukan dalam bentuk teks, objek atau modul tersebut bisa digunakan dari <code>java.io.File</code>. Jangan lupa menambahkan pengecualian jika fail yang dibaca tidak ada (<code>FileNotFoundException</code>).
    <br>
    Jika tidak ingin menggunakan fail dan memberi masukan secara manual, maka dipersilahkan
  </li>
  <li>
    Buat kelas dengan objek stroberi yang menampung nilai-nilai yang dibutuhkan untuk proses <i>grading</i>. Isi dalam kelas stroberi tersebut juga ada metode yang hanya bisa dilakukan jika terkait dengan stroberi (contoh: mendapatkan nilai ukuran stroberi)
  </li>
  <li>
    Buat kelas dengan objek pisang yang menampung nilai-nilai yang dibutuhkan untuk proses <i>grading</i>. Isi dalam kelas pisang tersebut juga ada metode yang hanya bisa dilakukan jika terkait dengan pisang (contoh: mendapatkan nilai ukuran pisang)
  </li>
  <li>
    Kelas <i>grader</i> adalah kelas atau objek paling penting di sini. Dia menentukan bagaimana stroberi dapat diterima ataupun ditolak. Maka, isi dari kelas atau objek ini adalah perhitungan-perhitungan
  </li>
  <li>
    Kelas kontainer sebenarnya opsional, tetapi akan bagus jika ditambahkan karena sesuai dengan ilustrasi yang merepresentasikan objek di dunia nyatanya. Bayangkan saja, kontainer ini sebagai "wadah" ketika stroberi ditambahkan, kemudian sebagai "objek" yang melewati alat <i>grader</i>. Singkatnya, kontainer diperlukan agar <i>grader</i> tidak menilai stroberi satu-persatu, tapi secara paketan kontainer
  </li>
</ol>

Catatan: petunjuk/*clue* ini tidak wajib diikuti, tapi bisa dipakai sebagai patokan. Seminimal mungkin dapat mengikuti petunjuk/*clue*, tapi jika menemukan solusi yang lebih baik, maka bisa menggunakan solusi yang lebih baik tersebut (contoh: menggunakan *enumeration*).


---

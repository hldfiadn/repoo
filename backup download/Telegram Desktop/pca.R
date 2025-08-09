#contoh pertama
a<-c(1,2,3,4,5)   #vector a
b<-c(1,5,8,9,2)   #vector b
ab<- data.frame(a,b)   #digabung dijadiin data frame
View(ab)  #untuk lihat tabelnya
str(ab)   #untuk lihat tipe datanya (tipe datanya numerik karena dua-duannya angka)
#covarian
cov(ab)  #(2.5 : ragam a, 12.5 : ragam b, 1.5 : covarian)
#eigen
eigen(cov(ab))  #nilai eigen tdk dicari dari data al tapi dari data cov
#====================
#contoh kedua
data("mtcars")  #datanya udah ada di r studio
str(mtcars)   #cek tipe data
datamobil<-mtcars[,c(1:7,10,11)]  #di vs dan am nilainya 0 dan 1, drat satuan disp ratusan jadi rentangnya beda
#jadi yang dipake data 1-7, 10, 11 vs dan am ga dipake
View(datamobil)
cov(datamobil)
eigen(cov(datamobil))
#PCA (diusahakan rentangnya harus sama)
mobil.pca<-prcomp(datamobil, center=TRUE, scale.=TRUE) #datamobil nama filenya, center dan true untuk menyamakan rentangnya
summary(mobil.pca)
#standard deviation : nilai eigen
#proportion of variance :proporsi nilai eigen
#cumulative proportion : kumulatif dari nilai proporsi
#pcnya sampai 9 karena variabelnya ada 9
pcnya<-predict(mobil.pca, newdata=datamobil)
View((pcnya))
#=========================

#A
#Mendefinisikan fitur menjadi dataframe
fitur1 <- c(10,13,4,10,11)
fitur2 <- c(12,16,7,16,9)
fitur3 <- c(5,8,11,11,7)
data <- data.frame(fitur1,fitur2,fitur3)
#Varian(S)
var(fitur1)
var(fitur2)
var(fitur3)
cov(data)
eigen(cov(data))
#===========================
#B
a <- matrix(c(4,3,3,4.5),2,2)
a
eigen_matrix <- eigen(a)
#eigen value
eigen_matrix$values
#eigen vector
eigen_matrix$vectors
data.pca<-prcomp(data, center=TRUE, scale.=TRUE) 
summary(data.pca)
pcnya<-predict(data.pca, newdata=data)
View((pcnya))







#Library
library(readr)
library(factoextra)

#Menginput Dataset ke R
data <- read.csv("C:/Users/ACER/Downloads/csgo_players.csv", row.names = NULL)

# Set kolom pertama menjadi nama baris
baru <- data[,-2] # Menghapus kolom pertama
rownames(baru) <- make.names(data$nickname, unique = TRUE)

#Mengambil 50 data acak
databaru <- baru[sample(nrow(data), 50),c(7,8,10,11,12,13,14,15)]

#Lakukan normalisasi data
#Cari kodenya

#Mencari Jumlah Clustering Optimal Dengan Metode Silhouette
fviz_nbclust(databaru, kmeans, method = "silhouette")

#Kmeans Tanpa di PCA dengan k=2
kmeans.awal <- kmeans(databaru,2)
kmeans.awal

#Kmeans Tanpa di PCA dengan k=5
kmeans.awal <- kmeans(databaru,5)
kmeans.awal

#Gambar Plot Kmeans Sebelum di PCA
plot(databaru[c("total_kills", "total_deaths")], col=
       kmeans.awal$cluster, main = "Kmeans Sebelum PCA" )
points(kmeans.awal$centers[,c("total_kills", "total_deaths")],
       col= 1:2, pch = 8, cex =2)

#Gambar Plot clustering Kmeans Sebelum di PCA
fviz_cluster(kmeans.awal, databaru)

#Kmeans Setelah di PCA
data.pca <- prcomp(databaru, center = TRUE, scale = TRUE)
df.pca <- as.data.frame(data.pca$x[,1:2])
kmeans2 <- kmeans(df.pca,2)
kmeans2

#Gambar Plot Kmeans k=2 Setelah di PCA
plot (df.pca[c("PC1", "PC2")], col= kmeans2$cluster, main = "Kmeans Setelah PCA")
points(kmeans2$centers[,c("PC1", "PC2")], col= 1:2, pch = 8, cex = 2)

#Gambar Plot clustering Kmeans Setelah di PCA
fviz_cluster(kmeans2, databaru)


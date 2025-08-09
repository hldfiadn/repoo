#nmf update multiplicative
library(matlib)
V <- matrix(c(1,1,1,2,1,1,3,2,2,3,1,1), nrow = 3)
r = 2
H <- matrix(c(1,0,1,1,1,0,0,1), nrow = r)


n = 1
maxiter = 100 #masukkan jumlah iterasi maks
Norm_G = 0
err = 0.0001 #masukkan maks error
for (i in n:maxiter) {
  if (Norm_G == 0 || Norm_G > err){
    H_inv <- inv(H%*%t(H))
    Wt <- H_inv %*% (H%*%t(V))
    W <- t(Wt)
    
    H_ij <- (H * ( (t(W)%*%V) / (t(W) %*% W %*% H) ))
    W[W < 0] <- 1e-9
    W_inv <- inv(t(W)%*%W)
    H = W_inv %*% (t(W) %*% V)
    
    W_ij <- (W * (V%*%t(H_ij)) / (W %*% H_ij %*% t(H_ij)) )
    H[H < 0] <- 0.0000001
    
    Faktor <- W %*% H
    Galat <- (V - Faktor)
    Norm_G <- sqrt(sum(Galat^2))
    cat("Iterasi ke",i,":", Norm_G, "\n")
  }
}
turunan <- function(f, x, h) {
  mb = NULL
  mc = NULL
  md = NULL
  me = NULL
  mf = NULL
  mg = NULL
  mh = NULL
  x0 = x-h
  x1 = x
  x2 = x+h
  
  dx <- genD(func = f, x = x)$D[1]
  
  maju <- (f(x2)-f(x1))/h
  pusat <- (f(x2)-f(x0))/2*h
  mundur <- (f(x1)-f(x0))/h
  
  galat1 <- abs (maju-dx)
  galat2 <- abs (pusat-dx)
  galat3 <- abs (mundur-dx)
  
  mb[1] = h
  mc[1] = maju
  md[1] = pusat
  me[1] = mundur
  mf[1] = galat1
  mg[1] = galat2
  mh[1] = galat3
  
  matriks <- matrix(c(mb, mc, md, me, mf, mg, mh), ncol=7,
                    dimnames = list(NULL, c("h", "selisih maju", "selisih pusat", "selisih mundur", "galat maju", "galat pusat", "galat mundur" )))
  return(matriks)
}

f3 <- function(x) {
  log(x^3-x+1)
}

turunan(f3, 1, 0.1)
turunan(f3, 1, 0.01)
turunan(f3, 1, 0.001)
turunan(f3, 1, 0.0001)
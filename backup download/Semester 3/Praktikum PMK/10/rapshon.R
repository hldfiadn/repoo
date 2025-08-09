#rapshon
install.packages('numDeriv')
library(numDeriv)
library(SciViews)
rapshon <- function(f, x0, n, epsilon){
  
  ma = NULL
  mb = NULL
  mc = NULL
  md = NULL
  me = NULL
  
  for (i in 1:n) {
    fx0 <- f(x0)
    dx <- genD(f = f, x = x0)$D[1]
    x1 <- x0 - (fx0/dx)
    
    ma[i] = x0
    mb[i] = fx0
    mc[i] = x1
    md[i] = abs(x1-x0)
    me[i] = abs((x1-x0)/x1)
    
    if ((f(x1) == 0) || abs((x1-x0)/x1) < epsilon) {
      break
    }
    x0 <- x1
  }
  
  matriks <- matrix (c(ma, mb, mc, md, me), ncol = 5,
                     dimnames = list(NULL, c("x0", "f(x)", "xn", "xn-x0", "(xn-x0)/xn")))
  return(matriks)
}

f <- function(x)
{
  x^2 - 4*x + exp(x)
}
rapshon(func, 1, 20, 1e-6)

f <- function(x) {
  2*x^4 + 10*x^2 - 15*x + 2
}
rapshon(f, 5, 10, 0.01)
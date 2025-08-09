#metode secant
secant <- function(f, x0, x1, n, epsilon) {
  ma = NULL
  mb = NULL
  mc = NULL
  md = NULL
  me = NULL
  mf = NULL
  
  for (i in 1:(n+2)) {
    fx0 <- f(x0)
    fx1 <- f(x1)
    x2 <- x1-((fx1*(x1-x0))/(fx1-fx0))
    
    ma[i] = x0
    mb[i] = x1
    mc[i] = fx0
    md[i] = fx1
    me[i] = x2
    mf[i] = abs(x2-x1)
    
    if ((f(x2)) == 0 || abs(x2-x1) < epsilon ) {
      break
    }
    x0 <- x1
    x1 <- x2
  }
  matriks <- matrix(c(ma,mb,mc,md,me,mf), ncol=6,
                    dimnames = list(NULL, c("x(n-1)", "xn", "fx(n-1)", "fx(n)", "x(n+1)", "x(n+1)-xn")))
  return(matriks)
}

f <- function(x) {
  x^2 - 4*x + exp(x)
}
secant(f, 0, 1, 20, 1e-6)

f <- function(x) {
  2*x^4 + 10*x^2 - 15*x + 2
}
secant(f, 4, 5, 10, 0.01)
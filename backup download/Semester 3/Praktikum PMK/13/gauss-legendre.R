gauss <- function(f, a, b) {
  x <- function(u) {
    ((u+1)*(b-a)+2*a)/2
  }
  t1 <- x(1/sqrt(3))
  t2 <- x(-1/sqrt(3))
  hasil <- ((b-a)/2)*(f(t1)+f(t2))
  return(hasil)
}

f2 <- function(x) {
  (2*x+3)*exp(x)
}

gauss(f2, 2, 5)
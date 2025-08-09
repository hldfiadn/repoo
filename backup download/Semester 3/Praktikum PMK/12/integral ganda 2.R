integralganda2 <- function(f, a, b, c, d, h1, h2) {
  hasil = 0
  for (i in seq(a, b, by = h1)) {
    sum = 0
    for(j in seq(c, d, by = h2)) {
      if(j==c || j==d) {
        sum <- sum + f(i, j)
      }
      else {
        sum <- sum + 2*f(i, j)
      }
    }
    if(i==a || i==b) {
      hasil <- hasil + (h2/2)*sum
    }
    else {
      hasil <- hasil + 2*((h2/2)*sum)
    }
  }
  return((h1/2)*hasil)
}

f2 <- function(x, y) {
  (x^2*y^3) - (x*y)
}

integralganda2(f2, 1, 3, 0, 2, 0.5, 0.5)
#trapesium

trapesium <- function(x) {
  x*exp(-x^2)
}
I = 0
a = 0
b = 1.5
n = 8
delta <- (b-a)/n
for (x in 0:n) {
  if (x==0 || x==n) {
    I = I + trapesium(x*delta)
  }
  else {
    I = I + 2*(trapesium(x*delta))
  }
}
I = (delta/2)*I
print(I)
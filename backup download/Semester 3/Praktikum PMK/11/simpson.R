#simpson

simpson <- function(x) {
  x*exp(-x^2)
}
I = 0
a = 0
b = 1.5
n = 8
delta = (b-a)/n
for (x in 0:n) {
  if (x == 0 || x == n) {
    I = I + simpson(x*delta)
  }
  else if (x %% 2 == 0) {
    I = I + 2*simpson(x*delta)
  }
  else {
    I = I + 4*simpson(x*delta)
  }
}
I = I * delta/3
print(I)
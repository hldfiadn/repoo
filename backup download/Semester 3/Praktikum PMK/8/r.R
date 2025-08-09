#nomor 1
g <- expression((t^3+10*t)/(sqrt(t^2+4)))
dg <- D(g, 't')
ddg <- D(dg, 't')

t <- 0.17
eval(dg)
eval(ddg)

#nomor 2
f1 <- function(x) {
  ((exp(x)-exp(-x))/(2*x))
}
x <- 0.1
for (i in 1:6){
  print(f1(x))
  x = x * 0.1
}
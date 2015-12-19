print("Entre com um valor de x:")
x1 <- readline()
x1 <- as.integer(x1)

print("Entre com um valor de y:")
y1 <- readline()
y1 <- as.integer(y1)

print("Entre com um valor de x:")
x2 <- readline()
x2 <- as.integer(x2)

print("Entre com um valor de y:")
y2 <- readline()
y2 <- as.integer(y2)

print("Entre com um valor de x:")
x3 <- readline()
x3 <- as.integer(x3)

print("Entre com um valor de y:")
y3 <- readline()
y3 <- as.integer(y3)

par1 <- sprintf("Par: (%.0f, %.0f)", x1, y1)
par2 <- sprintf("Par: (%.0f, %.0f)", x2, y2)
par3 <- sprintf("Par: (%.0f, %.0f)", x3, y3)

print(par1)
print(par2)
print(par3)

vx <- seq(from=0, to=10)
plot(vx, vx, type="l")
points(x1,y1)
points(x2,y2)
points(x3,y3)
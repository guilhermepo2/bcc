print("Entre com os valores de a, b e c:")
entradas <- scan()
a <- entradas[1]
b <- entradas[2]
c <- entradas[3]

delta <- (b*b) - (4*a*c)
print(delta)
if(delta < 0) {
	print("as raizes sao complexas")
	
	complexo <- abs(delta)
	x1 <- complex(real = (-1 * b), imaginary = complexo)
	x1 <- x1 / (2*a)
	x2 <- complex(real = (-1 * b), imaginary = -complexo)
	x2 <- x2 / (2*a)
} else {
	if (delta == 0) {
		print ("as raizes sao iguais")
	} else {
		print ("as raizes sao reais e diferentes")
	}
	
	x1 <- ((-1 * b) + sqrt(delta)) / (2*a)
	x2 <- ((-1 * b) - sqrt(delta)) / (2*a)
}

Xv <- (-1*(b/(2*a)))
Yv <- a*Xv^2 + b*Xv + c

print("Raizes: ")
print(x1)
print(x2)
pontov <- sprintf("Ponto do Vertice: (%f, %f)", Xv, Yv)

xmin <- Xv - 5
xmax <- Xv + 5

valores_x = seq(from=xmin, to=xmax, length.out=51)
valores_y <- (a*(valores_x*valores_x))+(b*valores_x)+c

valores_x2 <- c(x1, x2, Xv)
#valores_x2 <- sort(valores_x)
valores_y2 <- (a*(valores_x*valores_x))+(b*valores_x)+c

plot(valores_x, valores_y, type="l")
points(Xv, Yv)
points(x1, a*x1^2 + b*x1 + c)
points(x2, a*x2^2 + b*x2 + c)

abline(v=Xv)
abline(h=Yv)
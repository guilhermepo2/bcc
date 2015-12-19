print("Entre com os valores de a, b e c:")
entradas <- scan()
a <- entradas[1]
b <- entradas[2]
c <- entradas[3]

delta <- (b*b) - (4*a*c)
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
	
	x1 <- ((-1 * b) + delta) / (2*a)
	x2 <- ((-1 * b) - delta) / (2*a)
}

print("Raizes: ")
print(x1)
print(x2)
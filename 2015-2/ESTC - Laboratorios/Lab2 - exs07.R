print("Entre com os valores pelo teclado:")
entrada <- scan()
print("Valor da confianca:")
confianca <- readline()
confianca <- as.integer(confianca)

media <- mean(entrada)
desviop <- sqrt(var(entrada))

if (length(entrada) < 30)
{
	z <- qt(entrada, df=gdl)
} else {
	z <- qnorm(entrada)
}

print(z)
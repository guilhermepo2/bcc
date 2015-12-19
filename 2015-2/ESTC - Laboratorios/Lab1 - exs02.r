input <- scan()
media <- sum(input) / length(input)

desvio1 <- 0

for (i in input)
{
	desvio1 <- desvio1 + ((i - media)*(i - media))
}

desvio1 <- desvio1 / (length(input)-1)
desvio1 <- sqrt(desvio1)

resultado <- sprintf("o desvio e: %.5f", desvio1)
print(resultado)


print("Entre com os valores de x:")
x <- scan()
y <- sin(x)

media <- sum(y)/length(y)
desvio <- sqrt(var(y))

plot(x,y)
abline(h=media)
abline(h=(media + desvio), lty = 2)
abline(h=(media - desvio), lty = 2)
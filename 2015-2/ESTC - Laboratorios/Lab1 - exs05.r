x <- c(2,3,5,6,6,7,8,9,10,11,11,14,15,19)

print(x)

xb <- mean(x, trim=0)
print(" # = 0")
print(xb)
xb <- mean(x, trim=0.1)
print(" # = 0.1")
print(xb)
xb <- mean(x, trim=0.2)
print(" # = 0.2")
print(xb)
xb <- mean(x, trim=0.5)
print(" # = 0.5")
print(xb)
xb <- mean(x, trim=1.0)
print(" # = 1.0")
print(xb)

print("pela palavra 'trim', provavelmente indica que uma parte da entrada esta sendo removida, fazendo testes, provavelmente a fracao presente em # representa a quantidade de elementos que vao ser cortados do vetor no inicio e no fim, e entao sera calculada a media - onde a quantidade de elementos removidas e n*# ")
print("a primeira coisa que pode ser observada e que com # maior que 0.5, o valor nao e alterado, entao com # = 2.0, o valor sera o mesmo que o valor de # = 0.5")

xb <- mean(x, trim=2.0)
print(" # = 2.0")
print(xb)
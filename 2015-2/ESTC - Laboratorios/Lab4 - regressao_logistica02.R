reacao_y <- c(0,1,0,0,1,0,1,1,0,1,0,1,0,0,0,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,0,1,1,0,1,1)
idade_x1 <- c(22,38,36,58,37,31,32,54,60,34,45,27,30,20,30,30,22,26,19,18,22,23,24,50,20,47,34,31,43,35,23,34,51,63,22,29)
escolaridade_x2 <- c(6,12,12,8,12,12,10,12,8,12,12,12,8,4,8,8,12,8,9,4,12,6,12,12,12,12,12,12,12,8,8,12,16,12,12,12)
sexo_x3 <- c(1,1,0,0,1,0,1,1,1,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,0,1,0,0,0,1,1,1)

dados <- data.frame(Y=reacao_y, X1 = idade_x1, X2 = escolaridade_x2, X3 = sexo_x3)

minha_regressao <- glm(Y~X1+X2+X3, data=dados, family=binomial())
summary(minha_regressao)
print(confint(minha_regressao, confint = 0.95))

# calculando os odds ratio OR=e^(bi)
ORx1 = exp(summary(minha_regressao)$coefficients[2,1])
ORx2 = exp(summary(minha_regressao)$coefficients[3,1])
ORx3 = exp(summary(minha_regressao)$coefficients[4,1])
print(ORx1) # tem esse tanto de chance de Y acontecer X1 = 1
print(ORx2) # tem esse tanto de chance de Y acontecer X2 = 1
print(ORx3) # tem esse tanto de chance de Y acontecer em X3 = 1

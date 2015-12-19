y <- c(9.95, 24.25, 31.75, 35, 25.02, 16.86, 14.38, 9.6, 24.35, 27.5, 17.08, 37, 41.95, 11.66, 21.65, 17.89, 69, 10.3, 34.93, 46.59, 44.88, 54.12, 56.23, 22.13, 21.15)
x1 <- c(2,8,11,10,8,4,2,2,9,8,4,11,12,2,4,4,20,1,10,15,15,16,17,6,5)

matriz_dados <- matrix(c(y,x1), nrow=length(y), ncol=2)
media_x <- mean(x1)
media_y <- mean(y)
string_medias <- sprintf("Media de X: %f - Media de Y: %f", media_x, media_y)


SQX <- sum((x1 - media_x)^2)
SQXY <- sum((x1 - media_x)*(y - media_y))
string_sq <- sprintf("SQX: %f - SQXY: %f", SQX, SQXY)

b1 <- SQXY/SQX
b0 <- media_y - (b1*media_x)
string_equacao <- sprintf("Equacao: y = %fx + %f", b1, b0)


STQ <- sum((y - media_y)^2)
SQReg <- sum(((b1*x1 + b0)- media_y)^2)
SQR <- sum(((b1*x1 + b0)- y)^2)
string_st <- sprintf("STQ: %f - SQReg: %f - SQR: %f", STQ, SQReg, SQR)

r2 <- SQReg / STQ
string_significancia <- sprintf("Significancia: %f", r2)

Syx <- sqrt(SQR / (length(y)-2))
Sb1 <- (Syx/(sqrt(SQX)))
t <- 0.6853 # pela tabela
string_sss <- sprintf("Syx: %f - Sb1: %f - t: %f", Syx, Sb1, t)

betamin <- b1 - (t*Sb1)
betamax <- b1 + (t*Sb1)
string_intervalo <- sprintf("Intervalo De Confianca: %f <= B <= %f", betamin, betamax)

MQReg <- SQReg
MQR <- (SQR/(length(y)-2))
fzero <- MQReg/MQR
string_mq <- sprintf("MQReg: %f - MQR: %f - F0: %f", MQReg, MQR, fzero)

print("RESULTADOS:")
print(matriz_dados)
print(string_medias)
print(string_sq)
print(string_equacao)
print(string_st)
print(string_significancia)
print(string_sss)
print(string_intervalo)
print(string_mq)
dados <- data.frame(X=c(seq(from=0,to=0,length.out=20),seq(from=1,to=1,length.out=10),seq(from=0,to=0,length.out=80),seq(from=1,to=1,length.out=90)),
					Y=c(seq(from=1,to=1, length.out=20),seq(from=1,to=1, length.out=10),seq(from=0,to=0, length.out=80),seq(from=0,to=0, length.out=90)))
					
minha_regressao <- glm(Y~X, data=dados)
summary(minha_regressao)
print(minha_regressao)
confint(minha_regressao)

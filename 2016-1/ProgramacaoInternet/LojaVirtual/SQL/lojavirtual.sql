CREATE SCHEMA LOJAVIRTUAL;
SET search_path to LOJAVIRTUAL;

CREATE TABLE CLIENTE(
	cpf varchar(15),
	nome varchar(35),
	endereco varchar(55),
	usuario varchar(25),
	senha varchar(25),

	CONSTRAINT cliente_pk PRIMARY KEY (cpf)
);

CREATE TABLE PRODUTO(
	id integer,
	nome varchar(30) NOT NULL,
	descricao varchar(100) NOT NULL,
	quantidade integer NOT NULL,
	valor double precision NOT NULL,

	CONSTRAINT produto_pk PRIMARY KEY (id)
);

CREATE TABLE VENDA(
	venda_id integer,
	cliente_cpf varchar(11),
	data_compra date NOT NULL,
	frete double precision NOT NULL,

	CONSTRAINT venda_pk PRIMARY KEY (venda_id),
	CONSTRAINT venda_fk1 FOREIGN KEY (cliente_cpf) REFERENCES CLIENTE(cpf) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE ENVOLVE(
	envolve_id integer,
	venda_id integer,
	produto_id integer,

	CONSTRAINT envolve_pk PRIMARY KEY (envolve_id),
	CONSTRAINT envolve_fk1 FOREIGN KEY (venda_id) REFERENCES VENDA(venda_id) ON DELETE CASCADE ON UPDATE CASCADE,
	CONSTRAINT envolve_fk2 FOREIGN KEY (produto_id) REFERENCES PRODUTO(id) ON DELETE CASCADE ON UPDATE CASCADE
);
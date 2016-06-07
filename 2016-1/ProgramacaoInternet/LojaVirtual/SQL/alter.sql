SET search_path TO LOJAVIRTUAL;

CREATE SEQUENCE venda_id_seq;
ALTER TABLE venda ALTER COLUMN venda_id SET DEFAULT nextval('venda_id_seq');

CREATE SEQUENCE envolve_id_seq;
ALTER TABLE envolve ALTER COLUMN envolve_id SET DEFAULT nextval('envolve_id_seq');


ALTER TABLE venda ALTER COLUMN cliente_cpf TYPE varchar(15);

DELETE from produto where id = 2;

INSERT INTO produto VALUES(2, 'batata doce em po', 'batata doce, so que em po', 10, 3.99);
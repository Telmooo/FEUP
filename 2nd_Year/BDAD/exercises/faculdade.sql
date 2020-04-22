DROP TABLE IF EXISTS Aluno;
DROP TABLE IF EXISTS Prof;
DROP TABLE IF EXISTS Cadeira;
DROP TABLE IF EXISTS Prova;

CREATE TABLE aluno
(	nr	varchar2(5)	 not null,
 	nome	varchar2(50) not null,
 	CONSTRAINT aluno_pk PRIMARY KEY (nr)
);

INSERT INTO aluno VALUES ('100','João');
INSERT INTO aluno VALUES ('110','Manuel');
INSERT INTO aluno VALUES ('120','Rui');
INSERT INTO aluno VALUES ('130','Abel');
INSERT INTO aluno VALUES ('140','Fernando');
INSERT INTO aluno VALUES ('150','Ismael');

CREATE TABLE prof
(	sigla	varchar2(5)	not null,
 	nome	varchar2(50)	not null,
 	CONSTRAINT prof_pk PRIMARY KEY (sigla)
);

INSERT INTO prof VALUES ('ECO','Eugénio');
INSERT INTO prof VALUES ('FNF','Fernando');
INSERT INTO prof VALUES ('JLS','João');

CREATE TABLE cadeira
(	cod	varchar2(5)	not null,
 	design	varchar2(50)	not null,
    curso	varchar2(10)	not null,
    regente	varchar2(5)	REFERENCES prof(sigla),
 	CONSTRAINT cadeira_pk PRIMARY KEY (cod)
);

INSERT INTO cadeira VALUES ('TS1','Teoria dos Sistemas 1','IS','FNF');
INSERT INTO cadeira VALUES ('BD','Bases de Dados','IS','ECO');
INSERT INTO cadeira VALUES ('EIA','Estruturas de Informação e Algoritmos','IS','ECO');
INSERT INTO cadeira VALUES ('EP','Electrónica de Potência','AC','JLS');
INSERT INTO cadeira VALUES ('IE','Instalações Eléctricas','AC','JLS');

CREATE TABLE prova
(	nr	varchar2(5)	REFERENCES aluno(nr),
 	cod	varchar2(50) REFERENCES cadeira(cod),
    data	date,
    nota	number(2) check (nota>=0 AND nota<=20),
 	CONSTRAINT prova_pk PRIMARY KEY (nr, cod, data)
);

INSERT INTO prova VALUES ('100','TS1','92-02-11',8);
INSERT INTO prova VALUES ('100','TS1','93-02-02',11);
INSERT INTO prova VALUES ('100','BD','93-02-04',17);
INSERT INTO prova VALUES ('100','EIA','92-01-29',16);
INSERT INTO prova VALUES ('100','EIA','93-02-02',13);
INSERT INTO prova VALUES ('110','EP','92-01-30',12);
INSERT INTO prova VALUES ('110','IE','92-02-05',10);
INSERT INTO prova VALUES ('110','IE','93-02-01',14);
INSERT INTO prova VALUES ('120','TS1','93-01-31',15);
INSERT INTO prova VALUES ('120','EP','93-02-04',13);
INSERT INTO prova VALUES ('130','BD','93-02-04',12);
INSERT INTO prova VALUES ('130','EIA','93-02-02',7);
INSERT INTO prova VALUES ('130','TS1','92-02-11',8);
INSERT INTO prova VALUES ('140','TS1','93-01-31',10);
INSERT INTO prova VALUES ('140','TS1','92-02-11',13);
INSERT INTO prova VALUES ('140','EIA','93-02-02',11);
INSERT INTO prova VALUES ('150','TS1','92-02-11',10);
INSERT INTO prova VALUES ('150','EP','93-02-02',11);
INSERT INTO prova VALUES ('150','BD','93-02-04',17);
INSERT INTO prova VALUES ('150','EIA','92-01-29',16);
INSERT INTO prova VALUES ('150','IE','93-02-02',13);

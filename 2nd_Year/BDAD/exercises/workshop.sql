-- Apaga triggers
DROP VIEW IF EXISTS modelosMarcas;
DROP TRIGGER IF EXISTS defaultCliente;
DROP TRIGGER IF EXISTS AtualizaStockPecas;
DROP TRIGGER IF EXISTS validaPecasReparacao;
DROP TRIGGER IF EXISTS insertOnView;

-- Apaga tabelas
DROP Table IF EXISTS FuncionarioReparacao;
DROP Table IF EXISTS Funcionario;
DROP Table IF EXISTS Especialidade;
DROP Table IF EXISTS PecaModelo;
DROP Table IF EXISTS ReparacaoPeca;
DROP Table IF EXISTS Peca;
DROP Table IF EXISTS Reparacao;
DROP Table IF EXISTS Carro;
DROP Table IF EXISTS Cliente;
DROP Table IF EXISTS CodPostal;
DROP Table IF EXISTS Modelo;
DROP Table IF EXISTS Marca;

-- Cria tabelas
CREATE TABLE Marca (
idMarca INTEGER PRIMARY KEY AUTOINCREMENT,
nome NVARCHAR2(50) NOT NULL);

CREATE TABLE Modelo (
idModelo INTEGER PRIMARY KEY AUTOINCREMENT,
nome NVARCHAR2(50) NOT NULL,
idMarca NUMBER REFERENCES Marca(idMarca));

CREATE TABLE CodPostal (
codPostal1 CHAR(4) PRIMARY KEY,
localidade NVARCHAR2(30));

CREATE TABLE Cliente (
idCliente INTEGER PRIMARY KEY AUTOINCREMENT,
nome NVARCHAR2(50) NOT NULL,
morada NVARCHAR2(50),
codPostal1 CHAR(4) REFERENCES CodPostal(codPostal1),
codPostal2 CHAR(3),
telefone CHAR(9));

CREATE TABLE Carro (
idCarro INTEGER PRIMARY KEY AUTOINCREMENT,
Matricula CHAR(6) UNIQUE,
idModelo NUMBER REFERENCES Modelo(idModelo),
idCliente NUMBER REFERENCES Cliente(idCliente));

CREATE TABLE Reparacao (
idReparacao INTEGER PRIMARY KEY AUTOINCREMENT,
dataInicio DATE,
dataFim DATE,
idCliente NUMBER REFERENCES Cliente(idCliente),
idCarro NUMBER REFERENCES Carro(idCarro),
CONSTRAINT ch_df_di CHECK (dataFim>=dataInicio));

CREATE TABLE Peca (
idPeca INTEGER PRIMARY KEY AUTOINCREMENT,
codigo CHAR(20) UNIQUE,
designacao NVARCHAR2(50),
custoUnitario NUMBER(9,3) CHECK (custoUnitario >= 0),
quantidade NUMBER(7,0) CHECK (quantidade >= 0));

CREATE TABLE ReparacaoPeca (
idReparacao NUMBER REFERENCES Reparacao(idReparacao),
idPeca NUMBER REFERENCES Peca(idPeca),
quantidade NUMBER(7,0) CHECK (quantidade >= 0),
CONSTRAINT pk_reparacao_peca PRIMARY KEY (idReparacao, idPeca));

CREATE TABLE PecaModelo (
idPeca NUMBER REFERENCES Peca(idPeca),
idModelo NUMBER REFERENCES Modelo(idModelo),
CONSTRAINT pk_peca_modelo PRIMARY KEY (idPeca, idModelo));

CREATE TABLE Especialidade (
idEspecialidade INTEGER PRIMARY KEY AUTOINCREMENT,
nome NVARCHAR2(50) NOT NULL,
custoHorario NUMBER(9,3) CHECK (custoHorario >= 0));

CREATE TABLE Funcionario (
idFuncionario INTEGER PRIMARY KEY AUTOINCREMENT,
nome NVARCHAR2(50) NOT NULL,
morada NVARCHAR2(50),
codPostal1 CHAR(4) REFERENCES CodPostal(codPostal1),
codPostal2 CHAR(3),
telefone CHAR(9),
idEspecialidade NUMBER REFERENCES Especialidade(idEspecialidade));

CREATE TABLE FuncionarioReparacao (
idFuncionario NUMBER REFERENCES Funcionario(idFuncionario),
idReparacao NUMBER REFERENCES Reparacao(idReparacao),
numHoras NUMBER(7,0) CHECK (numHoras >= 0),
CONSTRAINT pk_funcionario_reparacao PRIMARY KEY (idFuncionario, idReparacao));

-- Apaga os registos das tabelas
DELETE FROM FuncionarioReparacao;
DELETE FROM Funcionario;
DELETE FROM Especialidade;
DELETE FROM PecaModelo;
DELETE FROM ReparacaoPeca;
DELETE FROM Peca;
DELETE FROM Reparacao;
DELETE FROM Carro;
DELETE FROM Cliente;
DELETE FROM CodPostal;
DELETE FROM Modelo;
DELETE FROM Marca;
DELETE FROM FuncionarioReparacao;
DELETE FROM Funcionario;
DELETE FROM Especialidade;

-- Insercao de registos na tabela codPostal
INSERT INTO CodPostal (codPostal1, localidade) VALUES ('4200','Porto');
INSERT INTO CodPostal (codPostal1, localidade) VALUES ('4400','Vila Nova de Gaia');
INSERT INTO CodPostal (codPostal1, localidade) VALUES ('4450','Matosinhos');

-- Insercao de registos na tabela Cliente
INSERT INTO Cliente (nome, morada, codPostal1, codPostal2, telefone)
	VALUES ('Alberto Sousa', 'Rua Brito e Cunha, 125','4450','086','932853425');
INSERT INTO Cliente (nome, morada, codPostal1, codPostal2, telefone)
	VALUES ('Maria Francisca Pereira Nobre','Avenida Meneres, 201','4450','191','933278005');
INSERT INTO Cliente (nome, morada, codPostal1, codPostal2, telefone)
	VALUES ('Rodrigo Meireles de Aguiar','Rua da Cunha, 310 1st Dir','4200','250','928604666');
INSERT INTO Cliente (nome, morada, codPostal1, codPostal2, telefone)
	VALUES ('Adao Lopes Sa','Rua Domingos de Matos, 200 3rd Esq','4400','120','963670913');

-- Insercao de registos na tabela Marca
INSERT INTO Marca (nome) VALUES ('Renault');
INSERT INTO Marca (nome) VALUES ('Volvo');

-- Insercao de registos na tabela Modelo
INSERT INTO Modelo (nome, idMarca)
	VALUES ('Clio 1.9D', 1);
INSERT INTO Modelo (nome, idMarca)
	VALUES ('V50 Momentum', 2);
INSERT INTO Modelo (nome, idMarca)
	VALUES ('C30 Drive', 2);

-- Insercao de registos na tabela Carro
INSERT INTO Carro (matricula, idModelo, idCliente)
	VALUES ('2490CV', 1, 4);
INSERT INTO Carro (matricula, idModelo, idCliente)
	VALUES ('36DH79', 2, 2);
INSERT INTO Carro (matricula, idModelo, idCliente)
	VALUES ('1127XY', 3, 3);
INSERT INTO Carro (matricula, idModelo, idCliente)
	VALUES ('78AB27', 3, 2);
INSERT INTO Carro (matricula, idModelo, idCliente)
	VALUES ('16IU02', 3, 4);

-- Insercao de registos na tabela Reparacao
INSERT INTO Reparacao (dataInicio, dataFim, idCliente, idCarro)
	VALUES ('2010-09-17', '2010-09-20', 1, 3);
INSERT INTO Reparacao (dataInicio, dataFim, idCliente, idCarro)
	VALUES ('2010-09-19', '2010-09-21', 1, 3);
INSERT INTO Reparacao (dataInicio, dataFim, idCliente, idCarro)
	VALUES ('2010-09-15', '2010-09-16', 4, 1);
INSERT INTO Reparacao (dataInicio, dataFim, idCliente, idCarro)
	VALUES ('2009-09-18', '2009-09-27', 4, 5);

SELECT * FROM Reparacao; -- Ver que o idCliente ja nao e NULL;

-- Insercao de registos na tabela Peca
INSERT INTO Peca (codigo, designacao, custoUnitario, quantidade)
	VALUES ('37XX98', NULL, 3, 100);
INSERT INTO Peca (codigo, designacao, custoUnitario, quantidade)
	VALUES ('75VBO98', NULL, 25, 10);

-- Insercao de registos na tabela PecaModelo
INSERT INTO PecaModelo (idPeca, idModelo) VALUES (1, 1);
INSERT INTO PecaModelo (idPeca, idModelo) VALUES (2, 3);

-- Insercao de registos na tabela ReparacaoPeca
INSERT INTO ReparacaoPeca (idReparacao, idPeca, quantidade) VALUES (2, 1, 8);
INSERT INTO ReparacaoPeca (idReparacao, idPeca, quantidade) VALUES (3, 2, 2);

-- Insercao de registos na tabela Especialidade
INSERT INTO Especialidade(nome, custoHorario)
	VALUES ('Electricista', 15);
INSERT INTO Especialidade(nome, custoHorario)
	VALUES ('Mecanico', 12);
INSERT INTO Especialidade(nome, custoHorario)
	VALUES ('Chapeiro', 10);

-- Insercao de registos na tabela Funcionario
INSERT INTO Funcionario(nome, morada, codPostal1, codpostal2, telefone, idEspecialidade)
	VALUES ('Abel Sousa', 'Rua da Preciosa, 317-1st Esq', 4200, 137, '226903271', 1);
INSERT INTO Funcionario(nome, morada, codPostal1, codpostal2, telefone, idEspecialidade)
	VALUES ('Mario Teixeira', 'Rua Seca, 17', 4400, 210, '227519090', 2);
INSERT INTO Funcionario(nome, morada, codPostal1, codpostal2, telefone, idEspecialidade)
	VALUES ('Rogerio Silva', 'Rua dos Caldeireiros, 312, 3rd F', 4400, 112, '227403728', 2);
INSERT INTO Funcionario(nome, morada, codPostal1, codpostal2, telefone, idEspecialidade)
	VALUES ('Luis Pereira', 'Rua Teixeira de Pascoaes, 117, 2nd D', 4450, 117, '225901707', 3);

-- Insercao de registos na tabela FuncionarioReparacao
INSERT INTO FuncionarioReparacao (idFuncionario, idReparacao, numHoras) VALUES (1,1,1);
INSERT INTO FuncionarioReparacao (idFuncionario, idReparacao, numHoras) VALUES (4,1,4);
INSERT INTO FuncionarioReparacao (idFuncionario, idReparacao, numHoras) VALUES (1,2,1);
INSERT INTO FuncionarioReparacao (idFuncionario, idReparacao, numHoras) VALUES (2,2,6);
INSERT INTO FuncionarioReparacao (idFuncionario, idReparacao, numHoras) VALUES (4,2,2);
INSERT INTO FuncionarioReparacao (idFuncionario, idReparacao, numHoras) VALUES (1,3,1);

.shell echo Exercise 1
DROP TRIGGER IF EXISTS EX1;
CREATE TRIGGER EX1
AFTER INSERT ON Reparacao
FOR EACH ROW
WHEN New.idCliente IS NULL
BEGIN
    UPDATE Reparacao
    SET idCliente = (SELECT idCliente FROM Carro WHERE idCarro=New.idCarro)
    WHERE idCliente IS NULL;
END;

.shell echo Test Exercise 1
INSERT INTO Reparacao(dataInicio, dataFim, idCarro) VALUES("2011-09-21", "2011-09-25", 1);

.shell echo Expected Empty
SELECT * FROM Reparacao WHERE idCliente IS NULL;

.shell echo Exercise 2
DROP TRIGGER IF EXISTS EX2;
CREATE TRIGGER IF EXISTS EX2


.shell echo Exercise 3
DROP TRIGGER IF EXISTS EX3;
CREATE TRIGGER EX3
AFTER INSERT ON ReparacaoPeca
FOR EACH ROW
BEGIN
    UPDATE Peca
    SET quantidade=quantidade - New.quantidade
    WHERE idPeca=New.idPeca;
END;

.shell echo Test Exercise 3
INSERT INTO ReparacaoPeca(idPeca, quantidade) VALUES(1, 10);
INSERT INTO ReparacaoPeca(idPeca, quantidade) VALUES(2, 10);

.shell echo Expected ID=1 - Quantidade -> 90, ID=2 - Quantidade=0
SELECT * FROM Peca WHERE idPeca=1 OR idPeca=2;

.shell echo Exercise 4
DROP TRIGGER IF EXISTS EX4;
CREATE TRIGGER EX4
AFTER INSERT ON ReparacaoPeca

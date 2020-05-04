.shell echo Exercise 1
SELECT * FROM Peca
    WHERE custoUnitario < 10 AND codigo LIKE '%98%';

.shell echo Exercise 2
SELECT matricula FROM Carro
    WHERE idCarro IN
        (SELECT idCarro FROM Reparacao
            WHERE dataFim LIKE '2010-09-%');

.shell echo Exercise 3
SELECT nome FROM ((((Cliente NATURAL JOIN Carro) NATURAL JOIN Reparacao) NATURAL JOIN ReparacaoPeca) NATURAL JOIN (SELECT idPeca, custoUnitario FROM Peca))
    WHERE custoUnitario > 10 ORDER BY custoUnitario DESC;

.shell echo Exercise 4
SELECT nome FROM Cliente
    WHERE idCliente NOT IN
        (SELECT idCliente FROM Carro);

.shell echo Exercise 5
SELECT idCarro, COUNT(idReparacao) AS TimesRepaired FROM Reparacao GROUP BY (idCarro);

.shell echo Exercise 6
SELECT idCarro, SUM((CAST(SUBSTR(dataFim, -2, 2) as INTEGER) - CAST(SUBSTR(dataInicio, -2, 2) as INTEGER))) as NumberDays FROM Reparacao GROUP BY (idCarro);

.shell echo Exercise 7
SELECT AVG(custoUnitario) as AvgPrice, SUM(custoUnitario * quantidade) as TotalPrice, SUM(quantidade) AS TotalQuantity,
        MAX(custoUnitario) AS MaxPrice, MIN(custoUnitario) as MinPrice FROM Peca;

.shell echo Exercise 13

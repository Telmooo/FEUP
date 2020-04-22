.shell echo Exercise 1
SELECT nr FROM aluno;

.shell echo Exercise 2
SELECT cod, design FROM cadeira
    WHERE curso='AC';

.shell echo Exercise 3
SELECT aluno.nome as AlunoNome, prof.nome as ProfNome FROM aluno, prof
    WHERE aluno.nome=prof.nome;

.shell echo Exercise 4
SELECT nome FROM aluno EXCEPT SELECT nome FROM prof;

.shell echo Exercise 5
SELECT nome FROM aluno UNION SELECT nome FROM prof;

.shell echo Exercise 6
SELECT nome FROM
    (SELECT DISTINCT nome, aluno.nr FROM aluno, prova
        WHERE aluno.nr=prova.nr AND prova.cod='TS1');

.shell echo Exercise 7
SELECT nome FROM aluno WHERE nr IN (
    SELECT nr FROM prova NATURAL JOIN cadeira
        WHERE cadeira.curso='IS');

.shell echo Exercise 8
.shell echo By counting
SELECT nome FROM aluno
    WHERE nr IN
        (SELECT nr FROM
            (SELECT nr, COUNT(cod) as passed, cadeiras FROM
                    (SELECT DISTINCT aluno.nr, prova.cod FROM (aluno NATURAL JOIN prova) NATURAL JOIN cadeira
                        WHERE cadeira.curso='IS' AND nota>=10 GROUP BY prova.nr, prova.cod),
                    (SELECT COUNT(cod) as cadeiras FROM cadeira WHERE curso='IS') GROUP BY nr)
            WHERE passed=cadeiras);

.shell echo By negation
/*SELECT nr, cod FROM
    (SELECT nr, cod, MAX(nota) as best FROM (aluno NATURAL JOIN prova) NATURAL JOIN cadeira
        WHERE curso='IS' GROUP BY nr, cod)
    WHERE best < 10;*/

SELECT nr, cod FROM prova
    WHERE NOT EXISTS (
        SELECT * FROM cadeira
            WHERE curso='IS' AND
    )

/*
.shell echo Exercise 9
SELECT MAX(nota) FROM prova;

.shell echo Exercise 10
SELECT AVG(nota) FROM prova
    WHERE cod='BD';

.shell echo Exercise 11
SELECT COUNT(nr) FROM aluno;

.shell echo Exercise 12
SELECT curso, COUNT(cod) FROM cadeira GROUP BY curso;

.shell echo Exercise 13
SELECT nr, COUNT(nr) FROM prova GROUP BY nr;

.shell echo Exercise 14
SELECT nr, AVG(nota) FROM prova GROUP BY nr;
*/

# Relational Algebra

Given the following database

```
group: Faculdade

Aluno = {
	nr:number, Nome:string
	100, Joao
	110, Manuel
	120, Rui
	130, Abel
	140, Fernando
	150, Ismael
}

Prof = {
  sigla:string, Nome:string
	ECO, Eugenio
	FNF, Fernando
	JLS, Joao
}

Cadeira = {
  cod:string, design:string, curso:string, regente:string
	TS1, 'Teoria dos Sistemas I', IS, FNF
	BD, 'Bases de Dados', IS, ECO
	EIA, 'Estruturas de Informação e Algoritmos', IS, ECO
	EP, 'Electrónica de Potência', AC, JLS
	IE, 'Instalações Eléctricas', AC, JLS
}

Prova = {
  nr:number, cod:string, data:date, nota:number
	100, TS1, 1992-02-11, 8
	100, TS1, 1993-02-02, 11
	100, BD, 1993-02-04, 17
	100, EIA, 1992-01-29, 16
	100, EIA, 1993-02-02, 13
	110, EP, 1992-01-30, 12
	110, IE, 1992-02-05, 10
	110, IE, 1993-02-01, 14
	120, TS1, 1993-01-31, 15
	120, EP, 1993-02-04, 13
	130, BD, 1993-02-04, 12
	130, EIA, 1993-02-02, 7
	130, TS1, 1993-02-11, 8
	140, TS1, 1993-01-31, 10
	140, TS1, 1992-02-11, 13
	140, EIA, 1993-02-02, 11
	150, TS1, 1992-02-11, 10
	150, EP, 1993-02-02, 11
	150, BD, 1993-02-04, 17
	150, EIA, 1992-01-29, 16
	150, IE, 1993-02-02, 13
}
```

## 1) Number of the students
```
π nr (Aluno)
```

## 2) Code and designation of the subjects of course "AC"
```
π cod, design (σ curso='AC' (Cadeira))
```

## 3) Are there common names for students and teachers? Which are?
```
π Aluno.Nome, Prof.Nome (σ Aluno.Nome=Prof.Nome ((Aluno)⨯(Prof)))
```

## 4) What are the specific names of students, i.e., that no teacher has?
```
π Aluno.Nome ((Aluno) - ((Aluno) ⋉ (Prof)))
```

## 5) What are the names of people related to the college?
```
(π Nome (Aluno)) ∪ (π Nome (Prof))
```

## 6) What are the names of the students who took a 'ts1' test?
```
π Aluno.Nome (σ Prova.cod='TS1' ((Aluno) ⨝ (Prova)))
```

## 7) What are the names of students enrolled in the 'IS' course?
```
(π Aluno.Nome (σ Cadeira.curso='IS' (((Aluno) ⨝ (Prova)) ⨝ (Cadeira)))) ∪ (π Prof.Nome (σ Cadeira.curso='IS' ((Prof) ⨝ Prof.sigla=Cadeira.regente (Cadeira))))
```

## 8) What are the names of students who completed the 'IS' course?
```

```

## 9)
```
γ max(Prova.nota) -> max (Prova)
```

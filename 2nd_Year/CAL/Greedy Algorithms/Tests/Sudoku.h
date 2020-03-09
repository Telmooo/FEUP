/*
 * Sudoku.h
 *
 */

#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define IllegalArgumentException -1

class Sudoku {
	/**
	 * numbers[i][j] - numero que ocupa a linha i, coluna j (de 0 a 8)
	 * 0 quer dizer nao preenchido.
	 */
	int numbers[9][9];

	/**
	 * Informacao derivada da anterior, para acelerar processamento (numero de 1 a 9, nao usa 0)
	 */
	int countFilled;
	bool columnHasNumber[9][10];
	bool lineHasNumber[9][10];
	bool block3x3HasNumber[3][3][10];

	void initialize();

public:
	/** Inicia um Sudoku vazio.
	 */
	Sudoku();

	/**
	 * Inicia um Sudoku com um conteudo inicial.
	 * Lanca excepcao IllegalArgumentException se os valores
	 * estiverem fora da gama de 1 a 9 ou se existirem numeros repetidos
	 * por linha, coluna ou bloc 3x3.
	 *
	 * @param nums matriz com os valores iniciais (0 significa por preencher)
	 */
	Sudoku(int nums[9][9]);

	/**
	 * Obtem o conteudo actual (so para leitura!).
	 */
	int** getNumbers();


	/**
	 * Verifica se o Sudoku j� est� completamente resolvido
	 */
	bool isComplete();

	/**
	 * Verifies if cell at row i and column j can have the number n
	 * @param i row number
	 * @param j columun number
	 * @param n number (1-9)
	 * @return true if valid else false
	 */
	bool isValid(int i, int j, int n);


	/**
	 * Resolve o Sudoku.
	 * Retorna indica��o de sucesso ou insucesso (sudoku imposs�vel).
	 */
	bool solve();

	bool solve(int x, int y);

	int solveAll();

	/**
	 * Imprime o Sudoku.
	 */
	void print();
};

#endif /* SUDOKU_H_ */

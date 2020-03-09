/*
 * Sudoku.cpp
 *
 */

#include "Sudoku.h"

/** Inicia um Sudoku vazio.
 */
Sudoku::Sudoku() {
	this->initialize();
}

/**
 * Inicia um Sudoku com um conteudo inicial.
 * Lança excepcao IllegalArgumentException se os valores
 * estiverem fora da gama de 1 a 9 ou se existirem numeros repetidos
 * por linha, coluna ou bloc 3x3.
 *
 * @param nums matriz com os valores iniciais (0 significa por preencher)
 */
Sudoku::Sudoku(int nums[9][9]) {
	this->initialize();

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (nums[i][j] != 0) {
				int n = nums[i][j];
				numbers[i][j] = n;
				lineHasNumber[i][n] = true;
				columnHasNumber[j][n] = true;
				block3x3HasNumber[i / 3][j / 3][n] = true;
				countFilled++;
			}
		}
	}
}

void Sudoku::initialize() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int n = 0; n < 10; n++) {
				numbers[i][j] = 0;
				lineHasNumber[i][n] = false;
				columnHasNumber[j][n] = false;
				block3x3HasNumber[i / 3][j / 3][n] = false;
			}
		}
	}

	this->countFilled = 0;
}

/**
 * Obtem o conteudo actual (so para leitura!).
 */
int** Sudoku::getNumbers() {
	int** ret = new int*[9];

	for (int i = 0; i < 9; i++) {
		ret[i] = new int[9];

		for (int a = 0; a < 9; a++)
			ret[i][a] = numbers[i][a];
	}

	return ret;
}

/**
 * Verifica se o Sudoku ja esta completamente resolvido
 */
bool Sudoku::isComplete() {
	return countFilled == 9 * 9;
}

bool Sudoku::isValid(int i, int j, int n) {
    return !(lineHasNumber[i][n]             ||
             columnHasNumber[j][n]           ||
             block3x3HasNumber[i/3][j/3][n]);
}

/**
 * Resolve o Sudoku.
 * Retorna indicacao de sucesso ou insucesso (sudoku impossivel).
 */
bool Sudoku::solve(int x, int y) {
    if (isComplete()) return true;
    if (y >= 9) return false;

    if (numbers[x][y] != 0) {
        return solve((x + 1) % 9, y + (x / 8));
    }

    for (int n = 1; n <= 9; n++) {
        if (lineHasNumber[x][n]         ||
            columnHasNumber[y][n]       ||
            block3x3HasNumber[x/3][y/3][n]   ) continue;

        this->countFilled++;
        numbers[x][y] = n;
        lineHasNumber[x][n] = true;
        columnHasNumber[y][n] = true;
        block3x3HasNumber[x/3][y/3][n] = true;

        if (solve((x + 1) % 9, y + (x / 8))) {
            return true;
        } else {
            this->countFilled--;
            numbers[x][y] = 0;
            lineHasNumber[x][n] = false;
            columnHasNumber[y][n] = false;
            block3x3HasNumber[x/3][y/3][n] = false;
        }
    }

    return false;
}

bool Sudoku::solve() {
    return solve(0, 0);
}

int Sudoku::solveAll() {

}

/**
 * Imprime o Sudoku.
 */
void Sudoku::print() {
	for (int i = 0; i < 9; i++) {
		for (int a = 0; a < 9; a++)
			cout << this->numbers[i][a] << " ";

		cout << endl;
	}
}

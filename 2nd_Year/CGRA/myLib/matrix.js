
class Matrix {
    constructor(rows, cols) {
        this.rows = rows;
        this.cols = cols;
        this.data = Array(this.rows).fill().map(() => Array(this.cols).fill(0));
    }

    copy() {
        var new_matrix = new Matrix(this.rows, this.cols);
        for (var i = 0; i < this.rows; i++) {
            for (var j = 0; j < this.cols; i++) {
                new_matrix.data[i][j] = this.data[i][j];
            }
        }
        return new_matrix;
    }

    map(func) {
        for (var i = 0; i < this.rows; i++) {
            for (var j = 0; j < this.cols; j++) {
                var value = this.data[i][j];
                this.data[i][j] = func(value, i, j);
            }
        }
        return this;
    }

    static map(matrix, func) {
        return new Matrix(matrix.rows, matrix.cols).map((value, i, j) => func(value, i, j));
    }

    static fromArray(array, rows, cols) {
        if (rows * cols != array.length) {
            console.log("Matrix can't have null values (matrix and array don't match in dimensions)");
        }
        return new Matrix(rows, cols).map((value, i, j) => array[i * rows + j]);
    }

    toArray() {
        var array = [];
        for (var i = 0; i < this.rows; i++) {
            for (var j = 0; j < this.cols; j++) {
                array.push(this.data[i][j]);
            }
        }
        return array;
    }

    add(other) {
        if (other instanceof Matrix) {
            if (this.rows != other.rows || this.cols != other.cols) {
                console.log("Matrices must have same dimensions");
                return;
            }
            return this.map((value, i, j) => value + other.data[i][j]);
        } else {
            return this.map((value, i, j) => value + other);
        }

        return new Matrix(A.rows, B.rows).map((value, i, j) => A.data[i][j] + B.data[i][j]);
    }

    static add(A, B) {
        if (A.rows != B.rows || A.cols != B.cols) {
            console.log("Matrices must have same dimensions");
            return;
        }

        return new Matrix(A.rows, B.rows).map((value, i, j) => A.data[i][j] + B.data[i][j]);
    }

    subtract(other) {
        if (other instanceof Matrix) {
            if (this.rows != other.rows || this.cols != other.cols) {
                console.log("Matrices must have same dimensions");
                return;
            }
            return this.map((value, i, j) => value - other.data[i][j]);
        } else {
            return this.map((value, i, j) => value - other);
        }

        return new Matrix(A.rows, B.rows).map((value, i, j) => A.data[i][j] + B.data[i][j]);
    }

    static subtract(A, B) {
        if (A.rows != B.rows || A.cols != B.cols) {
            console.log("Matrices must have same dimensions");
            return;
        }

        return new Matrix(A.rows, B.rows).map((value, i, j) => A.data[i][j] - B.data[i][j]);
    }

    static multiply(A, B) {
        if (A.cols != B.rows) {
            console.log("Number of columns in matrix A must match the number of rows in matrix B");
            return;
        }
        return new Matrix(A.rows, B.cols).map((value, i, j) => {
            var sum = 0;
            for (var k = 0; k < A.cols; k++) {
                sum += A.data[i][k] * B.data[k][j];
            }
            return sum;
        });
    }

    multiply(factor) {
        return this.map((value, i, j) => value * factor);
    }



    print() {
        console.table(this.data);
        return this;
    }
}

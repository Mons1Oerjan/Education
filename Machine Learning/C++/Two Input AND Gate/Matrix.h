#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

template <class T>
class Matrix {
    private:
        T rows;
        T cols;
        vector<vector<T>> data;
    public:
        // empty constructor
        Matrix() {
        }

        Matrix(int rows, int cols, int numZeros) {
            this->rows = rows;
            this->cols = cols;

            // push values based on the input array:
            for (int i = 0; i < rows; i++) {
                vector<T> row;

                for (int j = 0; j < cols; j++) {
                    row.push_back(0);
                }

                this->data.push_back(row);
            }
        }

        // constructor with specified matrix values
        Matrix(const int rows, const int cols, T values[]) {
            this->rows = rows;
            this->cols = cols;
            int curr = 0;

            // push values based on the input array:
            for (int i = 0; i < rows; i++) {
                vector<T> row;

                for (int j = 0; j < cols; j++) {
                    row.push_back(values[curr]);
                    curr++;
                }

                this->data.push_back(row);
            }
        }

        // constructor with random matrix values
        Matrix(T rows, T cols) {
            srand(time(NULL));

            // fill in random values:
            if (strcmp(typeid(rows).name(), "int") && strcmp(typeid(cols).name(), "int")) {
                this->rows = rows;
                this->cols = cols;

                // generate random numbers [0, 1]
                for (int i = 0; i < rows; i++) {
                    vector<T> row;

                    for (int j = 0; j < cols; j++) {
                        int randomNumber = rand() % 2;
                        row.push_back(randomNumber);
                    }

                    this->data.push_back(row);
                }
            } else if (strcmp(typeid(rows).name(), "float") && strcmp(typeid(cols).name(), "float")) {
                this->rows = rows;
                this->cols = cols;

                // generate random floats between 0 and 1
                for (int i = 0; i < rows; i++) {
                    vector<T> row;

                    for (int j = 0; j < cols; j++) {
                        int randomNumber = rand() / double(RAND_MAX);
                        row.push_back(randomNumber);
                    }

                    this->data.push_back(row);
                }
            } else {
                cout << "Error: Rows and Cols must be int or float types." << endl;
            }
        }

        // destructor
        ~Matrix() {
        }

        T getRows() {
            return this->rows;
        }

        T getCols() {
            return this->cols;
        }

        vector<vector<T>> getData() {
            return this->data;
        }

        void setRows(T rows) {
            this->rows = rows;
        }

        void setCols(T cols) {
            this->cols = cols;
        }

        void setData(vector<vector<T>> data) {
            this->data = data;
        }

        // retrieve a row in the matrix
        T operator [](int row) {
            return this->data[row];
        }

        // constant addition
        Matrix<T>* operator +(T valueToAdd) {
            Matrix<T>* newMatrix = new Matrix();
            vector<vector<T>> sumMatrix;

            // add valueToAdd to each index
            for (int i = 0; i < this->rows; i++) {
                vector<T> row;

                for (int j = 0; j < this->cols; j++) {
                    T value = this->data[i][j] + valueToAdd;
                    row.push_back(value);
                }

                sumMatrix.push_back(row);
            }

            newMatrix->rows = this->rows;
            newMatrix->cols = this->cols;
            newMatrix->data = sumMatrix;

            return newMatrix;
        }

        // matrix addition
        Matrix<T>* operator +(Matrix<T>* valueToAdd) {
            Matrix<T>* newMatrix = new Matrix();
            vector<vector<T>> sumMatrix;

            // perform matrix addition
            for (int i = 0; i < this->rows; i++) {
                vector<T> row;

                for (int j = 0; j < this->cols; j++) {
                    T value = this->data[i][j] + valueToAdd->data[i][j];
                    row.push_back(value);
                }

                sumMatrix.push_back(row);
            }


            newMatrix->rows = this->rows;
            newMatrix->cols = this->cols;
            newMatrix->data = sumMatrix;

            return newMatrix;
        }

        // subtract a constant
        Matrix<T>* operator -(T valToSubtract) {
            Matrix<T>* newMatrix = new Matrix();
            vector<vector<T>> diffMatrix;

            // subtract valToSubtract from each index
            for (int i = 0; i < this->rows; i++) {
                vector<T> row;

                for (int j = 0; j < this->cols; j++) {
                    T value = this->data[i][j] - valToSubtract;
                    row.push_back(value);
                }

                diffMatrix.push_back(row);
            }


            newMatrix->rows = this->rows;
            newMatrix->cols = this->cols;
            newMatrix->data = diffMatrix;

            return newMatrix;
        }

        // matrix subtraction
        Matrix<T>* operator -(Matrix<T>* valueToAdd) {
            Matrix<T>* newMatrix = new Matrix();
            vector<vector<T>> diffMatrix;

            // perform matrix subtraction
            for (int i = 0; i < this->rows; i++) {
                vector<T> row;

                for (int j = 0; j < this->cols; j++) {
                    T value = this->data[i][j] - valueToAdd->data[i][j];
                    row.push_back(value);
                }

                diffMatrix.push_back(row);
            }


            newMatrix->rows = this->rows;
            newMatrix->cols = this->cols;
            newMatrix->data = diffMatrix;

            return newMatrix;
        }

        // constant multiplication
        Matrix<T>* operator *(T valToMultiply) {
            Matrix<T>* newMatrix = new Matrix();
            vector<vector<T>> prodMatrix;

            // multiply valToMultiply to each index
            for (int i = 0; i < this->rows; i++) {
                vector<T> row;

                for (int j = 0; j < this->cols; j++) {
                    T value = this->data[i][j] * valToMultiply;
                    row.push_back(value);
                }

                prodMatrix.push_back(row);
            }

            newMatrix->rows = this->rows;
            newMatrix->cols = this->cols;
            newMatrix->data = prodMatrix;

            return newMatrix;
        }

        // matrix multiplication
        Matrix<T>* operator *(Matrix<T>* valToMultiply) {
            Matrix<T>* newMatrix = new Matrix();

            if (this->cols != valToMultiply->rows) {
                cout << "Error: Can't multiply these two matrices" << endl;
                return newMatrix;
            }

            newMatrix->rows = this->rows;
            newMatrix->cols = valToMultiply->cols;
            vector<vector<T>> prodMatrix;

            // perform matrix multiplication
            for (int i = 0; i < newMatrix->rows; i++) {
                vector<T> resultRow;
                vector<T> thisRow = this->data[i];

                for (int j = 0; j < newMatrix->cols; j++) {
                    vector<T> otherCol;
                    T sum = 0;

                    // populate otherCol
                    for (int k = 0; k < valToMultiply->rows; k++) {
                        otherCol.push_back(valToMultiply->data[k][j]);
                    }

                    // calculate the sum of the products of thisRow and otherCol
                    for (int k = 0; k < valToMultiply->rows; k++) {
                        sum += (thisRow[k] * otherCol[k]);
                    }

                    resultRow.push_back(sum);
                }

                prodMatrix.push_back(resultRow);
            }

            newMatrix->data = prodMatrix;

            return newMatrix;
        }

        // raise each index to the power of num
        Matrix<T>* operator ^(int num) {
            Matrix<T>* newMatrix = new Matrix();
            vector<vector<T>> powMatrix;

            for (int i = 0; i < this->rows; i++) {
                vector<T> row;

                for (int j = 0; j < this->cols; j++) {
                    T value = pow(this->data[i][j], num);
                    row.push_back(value);
                }

                powMatrix.push_back(row);
            }

            newMatrix->rows = this->rows;
            newMatrix->cols = this->cols;
            newMatrix->data = powMatrix;

            return newMatrix;
        }

        // return a new matrix with each index .exp()
        Matrix<T>* expo() {
            Matrix<T>* newMatrix = new Matrix();
            vector<vector<T>> expMatrix;

            for (int i = 0; i < this->rows; i++) {
                vector<T> row;

                for (int j = 0; j < this->cols; j++) {
                    T value = exp(this->data[i][j]);
                    row.push_back(value);
                }

                expMatrix.push_back(row);
            }

            newMatrix->rows = this->rows;
            newMatrix->cols = this->cols;
            newMatrix->data = expMatrix;

            return newMatrix;
        }

        // calculate the sum of all indices
        T sum() {
            T sum = 0;

            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < this->cols; j++) {
                    sum += this->data[i][j];
                }
            }

            return sum;
        }

        // return a new matrix which is the transpose of the original matrix
        Matrix<T>* transpose() {
            Matrix<T>* newMatrix = new Matrix();
            vector<vector<T>> transposeMatrix;

            // perform transpose on a square matrix:
            for (int i = 0; i < this->cols; i++) {
                vector<T> col;

                for (int j = 0; j < this->rows; j++) {
                    T value = this->data[j][i];
                    col.push_back(value);
                }

                transposeMatrix.push_back(col);
            }

            // switch rows and cols:
            newMatrix->rows = this->cols;
            newMatrix->cols = this->rows;

            newMatrix->data = transposeMatrix;

            return newMatrix;
        }

        // print the matrix in numpy format
        void toString() {
            int j_curr = 0;
            cout << "[";

            for (int i = 0; i < this->rows; i++) {
                cout << "[";

                for (int j = 0; j < this->cols-1; j++) {
                    j_curr++;
                    cout << this->data[i][j] << ", ";
                }

                if (i == this->rows - 1) {
                    cout << this->data[i][j_curr] << "]]" << endl;
                } else {
                    cout << this->data[i][j_curr] << "]," << endl;
                }
            }
        }
};

#endif

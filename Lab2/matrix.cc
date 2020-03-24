#include <iostream>
#include <climits>

using namespace std;

#include "matrix.h"
#include "matrixElement.h"

TwoDimensionMatrix::TwoDimensionMatrix() {
    this->matrix = new MatrixElement*[size];
    for(int i = 0; i < size; i++) {
        this->matrix[i] = new MatrixElement[size];
        for(int j = 0; j < size; j++) {
            this->matrix[i][j] = 0;
        }
    }
}
TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix& otherMatrix) {
    this->matrix = new MatrixElement*[size];
    for(int i = 0; i < size; i++) {
        this->matrix[i] = new MatrixElement[size];
        for(int j = 0; j < size; j++) {
            if(i < otherMatrix.size && j < otherMatrix.size) {
                this->matrix[i][j] = otherMatrix.matrix[i][j];
            } else {
                this->matrix[i][j] = 0;
            }
        }
    }
}
TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement matrix[size][size]) {
    this->matrix = new MatrixElement*[this->size];
    for(int i = 0; i < this->size; i++) {
        this->matrix[i] = new MatrixElement[this->size];
        for(int j = 0; j < this->size; j++) {
                this->matrix[i][j] = matrix[i][j];
        }
    }
}

int TwoDimensionMatrix::get(int i, int j) const{
    return this->matrix[i][j];
}

int getMax(const TwoDimensionMatrix& matrix) {
    int max = INT_MIN;
    for(int i = 0; i < matrix.size; i++) {
        for(int j = 0; j < matrix.size; j++) {
            if(matrix.matrix[i][j] > max) {
                max = matrix.matrix[i][j];
            }
        }
    }
    return max;
}
int getLen(int num) {
    int res = 0;
    while(num > 0) {
        num /= 10;
        res++;
    }
    return res;
}
string getSpaces(int num, int maxLen) {
    string res = " ";
    int a = maxLen - getLen(num);
    for(int i = 0; i < a; i++) {
        res += " ";
    }
    return res;
}
ostream& operator << (ostream &out, const TwoDimensionMatrix& matrix) {
    // So that it looks cool and readable for big numbers, we need to start of with finding max value
    int max = getMax(matrix);
    // Then we need to get max possible length of matrix
    int maxLen = getLen(max);

    out<<"Printing values from two-dimension square matrix of size "<<matrix.size<<endl;
    for(int i = 0; i < matrix.size; i++) {
        out<<"[ ";
        for(int j = 0; j < matrix.size; j++) {
            out<<matrix.matrix[i][j]<<getSpaces(matrix.matrix[i][j], maxLen);
        }
        out<<"]"<<endl;
    }
    return out;
}

TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2) {
    TwoDimensionMatrix res = TwoDimensionMatrix(matrix1);
    for(int i = 0; i < matrix2.size; i++) {
        for(int j = 0; j < matrix2.size; j++) {
            if(i < matrix1.size && j < matrix2.size) {
                res.matrix[i][j] += matrix2.matrix[i][j];
            }
        }
    }
    return res;
}

TwoDimensionMatrix& TwoDimensionMatrix::operator*=(MatrixElement number) {
    for(int i = 0; i < this->size; i++) {
        for(int j = 0; j < this->size; j++) {
            this->matrix[i][j] *= number;
        }
    }
    return *this;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix& matrix) const {
    TwoDimensionMatrix res = *this;
    for(int i = 0; i < this->size; i++) {
        for(int j = 0; j < this->size; j++) {
            if(i < matrix.size && j < matrix.size) {
                res.matrix[i][j] = this->matrix[i][j] && matrix.matrix[i][j];
            } else {
                res.matrix[i][j] = 0;
            }
        }
    }
    return res;
}

MatrixElement* TwoDimensionMatrix::operator[](size_t i) {
    return this->matrix[i];
}
const MatrixElement* TwoDimensionMatrix::operator[](size_t i) const {
    return this->matrix[i];
}

TwoDimensionMatrix::operator size_t() const{
    return static_cast<size_t>(this->size);
}

TwoDimensionMatrix::~TwoDimensionMatrix() {
    for(int i = 0; i < this->size; i++) {
        delete[] this->matrix[i];
    }
    delete[] this->matrix;
}
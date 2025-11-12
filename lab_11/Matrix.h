#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

class Matrix {
private:
    int size;
    vector<vector<int>> data;

public:
    // Constructors
    Matrix() : size(0) {}
    Matrix(int n);

    // File Reading
    void readFromFile(const string &filename, Matrix &m1, Matrix &m2);

    // Display
    void display() const;

    // Operator Overloads
    Matrix operator+(const Matrix &other) const;
    Matrix operator*(const Matrix &other) const;

    // Diagonal Sum
    void diagonalSum() const;

    // Row/Column Swap
    Matrix swapRows(int r1 = 0, int r2 = 1) const;
    Matrix swapCols(int c1 = 0, int c2 = 1) const;

    // Update
    Matrix updateElement(int row = 0, int col = 0, int val = 100) const;

    // Getters
    int getSize() const { return size; }
    int getElement(int row, int col) const { return data[row][col]; }
};

#endif
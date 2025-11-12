#include "Matrix.h"

Matrix::Matrix(int n) {
    size = n;
    data.resize(n, vector<int>(n, 0));
}

// Reads from file and fills two matrices
void Matrix::readFromFile(const string &filename, Matrix &m1, Matrix &m2) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Error opening file.\n";
        return;
    }

    int n;
    fin >> n;

    m1 = Matrix(n);
    m2 = Matrix(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> m1.data[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> m2.data[i][j];

    fin.close();
}

// Display matrix
void Matrix::display() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << setw(4) << data[i][j];
        cout << endl;
    }
}

// Add two matrices
Matrix Matrix::operator+(const Matrix &other) const {
    Matrix result(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

// Multiply two matrices
Matrix Matrix::operator*(const Matrix &other) const {
    Matrix result(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int sum = 0;
            for (int k = 0; k < size; k++)
                sum += data[i][k] * other.data[k][j];
            result.data[i][j] = sum;
        }
    }
    return result;
}

// Sum of diagonals
void Matrix::diagonalSum() const {
    int mainDiag = 0, secDiag = 0;
    for (int i = 0; i < size; i++) {
        mainDiag += data[i][i];
        secDiag += data[i][size - i - 1];
    }
    cout << "Main diagonal sum: " << mainDiag << endl;
    cout << "Secondary diagonal sum: " << secDiag << endl;
}

// Swap rows (pass-by-value)
Matrix Matrix::swapRows(int r1, int r2) const {
    Matrix temp = *this;
    if (r1 >= 0 && r2 >= 0 && r1 < size && r2 < size)
        swap(temp.data[r1], temp.data[r2]);
    else
        cout << "Invalid row indices.\n";
    return temp;
}

// Swap columns
Matrix Matrix::swapCols(int c1, int c2) const {
    Matrix temp = *this;
    if (c1 >= 0 && c2 >= 0 && c1 < size && c2 < size) {
        for (int i = 0; i < size; i++)
            swap(temp.data[i][c1], temp.data[i][c2]);
    } else
        cout << "Invalid column indices.\n";
    return temp;
}

// Update element
Matrix Matrix::updateElement(int row, int col, int val) const {
    Matrix temp = *this;
    if (row >= 0 && col >= 0 && row < size && col < size)
        temp.data[row][col] = val;
    else
        cout << "Invalid indices.\n";
    return temp;
}
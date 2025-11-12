#include "Matrix.h"

int main() {
    Matrix A, B;

    string filename = "matrix_input.txt";
    A.readFromFile(filename, A, B);

    cout << "Matrix A:\n";
    A.display();
    cout << "\nMatrix B:\n";
    B.display();

    cout << "\nA + B:\n";
    (A + B).display();

    cout << "\nA * B:\n";
    (A * B).display();

    cout << "\nDiagonal sums for A:\n";
    A.diagonalSum();

    cout << "\nAfter swapping rows (0,1) in A:\n";
    A.swapRows().display();

    cout << "\nAfter swapping columns (0,1) in A:\n";
    A.swapCols().display();

    cout << "\nAfter updating A[0][0] = 100:\n";
    A.updateElement().display();

    return 0;
}
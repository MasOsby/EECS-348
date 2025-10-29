// EECS 468 lab 9 Matrix Operations
// this program performs various operations on NxN matrices read from a file
// inputs: files containing two NxN matrices
// outputs: addition, multiplication, diagonal sums, row/column swaps, element updates
// Collaborattors: ChatGPT
// Mo Osby - 2025
// Date: 28th of October 2025
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

// Function to read two matrices from file
bool loadMatricesFromFile(string filename, int &N, vector<vector<int>> &A, vector<vector<int>> &B) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file.\n";
        return false;
    }

    file >> N; // read matrix size
    if (N <= 0) { // if N is invalid
        cerr << "Error: Invalid matrix size.\n"; // error handling
        return false;
    }

    A.assign(N, vector<int>(N)); // initialize matrices
    B.assign(N, vector<int>(N));

    // Read first matrix
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            file >> A[i][j];

    // Read second matrix
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            file >> B[i][j];

    file.close();
    return true;
}

// Helper to print a matrix
void printMatrix(const vector<vector<int>> &M, const string &name) {
    cout << "\n" << name << ":\n";
    for (const auto &row : M) {
        for (int val : row)
            cout << setw(5) << val;
        cout << '\n';
    }
}
// vector is pretty much a list so, using vector<vector<int>> we make a 2d list which can store our matrix
vector<vector<int>> addMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B) { 
    int N = A.size();
    vector<vector<int>> result(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i][j] = A[i][j] + B[i][j];

    return result;
}

vector<vector<int>> multiplyMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    // looping through rows of A to multiply with columns of B and make a new matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}
// Diagonal sum function 
void sumDiagonals(const vector<vector<int>> &M) {
    int n = M.size();
    int mainSum = 0, secSum = 0;

    for (int i = 0; i < n; ++i) {
        mainSum += M[i][i];               // main diagonal
        secSum += M[i][n - i - 1];        // secondary diagonal
    }

    cout << "Main diagonal sum: " << mainSum << endl; // cout is used to print to console
    cout << "Secondary diagonal sum: " << secSum << endl;
}
// Row swapping function
void swapRows(vector<vector<int>> &M, int row1, int row2) {
    int n = M.size();

    if (row1 < 0 || row2 < 0 || row1 >= n || row2 >= n) {
        cout << "Invalid row indices!" << endl;
        return;
    }

    swap(M[row1], M[row2]);

    cout << "After swapping rows " << row1 << " and " << row2 << ":" << endl;
    for (const auto &row : M) {
        for (int val : row)
            cout << setw(5) << val;
        cout << endl;
    }
}
// swap column function
void swapColumns(vector<vector<int>> &M, int col1, int col2) {
    int n = M.size();

    if (col1 < 0 || col2 < 0 || col1 >= n || col2 >= n) {
        cout << "Invalid column indices!" << endl;
        return;
    }

    for (int i = 0; i < n; ++i)
        swap(M[i][col1], M[i][col2]);

    cout << "After swapping columns " << col1 << " and " << col2 << ":" << endl;
    for (const auto &row : M) {
        for (int val : row)
            cout << setw(5) << val;
        cout << endl;
    }
}
// updating matrix values function
void updateMatrixValue(vector<vector<int>> &M, int row, int col, int newValue) {
    int n = M.size();

    if (row < 0 || col < 0 || row >= n || col >= n) {
        cout << "Invalid indices!" << endl;
        return;
    }

    M[row][col] = newValue;

    cout << "After updating element (" << row << ", " << col << ") to " << newValue << ":" << endl;
    for (const auto &r : M) {
        for (int val : r)
            cout << setw(5) << val;
        cout << endl;
    }
}
// Main function with menu options to choose from like: addition, multiplication, diagonal sums, row/column swaps, element updates
int main() {
    string filename;
    int N;
    vector<vector<int>> A, B;

    cout << "Enter filename: ";
    cin >> filename;

    if (!loadMatricesFromFile(filename, N, A, B)) {
        return 1; // quit if file failed
    }

    printMatrix(A, "Matrix A");
    printMatrix(B, "Matrix B");

    int choice;
    do {
        cout << "\n===== Matrix Operations Menu =====\n";
        cout << "1. Add Matrices\n";
        cout << "2. Multiply Matrices\n";
        cout << "3. Sum of Diagonals (Matrix A)\n";
        cout << "4. Swap Rows (Matrix A)\n";
        cout << "5. Swap Columns (Matrix A)\n";
        cout << "6. Update Element (Matrix A)\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                auto sum = addMatrices(A, B);
                printMatrix(sum, "A + B");
                break;
            }
            case 2: {
                auto product = multiplyMatrices(A, B);
                printMatrix(product, "A * B");
                break;
            }
            case 3: {
                sumDiagonals(A);
                break;
            }
            case 4: {
                int r1, r2;
                cout << "Enter two row indices to swap: ";
                cin >> r1 >> r2;
                swapRows(A, r1, r2);
                break;
            }
            case 5: {
                int c1, c2;
                cout << "Enter two column indices to swap: ";
                cin >> c1 >> c2;
                swapColumns(A, c1, c2);
                break;
            }
            case 6: {
                int row, col, val;
                cout << "Enter row, column, and new value: ";
                cin >> row >> col >> val;
                updateMatrixValue(A, row, col, val);
                break;
            }
            case 0:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
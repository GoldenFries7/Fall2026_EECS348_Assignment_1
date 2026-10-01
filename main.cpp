#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

// Helper function to print matrices with aligned columns
void printMatrix(const vector<vector<int>>& matrix) {
    int N = matrix.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << "\n";
    }
}

// Task 1: Load N and two NxN matrices from a file
bool loadMatrices(const string& filename, int& N, vector<vector<int>>& A, vector<vector<int>>& B) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Cannot open file.\n";
        return false;
    }
    if (!(file >> N) || N <= 0) {
        cerr << "Error: Invalid matrix size. N must be a positive integer.\n";
        return false;
    }

    A.assign(N, vector<int>(N));
    B.assign(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            file >> A[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            file >> B[i][j];

    return true;
}

// Task 2: Add two matrices
void addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int N = A.size();
    vector<vector<int>> C(N, vector<int>(N));
    cout << "\nA + B:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    printMatrix(C);
}

// Task 3: Multiply two matrices
void multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int N = A.size();
    vector<vector<int>> C(N, vector<int>(N, 0));
    cout << "\nA * B:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printMatrix(C);
}

// Task 4: Main and secondary diagonal sums
void diagonalSums(const vector<vector<int>>& A) {
    int N = A.size();
    int main_sum = 0;
    int sec_sum = 0;
    for (int i = 0; i < N; ++i) {
        main_sum += A[i][i];
        sec_sum += A[i][N - 1 - i];
    }
    cout << "\nDiagonal sums for Matrix A:\n";
    cout << "Main diagonal sum: " << main_sum << "\n";
    cout << "Secondary diagonal sum: " << sec_sum << "\n";
}

// Task 5: Swap two rows
void swapRows(vector<vector<int>> A, int row1, int row2) {
    int N = A.size();
    cout << "\nProblem 5 - Rows " << row1 << " and " << row2 << " swapped:\n";
    if (row1 >= 0 && row1 < N && row2 >= 0 && row2 < N) {
        swap(A[row1], A[row2]);
        printMatrix(A);
    } else {
        cout << "Invalid row indices.\n";
    }
}

// Task 6: Swap two columns
void swapCols(vector<vector<int>> A, int col1, int col2) {
    int N = A.size();
    cout << "\nProblem 6 - Columns " << col1 << " and " << col2 << " swapped:\n";
    if (col1 >= 0 && col1 < N && col2 >= 0 && col2 < N) {
        for (int i = 0; i < N; ++i) {
            swap(A[i][col1], A[i][col2]);
        }
        printMatrix(A);
    } else {
        cout << "Invalid column indices.\n";
    }
}

// Task 7: Update one element
void updateElement(vector<vector<int>> A, int row, int col, int value) {
    int N = A.size();
    cout << "\nProblem 7 - Updated matrix:\n";
    if (row >= 0 && row < N && col >= 0 && col < N) {
        A[row][col] = value;
        printMatrix(A);
    } else {
        cout << "Invalid indices.\n";
    }
}

int main() {
    string filename;
    cout << "Enter input filename: \n";
    cin >> filename;
    
    int N;
    vector<vector<int>> A, B;
    
    if (!loadMatrices(filename, N, A, B)) {
        return 1;
    }

    cout << "Matrix A:\n";
    printMatrix(A);
    cout << "\nMatrix B:\n";
    printMatrix(B);

    addMatrices(A, B);
    multiplyMatrices(A, B);
    diagonalSums(A);
    
    // Testing swaps and updates based on the sample output requirements
    swapRows(A, 0, 2);
    swapCols(A, 0, 2);
    updateElement(A, 1, 2, 99);

    return 0;
}
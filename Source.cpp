#include <Windows.h> 
#include <iostream> 
#include <time.h> 
using namespace std;


void outputMatrix(int** matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int getCount(int** matrix, int row, int col, int num) {
    int res = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (num == matrix[i][j]) {
                res++;
            }
        }
    }
    return res;
}


void maxNumIteration(int** matrix, int row, int col, int& max) {
    bool finded = false;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (getCount(matrix, row, col, matrix[i][j]) >= 2) {
                if (!finded) {
                    max = matrix[i][j];
                    finded = true;
                }
                else if (max < matrix[i][j]) {
                    max = matrix[i][j];
                }

            }
        }
    }
}

void maxNumRecursive(int** matrix, int row, int col, int& max, int i = 0, int j = 0, bool finded = false) {
    if (j == col) {
        i++;
        j = i;
    }
    if (i == row) {

        return;
    }

    if (getCount(matrix, row, col, matrix[i][j]) >= 2)
        if (!finded) {
            max = matrix[i][j];
            finded = true;
        }
        else if (max < matrix[i][j]) {
            max = matrix[i][j];
        }
    j++;
    maxNumRecursive(matrix, row, col, max, i, j, finded);

}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int** matrix;
    int row, col;
    cout << "Введіть розмір квадратної матриці: "; cin >> row >> col;
    matrix = new int* [row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
        for (int j = 0; j < col; j++) {
            matrix[i][j] = rand() % 11;
        }
    }
    outputMatrix(matrix, row, col);
    int maxIter, maxRecursive;
    maxNumIteration(matrix, row, col, maxIter);
    cout << "Максимальне число, яке зустрічається ітераційний спосіб >= 2: " << maxIter << endl;

    maxNumIteration(matrix, row, col, maxRecursive);
    cout << "Максимальне число, яке зустрічається рекурсивний спосіб >= 2: " << maxRecursive << endl;
    for (int i = 0; i < row; i++)
        delete[] matrix[i];
    delete[] matrix;
    return 0;

}
#include <iostream>
#include <vector>
#include <iomanip> // для setw

using namespace std;

int main() {
    int N;
    cout << "Введите размерность матрицы (N): ";
    cin >> N;

    // Инициализация матрицы
    vector<vector<int>> matrix(N, vector<int>(N));

    // Заполнение матрицы
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                matrix[i][j] = 0;
            } else if (j == 0) {
                matrix[i][j] = (i == 0) ? 0 : 100;
            } else if (j == N - 1) {
                matrix[i][j] = (i == N - 1) ? 0 : 100;
            } else if (i < j) {
                matrix[i][j] = 100 + (j - i);
            } else {
                matrix[i][j] = 100 + (i - j);
            }
        }
    }

    // Вывод матрицы
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] == 0) {
                cout << "000 ";
            } else {
                cout << setw(3) << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
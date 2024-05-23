#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPSILON = 0.001;

// Вывод системы уравнений
void sysout(const vector<vector<double>>& a, const vector<double>& y, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "*x" << j;
            if (j < n - 1)
                cout << " + ";
        }
        cout << " = " << y[i] << endl;
    }
}

vector<double> gauss(vector<vector<double>> a, vector<double> y, int n) {
    vector<double> x(n);
    for (int k = 0; k < n; k++) {
        int index = k;
        double max = fabs(a[k][k]);
        for (int i = k + 1; i < n; i++) {
            if (fabs(a[i][k]) > max) {
                max = fabs(a[i][k]);
                index = i;
            }
        }
        if (max < EPSILON) {
            cout << "Решение получить невозможно из-за нулевого столбца " << index << " матрицы A" << endl;
            return {};
        }
        for (int j = 0; j < n; j++) {
            swap(a[k][j], a[index][j]);
        }
        swap(y[k], y[index]);
        for (int i = k; i < n; i++) {
            double temp = a[i][k];
            if (fabs(temp) < EPSILON) continue;
            for (int j = k; j < n; j++) {
                a[i][j] /= temp;
            }
            y[i] /= temp;
            if (i == k) continue;
            for (int j = 0; j < n; j++) {
                a[i][j] -= a[k][j];
            }
            y[i] -= y[k];
        }
    }
    for (int k = n - 1; k >= 0; k--) {
        x[k] = y[k];
        for (int i = 0; i < k; i++) {
            y[i] -= a[i][k] * x[k];
        }
    }
    return x;
}

int main() {
    int n = 4;
    vector<vector<double>> a = {
        {-0.77, -0.04, 0.21, -18},
        {0.25, -1.23, 0.16, -0.09},
        {-0.21, 0.16, 0.8, -0.13},
        {0.15, -1.31, 0.06, 1.12}
    };
    
    vector<double> y = {-1.24, 1.12, 2.56, -0.77};

    cout << "Система уравнений:" << endl;
    sysout(a, y, n);

    vector<double> gaussSolution = gauss(a, y, n);
    cout << "Решение методом Гаусса:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << gaussSolution[i] << endl;
    }

    return 0;
}
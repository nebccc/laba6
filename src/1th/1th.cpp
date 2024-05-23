#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int rn();
void init(vector<vector<int>>& matrix, int M, int N);
void print_matrix(const vector<vector<int>>& matrix);
void find_most_common(const vector<vector<int>>& matrix);

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> matrix(M, vector<int>(N));

    init(matrix, M, N);
    print_matrix(matrix);
    find_most_common(matrix);

    return 0;
}

int rn() {
    random_device rd;
    uniform_int_distribution<int> dist(0, 50);
    return dist(rd);
}

void init(vector<vector<int>>& matrix, int M, int N) {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            matrix[i][j] = rn();
        }
    }
}

void print_matrix(const vector<vector<int>>& matrix) {
    for(const auto& row : matrix) {
        for(const int num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }

    cout << "\n";
}

void find_most_common(const vector<vector<int>>& matrix) {
    vector<int> nums;

    for(const auto& row : matrix) {
        for(const int num : row) {
            nums.push_back(num);
        }
    }

    sort(nums.begin(), nums.end());

    int k = 1;
    int max_k = 0;
    int most_common = 0;

    for(size_t i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i - 1]) {
            k++;
        } else {
            if(k > max_k) {
                max_k = k;
                most_common = nums[i - 1];
            }
            k = 1;
        }
    }

    if(k > max_k) {
        most_common = nums[nums.size() - 1];
    }

    cout << most_common << "\n";
}
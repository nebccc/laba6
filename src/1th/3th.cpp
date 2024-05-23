#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <algorithm>

using namespace std;

int rn();
void init(vector<vector<int>>& matrix, int, int);
void print_matrix(const vector<vector<int>>&);
void find_max_num(vector<vector<int>>& matrix, int, int);

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> matrix(M, vector<int>(N));

    init(matrix, M, N);
    print_matrix(matrix);
    find_max_num(matrix, M, N);

    return 0;
}

int rn() {
    random_device rd;
    uniform_int_distribution<int> dist(0, 100);
    return dist(rd);
}

void init(vector<vector<int>>& matrix, int M, int N) {
    set<int> nums;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            int num;
            do {
                num = rn();
            } while(nums.find(num) != nums.end());
            nums.insert(num);
            matrix[i][j] = num;
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

void find_max_num(vector<vector<int>>& matrix, int M, int N) {
    vector<int> res;
    bool flag;

    for(int i = 0; i < M; i++){
        flag = true;

        auto min_in_row = min_element(matrix[i].begin(), matrix[i].end());
        int min_in_row_index = distance(matrix[i].begin(), min_in_row);

        int min_num = *min_element(matrix[i].begin(), matrix[i].end());


        for(int j = 0; j < M; j++) {
            if(min_num < matrix[j][min_in_row_index]){
                flag = false;
                
                break;
            }
        }

        if(flag) res.push_back(min_num);
    }

    cout << "\n";

    if (res.empty()) {
        cout << "No such elements found.\n";
    } else {
        cout << "Elements that are minimum in their row and maximum in their column are: ";
        for(int num : res) {
            cout << num << " ";
        }
        cout << "\n";
    }
}
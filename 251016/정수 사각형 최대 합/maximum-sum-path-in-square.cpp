#include <iostream>

using namespace std;

int n;
int grid[100][100];

int main() {
    cin >> n;

    long long max_value = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    long long max_arr[100][100];

    max_arr[0][0] = grid[0][0];

    for(int i=1; i<n; i++){
        max_arr[0][i] = grid[0][i] + max_arr[0][i-1];
    }

    for(int i=1; i<n; i++){
        max_arr[i][0] = grid[i][0] + max_arr[i-1][0];
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){

            max_arr[i][j] = max(max_arr[i-1][j], max_arr[i][j-1]) + grid[i][j];

            max_value = max(max_arr[i][j], max_value);
        }
    }

    cout << max_arr[n-1][n-1] << "\n";


    return 0;
}

#include <iostream>

using namespace std;

int n;
int grid[100][100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int min_arr[100][100];

    int max_arr[100][100];

    min_arr[0][0] = grid[0][0];

    for(int i=1; i<n; i++){

        min_arr[0][i] = min(grid[0][i], min_arr[0][i-1]);
    }

    for(int i=1; i<n; i++){

        min_arr[i][0] = min(grid[i][0], min_arr[i-1][0]);
    }


    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){

            int v1 = min(min_arr[i-1][j], grid[i][j]);
            int v2 = min(min_arr[i][j-1], grid[i][j]);

            min_arr[i][j] = max(v1, v2);
        }
    }

    cout << min_arr[n-1][n-1];

    return 0;
}
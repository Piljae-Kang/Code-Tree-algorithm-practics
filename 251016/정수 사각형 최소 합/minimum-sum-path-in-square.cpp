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

    long long min_arr[100][100];

    min_arr[0][n-1] = grid[0][n-1];

    for(int i=n-1; i>=0; i--){

        min_arr[0][i] = min_arr[0][i+1] + grid[0][i];

    }

    for(int i=1; i<n; i++){

        min_arr[i][n-1] = min_arr[i-1][n-1] + grid[i][n-1];
    }

    for(int i=1; i<n; i++){
        for(int j=n-2; j>=0; j--){
            
            min_arr[i][j] = min(min_arr[i-1][j], min_arr[i][j+1]) + grid[i][j];
        }
    }

    cout << min_arr[n-1][0];

    return 0;
}

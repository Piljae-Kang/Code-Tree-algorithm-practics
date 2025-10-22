#include <iostream>
#include <cstring>

using namespace std;

int n;
int grid[500][500];
int arr[500][500];

int move_func[4][2] = {{-1, 0}, {1,0}, {0, 1}, {0, -1}};

int max_cnt = 0;


int search(int u, int v){

    int max_value = 0;

    for(int i=0; i<4; i++){

        int n_u = u + move_func[i][0];
        int n_v = v + move_func[i][1];

        if(n_u<0||n_v<0||n_u>=n||n_v>=n) continue;

        if(grid[u][v] >= grid[n_u][n_v]) continue;

        // cout << "u, v : " << u << ", " << v << "\n"; 
        // cout << "n_u, n_v : " << n_u << ", " << n_v << "\n"; 

        if(arr[n_u][n_v] == -1){
            int value = search(n_u, n_v);

            max_value = max(max_value, value);
        } 
        else{
            max_value = max(max_value, arr[n_u][n_v]);
        }
    }

    arr[u][v] = max_value + 1;

    max_cnt = max(max_cnt, arr[u][v]);
    
    return arr[u][v];

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    memset(arr, -1, sizeof(arr));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(arr[i][j] == -1){

                arr[i][j] = search(i, j);
            } 

        }
    }

    // Please write your code here.

    cout << max_cnt << "\n";

    return 0;
}
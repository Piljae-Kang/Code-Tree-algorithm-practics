#include <iostream>

using namespace std;

int n, m;
int grid[101][101];

bool route = false;

int move_func[2][2] = {{1, 0}, {0, 1}};

int visited[101][101] = {0};

void dfs(int u, int v){

    if(u == n-1 && v == m-1){
        
        route = true;
        return;
    }

    visited[u][v] = 1;


    for(int i=0; i<2; i++){

        int n_u = u + move_func[i][0];
        int n_v = v + move_func[i][1];

        if(n_u < 0 || n_v < 0 || n_u >= n || n_v >= m) continue;

        if(grid[n_u][n_v] == 0) continue;

        if(visited[n_u][n_v] == 1) continue;

        dfs(n_u, n_v);

    }

    visited[u][v] = 0;

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

   dfs(0, 0);

   if(route == true) cout << "1\n";
   else cout << "0\n";

    return 0;
}

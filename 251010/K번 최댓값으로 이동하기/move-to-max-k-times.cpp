#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int n, k;
int grid[100][100];
int visited_b[100][100] = {0};
int visited[100][100] = {0};
int r, c;

int max_value = 0;
int value;

int move_func[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(int u, int v){

    queue<pair<int, int>> q;
    q.push(make_pair(u, v));

    while(!q.empty()){

        int c_u = q.front().first;
        int c_v = q.front().second;

        q.pop();

        for(int i=0; i<4; i++){

            int n_u = c_u + move_func[i][0];
            int n_v = c_v + move_func[i][1];

            if(n_u <0 || n_v <0 || n_u >=n || n_v >= n) continue;

            if(grid[n_u][n_v] > value) continue;

            if(visited[n_u][n_v] == 1) continue;

            q.push(make_pair(n_u, n_v));

            visited[n_u][n_v] = 1;


            if(grid[n_u][n_v] == max_value){

                if(n_u < r){
                    r = n_u; c = n_v;
                }

                if(n_u == u && n_v < c){
                    r = n_u; c = n_v;
                }
            }

            else if(grid[n_u][n_v] > max_value && grid[n_u][n_v] < value){

                max_value = grid[n_u][n_v];
                r = n_u; c = n_v;
            }

        }

    }

}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    r--; c--;

    for(int i=0; i<k; i++){

        memset(visited, 0, sizeof(visited));

        max_value = -1;
        value = grid[r][c];
        visited[r][c] = 1;
        bfs(r, c);

        // cout << "max_value : " << max_value << "\n";

        if (max_value == -1) break;

        // cout << r + 1 << " " << c + 1 << "\n";

    }

    cout << r + 1 << " " << c + 1 << "\n";
    
    // Please write your code here.

    return 0;
}

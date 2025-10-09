#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];

int visited_cnt = 0;

int visited[100][100] = {0};

int visited_g[100][100] = {0};

int move_func[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void bfs(int u, int v){

    queue<pair<int, int>> q;

    q.push(make_pair(u, v));
    visited[u][v] = 1;



    if(visited_g[u][v] == 0){
        visited_cnt++;
        visited_g[u][v] = 1;
    } 


    while(!q.empty()){

        int c_u = q.front().first;
        int c_v = q.front().second;

        q.pop();

        for(int i=0; i<4; i++){

            int n_u = c_u + move_func[i][0];
            int n_v = c_v + move_func[i][1];

            if(n_u < 0 || n_v < 0 || n_u >= n || n_v >= n) continue;
            if(visited[n_u][n_v] == 1 || grid[n_u][n_v] == 1) continue;

            if(visited_g[n_u][n_v] == 0){

                visited_cnt++;
                visited_g[n_u][n_v] = 1;

            } 

            q.push(make_pair(n_u, n_v));

            visited[n_u][n_v] = 1;

        }


    }

}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];


    for(int i=0; i<k; i++){

        int u, v;

		cin >> u >> v;

        memset(visited, 0, sizeof(visited));

        bfs(u-1, v-1);
        
    }

    cout << visited_cnt << "\n";

    return 0;
}

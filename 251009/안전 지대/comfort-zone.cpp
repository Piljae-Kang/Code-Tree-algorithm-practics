#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int grid[50][50];

int visited[50][50] = {0};

int k;

int move_func[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void dfs(int u, int v){

    visited[u][v] = 1;

    for(int i=0; i<4; i++){

        int n_u = u + move_func[i][0];
        int n_v = v + move_func[i][1];

        if(n_u<0 || n_v<0 || n_u >= N || n_v >= M) continue;

        if(visited[n_u][n_v] == 1) continue;

        if(grid[n_u][n_v] <= k) continue;

        dfs(n_u, n_v);

    }


}

int main() {
    cin >> N >> M;

    int max_k = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];

            max_k = max(grid[i][j], max_k);
        }
    }

    // Please write your code here.

    int max_idx = max_k;
    int max_value = 0;

    for(int i=1; i<=max_k; i++){

        memset(visited, 0, sizeof(visited));

        k = i;

        int cnt = 0;

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){

                if(grid[i][j] > k && visited[i][j] == 0){

                    dfs(i, j);
                    cnt++;
                }

            }
        }

		// cout << "i : " << cnt << "\n";

        if(cnt >= max_value){

			if(cnt == max_value){
				max_idx = min(max_idx, i);
			}
			else{
				max_idx = i;
			}

            max_value = cnt;

           
        }

    }

    cout << max_idx << " " << max_value << "\n";

    return 0;
}

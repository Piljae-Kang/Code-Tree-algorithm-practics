#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int a[100][100];

int dist[100][100] = {0};

int move_func[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};



void bfs(int u, int v){

    queue<pair<int, int>> q;

    q.push(make_pair(u, v));

    while(!q.empty()){

        pair<int, int> cur_pos = q.front();

        int cur_u = cur_pos.first;
        int cur_v = cur_pos.second;

        q.pop();

        for(int i=0; i<4; i++){

            int n_u = cur_u + move_func[i][0];
            int n_v = cur_v + move_func[i][1];

            if(n_u < 0 || n_v < 0 || n_u >= n || n_v >= m) continue;

            if(dist[n_u][n_v] != 0) continue;

            if(a[n_u][n_v] == 0) continue;

            dist[n_u][n_v] = dist[cur_u][cur_v] + 1;


            q.push(make_pair(n_u, n_v));

        }



    }

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    bfs(0, 0);

    if(dist[n-1][m-1] != 0){
        cout << "1\n";
    }
    else{
        cout << "0\n";
    }

    return 0;
}

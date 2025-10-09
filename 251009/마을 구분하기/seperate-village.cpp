#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grid[25][25];

int visited[25][25] = {0};

int people_cnt = 0;

int move_func[4][2] = {{-1, 0}, {1, 0}, { 0, -1}, {0, 1}};

void dfs(int u, int v){

    visited[u][v] = 1;

    for(int i=0; i<4; i++){

        int n_u = u + move_func[i][0];
        int n_v = v + move_func[i][1];

        if(n_u < 0 || n_v <0 || n_u >= n || n_v >= n) continue;

        if(visited[n_u][n_v] == 1 || grid[n_u][n_v] == 0) continue;

        people_cnt++;
        dfs(n_u, n_v);
    }


}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> v;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            if(grid[i][j] == 1 && visited[i][j] == 0){

                people_cnt = 1;

                dfs(i, j);

                v.push_back(people_cnt);
            }


        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << "\n";
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }

    return 0;
}

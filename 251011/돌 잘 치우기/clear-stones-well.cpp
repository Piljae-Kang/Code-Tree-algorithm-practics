#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int n, k, m;
int grid[100][100];
int r[10000], c[10000];

int visited[100][100] = {0};

int move_func[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int visit_cnt = 0;

int stone_num;

int max_value = 0;

int cb_cnt = 0;

void print_mat(){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            cout << grid[i][j] << " ";

        }

        cout << "\n";
    }
}


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

            if(n_u<0|| n_v<0 || n_u >= n || n_v >= n) continue;

            if(visited[n_u][n_v] == 1 || grid[n_u][n_v] == 1) continue;

            // cout << " n_u : " << n_u << ", n_v : " << n_v << "\n";

            visited[n_u][n_v] = 1;
            visit_cnt++;
            q.push(make_pair(n_u, n_v));
        }


    }


}

int search_k(){

    visit_cnt = 0;
    memset(visited, 0, sizeof(visited));

    for(int i=0; i<k; i++){

        int pos_r = r[i]; int pos_c = c[i];

        if(visited[pos_r][pos_c] == 1) continue;

        visited[pos_r][pos_c] = 1;
        visit_cnt++;

        bfs(pos_r, pos_c);

    }

    // cout << "visit_cnt : " << visit_cnt << "\n";

    return visit_cnt;

}


void combinatioin(vector<pair<int, int>>& stones, vector<int>& stone_idx, int idx, int depth){

    if(depth == m){

        // for(int i=0; i<stone_idx.size(); i++){
        //     cout << stone_idx[i] << " ";
        // }
        // cout << "\n";

        // print_mat();

        max_value = max(max_value, search_k());

        cb_cnt++;
        return;
    }

    for(int i=idx + 1; i<stone_num; i++){

        stone_idx.push_back(i);
        int u = stones[i].first;
        int v = stones[i].second;

        grid[u][v] = 0;

        combinatioin(stones, stone_idx, i, depth + 1);
        stone_idx.pop_back();

        grid[u][v] = 1;


    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> m;

    vector<pair<int, int>> stones;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){

            int value;

            cin >> value;

            grid[i][j] = value;


            if(value == 1){
                stones.push_back(make_pair(i, j));
            }
        }

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }

    // Please write your code here.

    stone_num = stones.size();

    vector<int> stone_idx;

    combinatioin(stones, stone_idx, -1, 0);

    cout << max_value << "\n";
    
    // cout << "cb_cnt : " << cb_cnt << "\n";

    return 0;
}

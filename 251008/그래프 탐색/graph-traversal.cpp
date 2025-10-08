#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;

int visited[10000] = {0};

int cnt = 0;

void dfs(int vertex){

	visited[vertex] = 1;

    for(int i=0; i<graph[vertex].size(); i++){

		int next = graph[vertex][i];

		if(visited[next] == 1) continue;

		cnt++;

		dfs(next);

	}


}

int main() {

	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n, m;

    cin >> n >> m;

	graph.assign(n+1, vector<int>());

    for (int i = 0; i < m; i++) {
		
		int v1, v2;
		cin >> v1 >> v2;

		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
    }



    dfs(1);

	cout << cnt << "\n";

    return 0;
}

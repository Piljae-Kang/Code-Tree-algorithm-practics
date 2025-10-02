#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

int n;
int x1[16], x2[16];

int visited[16] = {0};

int max_value = 0;

bool check_overlap(vector<int>& arr, int idx){

    for(int i=x1[idx]; i<=x2[idx]; i++){

        if(arr[i] == 1){
            return true;
        }
        else{
            arr[i] = 1;
        }
    }

    return false;

}


void find_max_none_overlap(vector<int>& arr, int depth, int idx){

    if(depth > 0){

        if(check_overlap(arr, idx)) return;

        max_value = max(max_value, depth);

        if(depth == n){

            return;
        }

    }

    for(int i=1; i<=n; i++){

        if(visited[i] == 1) continue;

        vector<int> tmp = arr;

        visited[i] = 1;
        find_max_none_overlap(arr, depth+1, i);
        
        arr = move(tmp);

        visited[i] = 0;
    }




}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x1[i] >> x2[i];
    }

    // Please write your code here.

    vector<int> arr(1001, 0);

    find_max_none_overlap(arr, 0, 0);
    
    cout << max_value << "\n";

    return 0;
}

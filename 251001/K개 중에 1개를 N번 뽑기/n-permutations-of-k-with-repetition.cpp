#include <iostream>
#include <vector>

using namespace std;

int K, N;

void pick(vector<int>& arr, int depth){

    if(depth == N){

        for(int cp : arr){

            cout << cp << " ";
            
        }
        cout << "\n";

        return;
    }

    for(int i=1; i<=K; i++){


        arr.push_back(i);
        pick(arr, depth+1);
        arr.pop_back();
    }
    



}

int main() {
    cin >> K >> N;

    // Please write your code here.

    vector<int> arr;

    pick(arr, 0);

    return 0;
}

#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.

    int arr[1001] = {0};

    arr[2] = 1; arr[3] = 1; arr[4] = 1;

    for(int i=5; i<=n; i++){

        if(arr[i-2] != 0) arr[i] += arr[i-2];

        if(arr[i-3] != 0) arr[i] += arr[i-3];

    }

    cout << arr[n] % 10 << "\n";

    return 0;
}
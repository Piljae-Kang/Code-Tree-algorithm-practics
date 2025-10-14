#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.

    long long arr[1001] = {0};

    arr[2] = 1; arr[3] = 1; arr[4] = 1;

    for(int i=5; i<=n; i++){

        arr[i] += arr[i-2];
        arr[i] += arr[i-3];
        arr[i] = arr[i] % 10007;

        cout << arr[i] << "\n";

    }

    cout << arr[n] << "\n";

    return 0;
}
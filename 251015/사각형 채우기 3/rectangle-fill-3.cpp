#include <iostream>

using namespace std;

int n;

int main() {

    cin >> n;

    int arr[1001];

    arr[1] = 2;

    for(int i=2; i<=n; i++){

        arr[i] = (3 * arr[i-1] + 1) % 1000000007;

    }

    cout << arr[n] << "\n";


    return 0;
}

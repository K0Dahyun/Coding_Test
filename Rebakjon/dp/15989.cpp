#include <iostream>
#include <vector>
#define MAX 10000

using namespace std;

int arr[10001][4];

void dp() {
    arr[1][1] = 1;

    arr[2][1] = 1;
    arr[2][2] = 1;

    arr[3][1] = 1;
    arr[3][2] = 1;
    arr[3][3] = 1;

    for(int i = 4; i < 10001; i++) {
        arr[i][1] = 1;
        arr[i][2] = arr[i - 2][1] + arr[i - 2][2];
        arr[i][3] = arr[i - 3][1] + arr[i - 3][2] + arr[i - 3][3];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;

    dp();

    while(t--) {
        cin >> n;

        cout << arr[n][1] + arr[n][2] + arr[n][3] << endl;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; // loop n
    cin >> n;

    vector<int> loop(n);
    for(int i = 0; i < n; i++)
        cin >> loop[i];

    sort(loop.begin(), loop.end());

    int max_weight = 0;

    for(int i = 0; i < n; i++) {
        max_weight = max(max_weight, (n - i) * loop[i]);
    }

    cout << max_weight << endl;
}
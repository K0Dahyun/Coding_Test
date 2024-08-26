#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<int> inputs;

void dfs(int depth) {
    if(depth == m) {
        for(int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    int tmp = 0;
    for(int i = 0; i < n; i++) {
        if(tmp != inputs[i] && arr[depth - 1] <= inputs[i]) {
            arr[depth] = inputs[i];
            tmp = inputs[i];
            dfs(depth + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    inputs.resize(n, 0);
    arr.resize(m, 0);

    for(int i = 0; i < n; i++)
        cin >> inputs[i];

    sort(inputs.begin(), inputs.end());
    
    dfs(0);

    return 0;
}

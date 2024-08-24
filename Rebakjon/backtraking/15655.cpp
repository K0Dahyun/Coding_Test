#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<bool> visited;
vector<int> inputs;

void dfs(int depth) {
    if(depth == m) {
        for(int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i] && arr[depth - 1] <= inputs[i]) {
            visited[i] = true;
            arr[depth] = inputs[i];
            dfs(depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    arr.resize(m, 0);
    visited.resize(m, 0);
    inputs.resize(n, 0);

    for(int i = 0; i < n; i++)
        cin >> inputs[i];
    
    sort(inputs.begin(), inputs.end());

    dfs(0);   
}
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
vector<bool> visited;

void dfs(int depth) {
    if(depth == m) {
        for(int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(!visited[i] && arr[depth - 1] < i) {
            visited[i] = true;
            arr[depth] = i;
            dfs(depth + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    arr.resize(m + 1, 0);
    visited.resize(m + 1, false);

    dfs(0);

    return 0;
}
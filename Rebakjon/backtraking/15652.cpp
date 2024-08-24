#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;

void dfs(int depth) {
    if(depth == m) {
        for(int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(arr[depth - 1] <= i) {
            arr[depth] = i;
            dfs(depth + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    cin >> n >> m;
    arr.resize(m, 0);
    
    dfs(0);
}
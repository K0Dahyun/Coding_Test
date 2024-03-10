#include <iostream>
#include <queue>

using namespace std;
#define MAX 101

int n, m;
int map[MAX][MAX];
bool visited[MAX];

queue<int> q;

int BFS(int v) {
    int result = 0;

    q.push(v);
    visited[v] = true;

    while(!q.empty()) {
        v = q.front();
        q.pop();

        for(int i = 1; i <= n; i++) {
            if(map[v][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
                result++;
            }
        }
    }

    return result;
}

int main() { 
    cin >> n;
    cin >> m;
    int a, b;

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    
    cout << BFS(1) << endl;

    return 0;
}

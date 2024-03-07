// Point
// 정점 번호가 작은 것을 먼저 방문
// 정점 번호는 1번부터 N번까지이다
// 첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000)
// 정잠의 개수가 정점 번호보다 큼 

#include <iostream>
#include <queue>

using namespace std;
#define MAX 1001

int n, m, v;
int map[MAX][MAX];
bool visited[MAX];
queue<int> q;

void reset() {
    for(int i = 1; i <= n ; i++) {
        visited[i] = 0;
    }
}

void DFS(int v) {
    visited[v] = true;
    cout << v << " ";
    for(int i = 1; i <= n; i++) {
        if(map[v][i] && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int v) {
    q.push(v);
    visited[v] = true;
    cout << v << " ";

    while(!q.empty()) {
        v = q.front();
        q.pop();

        for(int i = 1; i <=n; i++) {
            if(map[v][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
                cout << i << " ";
            }
        }
    }
}

int main() { 
    cin >> n >> m >> v; //정점개수, 간선개수, 시작점
    int a, b;

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    reset();
    DFS(v);

    cout << endl;

    reset();
    BFS(v);

    return 0;
}

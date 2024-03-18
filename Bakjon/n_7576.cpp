#include <iostream>
#include <queue>

using namespace std;
#define MAX 1001

int n, m;
int map[MAX][MAX];
queue<pair<int, int>> q;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void BFS() {
    int cx, cy;
    int nx, ny;

    while(!q.empty()) {
        cx = q.front().first;
        cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if(nx >= n || ny >= m || nx < 0 || ny < 0) continue;

            if(map[nx][ny] == -1) continue;

            if(map[nx][ny] == 0) {
                map[nx][ny] = map[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    int v;
    int max = 0;

    cin >> m >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v;
            map[i][j] = v;
            if(v == 1) {
                q.push({i, j});
            }
        }
    }

    BFS();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
            if(map[i][j] > max) {
                max = map[i][j];
            }
        }
    }

    cout << max - 1 << endl;

    return 0;
}
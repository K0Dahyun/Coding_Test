#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n, m, k;
vector<vector<bool>> map;
queue<pair<int, int>> q;

void bfs(int x, int y) {
    int cx, cy;
    int nx, ny;
        
    q.push({x, y});
    map[x][y] = true;
    
    while(!q.empty()) {
        cx = q.front().first;
        cy = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if(map[nx][ny]) {
                map[nx][ny] = false;
                q.push({nx, ny});
            } 
        }
    }
}

int main() {
    int cnt;
    cin >> cnt;

    while(cnt--) {
        cin >> n >> m >> k;

        map.assign(n, vector<bool>(m, false));

        while(k--) {
            int x, y;
            cin >> x >> y;
            map[x][y] = true;
        }

        int result = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(map[i][j]) {
                    bfs(i, j);
                    result++;
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}
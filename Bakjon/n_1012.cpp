#include <iostream>
#include <queue>

using namespace std;
#define MAX 50

int n, m, k;
bool map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

queue<pair<int, int>> q;

void reset() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            map[i][j] = false;
            visited[i][j] = false; 
        }
    }
}

void BFS(int x, int y) {
    int cx, cy;
    int nx, ny;
    q.push({x, y});

    while(!q.empty()) {
        cx = q.front().first;
        cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if(nx >= n || ny >= m || nx < 0 || ny < 0)
                continue;
            if(map[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    int count;
    int x, y;
    int result;

    cin >> count;
    for(int i = 0; i < count; i++) {
        result = 0;
        cin >> n >> m >> k;

        for(int i = 0; i < k; i++) {
            cin >> x >> y;
            map[x][y] = true;
        }

        for(int x = 0; x < n; x++) {
            for(int y = 0; y < m; y++) {
                if(!visited[x][y] && map[x][y]) {
                    BFS(x, y);
                    result++;
                }
            }
        }
        cout << result << endl;

        reset();
    }


}
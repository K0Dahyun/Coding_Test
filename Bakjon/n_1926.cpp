#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 501

int n, m;
int map[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>> q;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int BFS(int x, int y) {
    int cx, cy, nx, ny;
    int result = 1;

    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        cx = q.front().first;
        cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if(nx >= n || ny >= m || nx < 0 || ny < 0) continue;

            if(map[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                result++;
            }
        }
    }

    return result;
}


int main() {
    vector<int> result;

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] && !visited[i][j]) {
                result.push_back(BFS(i, j));
            }
        }
    }

    cout << result.size() << endl;

    cout << *max_element(result.begin(), result.end()) << endl;

}
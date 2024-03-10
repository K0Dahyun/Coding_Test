#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 26

int n;
int map[MAX][MAX];
int visited[MAX][MAX];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

queue<pair<int, int>> q;

int BFS(int a, int b) {
    int result = 0;
    int cx, cy, nx, ny;
    
    q.push({a,b});
    visited[a][b] = true;
    result++;

    while(!q.empty()) {
        cx = q.front().first;
        cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if(nx >= n || ny >= n || nx < 0 || ny < 0)
                continue;

            if(map[nx][ny] && !visited[nx][ny] ) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                result++;
            }
        }
    }

    return result;
}


int main() {
    cin >> n;
    vector<int> result;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] && !visited[i][j]) {
                result.push_back(BFS(i, j));
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << endl;

    return 0;
}
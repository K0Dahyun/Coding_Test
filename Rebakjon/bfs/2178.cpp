#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;


int main() {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for(int j = 0; j < m; j++)
            if(row[j] == '1')
                map[i][j] = 1;
    }

    queue<pair<int, int>> q;
    q.push({0, 0});

    int cx, cy;
    int nx, ny;

    while(!q.empty()) {
        cx = q.front().first;
        cy = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if(nx >= n || ny >= m || nx < 0 || ny < 0)
                continue;
            
            if(map[nx][ny] == 1) {
                map[nx][ny] = map[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << map[n - 1][m - 1] << endl;

    return 0;
}
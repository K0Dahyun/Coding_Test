#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    int n, m;
    scanf("%d %d", &m, &n);

    vector<vector<int>> map(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp;
            scanf("%d", &temp);

            map[i][j] = temp;
            if(temp == 1) {
                q.push({i, j});
            }
        }   
    }

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
                        
            if(map[nx][ny] == 0) {                
                map[nx][ny] = map[cx][cy] + 1;
                q.push({nx, ny});
            }        
        }
    }

    int max_day = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
            if(map[i][j] > max_day) {
                max_day = map[i][j];
            }
        }   
    }

    cout << max_day - 1 << endl;

    return 0;
}
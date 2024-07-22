#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n, m;
vector<vector<int>> escape_time; // -1 - 간적없음, 0 - 불전파
vector<vector<bool>> map; // 1 - 갈수없음, 0 - 갈수있음
queue<pair<int, int>> q; // 불과 지훈이를 넣고, 불을 먼저 한칸 씩 번지게 한 후 지훈이를 이동시킴 

int main() {
    cin >> n >> m;

    escape_time.resize(n, vector<int>(m, -1)); // -1 - 방문한적없음
    map.resize(n, vector<bool>(m, true));

    int start_x, start_y;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char temp;
            cin >> temp;

            if(temp == '#') 
                map[i][j] = false;
            else if(temp == 'F') {
                map[i][j] = false;
                q.push({i, j}); // 불을 먼저 큐에 넣음
            }
            else if(temp == 'J') { // 불을 먼저 다 넣고, 지훈이를 넣어여 하기 때문에 잠시 저장
                start_x = i;
                start_y = j;
            }
        }
    }

    q.push({start_x, start_y});

    escape_time[start_x][start_y] = 1;

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();

        if(map[cx][cy] == 0 && cx == 0 || cy == 0 || cx == n - 1 || cy == m - 1) {
            cout << escape_time[cx][cy] << endl;
            return 0;
        }

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            
            if(!map[nx][ny]) // 벽이나 불이라면
                continue;
            
            if(escape_time[nx][ny] == -1) { // 불이 전파되지 않았고, 방문한 적이 없다면
                escape_time[nx][ny] = escape_time[cx][cy] + 1;
                map[nx][ny] = false;
                q.push({nx, ny});
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}
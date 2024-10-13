#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<string> map;
vector<vector<int>> fire_time;
vector<vector<int>> escape_time;

queue<pair<int, int>> fire;
queue<pair<int, int>> escape;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    map.resize(n);
    fire_time.resize(n, vector<int>(m, -1));
    escape_time.resize(n, vector<int>(m, -1));

    for(int i = 0; i < n; i++)
        cin >> map[i];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 'F') {
                fire.push({i, j});
                fire_time[i][j] = 0;
            }
            if(map[i][j] == 'J') {
                escape.push({i, j});
                escape_time[i][j] = 0;
            }
        }
    }

    while(!fire.empty()) {
        int cx = fire.front().first;
        int cy = fire.front().second;

        fire.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            
            if(fire_time[nx][ny] > -1 || map[nx][ny] == '#')
                continue;
            
            fire_time[nx][ny] = fire_time[cx][cy] + 1;

            fire.push({nx, ny});
        }
    }

    while(!escape.empty()) {
        int cx = escape.front().first;
        int cy = escape.front().second;

        escape.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << escape_time[cx][cy] + 1;
                return 0;
            }
            
            if(escape_time[nx][ny] > -1 || map[nx][ny] == '#')
                continue;

            if(fire_time[nx][ny] > -1 && fire_time[nx][ny] <= escape_time[cx][cy] + 1)
                continue;
            
            escape_time[nx][ny] = escape_time[cx][cy] + 1;

            escape.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
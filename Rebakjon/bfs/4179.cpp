#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

string map[1001];
int fire_time[1001][1001];
int escape_time[1001][1001];

queue<pair<int, int>> fire;
queue<pair<int, int>> escape;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> map[i];
    
	for (int i = 0; i < n; i++) {
		fill(escape_time[i], escape_time[i] + m, -1);
		fill(fire_time[i], fire_time[i] + m, -1);
	}
    
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

    // 불 전파 속도
    while(!fire.empty()) {
        int cx = fire.front().first;
        int cy = fire.front().second;

        fire.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx >= n || ny >= m || nx < 0 || ny < 0)
                continue;
            
            if(fire_time[nx][ny] >= 0 || map[nx][ny] == '#')
                continue;
            
            fire_time[nx][ny] = fire_time[cx][cy] + 1;

            fire.push({nx, ny});
        }
    }

    // 탈출 속도
    while(!escape.empty()) {
        int cx = escape.front().first;
        int cy = escape.front().second;

        escape.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 도착
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
                cout << escape_time[cx][cy] + 1 << endl;
                return 0;
            }
            
            if(escape_time[nx][ny] >= 0 || map[nx][ny] == '#')
                continue;

            if(fire_time[nx][ny] != -1 && fire_time[nx][ny] <= escape_time[cx][cy] + 1)
                continue;
            
            escape_time[nx][ny] = escape_time[cx][cy] + 1;

            escape.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}

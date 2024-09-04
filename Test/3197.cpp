#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

string map[1501];
int water_time[1501][1501]; // 도달시간
bool visited[1501][1501];

queue<pair<int, int>> water;
queue<pair<int, int>> swan_q, swan_next_q;

int r, c;
pair<int, int> swans[2];

bool canMeet(int day) {
    while(!swan_q.empty()) {
        int cx = swan_q.front().first;
        int cy = swan_q.front().second;

        swan_q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx >= r || ny >= c || nx < 0 || ny < 0)
                continue;

            if(visited[nx][ny])
                continue;
            
            visited[nx][ny] = true;

            if(map[nx][ny] == 'L')
                return true;
            
            if(water_time[nx][ny] <= day)
                swan_q.push({nx, ny});
            else
                swan_next_q.push({nx, ny});
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> r >> c;

    int swan_index = 0;

    for(int i = 0; i < r; i++) {
        cin >> map[i];
        for(int j = 0; j < c; j++) { // 백조가 처음 놓여진 곳도 물이 있기 때문
            if(map[i][j] != 'X') {
                water.push({i, j});
                water_time[i][j] = 0;
            }
            else
                water_time[i][j] = -1;
            
            if(map[i][j] == 'L')
                swans[swan_index++] = {i, j};
        }
    }

    // 물 전파 속도
    while(!water.empty()) {
        int cx = water.front().first;
        int cy = water.front().second;

        water.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx >= r || ny >= c || nx < 0 || ny < 0)
                continue;
            
            if(water_time[nx][ny] != -1) // 물이 이미 있는 곳이라면
                continue;
            
            water_time[nx][ny] = water_time[cx][cy] + 1;

            water.push({nx, ny});
        }
    }

    // 하나의 백조가 다른 백조를 만나는 것은
    // 백조를 둘다 움직일게 아니라
    // 미로에서 지정된 곳에 도달하는 문제랑 똑같음
    swan_q.push({swans[0]});
    visited[swans[0].first][swans[0].second] = true;

    int day = 0;
    while(true) {
        if(canMeet(day)) {
            cout << day << endl;
            return 0;
        }

        day++;

        // 기다리고 있는 백조를 현재 체크해야 하는 백조로 치환
        swan_q = swan_next_q;

        // 기존에 있던 기다리던 백조는 모두 없앰
        while(!swan_next_q.empty()) 
            swan_next_q.pop();
    }

    return 0;
}

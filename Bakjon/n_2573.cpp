#include <iostream>
#include <queue>
#define MAX 300
using namespace std;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int map[MAX][MAX] = {0, };
bool visited[MAX][MAX];
queue<pair<int, int>> q;

void reset() {
    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < m - 1; j++) {
            visited[i][j] = false;
        }
    }
}

void melting_ice() {
    vector<pair<pair<int, int>, int>> changes;

    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < m - 1; j++) {
            if(map[i][j] == 0) continue; //현재칸이 바다라면 pass

            int sea_count = 0;

            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                if(map[nx][ny] == 0) { // 주변 칸이 바다라면
                    sea_count++;
                }
            }
            changes.push_back({{i, j}, sea_count});
        }
    }

    for(int i = 0; i < changes.size(); i++) {
        if(map[changes[i].first.first][changes[i].first.second] < changes[i].second) {
            map[changes[i].first.first][changes[i].first.second] = 0;
        }
        else {
            map[changes[i].first.first][changes[i].first.second] -= changes[i].second;
        }
    }
}

void BFS_divide_area(int x, int y) {
    int cx, cy;
    int nx, ny;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        cx = q.front().first;
        cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            
            if(map[nx][ny] != 0 && !visited[nx][ny]) { // 바다가 아니고 방문하지 않았다면
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }

    }

}

int main() {
    int year = 0;
    int area_count;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    while(true) {
        area_count = 0;
        reset();

        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j < m - 1; j++) {
                if(map[i][j] != 0 && !visited[i][j]) { // 바다가 아니고 방문하지 않았다면
                    area_count++;
                    if(area_count > 1) {
                        cout << year << endl;
                        return 0;
                    }
                    BFS_divide_area(i, j);
                }
            }
        }

        if(area_count == 0) {
            cout << 0 << endl;
            break;
        }
        
        melting_ice();


        year++;
    }

    return 0;
}
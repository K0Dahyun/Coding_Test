#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n;
vector<vector<int>> Non_RG_map;
vector<vector<int>> RG_map;
queue<pair<int, int>> q;

void bfs(int x, int y, vector<vector<int>>& map) {
    int cx, cy;
    int nx, ny;
    int cur_color = map[x][y];

    map[x][y] = -1;
    q.push({x, y});

    while (!q.empty())
    {
        cx = q.front().first; 
        cy = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            
            if(map[nx][ny] == cur_color) {
                map[nx][ny] = -1;
                q.push({nx, ny});
            }
        }
        
    }
}

int main() {
    cin >> n;

    Non_RG_map.resize(n ,vector<int>(n, 0));
    RG_map.resize(n ,vector<int>(n, 0));

    // R - 0, G - 1, B - 2
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char temp;
            cin >> temp;

            if(temp == 'R') {
                Non_RG_map[i][j] = 0;
                RG_map[i][j] = 0;
            }
            else if(temp == 'G') {
                Non_RG_map[i][j] = 1;
                RG_map[i][j] = 0; // 색맹 지도는 R과 G가 같은 인덱스
            }
            else {
                Non_RG_map[i][j] = 2;
                RG_map[i][j] = 2;

            }
        }
    }

    // 일반인
    int result = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(Non_RG_map[i][j] != -1) {
                bfs(i, j, Non_RG_map);
                result++;
            }
        }
    }

    // 색맹
    int RG_result = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(RG_map[i][j] != -1) {
                bfs(i, j, RG_map);
                RG_result++;
            }
        }
    }

    cout << result << " " << RG_result << endl;

    return 0;
}
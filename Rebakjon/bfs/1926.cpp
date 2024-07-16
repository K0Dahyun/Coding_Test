#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int x, y;
vector<vector<bool>> map;
queue<pair<int, int>> q;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs(int x, int y) {
    int cx, cy; // current x, y
    int nx, ny; // possible position
    int area = 1;

    q.push({x, y});
    map[x][y] = false;

    while(!q.empty()) {
        cx = q.front().first;
        cy = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if(nx >= n || ny >= m || nx < 0 || ny < 0)
                continue;
            
            if(map[nx][ny]) {
                map[nx][ny] = false;
                q.push({nx, ny});
                area++;
            }
        }
    }

    return area;
}

int main() {   
    scanf("%d %d", &n, &m);
    map.resize(n, vector<bool>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp;
            scanf("%d", &temp);
            map[i][j] = (temp == 1);
        }
    }

    int max_area = 0;
    int area_count = 0;
    int area;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j]) {
                area_count++;
                area = bfs(i, j);
                if(area > max_area){
                    max_area = area;
                }
            }
        }
    }

    printf("%d\n", area_count);
    printf("%d\n", max_area);
}
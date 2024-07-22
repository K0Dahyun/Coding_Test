#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n, m, k;
vector<vector<bool>> area;
queue<pair<int, int>> q;

int bfs(int x, int y) {
    area[x][y] = true;
    q.push({x, y});

    int size = 1;

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            
            if(!area[nx][ny]) {
                size++;
                area[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return size;
}

int main() {
    cin >> m >> n >> k;

    area.resize(m, vector<bool>(n, false));

    while(k--) {
        int x1, x2, y1, y2; // (x1, y1) - 왼쪽 아래, (x2, y2) - 오른쪽 위
        cin >> x1 >> y1 >> x2 >> y2;

        for(int i = y1; i < y2; i++) {
            for(int j = x1; j < x2; j++)
                area[i][j] = true;
        }
    }

    int area_count = 0;
    vector<int> area_size;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!area[i][j]) {
                area_count++;
                int size = bfs(i, j);
                area_size.push_back(size);
            }
        }
    }

    sort(area_size.begin(), area_size.end());

    cout << area_count << endl;
    for(int i = 0; i < area_count; i++) {
        cout << area_size[i] << " ";
    }

    cout << endl;

    return 0;
}
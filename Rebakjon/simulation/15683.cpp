#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, -1, 0, 1}; // 우, 상, 좌, 하
int dy[4] = {1, 0, -1, 0};

int n, m;
int ans = 1e9;
int map[9][9];
vector<pair<int, int>> cctv;

void go(int x, int y, int dir) {
    dir %= 4;

    while(1) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        x = nx;
        y = ny;

        // out of map
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) return;

        // wall
        if(map[nx][ny] == 6) return;

        // another cctv
        if(map[nx][ny] != 0) continue;

        map[nx][ny] = -1;
    }

}

void dfs(int cctv_idx) {
    if(cctv_idx == cctv.size()) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int k = 0; k < m; k++) {
                if(map[i][k] == 0)
                    cnt++;
            }
        }

        ans = min(ans, cnt);

        return;
    }

    int x = cctv[cctv_idx].first;
    int y = cctv[cctv_idx].second;

    int tmp[9][9]; // have to save original map

    for(int i = 0; i < 4; i++) {
        // copy previous map to tmp
        for(int i = 0; i < n; i++) {
            for(int k = 0; k < m; k++)
                tmp[i][k] = map[i][k];
        }

        if(map[x][y] == 1)
            go(x, y, i);
        else if (map[x][y] == 2) {
            go(x, y, i);
            go(x, y, i + 2);
        }
        else if(map[x][y] == 3) {
            go(x, y, i);
            go(x, y, i + 1);
        }
        else if(map[x][y] == 4) {
            go(x, y, i);
            go(x, y, i + 1);
            go(x, y, i + 2);
        }
        else if(map[x][y] == 5) {
            go(x, y, i);
            go(x, y, i + 1);
            go(x, y, i + 2);
            go(x, y, i + 3);
        }

        dfs(cctv_idx + 1);

        for(int i = 0; i < n; i++) {
            for(int k = 0; k < m; k++)
                map[i][k] = tmp[i][k];
        }   
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    // input
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < m; k++) {
            cin >> map[i][k];
            if(map[i][k] != 0 && map[i][k] != 6)
                cctv.push_back({i, k});
        }
    }

    dfs(0);

    cout << ans << endl;

    return 0;
}
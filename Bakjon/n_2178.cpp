#include <iostream>
#include <queue>
#include <string>

using namespace std;
#define MAX 101

int n, m;
int map[MAX][MAX];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

queue<pair<int, int>> q;

int BFS(int a, int b) {
    int result = 0;
    int cur_x, cur_y;
    int nex_x, nex_y;

    q.push({a,b});

    while(!q.empty()) {
        cur_x = q.front().first;
        cur_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            nex_x = cur_x + dx[i];
            nex_y = cur_y + dy[i];

            if(nex_x >= n || nex_y >= m || nex_x < 0 || nex_y < 0)
                continue;
            if(map[nex_x][nex_y] == 0)
                continue;
            if(map[nex_x][nex_y] == 1) {
                map[nex_x][nex_y] = map[cur_x][cur_y] + 1;
                q.push({nex_x, nex_y});
            }
        }
    }
    return map[n - 1][m - 1];
}

int main() {
    cin >> n >> m;
    
    string value;
    for(int i = 0; i < n; i++) {
        cin >> value;
        for(int j = 0; j < m; j++) {
            map[i][j] = value[j] - '0';
        }
    }

    cout << BFS(0, 0) << std::endl;    
}



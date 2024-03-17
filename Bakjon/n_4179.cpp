#include <iostream>
#include <queue>

using namespace std;
#define MAX 1001
int n, m;
char map[MAX][MAX];
queue<pair<int, int>> jihoon;
queue<pair<int, int>> fire;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void fireSpread() {
    int cur_x, cur_y;
    int new_x, new_y;
    int size = fire.size();

    while(size--) {
        cur_x = fire.front().first;
        cur_y = fire.front().second;
        fire.pop();

        for(int i = 0; i < 4 ; i++) {
            new_x = cur_x + dx[i];
            new_y = cur_y + dy[i];

            if(new_x >= n || new_y >= m || new_x < 0 || new_y < 0) continue;
            if(map[new_x][new_y] == '#') continue;
            
            map[new_x][new_y] = '#';
            fire.push({new_x, new_y});
        }
    }
}

bool escapes() {
    int cur_x, cur_y;
    int new_x, new_y;
    int size = jihoon.size();

    if(size == 0) {
        cout << "IMPOSSIBLE";
        exit(0);
    }

    while(size--) {
        cur_x = jihoon.front().first;
        cur_y = jihoon.front().second;
        jihoon.pop();

        if(cur_x == 0 || cur_y == 0 || cur_x == n - 1 || cur_y == m - 1)
            return true;

        for(int i = 0; i < 4 ; i++) {
            new_x = cur_x + dx[i];
            new_y = cur_y + dy[i];

            if(new_x >= n || new_y >= m || new_x < 0 || new_y < 0) continue;
            if(map[new_x][new_y] == '#') continue;
            
            map[new_x][new_y] = '#';
            jihoon.push({new_x, new_y});
        }
    }

    return false;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> map[i];
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 'J') {
                jihoon.push({i, j});
                map[i][j] = '#';
            }

            else if(map[i][j] == 'F') {
                fire.push({i, j});
                map[i][j] = '#';
            }
        }
    }

    int step = 0;
    do {
        fireSpread();
        step++;
    } while(!escapes());

    cout << step;

    return 0;
}
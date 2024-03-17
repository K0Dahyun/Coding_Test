#include <iostream>
#include <queue>

using namespace std;
#define MAX 100

char map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<int, int>> q;
int n;

void reset() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            visited[i][j] = false;
    }
}

void BFS(int x, int y, int color) {
    int cur_x, cur_y;
    int new_x, new_y;

    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        cur_x = q.front().first;
        cur_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            new_x = cur_x + dx[i];
            new_y = cur_y + dy[i];

            if(new_x >= n || new_y >= n || new_x < 0 || new_y < 0) 
                continue;
            if(visited[new_x][new_y]) 
                continue;

            if((color != 'B' && map[new_x][new_y] != 'B') || (color == 'B' && map[new_x][new_y] == 'B')){
                visited[new_x][new_y] = true;
                q.push({new_x, new_y});
            }
        }
    }
}

void BFS_Non(int x, int y, int color) {
    int cur_x, cur_y;
    int new_x, new_y;

    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        cur_x = q.front().first;
        cur_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            new_x = cur_x + dx[i];
            new_y = cur_y + dy[i];

            if(new_x >= n || new_y >= n || new_x < 0 || new_y < 0) 
                continue;
            if(visited[new_x][new_y]) 
                continue;

            if(map[new_x][new_y] == color) {
                visited[new_x][new_y] = true;
                q.push({new_x, new_y});
            }
        }
    }
}

int main() {
    int result = 0;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                BFS_Non(i, j, map[i][j]);
                result++;
            }
        }
    }

    cout << result << endl;

    reset();
    result = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j]) {
                BFS(i, j, map[i][j]);
                result++;
            }
        }
    }

    cout << result << endl;

    return 0;
}
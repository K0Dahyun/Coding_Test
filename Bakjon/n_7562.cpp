#include <iostream>
#include <queue>

using namespace std;
#define MAX 300

int n;
int start_x, start_y;
int dest_x, dest_y;
int map[MAX][MAX];
queue<pair<int, int>> q;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

void reset() {
    while(!q.empty())
        q.pop();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            map[i][j] = 0;
        }
    }
}

void BFS() {
    int cx, cy;
    int nx, ny;
    q.push({start_x, start_y});

    while(!q.empty()) {
        cx = q.front().first;
        cy = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++) {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if(nx == dest_x && ny == dest_y) {
                cout << map[cx][cy] + 1 << endl;
                return;
            }

            if(nx >= n || ny >= n || nx < 0 || ny < 0) continue;

            if(map[nx][ny] == 0) {
                map[nx][ny] = map[cx][cy] + 1;
                q.push({nx, ny});
            }
        }

    }
}

int main() {
    int count;

    cin >> count;

    while(count--) {
        cin >> n;
        cin >> start_x >> start_y;
        cin >> dest_x >> dest_y;

        if(start_x == dest_x && start_y == dest_y) {
            cout << 0 << endl;
            continue;
        }

        reset();

        BFS();
    } 

    return 0;
}

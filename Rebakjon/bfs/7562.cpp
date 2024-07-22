
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int bfs(int n, int start_x, int start_y, int desti_x, int desti_y) {
    vector<vector<int>> map(n, vector<int>(n, 0));
    queue<pair<int, int>> q;

    q.push({start_x, start_y});

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();

        if(cx == desti_x && cy == desti_y)
            return map[cx][cy];

        for(int i = 0; i < 8; i++) {
            int nx = cx + dx[i];  
            int ny = cy + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;

            if(map[nx][ny] == 0) {
                map[nx][ny] = map[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }  

    return -1;

}

int main() {
    int cnt;
    cin >> cnt;

    while(cnt--) {
        int n;
        cin >> n;

        int start_x, start_y;
        int desti_x, desti_y;

        cin >> start_x >> start_y;
        cin >> desti_x >> desti_y;

        cout << bfs(n, start_x, start_y, desti_x, desti_y) << endl;

    }
    
    return 0;
}
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int solution(vector<string> maps) {
    int answer = -1;
    queue <pair<int, int>> q;

    int x_size = maps.size();
    int y_size = maps[0].size();
    vector<vector<int>> vis(x_size, vector<int>(maps[0].size(), 0));

    pair<int, int> start;
    pair<int, int> exit;
    pair<int, int> leva;
    pair<int, int> cur;

    int cur_x, cur_y;
    int next_x, next_y;
    bool leva_pass = false;
    int time = 0;

    for(int i = 0; i < x_size; i++) {
        for(int j = 0; j < y_size; j++) {
            if(maps[i][j] == 'S')
                start = {i, j};
            if(maps[i][j] == 'E')
                exit = {i, j};
            if(maps[i][j] == 'L')
                leva = {i, j};
        }
    }

    q.push(start);    

    while(!q.empty()) {
        cur = q.front();
        cur_x = cur.first;
        cur_y = cur.second;
        q.pop();

        if(!leva_pass && cur == leva) {
            leva_pass = true;
            time = vis[cur_x][cur_y];
            q = queue <pair<int, int>> ();
            vis = vector<vector<int>> (x_size, vector<int>(maps[0].size(), 0));
            vis[cur_x][cur_y] = time;
        }

        if(leva_pass && cur == exit) {
            answer = vis[cur_x][cur_y];
            break;
        }

        for(int k = 0; k < 4; k++) {
            next_x = cur_x + dx[k];
            next_y = cur_y + dy[k];

            if(next_x >= x_size || next_y >= y_size || next_x < 0 || next_y < 0) continue;
            if(maps[next_x][next_y] == 'X' || vis[next_x][next_y]) continue;

            vis[next_x][next_y] = vis[cur_x][cur_y] + 1;

            q.push(make_pair(next_x, next_y));
        }

    }
    return answer;
}
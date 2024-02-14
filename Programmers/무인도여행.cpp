#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    queue<pair<int, int>> q; // i, j
    int x_size = maps.size();
    int y_size = maps[0].size();
    int day = 0;
    pair<int, int> cur;
    int nx, ny;

    for(int i = 0; i < x_size; i++) {
        for(int j = 0; j < y_size; j++) {
            if(!isdigit(maps[i][j]) || visited[i][j]) continue;
            day = maps[i][j] - '0';
            q.push(make_pair(i, j));
            visited[i][j] = true;

            while(!q.empty()) {
                cur = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {
                    nx = cur.first + dx[k];
                    ny = cur.second + dy[k];

                    if(nx >= x_size || ny >= y_size || nx < 0 || ny < 0) continue;
                    if(!isdigit(maps[nx][ny]) || visited[nx][ny]) continue;
                    day += maps[nx][ny] -'0';
                    visited[nx][ny] = true;

                    q.push(make_pair(nx, ny));
                }
            }
            answer.push_back(day);

        }
    }
    if(answer.empty()) answer.push_back(-1);
    else sort(answer.begin(), answer.end());

    return answer;
}
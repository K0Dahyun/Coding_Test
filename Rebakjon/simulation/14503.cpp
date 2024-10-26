#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    
    int cur_x, cur_y, direction; // 0 - north, 1 - east, 2 - sourth, 3 - west 
    cin >> cur_x >> cur_y >> direction;

    for(int i = 0; i < n; i++) {
        for(int k = 0; k < m; k++)
            cin >> map[i][k];
    }

    int count = 0;

    while(1) {
        // 1 : if current position is not clean, just clean
        if(map[cur_x][cur_y] == 0) {
            map[cur_x][cur_y] = 2;
            count++;
        }

        // check surrounding position clear or not
        bool clean_surround = true;

        for(int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(map[next_x][next_y] == 0) {
                clean_surround = false;
                break;
            }
        }

        // 2 : if all clean surrounding position
        if(clean_surround) {
            int back_x = cur_x;
            int back_y = cur_y;

            if(direction == 0) back_x++;
            else if(direction == 1) back_y--;
            else if(direction == 2) back_x--;
            else back_y++;

            // 2-1 : if there is no wall back
            if(map[back_x][back_y] != 1) {
                cur_x = back_x;
                cur_y = back_y;
            }
            else  { // 2-2 : if there is wall back
                cout << count;
                return 0;
            }
        }
        else { // 3 : if some position not clean 
            direction = (direction + 3) % 4; // 3-1 : turn 90 degree

            if(direction == 0 && map[cur_x - 1][cur_y] == 0) cur_x--;
            else if(direction == 1 && map[cur_x][cur_y + 1] == 0) cur_y++;
            else if(direction == 2 && map[cur_x + 1][cur_y] == 0) cur_x++;
            else if(direction == 3 && map[cur_x][cur_y - 1] == 0) cur_y--;
        }

    }
    
    cout << count;

    return 0;
}
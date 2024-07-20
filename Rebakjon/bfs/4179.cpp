#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// 4 4
// ####
// #JF#
// #..#
// #..#

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    int n, m;
    cin >> n >> m;

    vector<vector<int>> fire_time(n, vector<int>(m, 0));
    vector<vector<int>> escape_time(n, vector<int>(m, 0));
    queue<pair<int, int>> escape;
    queue<pair<int, int>> fire;

    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < m; j++) {
            if(temp[j] == 'F') {
                fire.push({i, j});
                fire_time[i][j] = 1;
            }
            if(temp[j] == 'J') {
                escape.push({i, j});
                escape_time[i][j] = 1;
            }
            if(temp[j] == '#') {
                fire_time[i][j] = -1;
                escape_time[i][j] = -1;
            }
            
        }
    }

    // Fire spread time
    int fcx, fcy; // fire current pose
    int fnx, fny; // fire next pose

    while(!fire.empty()) {
        fcx = fire.front().first;
        fcy = fire.front().second;

        fire.pop();

        for(int i = 0; i < 4; i++) {
            fnx = fcx + dx[i];
            fny = fcy + dy[i];

            if(fnx >= n || fny >= m || fnx < 0 || fny < 0)
                continue;
                    
            if(fire_time[fnx][fny] == 0) {
                fire_time[fnx][fny] = fire_time[fcx][fcy] + 1;
                fire.push({fnx, fny});
            }

        }
    }

    // cout << "fire" << endl;
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << fire_time[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Escape time
    int ecx, ecy; // escape current pose
    int enx, eny; // escape next pose

    while(!escape.empty()) {
        ecx = escape.front().first;
        ecy = escape.front().second;

        escape.pop();

        for(int i = 0; i < 4; i++) {
            enx = ecx + dx[i];
            eny = ecy + dy[i];

            if(enx >= n || eny >= m || enx < 0 || eny < 0)
                continue;
            
            if(escape_time[enx][eny] == -1)
                continue;

            if(escape_time[ecx][ecy] + 1 >= fire_time[enx][eny])
                continue;

            escape_time[enx][eny] = escape_time[ecx][ecy] + 1;
            escape.push({enx, eny});

            if(enx == 0 || enx == n - 1 || eny == 0 || eny == m - 1) {
                cout << escape_time[enx][eny]<< endl;
                // cout << "escape" << endl;
                // for(int i = 0; i < n; i++) {
                //     for(int j = 0; j < m; j++) {
                //         cout << escape_time[i][j] << " ";
                //     }
                //     cout << endl;
                // }
                return 0;
            }
                    
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
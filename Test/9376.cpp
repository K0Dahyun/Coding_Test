#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

string map[101];
int visited[101][101]; // 0 - 벽이거나 방문했거나, 1 - 갈수있음, 2 - 문
queue<pair<int, int>> q;

int dfs() {

}

int main() {
    int n;
    cin >> n;

    while(n--) {
        int h, w;
        cin >> h >> w;

        for(int i = 0; i < h; i++)
            cin >> map[i];

        for(int i = 0; i < h; i++) {
            for(int k = 0; k < w; k++) {
                if(map[i][k] == '*')
                    visited[i][k] == 0;
                else
                    visited[i][k] == 1;

                if(map[i][k] == '$')
                    q.push({i, k});
            }
        }

        

    }
}
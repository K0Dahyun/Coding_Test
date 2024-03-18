#include <iostream>
#include <queue>

using namespace std;

int map[99][99][100];
queue<pair<pair<int,int>,int> > q;
int n, m, h;

q.push(make_pair(make_pair(i,j),k));

int main() {
    cin >> n >> m >> h;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                cin >> map[i][j][k];
            }
        }
    }

    




}

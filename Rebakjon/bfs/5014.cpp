#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int f, s, g, u, d; // f - 총 층수, s - 경호, g - 목적지, 위로 - u, 아랠로 - d
    cin >> f >> s >> g >> u >> d;

    vector<int> ele(f + 1, -1); // 엘레베이터, 0층은 안씀, -1이면 방문한 적 없음
    queue<int> q;

    ele[s] = 0; // 시작위치에선 0초
    q.push(s);

    while(!q.empty()) {
        int cur = q.front();

        if(cur == g) {
            cout << ele[cur] << endl;
            return 0;
        }

        q.pop();

        int next_d = cur - d;
        int next_u = cur + u;

        if(next_d > 0 && ele[next_d] == -1) {
            ele[next_d] = ele[cur] + 1;
            q.push({next_d});
        }

        if(next_u <= f && ele[next_u] == -1) {
            ele[next_u] = ele[cur] + 1;
            q.push({next_u});
        }

    }

    cout << "use the stairs" << endl;

    return 0;

}
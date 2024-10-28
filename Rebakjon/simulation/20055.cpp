#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int belt[101];
bool visited[101]; // robot position

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> belt[i];

    int start = 1;
    int end = n;
    int cnt = 0;
    int ans = 0;
    queue<int> robot;

    while(cnt < k) {
        ans++;

        // move belt
        start--;
        end--;
        if(start < 1) start = 2 * n;
        if(end < 1) end = 2 * n;

        // move robot
        int size = robot.size();
        for(int i = 0; i < size; i++) {
            int cur = robot.front();
            visited[cur] = false;
            robot.pop();
            
            // if current position is end, because of moving belt and dont move robot
            if(cur == end) continue;

            int next = cur + 1;
            if(next > 2 * n) next = 1;

            // if belt avalible and there is no another robot
            if(belt[next] >= 1 && !visited[next]) {
                belt[next]--;

                if(belt[next] == 0) cnt++;

                if(next == end) continue;

                visited[next] = true;
                robot.push(next);
            }
            else { // if robot cant go, just stay
                visited[cur] = true;
                robot.push(cur);
            }
        }

        // make new robot
        if(!visited[start] && belt[start] >= 1) {
            visited[start] = true;
            belt[start]--;
            robot.push(start);

            if(belt[start] == 0) cnt++; 
        }
    }

    cout << ans << endl;

    return 0;
}
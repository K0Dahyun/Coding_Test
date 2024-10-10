#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int min_time = 999999;
bool visited[100001];
queue<pair<int, int>> q; // 위치, 도달 시간 

int main() {
    int n, k;
    cin >> n >> k;

    int cnt = 0;

    q.push({n, 0});

    while(!q.empty()) {
        int cur_pose = q.front().first;
        int cur_time = q.front().second;

        q.pop();
        
        visited[cur_pose] = true;

        if(min_time < cur_time) // 과거에 있던 최소 시간보다 현재 시간이 길 경우, 더 탐색할 필요가 없음
            break;
        
        if(cur_pose == k) {
            min_time = cur_time;
            cnt++;
            continue;
        }

        if(cur_pose + 1 <= 100000 && !visited[cur_pose + 1])
            q.push({cur_pose + 1, cur_time + 1});

        if(cur_pose - 1 >= 0 && !visited[cur_pose - 1])
            q.push({cur_pose - 1, cur_time + 1});

        if(2 * cur_pose <= 100000 && !visited[2 * cur_pose])
            q.push({2 * cur_pose, cur_time + 1});
    }

    cout << min_time << "\n" << cnt << "\n";
    
    return 0;
    
}
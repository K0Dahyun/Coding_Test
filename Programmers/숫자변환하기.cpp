#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[1000001];

int solution(int x, int y, int n) {
    int answer, cur, curt;
    queue <pair<int, int>> q;

    if(x == y) return 0;

    q.push(make_pair(x, 0));
    while(!q.empty()) {
        cur = q.front().first;
        curt = q.front().second;

        q.pop();

        if(cur + n <= y && !visited[cur + n]) {
            visited[cur + n] = true;
            if(cur + n == y) return curt + 1;
            q.push(make_pair(cur + n, curt + 1));
        }
        
        if(cur * 2 <= y && !visited[cur * 2]) {
            visited[cur * 2] = true;
            if(cur * 2 == y) return curt + 1;
            q.push(make_pair(cur * 2, curt + 1));
        }
        
        if(cur * 3 <= y && !visited[cur * 3]) {
            visited[cur * 3] = true;
            if(cur * 3 == y) return curt + 1;
            q.push(make_pair(cur * 3, curt + 1));
        }
    }
    return -1;
}
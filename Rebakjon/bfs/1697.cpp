#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // Input
    int n, k;
    cin >> n >> k;
    
    // Moving position
    queue<int> q;
    
    // Time path
    int time[100001] = {0,};
    
    q.push(n);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
            
        // Meet
        if(cur == k) {
            cout << time[cur] << endl;
            break;
        }
        
        if(cur - 1 >= 0 && time[cur - 1] == 0) {
            time[cur - 1] = time[cur] + 1;
            q.push(cur - 1);
        }
        
        if(cur + 1 <= 100001 && time[cur + 1] == 0) {
            time[cur + 1] = time[cur] + 1;
            q.push(cur + 1);
        }
        
        if(2 * cur <= 100001 && time[2 * cur] == 0) {
            time[2 * cur] = time[cur] + 1;
            q.push(2 * cur);
        }
        
    }
    
    return 0;
    
}
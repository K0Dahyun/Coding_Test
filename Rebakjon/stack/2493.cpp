#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;

    stack<pair<int, int>> s; // {인덱스, 탑 높이}

    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;

        while(!s.empty()) {
            if(s.top().second > k) { // 입력받은 탑보다 더 큰 탑을 만났을때
                cout << s.top().first << "\n";
                break;
            }
            s.pop();
        }

        if(s.empty())
            cout << 0 << "\n";
        
        s.push({i + 1, k});
    }

    return 0;
}

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    priority_queue<int> max; // 작은것 중에 가장 큰것
    priority_queue<int, vector<int>, greater<int>> min; // 큰것 중에 가장 작은것

    while(n--) {
        int input;
        cin >> input;

        if(max.size() == min.size())
            max.push(input);
        else
            min.push(input);
        
        if(!max.empty() && !min.empty() && max.top() > min.top()) {
            int a = max.top();
            int b = min.top();

            max.pop();
            min.pop();
        
            max.push(b);
            min.push(a);
        }

        cout << max.top() << "\n";
    }

    return 0;
}

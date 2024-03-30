#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int count;
    cin >> count;

    vector<int> answer;
    stack<pair<int,int>> s;
    int value;


    for(int i = 0; i < count; i++) {
        cin >> value;
        
        while(!s.empty()) {
            if(s.top().second > value) {
                cout << s.top().first << " ";
                break;
            }
            s.pop();
        }
        if(s.empty()) {
            cout << 0 << " ";
        }

        s.push({i + 1, value});
    }

    return 0;
}
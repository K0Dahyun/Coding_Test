#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count;
    cin >> count;

    int v;
    stack<pair<int,int>> s;
    long long answer = 0;

    for(int i = 0; i < count; i++) {
        cin >> v;

        while(!s.empty() && s.top().first < v) {
            answer += s.top().second;
            s.pop();
        }

        if(!s.empty()) {
            if(s.top().first == v) {
                answer++;
                answer += s.top().second;
                s.top().second += 1;
            }
            else {
                s.push({v, 1});
                answer++;
            }
        }
        else {
            s.push({v, 1});
        }

    }

    cout << answer << endl;
    
    return 0;
}




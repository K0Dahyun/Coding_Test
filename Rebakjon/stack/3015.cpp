#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    // 키, 같은 키인 명수
    stack<pair<int, int>> s;
    long long answer = 0;

    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;

        int same_cnt = 1;

        while(!s.empty() && s.top().first <= input) {
            answer += s.top().second;
            if(s.top().first == input)
                same_cnt += s.top().second;
            s.pop();
        }

        if(!s.empty()) answer++;

        s.push({input, same_cnt});
    }

    cout << answer << endl;

    return 0;

}
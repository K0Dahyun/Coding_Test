#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    // input
    vector<int> inputs(n, 0);
    for(int i = 0; i < n; i++)
        cin >> inputs[i];
    
    // 스택엔 아직 오큰수를 찾지 못한 인덱스가 input됨
    stack<int> s;
    vector<int> answer(n, 0);

    for(int i = 0; i < n; i++) {
        while(!s.empty() && inputs[s.top()] < inputs[i]) {
            answer[s.top()] = inputs[i];
            s.pop();
        }

        s.push(i);
    }

    while(!s.empty()) {
        answer[s.top()] = -1;
        s.pop();
    }

    for(int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";

    return 0;
}
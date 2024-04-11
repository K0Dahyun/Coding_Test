#include <iostream>
#include <stack>

using namespace std;

int main() {
    int count;
    cin >> count;

    int value = 0;
    long long answer = 0;
    stack<int> s;

    for(int i = 0; i < count; i++) {
        cin >> value;

        while(!s.empty()) {
            if(s.top() > value)
                break;
            s.pop();
        }

        answer += (long long)s.size();
        s.push(value);
    }

    cout << answer << endl;

    return 0;
}
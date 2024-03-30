#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a;
    int number = 1;
    stack<int> s;
    vector<char> answer;

    for(int i = 0; i < n; i++) {
        cin >> a;

        while(number <= a) {
            s.push(number++);
            answer.push_back('+');
        }

        if(s.top() == a) {
            s.pop();
            answer.push_back('-');
        }

        else {
            cout << "No";
            return 0;
        }
    }

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }

    return 0;
}
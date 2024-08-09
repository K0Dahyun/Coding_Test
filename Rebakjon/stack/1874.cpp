#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    stack<int> s;
    vector<char> answer;
    int now = 1;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        while(temp >= now) {
            s.push(now);
            answer.push_back('+');
            now++;
        }

        if(s.top() == temp) {
            s.pop();
            answer.push_back('-');
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }

    for(int i = 0; i < answer.size(); i++)
        cout << answer[i] << endl;

    return 0;

}
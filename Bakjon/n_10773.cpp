#include <iostream>
#include <stack>

using namespace std;

int main() {
    int count, value;
    stack<int> s;
    int total = 0;

    cin >> count;

    while(count--) {
        cin >> value;

        if(value != 0) {
            total += value;
            s.push(value);
        }
        else {
            total -= s.top();
            s.pop();
        }
    }

    cout << total << endl;

    return 0;
}
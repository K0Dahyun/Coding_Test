#include <iostream>
#include <stack>

using namespace std;

int main() {
    int k;
    cin >> k;

    stack<int> v;

    while(k--) {
        int temp;
        cin >> temp;

        if(temp == 0)
            v.pop();
        else
            v.push(temp);
    }

    long long sum = 0;
    
    while(!v.empty()) {
        sum += v.top();
        v.pop();
    }

    cout << sum << endl;

    return 0;
}
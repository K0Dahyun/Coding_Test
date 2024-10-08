#include <vector>
#include <iostream>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> q;

    for(int i = 0; i < n * n; i++) {
        int temp;
        cin >> temp;

        q.push(temp);

        if(q.size() > n)
            q.pop();
    }

    cout << q.top();

    return 0;
}
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int v[n];
    for(int i = 0; i < n; i++) {
        int value;  
        cin >> value;
        v[i] = value;
    }

    sort(v, v + n); 

    int left = 0;
    int right = 0;
    // 1 3 5

    int diff;
    int min_diff = 2e9 + 1;

    while(left < n) {
        diff = v[right] - v[left];
        if(diff < m)
            right++;
        else if(diff > m) {
            min_diff = min(min_diff, diff);
            left++;
        }
        else {
            min_diff = m;
            break;
        }
    }
    cout << min_diff << endl;
}
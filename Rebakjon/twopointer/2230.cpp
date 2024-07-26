#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector<int> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    
    int end = 0;
    int min = 2000000000;

    for(int start = 0; start < n; start++) {
        while(end < n && v[end] - v[start] < m)
            end++;

        if(end == n) break;

        min = (v[end] - v[start] < min) ? v[end] - v[start] : min;
    }
    
    cout << min << endl;

    return 0;
}
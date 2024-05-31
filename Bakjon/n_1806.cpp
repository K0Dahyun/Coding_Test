#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, s;
    cin >> n >> s;

    int v[n];
    for(int i = 0; i < n; i++)
        cin >> v[i];

    // sort(v, v + n);

    // 1 2 3 4 5 5 7 8 9 10

    int left = 0;
    int right = 0;
    int sum = 0;
    int min_length = 2e9 + 1;

    while(right <= n) {
        if(sum >= s) {
            min_length = min(min_length, right - left);
            sum -= v[left];
            left++;
        }
        else {
            sum += v[right];
            right++;
        }
    }

    if(min_length == 2e9 + 1)
        cout << 0 << endl;
    else
        cout << min_length << endl;

    return 0;
}
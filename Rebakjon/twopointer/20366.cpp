#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n, 0);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int min_diff = INT_MAX;

    for(int i = 0; i < n - 3; i++) {
        for(int j = i + 3; j < n; j++) {
            int first_snowman = v[i] + v[j];
            int start = i + 1;
            int end = j - 1;

            while(start < end) {
                int second_snowman = v[start] + v[end];
                int diff = abs(first_snowman - second_snowman);

                min_diff = min(diff, min_diff);

                if(first_snowman < second_snowman)
                    end--;
                else if(first_snowman > second_snowman)
                    start++;
                else {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }

    cout << min_diff << endl;

    return 0;
}
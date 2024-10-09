#include <vector>
#include <iostream>

using namespace std;

int count[200000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    int maxsize = 0;
    int start = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        count[arr[i]]++;

        while(count[arr[i]] > k)
            count[arr[start++]]--;
        
        maxsize = maxsize > i - start + 1 ? maxsize : i - start + 1;
    }

    cout << maxsize;

    return 0;
}
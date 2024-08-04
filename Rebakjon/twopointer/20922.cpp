#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    vector<int> v(n, 0);
    vector<int> count(200001, 0);

    int start = 0;
    int max_length = 0;

    for(int end = 0; end < n; end++) {
        cin >> v[end];
        count[v[end]]++;

        while(count[v[end]] > k)
            count[v[start++]]--;

        max_length = max(end - start + 1, max_length);
    }

    cout << max_length << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    int start = 0;
    int end = 0;
    int sum = 0;
    int cnt = 0;

    while(end <= n) {
        if(sum < s) {
            if(end == n)
                break;
            sum += v[end++];
        }
        else if(sum > s)
            sum -= v[start++];
        else {
            cnt++;
            sum += v[end++];
        }
    }   

    cout << cnt << endl;

    return 0;
}
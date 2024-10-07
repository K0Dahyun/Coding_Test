#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, s;
    cin >> n >> s;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    int start = 0, end = 0, sum = 0;
    int Maxmin = 0x7FFFFFF;

    while(end <= n) {
        if(sum >= s) {
            Maxmin = min(Maxmin, end - start); // end는 이미 하나 올라가있기 때문에 +1 안함
            sum -= v[start++];
        }
        else
            sum += v[end++];
    }

    if(Maxmin == 0x7FFFFFF)
        cout << 0;
    else
        cout << Maxmin;
    
    return 0;
}
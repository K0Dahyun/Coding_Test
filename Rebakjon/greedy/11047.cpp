#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> money;
    
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        money.push_back(temp);
    }
    
    int cnt = 0;
    
    for(int i = n - 1; i >= 0; i--) {
        cnt += k / money[i];
        k %= money[i];
        
        if(k == 0)
            break;
    }
    
    cout << cnt << endl;
    
    return 0;
}
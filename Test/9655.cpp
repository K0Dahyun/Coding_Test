#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> dp(n + 1, false); // true - 상근 승, false - 창영 승

    dp[1] = true; // 1개면 상근 승 
    dp[2] = false;  // 2개면 창영 승
    dp[3] = true; // 3개면 상근 승

    for(int i = 4; i < n + 1; i++)
        dp[i] = !dp[i - 1] || !dp[i - 3];
    
    if(dp[n])
        cout << "SK" << endl;
    else
        cout << "CY" << endl;
    
    return 0;
}
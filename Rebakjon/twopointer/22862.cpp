#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> v(n);
    
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    int start = 0;
    int end = 0;
    int odd_cnt = 0; // 홀수
    int answer = 0;
    
    while(end < n) {
        if(odd_cnt > k) {
            if(v[start++] % 2 != 0)
                odd_cnt--;
        }
        else {
            if(v[end] % 2 != 0)
                odd_cnt++;
            end++;
            answer = end - start - odd_cnt > answer ? end - start - odd_cnt : answer;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
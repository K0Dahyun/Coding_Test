#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> v(1000001, 0);

    for(int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        for(int j = start + 1; j <= end; j++)
            v[j]++;
    }
    
    int start = 0;
    int end = 0;
    int sum = 0;
    int resstart = 0;
    int resend = 0;

    // 0인덱스는 비워있기 때문에 후위 연산자 사용 가능
    while(end < 1000001) {
        if(sum > k)
            sum -= v[++start];
        else if(sum < k)
            sum += v[++end];
        else{
            resstart = start;
            resend = end;
            break;
        }
    }

    cout << resstart << " " << resend  << endl;

    return 0;
}
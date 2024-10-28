#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    while(n--) {
        int number;
        cin >> number;

        vector<int> line(20);
        for(int i = 0; i < 20; i++)
            cin >> line[i];

        int ans = 0;
        
        for(int i = 0; i < 20; i++) {
            for(int k = i; k < 20; k++) {
                if(line[i] > line[k])
                    ans++;
            }
        }
    
        cout << number << " " << ans << "\n";
    }

    return 0;
}
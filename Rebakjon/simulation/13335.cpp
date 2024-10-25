#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, w, l;
    cin >> n >> w >> l;

    int weight_sum = 0; // current weight on lamp
    queue<int> lamp;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        int truck;
        cin >> truck;
        
        while(1) {
            if(lamp.size() == w) {
                weight_sum -= lamp.front();
                lamp.pop();
            }

            if(truck + weight_sum <= l) break;

            lamp.push(0); // if lamp is full, have to waiting out of front truck
            ans++;
        }

        lamp.push(truck);
        weight_sum += truck;
        ans++;
    }

    cout << ans + w;

    return 0;
}
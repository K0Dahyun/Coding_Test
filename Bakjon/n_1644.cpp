#include <iostream>
#include <vector> 
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int value;
    cin >> value;

    if(value == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<bool> v(value + 1, true);

    for(int i = 2; i * i <= value; i++) {
        if(v[i]) {
            for(int j = i * i; j <= value; j += i) {
                v[j] = false;
            }
        }
    }

    vector<int> prime;
    for(int i = 2; i <= value; i++) {
        if(v[i]){
            prime.push_back(i);
        }
    }

    int left = 0;
    int right = 0;
    int sum = 0;
    int answer = 0;

    while(right <= prime.size()) {
        if(sum >= value) {
            sum -= prime[left++];
        }
        if(sum < value) {
            sum += prime[right++];
        }

        if(sum == value) {
            // cout << "left:" << prime[left] << " right: " << prime[right] << endl;
            answer++;
        }
        
    }

    cout << answer << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 소수찾기
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    
    for(int i = 2; i * i <= n; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    
    vector<int> primes;
    
    for(int i = 2; i <= n; i++) {
        if(is_prime[i])
            primes.push_back(i);
    }
    
    // 연속합
    int start = 0;
    int end = 0;
    int sum = 0;
    int cnt = 0;
    
    int primes_num = (int)primes.size();
    
    while(end <= primes_num) {
        if(sum < n) {
            if(end == primes_num)
                break;
            sum += primes[end++];
        }
        else if(sum > n)
            sum -= primes[start++];
        else {
            cnt++;
            sum += primes[end++]; // end를 올리든 start를 올리든 상관없음
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}
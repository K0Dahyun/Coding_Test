#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    int count;
    int value;
    int result = 0;

    cin >> count;

    while(count--) {
        cin >> value;
        if(value == 1) continue;
        if(isPrime(value)) result++;
    }
    cout << result << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    int cnt = 0;

    for(int i = 0; i < input.size(); i++) {
        if(input[i] != input[i + 1])
            cnt++;
    }

    if(cnt == 0)
        cout << cnt;
    else
        cout << cnt / 2;
        
    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    int zero_cnt = 0;
    int one_cnt = 0;

    if(input[0] == '0')
        zero_cnt++;
    else
        one_cnt++;

    char prev = input[0];

    for(int i = 1; i < input.size(); i++) {
        if(input[i] != prev) {
            if(input[i] == '0')
                zero_cnt++;
            else
                one_cnt++;
            
            prev = input[i];
        }
    }

    if(zero_cnt > one_cnt)
        cout << one_cnt << endl;
    else
        cout << zero_cnt << endl;

    return 0;
}
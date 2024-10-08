#include <vector>
#include <string>
#include <iostream>

using namespace std;


int alpha[26];

int main() {
    string input;

    cin >> input;

    // 빈도수 확인
    for(int i = 0; i < input.size(); i++) {
        if(input[i] < 97) // 대문자
            alpha[input[i] - 65]++;
        else // 소문자
            alpha[input[i] - 97]++;
    }

    // 가장 빈도수가 높은 인덱스
    int max = 0, max_index = 0;

    for(int i = 0; i < 26; i++) {
        if(max < alpha[i]) {
            max = alpha[i];
            max_index = i;
        }
    }

    int same_cnt = 0;
    for(int i = 0; i < 26; i++) {
        if(max == alpha[i])
            same_cnt++;
    }
        
    if(same_cnt > 1)
        cout << "?";
    
    else
        cout << (char)(max_index + 65);
}
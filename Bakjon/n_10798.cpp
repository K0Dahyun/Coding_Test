// Input
// 총 다섯줄의 입력이 주어진다. 각 줄에는 최소 1개, 최대 15개의 글자들이 빈칸 없이 연속으로 주어진다. 
// 주어지는 글자는 영어 대문자 ‘A’부터 ‘Z’, 영어 소문자 ‘a’부터 ‘z’, 숫자 ‘0’부터 ‘9’ 중 하나이다. 
// 각 줄의 시작과 마지막에 빈칸은 없다.
// Output
// 영석이가 세로로 읽은 순서대로 글자들을 출력한다. 이때, 글자들을 공백 없이 연속해서 출력한다. 

/*
AABCDD
afzz
09121
a8EWg6
P5h3kx
*/ 


#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(){
    string temp;
    int max_size = 0;
    vector<string> v;
    
    for(int i = 0; i < 5; i++){
        cin >> temp;
        v.push_back(temp);
        if(temp.length() >= max_size){
            max_size = temp.length();
        }
    }

    for(int i = 0; i < max_size; i++){
        for(int j = 0; j < 5; j++){
            if(v[j][i])
                std::cout << v[j][i];
        }
    }

}
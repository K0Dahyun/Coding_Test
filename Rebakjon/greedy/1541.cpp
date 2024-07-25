#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// 55-50+40

using namespace std;

int main() {
    string formula;
    cin >> formula;

    string str_num;
    int result = 0;
    bool check = false;

    for(int i = 0; i <= formula.size(); i++) {
        if(formula[i] == '+' || formula[i] == '-' || i == formula.size()) { // 연산자를 만났거나 공식의 마지막을 만났을때
            if(check) { // 앞에 -가 있었다면
                result -= stoi(str_num);
                str_num = "";
            }
            else {
                result += stoi(str_num);
                str_num = "";
            }
        }

        else // 숫자라면
            str_num += formula[i];
        
        if(formula[i] == '-')
            check = true;
    }

    cout << result << endl;

    return 0;
}
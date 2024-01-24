// 두 수가 주어졌을 때, 다음 3가지 중 어떤 관계인지 구하는 프로그램을 작성하시오.
// 첫 번째 숫자가 두 번째 숫자의 약수이다. -> factor
// 첫 번째 숫자가 두 번째 숫자의 배수이다. -> multiple
// 첫 번째 숫자가 두 번째 숫자의 약수와 배수 모두 아니다. -> neither

#include <iostream>
#include <string>

int main() { 
    int a, b;
    std::string result;

    while(1) { 
        std::cin >> a >> b;
        if(a == 0 && b == 0) break;

        if(!(b % a)) {
            result = "factor";
        }
        else if(!(a % b)) {
            result = "multiple";
        }
        else{
            result = "neither";
        }
        
        std::cout << result << std::endl;

    }
}
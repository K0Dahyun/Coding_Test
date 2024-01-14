// 이와 같이 나열된 분수들을 1/1 → 1/2 → 2/1 → 3/1 → 2/2 → … 과 같은 지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.
// X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.

#include <iostream>

int main() {
    int c, a, b;
    int line = 1;

    std::cin >> c;

    while(c > line) {
        c -= line;
        line++;
    }

    if(!(line % 2)) { 
        a = c;
        b = line + 1 - c;
    }
    else {
        a = line + 1 - c;
        b = c;
    }

    std::cout << a << "/" << b << std::endl;


}
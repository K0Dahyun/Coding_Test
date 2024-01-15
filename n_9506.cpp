// 어떤 숫자 n이 자신을 제외한 모든 약수들의 합과 같으면, 그 수를 완전수라고 한다.
// 예를 들어 6은 6 = 1 + 2 + 3 으로 완전수이다.
// n이 완전수인지 아닌지 판단해주는 프로그램을 작성하라.

#include <iostream>
#include <vector>

int main() {
    int n, sum;
    std::vector<int> v;

    while(1) {
        n = 0;
        sum = 0;
        v.clear();

        std::cin >> n;
        if(n == -1) break;

        for(int i = 1; i < n; i++) {
            if(!(n % i)) {
                v.push_back(i);
                sum += i;
            }
        }

        if(sum == n) {
            std::cout << n << " = ";

            for(int i = 0; i < v.size() - 1; i++) {
                std::cout << v[i];
                std::cout << " + ";
            }

            std::cout << v.back() << std::endl;
        }
        else {
            std::cout << n << " is NOT perfect." << std::endl;
        }
    }
}
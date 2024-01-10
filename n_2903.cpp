#include <iostream>
#include <math.h>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    
    std::cout << std::fixed << (int)pow(pow(2,n) + 1, 2) << std::endl;

}
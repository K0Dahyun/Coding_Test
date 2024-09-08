#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(true) {
        int one, two, three;
        cin >> one >> two >> three;

        if(one == 0 || two == 0 || three == 0)
            break;

        if(one + two <= three || one + three <= two || two + three <= one)
            cout << "Invalid" << "\n";
        else if(one == two && two == three)
            cout << "Equilateral" << "\n";
        else if(one == two || one == three || two == three)
            cout << "Isosceles" << "\n";
        else
            cout << "Scalene" << "\n";
    }

    return 0;
}
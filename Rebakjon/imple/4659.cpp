#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool ismo(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(1) {
        string password;
        cin >> password;

        if(password == "end") break;

        bool acceptable = true;
        bool has_mo = false;
        int mo_continue_cnt = 0;
        int ja_continue_cnt = 0;

        for(int i = 0; i < password.size(); i++) {
            if(ismo(password[i])) {
                has_mo = true;
                mo_continue_cnt++;
                ja_continue_cnt = 0;
            }
            else {
                mo_continue_cnt = 0;
                ja_continue_cnt++;
            }

            if(mo_continue_cnt >= 3 || ja_continue_cnt >= 3) {
                acceptable = false;
                break;
            }

            if(i > 0 && password[i] != 'e' && password[i] != 'o' && password[i] == password[i - 1]) {
                acceptable = false;
                break;
            }
        }

        if(!has_mo)
            acceptable = false;

        if(acceptable)
            cout << "<" << password << "> is acceptable." << "\n";
        else
            cout << "<" << password << "> is not acceptable." << "\n";
    }

    return 0;
}
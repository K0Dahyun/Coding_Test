#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int light_n;
    cin >> light_n;

    vector<bool> light(light_n);
    for(int i = 0; i < light_n; i++) {
        int tmp;
        cin >> tmp;
        light[i] = tmp == 0 ? false : true;
    }
    
    int student_n;
    cin >> student_n;

    for(int i = 0; i < student_n; i++) {
        int sex, idx;
        cin >> sex >> idx;

        if(sex == 1) {
            for(int k = idx; k < light_n + 1; k += idx)
                light[k - 1] = !light[k - 1];
        }
        else {
            light[idx - 1] = !light[idx - 1];

            int left = idx - 2;
            int right = idx;

            while(1) {
                if(left < 0 || right >= light_n) break;

                if(light[left] == light[right]) {
                    light[left] = !light[left];
                    light[right] = !light[right];
                    
                    left--;
                    right++;
                }
                else break;
            }
        }
    }

    for(int i = 0; i < light_n; i++) {
        cout << light[i] << " ";
        if ((i + 1) % 20 == 0) cout << "\n";
    }
    
    return 0;
}
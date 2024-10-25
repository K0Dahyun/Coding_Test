#include <iostream>
#include <vector>

using namespace std;

int min_sum = 1e9;
int max_sum = -1e9;

int n;
int number[12];
int oper[4]; // + - * /

void dfs(int result, int idx) {
    if(idx == n) {
        max_sum = result > max_sum ? result : max_sum; 
        min_sum = result < min_sum ? result : min_sum;
        return;
    }

    for(int i = 0; i < 4; i++) {
        if(oper[i] > 0) {
            oper[i]--;
            if(i == 0) dfs(result + number[idx], idx + 1);
            else if(i == 1) dfs(result - number[idx], idx + 1);
            else if(i == 2) dfs(result * number[idx], idx + 1);
            else dfs(result / number[idx], idx + 1);

            oper[i]++;
        }
    }    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> number[i];
    
    for(int i = 0; i < 4; i++)
        cin >> oper[i];
    
    dfs(number[0], 1);

    cout << max_sum << endl << min_sum;

    return 0;
}
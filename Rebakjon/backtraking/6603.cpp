#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k;
int arr[6];
int inputs[13];

void dfs(int start, int depth) {
    if(depth == 6) {
        for(int i = 0; i < 6; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = start; i < k; i++) {
        arr[depth] = inputs[i];
        dfs(i + 1, depth + 1); 
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while(true) {
        cin >> k;
 
        if(k == 0) break;

        for(int i = 0; i < k; i++) 
            cin >> inputs[i];
        
        dfs(0, 0);

        cout << "\n";
    }

    return 0;
}
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int l, c;

vector<char> arr;
vector<char> inputs;

void dfs(int start, int depth, int mo, int ja) {
    if(depth == l) {
        if(mo >= 1 && ja >= 2) {
            for(int i = 0; i < l; i++)
                cout << arr[i];
            cout << "\n";
            return;
        }
    }

    for(int i = start; i < c; i++) {
        arr[depth] = inputs[i];
        if(inputs[i] == 'a' || inputs[i] == 'e' || inputs[i] == 'i' || inputs[i] == 'o' || inputs[i] == 'u')
            dfs(i + 1, depth + 1, mo + 1, ja);
        else
            dfs(i + 1, depth + 1, mo, ja + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> l >> c;

    arr.resize(l, 0);
    inputs.resize(c, 0);
    // visited.resize(c, false);

    for(int i = 0; i < c; i++)
        cin >> inputs[i];
    
    sort(inputs.begin(), inputs.end());

    dfs(0, 0, 0, 0);
}

// a t c i s w
// a c i t s w
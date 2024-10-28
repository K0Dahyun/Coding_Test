#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    char game;
    cin >> n >> game;

    unordered_set<string> s;

    for(int i = 0; i < n; i++) {
        string player;
        cin >> player;

        s.insert(player);
    }

    if(game == 'Y')
        cout << s.size();
    else if(game == 'F')
        cout << s.size() / 2;
    else
        cout << s.size() / 3;


    return 0;
}
#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, score, p;
    cin >> n >> score >> p;

    vector<int> rank;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        rank.push_back(input);
    }
    
    if(n == p && rank[n - 1] >= score) {
        cout << -1;
        return 0;
    }

    int tesu_rank = 1;
    for(int i = 0; i < n; i++) {
        if(rank[i] > score)
            tesu_rank++;
        else
            break;
    }
    
    cout << tesu_rank;

    return 0;
}
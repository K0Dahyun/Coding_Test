#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> person(n); // 몸무게, 키
    for(int i = 0; i < n; i++)
        cin >> person[i].first >> person[i].second;

    for(int i = 0; i < n; i++) {
        int rank = 0;
        for(int k = 0; k < n; k++) {
            if(person[i].first < person[k].first && person[i].second < person[k].second)
                rank++;
        }

        cout << rank + 1 << " ";
    }

    return 0;
}
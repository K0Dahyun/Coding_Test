#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int step_sum = 0;
    int total_sum = 0;
    for(int i = 0; i < n; i++) {
        step_sum += v[i];
        v[i] = step_sum;
        total_sum += v[i];
    }

    cout << total_sum << endl;
}
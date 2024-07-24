#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a;
    vector<int> b;

    for(int i = 0; i < n; i++) {
        int temp_a;
        cin >> temp_a;
        a.push_back(temp_a);
    }

    for(int i = 0; i < n; i++) {
        int temp_b;
        cin >> temp_b;
        b.push_back(temp_b);
    }
    
    int min_sum = 0;

    while(!a.empty()) {
        int a_max_index = max_element(a.begin(), a.end()) - a.begin();
        int b_min_index = min_element(b.begin(), b.end()) - b.begin();

        min_sum += *max_element(a.begin(), a.end()) * *min_element(b.begin(), b.end());
        a.erase(a.begin() + a_max_index);
        b.erase(b.begin() + b_min_index);
    }

    cout << min_sum << endl;
}
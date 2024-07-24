#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int number; // loop number
    cin >> number;

    vector<int> loop;
    for(int i = 0; i < number; i++) {
        int temp;
        cin >> temp;
        loop.push_back(temp);
    }

    sort(loop.begin(), loop.end());

    int max = loop[number - 1];

    for(int i = number - 1; i >= 0; i--) {
        int cur_weight = loop[i] * (number - i);
        if(cur_weight > max)
            max = cur_weight;
    }

    cout << max << endl;
}
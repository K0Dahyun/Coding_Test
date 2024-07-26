#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int num;
    cin >> num;

    deque<int> v(num);

    for(int i = 0; i < num; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int sum = 0;

    // 0과 음수를 처리
    while(!v.empty() && v.front() <= 0) {
        if(v.size() >= 2 && v[1] <= 0) { // 묶을 두번째 수가 있을때
            sum += v[0] * v[1];
            v.pop_front();
            v.pop_front();
        }
        else {
            sum += v[0];
            v.pop_front();
        }
    }

    while(!v.empty() && v.back() > 1) {
        if(v.size() >= 2 && v[v.size() - 2] > 1) {
            sum += v.back() * v[v.size() - 2];
            v.pop_back();
            v.pop_back();
        }
        else {
            sum += v.back();
            v.pop_back();
        }
    }

    // 남은 1 처리
    while(!v.empty()) {
        sum += v.back();
        v.pop_back();
    }

    cout << sum << endl;

    return 0;
}
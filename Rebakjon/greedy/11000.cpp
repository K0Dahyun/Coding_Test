#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> lectures;

    for(int i = 0; i < n; i++) {
        int temp_start, temp_finish;
        cin >> temp_start >> temp_finish;
        lectures.push_back({temp_start, temp_finish});
    }

    sort(lectures.begin(), lectures.end());

    priority_queue<int, vector<int>, greater<int>> finish; // 빨리 끝나는 시간을 담은 큐
    finish.push(lectures[0].second);

    for(int i = 1; i < lectures.size(); i++) {
        if(lectures[i].first >= finish.top())
            finish.pop();

        finish.push(lectures[i].second);
    }

    cout << finish.size() << endl;

    return 0;
}
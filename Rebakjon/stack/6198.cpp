#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// 내 건물이 바라볼 수 있는 빌딩의 수가 아닌
// 내 건물을 바라볼 수 있는 빌딩의 수를 세는 문제
// 스택을 사용해서 내림차순으로 정렬하면 내 건물을 바라볼 수 있는 건물들만 남음

int main() {
    int n;
    cin >> n;

    stack<int> s;
    long long sum = 0;

    for(int i = 0; i < n; i++) {
        int cur_building;
        cin >> cur_building;

        while(!s.empty() && s.top() <= cur_building)
            s.pop();
        
        sum += s.size();

        s.push(cur_building);
    }

    cout << sum << endl;

    return 0;
}
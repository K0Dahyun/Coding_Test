#include <vector>
#include <iostream>

using namespace std;

int n;
int answer = 0;
vector<int> visited(15); // 행(퀸 번호) - 열

bool check(int q_cnt) {
    for(int i = 0; i < q_cnt; i++) {
        // 어쩌피 행은 순차적으로 돌아가고, 열이 같은데 대각선으로 같은지 확인하면 됌
        if(visited[q_cnt] == visited[i] || q_cnt - i == abs(visited[q_cnt] - visited[i]));
            return false;
    }
    return true;
}

void n_queen(int q_cnt) {
    if(q_cnt == n) { // 퀸 다 둠
        answer++;
        return;
    }

    for(int k = 0; k < n; k++) {
        visited[q_cnt] = k;

        if(check(q_cnt))
            n_queen(q_cnt + 1);
    }
}

int main() {
    cin >> n;
    n_queen(0);
    cout << answer;
}
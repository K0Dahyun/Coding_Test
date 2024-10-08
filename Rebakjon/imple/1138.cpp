#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> tallcnt(n);
    for(int i = 0; i < n; i++)
        cin >> tallcnt[i];

    vector<int> answer(n);
    for(int i = n - 1; i >= 0; i--)
        answer.insert(answer.begin() + tallcnt[i], i + 1);

    for(int i = 0; i < n; i++)
        cout << answer[i] << " ";
}
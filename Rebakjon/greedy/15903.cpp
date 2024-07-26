#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    long long n, m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long>> cards;

    for(int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        cards.push(temp);
    }
         
    while(m--) {
        long long first_min = cards.top();
        cards.pop();
        long long second_min = cards.top();
        cards.pop();

        long long new_value = first_min + second_min;

        cards.push(new_value);
        cards.push(new_value);
    }

    long long sum = 0;

    while(!cards.empty()) {
        sum += cards.top();
        cards.pop();
    }

    cout << sum << endl;

    return 0;
}
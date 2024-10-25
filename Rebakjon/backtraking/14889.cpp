#include <iostream>
#include <vector>

using namespace std;

int n;
int point[21][21];
bool team[21]; // true - start, false - link
int ans = 1e9;

int calculateScore(int cur, bool flag) {
    int sum = 0;
    
    for(int i = 0; i < cur; i++) {
        if(team[i] == flag) {
            sum += point[i][cur];
            sum += point[cur][i];
        }
    }

    return sum;
}

void dfs(int cur, int depth) {
    if(depth == n / 2) { // if finish dividing team, have to calculate score
        int start_score = 0, link_score = 0;

        for(int i = 0; i < n; i++) { // find who is start and link member, and calculate score
            if(team[i]) start_score += calculateScore(i, team[i]);
            else link_score += calculateScore(i, team[i]);
        }

        ans = min(ans, abs(start_score - link_score));
        return;
    }

    // divide team
    for(int i = cur; i < n; i++) {
        if(team[i] == false) {
            team[i] = true;
            dfs(i, depth + 1);
            team[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++)
            cin >> point[i][k];
    }

    dfs(0, 0);

    cout << ans << endl;

    return 0;
}
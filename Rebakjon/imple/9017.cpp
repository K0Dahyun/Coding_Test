#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> race(n);
        map<int, int> teamCount; // team, count

        // counting and input
        for(int i = 0; i < n; i++) {
            cin >> race[i];
            teamCount[race[i]]++;
            race.push_back(i);
        }
        
        vector<int> teamScore[201];
        int idx = 1;

        // collect team score
        for(int i = 0; i < n; i++) {
            if(teamCount[race[i]] == 6) {
                teamScore[race[i]].push_back(idx);
                idx++;
            }
        }

        int winner = -1;
        int winScore = 1e9;
        int five = -1;

        // 
        for(int i = 1; i < 201; i++) {
            int tmp = 0;

            if(teamScore[i].size() == 6) {
                // sum score
                for(int k = 0; k < 4; k++)
                    tmp += teamScore[i][k];
                
                // find new mininum score
                if(tmp < winScore) {
                    winScore = tmp;
                    winner = i;
                    five = teamScore[i][4];
                }

                // if score same, have to compare 5 place score
                if(tmp == winScore && teamScore[i][4] < five) {
                    winner = i;
                    five = teamScore[i][4];
                }
            }
        }

        cout << winner << "\n";
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> map;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    map.resize(n, vector<char>(n));

    bool find_head = false;
    pair<int, int> heart;

    // input and find heart
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++) {
            cin >> map[i][k];
            
            if(!find_head && map[i][k] == '*') {
                find_head = true;
                heart = {i + 1, k};
            }
        }
    }

    cout << heart.first + 1 << " " << heart.second + 1 << "\n";

    // left arm
    int left_arm_length = 0;
    int left_arm = heart.second - 1; // col
    while(1) {
        if(map[heart.first][left_arm] != '*') break;
        
        left_arm_length++;
        left_arm--;
    }

    // right arm
    int right_arm_length = 0;
    int right_arm = heart.second + 1; // col
    while(1) {
        if(map[heart.first][right_arm] != '*') break;
        
        right_arm_length++;
        right_arm++;
    }


    // waist
    int waist_length = 0;
    int waist = heart.first + 1; // col
    while(1) {
        if(map[waist][heart.second] == '_') break;
        
        waist_length++;
        waist++;
    }


    // left leg
    int right_arm_length = 0;
    int right_arm = heart.second + 1; // col
    while(1) {
        if(map[heart.first + 1][right_arm] != '*') break;
        
        right_arm_length++;
        right_arm++;
    }




    cout << left_arm_length << " " << right_arm_length << "\n";

    return 0;

}
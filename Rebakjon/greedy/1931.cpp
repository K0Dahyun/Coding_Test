#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num;
    cin >> num;
    
    vector<pair<int, int>> meeting; // finish, start
    for(int i = 0; i < num; i++) {
        int start, finish;
        cin >> start >> finish;
        meeting.push_back({finish, start});
    }
    
    sort(meeting.begin(), meeting.end());
    
    int number_meeting = 0;
    int cur_finish = 0;
        
    for(auto itr = meeting.begin(); itr != meeting.end(); itr++) {
        if(itr->second >= cur_finish) {
            number_meeting++;
            cur_finish = itr->first;
        }
    }
    
    cout << number_meeting << endl;
    
    return 0;
}
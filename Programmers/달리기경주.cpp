#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer(players);
    map<string, int> m; // 등수 - 사람
    int locate;

    for(int i = 0; i < players.size(); i++) {
        m[players[i]] = i;
    }
    
    for (int i = 0; i < callings.size(); i++) {
        locate = m[callings[i]]; // 불린 사람의 등수
        m[answer[locate - 1]]++; // 불린 사람 보다 바로 앞에 있는 사람의 등수를 낮춤
        m[callings[i]]--; // 불린 사람의 등수를 높힘

        swap(answer[locate], answer[locate - 1]);
    }

    return answer;
} 
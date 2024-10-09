#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1e9

using namespace std;

vector<vector<pair<int, int>>> graph; // start, end, len

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, d;
    cin >> n >> d;

    graph.resize(d + 1);

    // input
    for(int i = 0; i < n; i++) {
        int start, end, len;
        cin >> start >> end >> len;

        // len이 되려 더 길때, 지름길이 아닐 경우
        if(len > end - start) continue;
        
        // end이 d 이상일 경우
        if(end > d) continue;

        graph[start].push_back({end, len});
    }
    
    // dp
    vector<int> distarr(d + 1, MAX);

    distarr[0] = 0;

    for(int i = 0; i <= d; i++) {
        // 이전값에서 한번더 가는게 빠른지, 이전에 계산한 지름길이 빠른지
        if(i) 
            distarr[i] = min(distarr[i], distarr[i - 1] + 1);
        
        // 현재 위치에서  
        for(auto& elem : graph[i])
            distarr[elem.first] = min(distarr[elem.first], distarr[i] + elem.second);
    }

    cout << distarr[d] << endl;

    return 0;
}
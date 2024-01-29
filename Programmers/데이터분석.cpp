#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    map<string, int> mapset;

    mapset.insert({ "code", 0 });
    mapset.insert({ "date", 1 });
    mapset.insert({ "maximum", 2 });
    mapset.insert({ "remain", 3 });

    for (int i = 0; i < data.size(); i++) {
        if (data[i][mapset[ext]] < val_ext) {
            answer.push_back(data[i]);
        }
    }
    
    int index = mapset[sort_by];
    sort(answer.begin(), answer.end(), [index](const vector<int>& a, const vector<int>& b) {
        return a[index] < b[index];
    }); 
    
    return answer;
}
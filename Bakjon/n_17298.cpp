#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int count;
    cin >> count;

    int input;
    vector<int> inputs;
    for(int i = 0; i < count; i++) {
        cin >> input;
        inputs.push_back(input);
    }

    stack<int> s;
    vector<int> answers(count, -1);
    for(int i = 0; i < count; i++) {
        while(!s.empty() && inputs[i] > inputs[s.top()]) {
            int index = s.top();
            s.pop();
            answers[index] = inputs[i];
        }
        s.push(i);
    }

    for(int i = 0; i < answers.size(); i++) {
        cout << answers[i] << " ";
    }

    return 0;
}
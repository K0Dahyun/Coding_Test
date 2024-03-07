#include <vector>
#include <map>
#include <iostream>

using namespace std;


// [100,180,360,100,270]
// 1:1, 2:3, 2:4, 3:4 

// int gcd(int a, int b) {
//     if(b == 0) return a;
//     return gcd(b, a % b);
// }

// void swap(int &a, int &b) {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// long long solution(vector<int> weights) {
//     long long answer = 0;
//     int div, num1, num2;
//     map<int, int> ratio;
//     ratio.insert({1, 2});
//     ratio.insert({2, 3});
//     ratio.insert({3, 4});

//     for(int i = 0; i < weights.size() - 1; i++) {
//         for(int j = i + 1; j < weights.size(); j++) {
//             if(weights[i] == weights[j]) {
//                 answer++;
//                 continue;
//             }

//             div = gcd(weights[i], weights[j]);
//             num1 = weights[i] / div;
//             num2 = weights[j] / div;

//             if(num1 > num2) swap(num1, num2);

//             if(ratio[num1] == num2) {
//                 answer++;
//             }
//         }
//         cout <<endl;
//     }

//     return answer;
// }

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<int int> counts;

    for(int i = 0; i < weights.size(); i++)
        counts[weights[i]]++;
    
    for(int i = 100; i < counts.size(); i++) {
        if(counts[i] >= 2)
            answer+=(counts[i] * counts[i] - 1) / 2;
    }

    for(int i = 0; i < weights.size(); i++) {
        if(weights[i] % 2 == 0) 
            answer+=counts[weights[i]/ 2 * 3];

        if(weights[i] % 3 == 0) 
            answer+=counts[weights[i]/ 3 * 4];

        answer += counts[weights[i] * 2];
    }


    return answer;
}
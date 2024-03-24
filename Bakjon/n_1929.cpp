#include <cstdio>
#include <vector>

int main() {
    int s, d;
    scanf("%d %d", &s, &d);
    vector<int> v(d + 1, 0);

    for(int i = 2; i <= d; i++) {
        v[i] = i;
    }

    for(int i = 2; i * i <= d; i++) {
        if(v[i] == 0) continue; //이미 소수라면 pass
        for(int j = 2 * i; j <= d; j += i) {
            if(v[j] == 0) continue;
            v[j] = 0;
        }
    }

    for(int i = s; i <= d; i++) {
        if(v[i] == 0) printf("%d\n", v[i]);
    }
    
    return 0;

}
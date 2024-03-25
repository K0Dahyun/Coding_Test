#include <cstdio>

using namespace std;

int main() {
    int v;
    scanf("%d", &v);

    for(int i = 2; i * i <= v; i++) {
        while(v % i == 0) {
            printf("%d\n", i);
            v /= i;
        }
    }

    if(v > 1) printf("%d\n", v);

    return 0;    
}
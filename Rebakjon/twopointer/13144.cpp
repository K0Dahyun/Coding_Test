    #include <iostream>
    #include <vector>
    using namespace std;

    bool visited[100001];

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        long long n;
        cin >> n;

        vector<long long> v(n + 1);

        for(long long i = 0; i < n; i++)
            cin >> v[i];
        
        int start = 0;
        int end = 1;
        visited[v[start]] = true;

        long long answer = n * (n + 1) / 2;

        while(end < n) {
            if(visited[v[end]]) {
                visited[v[start++]] = false;
                answer -= n - end;
            }
            else
                visited[v[end++]] = true;
        }

        cout << answer;

        return 0;
    }
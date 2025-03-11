#include <bits/stdc++.h>
using namespace std;

int main() {
    long n; 
    cin >> n;
    
    if (n == 0) {
        cout << 0 << endl;
    } else if (n <= 2) {
        cout << 1 << endl;
    } else if (n == 3) {
        cout << 2 << endl;
    } else {
        vector<long> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;

        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
        }
        cout << dp[n] << endl;
    }
    
    return 0;
}

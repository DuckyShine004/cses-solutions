#include <iostream>

using namespace std;

const int N = 6;
const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    long long k;
    long long dp[n + 1];

    dp[0] = 1;

    for (int x = 1; x <= n; x++) {
        k = 0;

        for (int i = 1; i <= N; i++) {
            if (x - i >= 0) {
                k += dp[x - i];
            }
        }

        dp[x] = k % MOD;
    }

    cout << dp[n];
}
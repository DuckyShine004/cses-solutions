#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    
    for (int &coin : coins) {
        cin >> coin;
    }

    long long k;
    long long dp[x + 1];

    dp[0] = 1;

    for (int i = 1; i <= x; i++) {
        k = 0;

        for (int coin : coins) {
            if (i - coin >= 0) {
                k += dp[i - coin];
            }
        }

        dp[i] = k % MOD;
    }

    cout << dp[x];
}
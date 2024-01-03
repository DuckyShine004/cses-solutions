#include <iostream>
#include <vector>
#include <cstring>

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

    long long dp[x + 1];

    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    for (int coin : coins) {
        for (int j = coin; j <= x; j++) {
            dp[j] = (dp[j] + dp[j - coin]) % MOD;
        }
    }

    cout << dp[x];
}
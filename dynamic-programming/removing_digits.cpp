#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n;

    vector<long long> dp(n + 1, INF);
    dp[0] = 0;

    for (int x = 1; x <= n; x++) {
        string digits = to_string(x);

        for (char d : digits) {
            k = x - ((int) d - 48);

            if (k >= 0) {
                dp[x] = min(dp[x], dp[k] + 1);
            }
        }
    }

    cout << dp[n];
}
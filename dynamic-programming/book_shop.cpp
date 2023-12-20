#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1001;
const int MAX_X = 100001;

int dp[MAX_N][MAX_X];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> H(n), S(n);

    for (int &h : H) {
        cin >> h;
    }

    for (int &s : S) {
        cin >> s;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];

            if (H[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], S[i - 1] + dp[i - 1][j - H[i - 1]]);
            }
        }
    }

    cout << dp[n][x];
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int N = 5001;

int dp[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s, t;
    cin >> s >> t;

    int m = s.length();
    int n = t.length();

    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = INF;
            dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (s[i - 1] != t[j - 1])});
        }
    }

    cout << dp[m][n];
}

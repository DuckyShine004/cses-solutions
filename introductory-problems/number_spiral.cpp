#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
    ll x, y;
    cin >> y >> x;

    ll n = max(x, y);
    ll m = n - 1;
    ll k = (m * (m + 1)) + 1;
    ll r = 2 * m;

    if (x == y) {
        cout << k << "\n";
        return;
    }

    if (r % 4 == 0) {
        cout << (x > y ? k + (n - y) : k - (n - x)) << "\n";
    } else {
        cout << (x > y ? k - (n - y) : k + (n - x)) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
}
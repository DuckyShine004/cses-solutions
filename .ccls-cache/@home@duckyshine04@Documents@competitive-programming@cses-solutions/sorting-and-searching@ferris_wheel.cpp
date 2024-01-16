#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> P(n);

    for (int &p : P) {
        cin >> p;
    }

    sort(P.begin(), P.end());

    int k, res;

    k = 0;
    res = 1;

    for (int p : P) {
        k += p;

        if (k > x) {
            k = p;
            res++;
        }
    }

    cout << res;
}

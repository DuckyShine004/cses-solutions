#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k, a, b;
    cin >> n >> m >> k;

    set<int> seen;

    vector<int> A(n);
    vector<int> B(m);

    for (int &a : A) {
        cin >> a;
    }

    for (int &b : B) {
        cin >> b;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int res = 0;

    for (int i = 0; i < n; i++) {
        a = A[i];

        for (int j = 0; j < m; j++) {
            b = B[j];

            if (b >= a - k && b <= a + k && seen.find(j) == seen.end()) {
                seen.insert(j);
                res++;

                break;
            }
        }
    }

    cout << res;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, l, r, mid;
    cin >> n;

    vector<int> lis;

    for (int i = 0; i < n; i++) {
        cin >> k;

        if (lis.empty() || k > lis.back()) {
            lis.push_back(k);
        } else {
            l = 0;
            r = lis.size() - 1;

            while (l < r) {
                mid = l + ((r - l) / 2);

                if (lis[mid] < k) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }

            lis[l] = k;
        }
    }

    cout << lis.size();
}
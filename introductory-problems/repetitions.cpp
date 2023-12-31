#include <iostream>
#include <string.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    int l = 0;
    int n = s.size();

    int res = 0;

    while (l < n) {
        int r = l;

        while (r < n && s[l] == s[r]) {
            r++;
        }

        res = max(res, r - l);
        l = r;
    }

    cout << res;
}
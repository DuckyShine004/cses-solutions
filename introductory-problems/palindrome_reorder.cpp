#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, e, o;
    cin >> s;

    int n = s.size();
    int l = 0;
    int r = n - 1;

    map<char, int> cmap;
    int odds = 0;

    for (char c : s) {
        cmap[c]++;
    }

    for (const auto &p : cmap) {
        if (p.second & 1) {
            o += string(p.second, p.first);
            odds++;
        } else {
            e += string(p.second, p.first);
        }
    }

    if (odds > 1) {
        cout << "NO SOLUTION";
        return 0;
    }

    s = e + o;
    string t(n, ' ');

    for (int i = 0; i < n; i++) {
        if (i & 1) {
            t[r--] = s[i];
        } else {
            t[l++] = s[i];
        }
    }

    cout << t;
}
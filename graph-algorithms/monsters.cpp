#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using namespace std::chrono;

#define f first
#define s second
#define ppb pop_back
#define psb push_back
#define forinc(i, a, b) for (int i = a; i <= b; i++)
#define fordec(i, a, b) for (int i = a; i >= b; i--)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define len(a) (a).length()
#define sz(a) (a).size()
#define vec1(type, n) vector<type>(n)
#define vec2(type, n, m) vector<vector<type>>((n), vector<type>((m)))
#define lsh(a) (1 << (a));
#define str(a) to_string(a)
#define ft front()
#define bk back()
#define all(a) (a).begin(), (a).end()
#define fastio()                                                               \
    (ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr),    \
     cerr.tie(nullptr));
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

// clang-format off
#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %ld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )
// clang-format on

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFLL = LLONG_MAX;
const pii d4[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const pii d8[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                   {0, 1},   {1, -1}, {1, 0},  {1, -1}};

template <typename T> void print_soln(const T &x) {
    for (auto it = x.begin(); it != x.end();) {
        cout << *it;
        if (++it != x.end())
            cout << " ";
    }

    cout << "\n";
}

template <typename T> T gcd(T a, T b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int recur_depth = 0;

// clang-format off
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
// clang-format on
#else
#define dbg(x)
#endif
template <typename Ostream, typename Cont>
typename enable_if<is_same<Ostream, ostream>::value, Ostream &>::type
operator<<(Ostream &os, const Cont &v) {
    os << "[";
    for (auto &x : v) {
        os << x << ", ";
    }

    return os << "]";
}
template <typename Ostream, typename... Ts>
Ostream &operator<<(Ostream &os, const pair<Ts...> &p) {
    return os << "{" << p.first << ", " << p.second << "}";
}

class UnionFind {
  public:
    vi reps;
    vi rank;

    UnionFind(int n) : reps(n), rank(n, 0) {
        FOR(i, 0, n) { reps[i] = i; }
    }

    int find(int x) {
        while (x != reps[x]) {
            reps[x] = reps[reps[x]];
            x = reps[x];
        }

        return x;
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) {
            return;
        }

        if (rank[x] > rank[y]) {
            reps[y] = x;
        } else {
            reps[x] = y;

            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
};

struct pnt2 {
    int x;
    int y;
};

struct pnt3 {
    int x;
    int y;
    int z;
};

bool is_valid(vs &arr, vvb &seen, int x, int y, int m, int n) {
    if (x < 0 || x >= m) {
        return false;
    }

    if (y < 0 || y >= n) {
        return false;
    }

    if (seen[x][y]) {
        return false;
    }

    return arr[y][x] == '.';
}

bool is_dst_valid(pii u, int m, int n) {
    return u.f == 0 || u.f == m - 1 || u.s == 0 || u.s == n - 1;
}

char get_direction(pii a, pii b) {
    if (b.s - a.s > 0) {
        return 'U';
    }

    if (b.s - a.s < 0) {
        return 'D';
    }

    if (b.f - a.f > 0) {
        return 'L';
    }

    return 'R';
}

void bfs(vs &arr, vvb &seen, queue<pii> &mst, pii src, int m, int n) {
    queue<pii> q;
    map<pii, pii> p;

    q.push(src);
    seen[src.f][src.s] = true;
    p[src] = {-1, -1};

    bool flag = false;
    string res;
    pii dst;

    int k, dx, dy;

    while (!q.empty()) {
        k = sz(mst);

        FOR(i, 0, k) {
            pii cur = mst.ft;
            mst.pop();

            for (pii d : d4) {
                dx = d.f + cur.f;
                dy = d.s + cur.s;

                if (is_valid(arr, seen, dx, dy, m, n)) {
                    mst.push({dx, dy});
                    seen[dx][dy] = true;
                }
            }
        }

        k = sz(q);

        FOR(i, 0, k) {
            pii u = q.ft;
            q.pop();

            if (is_dst_valid(u, m, n)) {
                flag = true;
                dst = u;
                break;
            }

            for (pii d : d4) {
                dx = d.f + u.f;
                dy = d.s + u.s;

                if (is_valid(arr, seen, dx, dy, m, n)) {
                    q.push({dx, dy});
                    seen[dx][dy] = true;
                    p[{dx, dy}] = u;
                }
            }
        }
    }

    if (!flag) {
        cout << "NO";
        return;
    }

    pii cur = dst;

    while (cur != src) {
        res += get_direction(cur, p[cur]);
        cur = p[cur];
    }

    reverse(all(res));

    cout << "YES\n" << len(res) << "\n" << res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vs arr(n);
    vvb seen = vec2(bool, m, n);
    queue<pii> mst;

    int i = 0;
    pii src;

    for (string &s : arr) {
        cin >> s;

        FOR(j, 0, m) {
            if (s[j] == 'A') {
                src = {j, i};
            }

            if (s[j] == 'M') {
                seen[j][i] = true;
                mst.push({j, i});
            }
        }

        i++;
    }

    bfs(arr, seen, mst, src, m, n);
}

int main() {
    fastio();

    int t = 1;
    // cin >> t;

#ifdef DEBUG
    while (t--) {
        time__("Time") { solve(); }
    }
#else
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    while (t--) {
        solve();
    }
#endif
}

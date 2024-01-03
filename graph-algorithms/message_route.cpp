#include <algorithm>
#include <chrono>
#include <cmath>
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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
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

bool seen[MAX_N];

void bfs(vector<vector<int>> &adj, int n) {
    int dst = n - 1;

    queue<int> q;
    map<int, int> p;

    q.push(0);
    seen[0] = true;

    p[0] = -1;
    bool flag = false;

    vi res;

    while (!q.empty()) {
        int u = q.ft;
        q.pop();

        if (u == dst) {
            flag = true;
            break;
        }

        for (int v : adj[u]) {
            if (seen[v]) {
                continue;
            }

            q.push(v);
            seen[v] = true;
            p[v] = u;
        }
    }

    if (!flag) {
        cout << "IMPOSSIBLE";
        return;
    }

    int cur = dst;

    while (cur != -1) {
        res.psb(cur);
        cur = p[cur];
    }

    reverse(all(res));

    cout << sz(res) << "\n";

    for (int a : res) {
        cout << a + 1 << " ";
    }
}

void solve() {
    int n, m, a, b;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    FOR(i, 0, m) {
        cin >> a >> b;
        adj[a - 1].psb(b - 1);
        adj[b - 1].psb(a - 1);
    }

    bfs(adj, n);
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

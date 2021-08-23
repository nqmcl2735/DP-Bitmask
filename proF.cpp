//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo INT_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 100005
#define MOD
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, m, k;
ll dp[maxn][35];
int clr[maxn];
vi ke[maxn];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++) {
        cin >> clr[i];
        dp[i][1 << (clr[i] - 1)] = 1;
    }
    for (int i = 1; i <= m; i ++)
    {
        int u, v;
        cin >> u >> v;
        if (clr[u] != clr[v]) {
            ke[u].PB(v);
            ke[v].PB(u);
        }
    }
    for (int x = 1; x < (1 << k); x ++)
        for (int u = 1; u <= n; u ++)
            for (int v : ke[u])
                if (x >> (clr[u] - 1) & 1 && x >> (clr[u] - 1) & 1)
                dp[u][x] += dp[v][x - (1 << (clr[u] - 1))];
    ll res = 0;
    for (int i = 1; i <= n; i ++)
        for (int x = 1; x < (1 << k); x ++)
            if(x != 1 << (clr[i] - 1))
                res += dp[i][x];
    cout << res;
}

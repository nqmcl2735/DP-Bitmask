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
int n;
ll a[25][25];
ll dp[1 << 20];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) cin >> a[i][j];
    dp[0] = 0;
    reset(dp, 0);
    for (int x = 1; x < (1 << n); x ++)
    {
        int k = __builtin_popcount(x);
        for (int i = 1; i <= n; i ++)
            if ((x >> (i - 1)) & 1) dp[x] = max(dp[x], dp[x - (1 << (i - 1))] + a[i][k]);
    }
    cout << dp[(1 << n) - 1];
}

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
int n, k;
ll dp[20][1 << 15];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> k;
    for (int i = 0; i < n; i ++)
        dp[i][1 << i] = 1;
    for(int x = 0; x < (1 << n); x ++)
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                if((i != j) && (x >> j) & 1 && (x >> i) & 1 && (abs(i - j) <= k))
                    dp[i][x] += dp[j][x - (1 << i)];
    ll res = 0;
    for (int i = 0; i < n; i ++)
        res += dp[i][(1 << n) - 1];
    cout << res;
}

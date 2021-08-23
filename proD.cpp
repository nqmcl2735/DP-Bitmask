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
#define Task "proD"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, m;
string a[20];
int s[20], cost[20][20];
int dp[20][1 << 15];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m;
    for (int i = 0; i < m; i ++)
        cin >> a[i];
    for (int i = 0; i < m - 1; i ++)
        for (int j = i + 1; j < m; j ++)
            for (int z = 0; z < n; z ++)
            {
                cost[i][j] += (a[i][z] != a[j][z]);
                cost[j][i] += (a[i][z] != a[j][z]);
            }
    for (int i = 0 ; i < m; i ++)
        for (int j = 0; j < n; j ++) s[i] += (a[i][j]=='1');
    reset(dp, 60);
    for (int i = 0; i < m; i ++)
        dp[i][1 << i] = s[i];
    for(int x = 0; x < (1 << m); x ++)
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < m; j ++)
                if(i != j && (x >> j) & 1 && (x >> i) & 1)
                    dp[i][x] = min(dp[i][x], dp[j][x - (1 << i)] + cost[i][j]);
    int res = oo;
    for (int i = 0; i < m; i ++)
        res = min(res, dp[i][(1 << m) - 1]);
    cout << res;
}

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
#define Task "proR"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n;
int b[25];
int vitri1[25];
ll dp[1 << 20];
int truoc[25];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        x --;
        vitri1[x] = i;
    }
    for (int i = 1; i <= n; i ++)
    {
        cin >> b[i];
        b[i] --;
        for (int j = 1; j < i; j ++)
            if (vitri1[b[j]] < vitri1[b[i]]) truoc[b[j]] += (1 << b[i]) ;
    }
    for(int i = 0; i < n; i ++) dp[1 << i] = 1;
    for(int x = 0; x < 1 << n; x ++)
        for(int i = 0; i < n; i ++)
            if(!(x >> i & 1) && !(x & truoc[i])) dp[x + (1 << i)] += dp[x];
    cout << dp[(1 << n) - 1];
}


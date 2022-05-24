#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
/*-----define-----*/
#define jizz ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ALL(X) (X).begin(), (X).end()
#define REP(I,N) for(int I=0;I<(N);I++)
#define REP1(I,N,M) for(int I=(N);I<(M);I++)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(), c.end(),x)-c.begin())
#define pb emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define LEN(X) strlen((X))
#define F first
#define S second
#define LB lower_bound
#define UP upper_bound
#define CN cout<<"\n"
#define maxE(x) (*max_element((x).begin(), (x).end()))
#define minE(x) (*min_element((x).begin(), (x).end()))
#define INF 0x3f3f3f3f
#define NINF 0xc0c0c0c0
/*-----typedef-----*/
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
signed main() {
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int a, b, flag, tc = 0;
    while(1) {
        map<int, int> mp;
        int v[1005][1005];
        memset(v, INF, sizeof(v));
        REP(i, 1005) v[i][i] = 0;
        while(cin >> a >> b && a != 0 && b != 0) {
            if(mp.find(a) == mp.end()) {
                flag = mp.size();
                mp[a] = flag;
            }
            if(mp.find(b) == mp.end()) {
                flag = mp.size();
                mp[b] = flag;
            }
            v[mp[a]][mp[b]] = 1;
        }
        int vnum = mp.size(), tot = 0;
        if(vnum==0) break;
        REP(k, vnum) REP(i, vnum) REP(j, vnum) v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
        REP(i, vnum) REP(j, vnum) tot += v[i][j];
        printf("Case %d: average length between pages = %.3lf clicks\n",++tc,(double)tot / (double)(vnum * (vnum - 1)));
    }

    return 0;
}
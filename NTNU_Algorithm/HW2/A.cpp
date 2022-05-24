#pragma GCC optimize ("O2")
#include<bits/stdc++.h>
#pragma region define/typedef
/*-----define-----*/
#define jizz ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ALL(X) (X).begin(), (X).end()
#define REP(I,N) for(int I=0;I<(N);I++)
#define REP1(I,N,M) for(int I=(N);I<(M);I++)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(), c.end(),x)-c.begin())
#define MS0(X) memset((X), 0, sizeof((X)))
#define maxE(x) (*max_element((x).begin(), (x).end()))
#define minE(x) (*min_element((x).begin(), (x).end()))
#define INF 0x3f3f3f3f
#define NINF 0xc0c0c0c0
/*-----typedef-----*/
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
#pragma endregion
inline char readchar() {
	const int S = 1<<20; // buffer size
	static char buf[S], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
	return *p++;
}
inline void input(int &_x){
    _x = 0;
    int _tmp = 1; char _tc = readchar();
    while((_tc < '0' || _tc > '9') && _tc != '-') _tc = readchar();
    if(_tc == '-') _tc = readchar(), _tmp = -1;
    while(_tc >= '0' && _tc <= '9') _x = _x*10+(_tc-48), _tc = readchar();
    _x *= _tmp;
}
int cost[2005], weight[3005], number[2005], c[3005];
void knapsack(int n, int w) {
    for (int i = 0; i < n; ++i) {
        int num = min(number[i], w / weight[i]);
        for (int k = 1; num > 0; k *= 2) {
            if (k > num) k = num;
            num -= k;
            for (int j = w; j >= weight[i] * k; --j)
                c[j] = max(c[j], c[j - weight[i] * k] + cost[i] * k);
        }
    }
    cout << c[w] << "\n";
}
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n,w;
    input(n);
    input(w);
    REP(i,n){
        input(weight[i]);
        input(cost[i]);
        input(number[i]);
    }
    knapsack(n,w);
    return 0;
}
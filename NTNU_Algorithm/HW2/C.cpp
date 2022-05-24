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
#define getchar getchar_unlocked
#define fread fread_unlocked
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
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n;
    input(n);
    PII treasurePosition[n+5];
    int arr[n+5];
    vector<int> dp;
    REP(i,n){
        input(treasurePosition[i].first);
        input(treasurePosition[i].second);
    }
    sort(treasurePosition,treasurePosition+n);
    REP(i,n) arr[i]=treasurePosition[i].second;
    dp.emplace_back(arr[0]);
    REP1(i,1,n){
        int tmp=arr[i];
        if(tmp>dp.back()) dp.emplace_back(tmp);
        else *lower_bound(dp.begin(),dp.end(),tmp)=tmp;
    }
    cout << dp.size() << "\n";
    return 0;
}
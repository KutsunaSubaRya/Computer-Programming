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
vector<int> v[3005];
int vis[3005],ansPosition,ansSum;
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
void dfs(int now,int sum){
    vis[now]=1;
    for(auto x:v[now]){
        if(vis[x]==0){
            vis[x]=1;
            dfs(x,sum+1);
        }
    }
    if(sum>ansSum){
        ansPosition=now;
        ansSum=sum;
    }
}
void dfsLex(int now){
    cout << now << " ";
    vis[now]=1;
    for(auto x:v[now]){
        if(vis[x]==0){
            vis[x]=1;
            dfsLex(x);
        }
    }
}
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int N,cycleRange;
    input(N); input(cycleRange);
    int a,b;
    REP(i,N-1){
        input(a); input(b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    int root=1;
    ansPosition=1;ansSum=0;
    MS0(vis);
    dfs(root,0);
    MS0(vis);
    dfs(ansPosition,0);
    int treeDiameter=ansSum;
    if(treeDiameter>cycleRange*2){
        cout << "-1\n";
        return 0;
    }
    REP1(i,1,N+1){
        sort(ALL(v[i]));
    }
    int nodeMaxLength[N+5];
    REP1(i,1,N+1){
        ansSum=0;
        MS0(vis);
        dfs(i,0);
        if(ansSum<=cycleRange){
            MS0(vis);
            dfsLex(i);
            break;
        }
    }
    cout << "\n";
    return 0;
}
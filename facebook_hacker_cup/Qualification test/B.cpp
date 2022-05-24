#pragma GCC optimize ("O2")
#include<bits/stdc++.h>
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
char mp[100][100];
int mp_num[2][100],N,fl=0;
void init(void){
    REP(i,100) REP(j,100) mp[i][j]='.';
    REP(i,2) REP(j,100) mp_num[i][j]=0;
}
void Solve(void){
    int lo_min=INF,meth=0;
    REP(i,N){
        int tmp=0,det=0;
        REP(j,N){
            if(mp[i][j]=='O') det=1;
            else if(mp[i][j]=='.') tmp++;
        }
        if(det==1) tmp=INF;
        mp_num[0][i]=tmp;
        lo_min=min(lo_min,tmp);
    }
    REP(j,N){
        int tmp=0,det=0;
        REP(i,N){
            if(mp[i][j]=='O') det=1;
            else if(mp[i][j]=='.') tmp++;
        }
        if(det==1) tmp=INF;
        mp_num[1][j]=tmp;
        lo_min=min(lo_min,tmp);
    }
    if(lo_min==1){
        REP(i,N) if(mp_num[1][i]==mp_num[0][i] && mp_num[0][i]==1 && mp[i][i]=='.') mp_num[0][i]=0;
    }
    REP(i,2) REP(j,N) if(mp_num[i][j]==lo_min) meth++;
    if(lo_min==INF) printf("Case #%d: Impossible\n",++fl);
    else printf("Case #%d: %d %d\n",++fl,lo_min,meth);
}
signed main(){
    int T;
    cin >> T;
    while(T--){
        init();
        cin >> N;
        REP(i,N) REP(j,N) cin >> mp[i][j];
        Solve();
    }
    return 0;
}
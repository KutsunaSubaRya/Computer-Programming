#pragma GCC optimize ("O2")
#include<bits/stdc++.h>
#pragma region define/typedef
/*-----define-----*/
#define jizz ios_base::sync_with_stdio(false),cin.tie(NULL)
#define REP(I,N) for(int I=0;I<(N);I++)
#define REP1(I,N,M) for(int I=(N);I<(M);I++)
#define MS0(X) memset((X), 0, sizeof((X)))
#define INF 0x3f3f3f3f
#define NINF 0xc0c0c0c0
#define lowbit(x) (x&(-x))
/*-----typedef-----*/
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
#pragma endregion
const int MAX=200005;
int bit[MAX];
void init(){
    MS0(bit);
}
void add_BIT(int id, int val){
    for(;id<MAX;id+=lowbit(id)) bit[id]+=val;
}
int query(int id){
    int tot=0;
    for(;id;id-=lowbit(id)) tot+=bit[id];
    return tot;
}
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int T,n,m,pos;
    cin >> T;
    while(T--){
        int arr[MAX]={0};
        cin >> n >> m;
        init();
        REP1(i,1,n+1){
            arr[i]=n+1-i;
            add_BIT(i,1);
        }
        REP1(i,1,m+1){
            cin >> pos;
            int tmp=query(arr[pos]);
            cout << n-tmp << " \n"[i==m];
            add_BIT(arr[pos],-1);
            arr[pos]=n+i;
            add_BIT(n+i,1);
        }
    }
    return 0;
}
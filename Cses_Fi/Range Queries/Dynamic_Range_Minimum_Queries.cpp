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
#define Mid(l,r) (l)+(((r)-(l))>>1)
#pragma endregion
int arr[200005],Tree[800005];
int up(int a, int b){
    return min(a,b);
}
void buildTree(int l, int r, int idx){
    if(l==r){
        Tree[idx]=arr[l];
        return;
    } 
    int mid=Mid(l,r);
    buildTree(l,mid,idx*2+2);
    buildTree(mid+1,r,idx*2+1);
    Tree[idx]=up(Tree[idx*2+2],Tree[idx*2+1]);
    return;
}
int Query(int x, int y, int l, int r, int idx){
    if(x==l && y==r) return Tree[idx];
    int mid=Mid(l,r);
    if(y<=mid) return Query(x,y,l,mid,idx*2+2);
    if(x>mid) return Query(x,y,mid+1,r,idx*2+1);
    return up(Query(x,mid,l,mid,idx*2+2),Query(mid+1,y,mid+1,r,idx*2+1));
}
void Update(int l, int r, int pos, int idx, int val){
    if(l==r){
        Tree[idx]=val;
        return;
    }
    int mid=Mid(l,r);
    if(pos<=mid) Update(l,mid,pos,idx*2+2,val);
    else if(pos>mid) Update(mid+1,r,pos,idx*2+1,val);
    Tree[idx]=up(Tree[idx*2+2],Tree[idx*2+1]);
}
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n,q,det,k,u,a,b;
    cin >> n >> q;
    REP1(i,1,n+1) cin >> arr[i];
    buildTree(1,n,0);
    while(q--){
        cin >> det;
        if(det==1){
            cin >> k >> u;
            Update(1,n,k,0,(int)u);
        }
        else{
            cin >> a >> b;
            int ans=Query(a,b,1,n,0);
            cout << ans << "\n";
        }
    }
    return 0;
}
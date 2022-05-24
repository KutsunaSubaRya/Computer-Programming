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
#define Mid(l,r) (l)+(((r)-(l))>>1)
/*-----typedef-----*/
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<PII> VPII;
#pragma endregion
const int mod=1e9+7;
LL arr[200005];
struct Leaf{
    long long val;
    int pos;
};
Leaf Tree[800005];
void up(int idx){
    if(Tree[idx*2+2].val<Tree[idx*2+1].val){
        Tree[idx].val=Tree[idx*2+2].val;
        Tree[idx].pos=Tree[idx*2+2].pos;  
        return;      
    }
    Tree[idx].val=Tree[idx*2+1].val;
    Tree[idx].pos=Tree[idx*2+1].pos;
    return;
}
void buildTree(int l, int r, int idx){
    if(l==r){
        Tree[idx].val=arr[l];
        Tree[idx].pos=l;
        return;
    } 
    int mid=Mid(l,r);
    buildTree(l,mid,idx*2+2);
    buildTree(mid+1,r,idx*2+1);
    up(idx);
    return;
}
Leaf Query(int x, int y, int l, int r, int idx){
    if(x==l && y==r) return Tree[idx];
    int mid=Mid(l,r);
    if(y<=mid) return Query(x,y,l,mid,idx*2+2);
    if(x>mid) return Query(x,y,mid+1,r,idx*2+1);
    Leaf tmp1,tmp2;
    tmp1=Query(x,mid,l,mid,idx*2+2);
    tmp2=Query(mid+1,y,mid+1,r,idx*2+1);
    return tmp1.val<tmp2.val?tmp1:tmp2;
}
void Update(int l, int r, int pos, int idx, LL val){
    if(l==r){
        Tree[idx].val=val;
        Tree[idx].pos=l;
        return;
    }
    int mid=Mid(l,r);
    if(pos<=mid) Update(l,mid,pos,idx*2+2,val);
    else if(pos>mid) Update(mid+1,r,pos,idx*2+1,val);
    up(idx);
}
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n;
    LL tot=0;
    cin >> n;
    REP1(i,1,n+1) cin >> arr[i];
    buildTree(1,n,0);
    REP1(i,1,n+1){
        Leaf tmp;
        tmp=Query(i,n,1,n,0);
        // cout << "tmp= " << tmp.val << " " << tmp.pos << "\n";
        // cout << "arr[i]= " << arr[i] << " " << i << "\n\n";
        if(tmp.val<arr[i]){
            // cout << "tmp= " << tmp.val << " " << tmp.pos << "\n";
            // cout << "arr[i]= " << arr[i] << " " << i << "\n\n";
            tot=(tot+((tmp.val+arr[i])*abs(tmp.pos-i))%mod)%mod;
            Update(1,n,tmp.pos,0,arr[i]);
            arr[tmp.pos]=arr[i];
        }
    }
    cout << tot << "\n";
    return 0;
}
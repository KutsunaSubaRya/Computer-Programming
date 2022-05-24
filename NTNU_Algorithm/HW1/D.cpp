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
#define lowbit(x) (x&-x)
/*-----typedef-----*/
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
vector<LL> status,lisan;
inline vector<LL> discretization(vector<LL> a){
    status.resize(a.size());
    lisan = a;
    sort(lisan.begin(),lisan.end());
    lisan.resize(unique(lisan.begin(),lisan.end())-lisan.begin());
    for(int i = 0; i < (int)a.size(); i++) 
        status[i] = lower_bound(lisan.begin(),lisan.end(),a[i])-lisan.begin();
    return status;
}
LL Bit[200005],n;
inline void modify(int x, int d){
    for(;x<=n;x+=lowbit(x)) Bit[x] += d;
}
inline LL query(int x){
    LL sum=0;
    for(;x;x-=lowbit(x)) sum += Bit[x];
    return sum;
}
#pragma endregion
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    LL tot_elem=0,det=0,tmp;
    vector<LL> arr,v1,v2;
    cin >> n;
    REP(i,n) { cin >> tmp; arr.emplace_back(tmp); }
    arr=discretization(arr);
    REP(i,n){
        arr[i]++;
        if(!(i&1)) v1.emplace_back(arr[i]);
        else v2.emplace_back(arr[i]);
    }
    LL ans=0;
    MS0(Bit);
    for(auto i:v1){
        ans+=tot_elem-query(i);
        modify(i,1);
        tot_elem++;
    }
    MS0(Bit);
    tot_elem=0;
    for(auto i:v2){
        ans+=tot_elem-query(i);
        modify(i,1);
        tot_elem++;
    }
    sort(arr.begin(),arr.end());
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    REP(i,n){
        int pos=i/2;
        if((!(i&1) && arr[i]!=v1[pos]) || (i&1 && arr[i]!=v2[pos])){
            det=1;
            break;
        }
    }
    if(det) cout << "no\n";
    else cout << "yes\n";
    cout << ans << "\n";
    return 0;
}
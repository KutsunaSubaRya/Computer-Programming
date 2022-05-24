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
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int tot=1,n,a,b,chk[100005];
    PII arr1[100005],arr2[100005];
    cin >> n;
    REP(i,n){
        cin >> a >> b;
        arr1[i]=make_pair(a,b);
    }
    sort(arr1,arr1+n);
    PII tmp=arr1[n-1],tmp1=arr1[n-1];
    int det=0;
    for(int i=n-2;i>=0;i--){
        if(tmp1.first>arr1[i].first && det){
            det=0;
            tmp=tmp1;
        }
        if(tmp.first==arr1[i].first){
            tot++;
        }
        else if(tmp.first>arr1[i].first && tmp.second<=arr1[i].second){
            det=1;
            tmp1=arr1[i];
            tot++;
        }
    }
    cout << tot << "\n";
    return 0;
}
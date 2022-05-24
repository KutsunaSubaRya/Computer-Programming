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
bool cmp(int a,int b){
    return abs(a+b);
}
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n,T;
    cin >> n;
    while(n--){
        cin >> T;
        vector<int> v(T);
        REP(i,T){
            cin >> v[i];
        }
        int mid=T/2,total=0,total1=0,total2=0;
        nth_element(v.begin(),v.begin()+mid,v.end());
        // cout << "mid= " << mid << "\n";
        // cout << accumulate(v.begin(),v.begin()+mid,total1) << "\n";
        // cout << accumulate(v.begin()+mid+1,v.end(),total2) << "\n";
        if(accumulate(v.begin(),v.begin()+mid,total1)>0){
            total+=(mid*v[mid])-accumulate(v.begin(),v.begin()+mid,total1);
        }
        if(accumulate(v.begin()+mid+1,v.end(),total2)>0){
            if(T%2==0) total+=accumulate(v.begin()+mid+1,v.end(),total2)-((mid-1)*v[mid]);
            else total+=accumulate(v.begin()+mid+1,v.end(),total2)-(mid*v[mid]);
        }
        // total=(mid*v[mid])-accumulate(v.begin(),v.begin()+mid,total1)+accumulate(v.begin()+mid+1,v.end(),total2)-(mid*v[mid]);
        cout << total << "\n";
        // if(T&1){ // odd
        //     int mid=T/2,total=0,total1=0,total2=0;
        //     nth_element(v.begin(),v.begin()+mid,v.end());
        //     // cout << "mid= " << mid << "\n";
        //     // cout << accumulate(v.begin(),v.begin()+mid,total1) << "\n";
        //     // cout << accumulate(v.begin()+mid+1,v.end(),total2) << "\n";
        //     total=(mid*v[mid])-accumulate(v.begin(),v.begin()+mid,total1)+accumulate(v.begin()+mid+1,v.end(),total2)-(mid*v[mid]);
        //     cout << total << "\n";
        // }
        // else{
        //     int tot1=0,tot2=0,mid1=T/2,total1=0,total2=0;
        //     nth_element(v.begin(),v.begin()+mid1,v.end());
        //     tot1=(mid1*v[mid1])-accumulate(v.begin(),v.begin()+mid1,total1)+accumulate(v.begin()+mid1+1,v.end(),total2)-(mid1*v[mid1]);
        //     int mid2=T/2+1;
        //     total1=0,total2=0;
        //     nth_element(v.begin(),v.begin()+mid2,v.end());
        //     tot2=(mid2*v[mid2])-accumulate(v.begin(),v.begin()+mid2,total1)+accumulate(v.begin()+mid2+1,v.end(),total2)-(mid2*v[mid2]);
        //     cout << min(tot1,tot2) << "\n";
        // }
    }
    return 0;
}
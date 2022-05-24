//#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
/*-----define-----*/
#define jizz ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ALL(X) (X).begin(), (X).end()
#define REP(I,N) for(int I=0;I<(N);I++)
#define REP1(I,N,M) for(int I=(N);I<(M);I++)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(), c.end(),x)-c.begin())
#define pb emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define LEN(X) strlen((X))
#define F first
#define S second
#define LB lower_bound
#define UP upper_bound
#define CN cout<<"\n"
#define maxE(x) (*max_element((x).begin(), (x).end()))
#define minE(x) (*min_element((x).begin(), (x).end()))
/*-----typedef-----*/
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
signed main(){
	jizz;
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	int T,n;
	double P;
	cin >> T;
	while(T--){
		int cost[10005],tot_w=0,tmp=0;
		double weight[10005],dp[10005]={0};
		cin >> P >> n;
		dp[0]=1; 
		REP(i,n){
			cin >> cost[i] >> weight[i];
			weight[i]=1-weight[i]; 
			tot_w+=cost[i];
		}
		REP(i,n) for(int j=tot_w;j>=cost[i];j--) dp[j]=max(dp[j],dp[j-cost[i]]*weight[i]);
		REP(i,tot_w+1)
			if(dp[i]>=1-P) tmp=i;
		cout << tmp << "\n";
	}
	return 0;
}
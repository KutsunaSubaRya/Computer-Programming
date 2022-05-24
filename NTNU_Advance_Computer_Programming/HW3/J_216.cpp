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
double dist(int x, int y, int x2, int y2){
    return sqrt((double)((x-x2)*(x-x2)+(y-y2)*(y-y2)));
}
signed main(){
    //jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n,flag=0;
    while(cin >> n && n!=0){
        double minu=2147483647;
        pair<int,int> edge[n+5];
        REP(i,n){
            cin >> edge[i].first >> edge[i].second;
        }
        vector<int> Permutation(n),ansEdge(n);
        iota(ALL(Permutation),0);
        do{
            double distance=0.0;
            for(auto it=Permutation.begin();it!=Permutation.end()-1;++it){
                distance+=dist(edge[*it].first,edge[*it].second,edge[*(it+1)].first,edge[*(it+1)].second)+16;
            }
            if(distance<minu){
                // ansEdge=Permutation;
                copy(Permutation.begin(),Permutation.end(),ansEdge.begin());
                minu=distance;
            }
        }while(next_permutation(ALL(Permutation)));
        cout << "**********************************************************\nNetwork #"<< ++flag << "\n";
        for(auto i=ansEdge.begin();i!=ansEdge.end()-1;++i){
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",edge[*i].first,edge[*i].second,edge[*(i+1)].first,edge[*(i+1)].second,dist(edge[*i].first,edge[*i].second,edge[*(i+1)].first,edge[*(i+1)].second)+16);
        }
        printf("Number of feet of cable required is %.2lf.\n",minu);
        //cout << minu << "\n";
    }
    
    return 0;
}
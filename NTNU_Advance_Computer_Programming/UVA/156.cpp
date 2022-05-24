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
bool cmp(const pair<int,string> &a, const pair<int,string> &b){
    return a.second<b.second;
}
signed main(){
    jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    string str;
    map<string,pair<int,string>> mp;
    while(getline(cin, str) && str[0]!='#'){
        stringstream ss(str);
        string tmp;
        while(ss>>tmp){
            string toLowerStr=tmp;
            transform(ALL(toLowerStr), toLowerStr.begin(), :: tolower);
            sort(ALL(toLowerStr));
            //cout << "sort: " << toLowerStr << "\n";
            mp[toLowerStr].first++;
            mp[toLowerStr].second=tmp;
        }
    }
    vector<string> strTmp;
    for(auto it:mp){
        //cout << it.first << " first= " << it.second.first << " second= " << it.second.second  << "\n";
        if(it.second.first==1){
            strTmp.emplace_back(it.second.second);
        }
    }
    sort(ALL(strTmp));
    for(auto i:strTmp){
        cout << i << "\n";
    }
    return 0;
}
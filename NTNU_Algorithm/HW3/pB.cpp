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
int n,m,timeLavaFlow=0;
string s[1005];
vector<string> lavaHistory[500005];
pair<int,int> doorPos;
const int direction[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
queue<pair<int,int>> q;
void printCurrentMapStatus(int Time){
    for(auto i:lavaHistory[Time]){
        cout << i << "\n";
    }
    cout << "\n";
}
bool isFlowable(int x, int y, int i, bool deter, int Time){ // deter=1 human, deter=0 lava
    if(x+direction[i][0]<n && x+direction[i][0]>=0 && y+direction[i][1]<m && y+direction[i][1]>=0){
        if(deter && lavaHistory[Time][x+direction[i][0]][y+direction[i][1]]=='D'){
            return true;
        }
        if(deter && lavaHistory[Time][x+direction[i][0]][y+direction[i][1]]=='C'){
            lavaHistory[Time][x+direction[i][0]][y+direction[i][1]]='B';
            q.emplace(make_pair(x+direction[i][0], y+direction[i][1]));
        }
        else if(!deter && s[x+direction[i][0]][y+direction[i][1]]=='C'){
            s[x+direction[i][0]][y+direction[i][1]]='L';
            q.emplace(make_pair(x+direction[i][0], y+direction[i][1]));
        }
    }
    return false;
}
bool isDoorRoundByLava(pair<int,int> Door){
    int x=Door.first,y=Door.second;
    REP(i,4){
        if(x+direction[i][0]<n && x+direction[i][0]>=0 && y+direction[i][1]<m && y+direction[i][1]>=0){
            if(s[x+direction[i][0]][y+direction[i][1]]=='C'){
                return false;
            }
        }
    }
    return true;
}
void lavaFloodFill(void){
    int cnt=q.size(),tmpCnt=0,flag=0;
    int cntTmp=0;
    while(!q.empty()){
        cntTmp++;
        pair<int,int> lavaPos;
        lavaPos=q.front(); q.pop();
        ++flag;
        REP(i,4){
            // cout << lavaPos.first << " " << lavaPos.second << "\n";
            isFlowable(lavaPos.first, lavaPos.second, i, false, 0);
        }
        if(cnt-flag==0){
            flag=0;
            cnt=q.size();
            REP(i,n) lavaHistory[timeLavaFlow].emplace_back(s[i]);
            ++timeLavaFlow;
            if(isDoorRoundByLava(doorPos)){
                break;
            }
        }
    }
    while(!q.empty()){
        q.pop();
    }
    cout << "cntTmp= " << cntTmp << "\n";
}
bool humanFloodFill(pair<int,int> bPos, int Time){
    while(!q.empty()) q.pop();
    q.push(bPos);
    bool findDoor=false;
    while(!q.empty()){
        pair<int,int> bCurrentPos;
        bCurrentPos=q.front(); q.pop();
        // cout << bCurrentPos.first << " " << bCurrentPos.second << "\n";
        REP(i,4){
            findDoor=isFlowable(bCurrentPos.first, bCurrentPos.second, i, true, Time);
            if(findDoor) break;
            // printCurrentMapStatus(Time);
        }
        if(findDoor) break;
        // printCurrentMapStatus();
    }
    while(!q.empty()) q.pop();
    if(findDoor) return true;
    return false;
}

signed main(){
    // jizz;
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    pair<int,int> playerPos,lavaPos;
    string tmp[1005];
    cin >> n >> m;
    REP(i,n) {
        cin >> s[i];
        tmp[i]=s[i];
        REP(j,m){
            if(s[i][j]=='B') playerPos=make_pair(i,j);
            else if(s[i][j]=='D') doorPos=make_pair(i,j);
            else if(s[i][j]=='L'){
                q.emplace(make_pair(i,j));
            }
        }
    }
    // printCurrentMapStatus(n,m);
    lavaFloodFill();
    REP(i,n) s[i]=tmp[i];
    // cout << timeLavaFlow << "\n";
    // REP(i,timeLavaFlow){
    //     for(auto j:lavaHistory[i]){
    //         cout << j << "\n";
    //     }
    //     cout << "\n";
    // }
    int l=0,r=timeLavaFlow;
    while(l<=r){
        int mid=(l+r)/2;
        // cout << "binary-> " << "\n";
        // for(auto j:lavaHistory[mid]){
        //     cout << j << "\n";
        // } cout << "\n";
        if(humanFloodFill(playerPos,mid)){
            // cout << "success" << "\n";
            l=mid+1;
        }
        else{
            r=mid-1;
        }
        // cout << "mid= " << mid <<"\n";
    }

    // cout << l << " " << r <<"\n"; 
    if(r==-1) cout << "-1\n";
    else cout << l << "\n";
    return 0;
}
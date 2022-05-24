#include <cstdio>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int bfs( vector<vector<char>>& );

int32_t start_x=0,start_y=0;
int32_t door_x=0,door_y=0;
int32_t second=0;
int32_t width_len=0,column_len=0;
const pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main(){

#ifndef ONLINE_JUDGE
    freopen("output.txt","w", stdout);
    freopen("input.txt", "r", stdin);
#endif

    cin>>column_len>>width_len;
    vector<vector<char>> table(column_len, vector<char>(width_len));
    queue<pair<int32_t,int32_t>> lava;

    int32_t cnt=0;
    int32_t match=0;

//28~33 INPUT
    for(int32_t i=0 ; i<column_len ; ++i){
        for(int32_t u=0 ; u<width_len ; ++u){
            cin>>table[i][u];
            if(table[i][u]=='B'){
                start_x=i;
                start_y=u;
            }
            if(table[i][u]=='D'){
                door_x=i;
                door_y=u;
            }
            if(table[i][u]=='L'){
                lava.emplace(i,u);
            }
        }
    }

    vector<vector<vector<char>>> flow( 1 , table );

//51~110 生圖
    for(int32_t a=1 ; a<width_len*column_len && !lava.empty() ; ++a){
        flow.emplace_back(flow[a-1]);
        int32_t lava_cnt=lava.size();

        for(int32_t e=0 ; e<lava_cnt ; ++e){
            pair<int32_t,int32_t>tmp=lava.front();
            lava.pop();

            for( int32_t u=0 ; u<4 ; ++u ) {
                int ni = tmp.first + dir[u].first;
                int nj = tmp.second+ dir[u].second;
                if(ni < 0 || ni >= column_len || nj < 0 || nj >= width_len ) continue;
                // do something

                if(flow[a][ni][nj]=='C'){
                    flow[a][ni][nj]='L';
                    lava.emplace(ni,nj);
                }
            }
        }

//74~86 檢查D旁邊的點是否完全沒有C了 若為真 就把該second記下來 然後離開這個破迴圈
        cnt=0;
        match=0;

        for( int32_t u=0 ; u<4 ; ++u ){
            int32_t ni=door_x+dir[u].first;
            int32_t nj=door_y+dir[u].second;
            if( ni < 0 || ni >= column_len || nj < 0 || nj >= width_len ) continue;
            cnt++;
            if( flow[a][ni][nj]!='C' ){
                match++;
            }
        }
        
        if(match==cnt){
            second=a;
            break;
        }
//92~109 檢查B旁邊的點是否完全沒有C了 若為真 就把該second記下來 然後離開這個破迴圈
        cnt=0;
        match=0;

        for( int32_t u=0 ; u<4 ; ++u ){
            int32_t ni=start_x+dir[u].first;
            int32_t nj=start_y+dir[u].second;
            if( ni < 0 || ni >= column_len || nj < 0 || nj >= width_len ) continue;
            cnt++;
            if( flow[a][ni][nj]!='C' ){
                match++;
            }
        }
        
        if(match==cnt){
            second=a;
            break;
        }
    }
/*以上生圖*/

    int32_t up=second;
    int32_t down=2;
    int32_t m=0;

    if( bfs(flow[0])==0 ){
        cout<<"-1\n";
        return 0;
    }else if( bfs(flow[1])==0 ){
        cout<<"-1\n";
        return 0;
    }
    int cnt=0;
    while(down<=up){
        cnt++;
        m=(down+up)/2;
        int32_t count=bfs(flow[m]);

        if( count==1 ){
            down=m+1;
        }else if( count==0 ){
            up=m-1;
        }
    }
    cout<<down-1<<'\n';
    cout << "cnt= "<< cnt << "\n";
    return 0;
}

int bfs( vector<vector<char>> &color ){
    queue<pair<int32_t,int32_t>> q;
    q.emplace(start_x,start_y);
    color[start_x][start_y]='L';
    //總共有 C L O B D
    //不能走 L、O
    //可以走 C
    while( !q.empty() ){
        pair<int32_t,int32_t>tmp=q.front();
        q.pop();

        for( int32_t u=0 ; u<4 ; ++u ) {
            int32_t ni = tmp.first  + dir[u].first;
            int32_t nj = tmp.second + dir[u].second;

            if( ni < 0 || ni >= column_len || nj < 0 || nj >= width_len ) continue;//越界 給我滾
            if( color[ni][nj]=='D' ) return 1;
            if( color[ni][nj]=='C' ){
                q.emplace(ni,nj);
                color[ni][nj]='L';
            }
        }        
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;
enum floor_type{
    lava,
    obstacle,
    common_floor,
    bed,
    door
};
int main(){
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    string input[n];
    for(int i=0;i<n;++i){
        cin.get();
        cin >> input[i];
    }
    vector<vector<floor_type>> room(n+2, vector<floor_type>(m+2, lava));
    queue<pair<int, int>> bfs_queue;
    vector<vector<bool>> visited(n+2, vector<bool>(m+2, false));
    pair<ll, ll> door_loc, bed_loc;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            switch(input[i-1][j-1]){
                case 'L':
                    room[i][j]=lava;
                    bfs_queue.emplace(i,j);
                    visited[i][j]= true;
                    break;
                case 'O':
                    room[i][j]=obstacle;
                    break;
                case 'C':
                    room[i][j]=common_floor;
                    break;
                case 'B':
                    room[i][j]=bed;
                    bed_loc= make_pair(i,j);
                    break;
                case 'D':
                    room[i][j]=door;
                    door_loc= make_pair(i,j);
                    break;
            }
        }
    }

    vector<vector<vector<floor_type>>>snapshot;
    vector<pair<int,int>> direction{make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1)};
    //lava expansion
    //bfs
    int cnt=0;
    snapshot.emplace_back(room);
    while(!bfs_queue.empty()){
        
        int old_source_num=bfs_queue.size();
        while(old_source_num>0){
            //push
            cnt++;
            pair<int,int> source=bfs_queue.front();
            bfs_queue.pop();
            //expansion
            for(auto i:direction){
                pair<int,int> tmp{source.first+i.first, source.second+i.second};
                if(room[tmp.first][tmp.second]==common_floor && !visited[tmp.first][tmp.second]){
                    room[tmp.first][tmp.second]=lava;
                    visited[tmp.first][tmp.second]= true;
                    bfs_queue.emplace(tmp);
                }
            }
            --old_source_num;
        }
        //If the door is surrounded by lava, then there is no need to save room map anymore.
        
        int door_block_count=0;
        for(auto i:direction){
            pair<int,int>tmp{door_loc.first+i.first, door_loc.second+i.second};
            if(room[tmp.first][tmp.second]==lava || room[tmp.first][tmp.second]==obstacle)  door_block_count++;
        }
        if(door_block_count==4) break;
        //write into snapshot
        snapshot.emplace_back(room);
    }
cout << "cnt= " << cnt << "\n";
// #ifndef ONLINE_JUDGE
//     //print lava expansion progress
//     int a=0;
//     for(auto &i:snapshot){
//         cout << ">> " << ++a << " <<\n";
//         for(auto &j:i){
//             for(auto k:j){
//                 switch(k){
//                     case lava:
//                         cout <<'L';
//                         break;
//                     case common_floor:
//                         cout <<'C';
//                         break;
//                     case bed:
//                         cout <<'B';
//                         break;
//                     case obstacle:
//                         cout <<'O';
//                         break;
//                     case door:
//                         cout <<'D';
//                 }
//             }
//             cout << '\n';
//         }
//     }
// #endif
// bfs from bed to door
    int left=0, right=snapshot.size(), mid;
    int binaryCnt=0,bfsCnt=0;
    bfs_queue.emplace(bed_loc);
    bool find_door=false;
    while(left<right){
        //binary search
        binaryCnt++;
        mid=left+(right-left)/2;
        if(mid==left) break;
        vector<vector<bool>> visited(n+2, vector<bool>(m+2, false));
        queue<pair<int, int>> bfs_queue;
        visited[bed_loc.first][bed_loc.second]= true;
        find_door= false;
        bfs_queue.emplace(bed_loc);
        //bfs
        while(!bfs_queue.empty()){
            bfsCnt++;
            int old_source_num=bfs_queue.size();
            while(old_source_num>0) {
                auto source = bfs_queue.front();
                bfs_queue.pop();
                --old_source_num;
                for(auto i: direction) {
                    pair<int,int> tmp{source.first + i.first, source.second + i.second};
                    if(snapshot[mid][tmp.first][tmp.second] == common_floor && !visited[tmp.first][tmp.second]) {
                        visited[tmp.first][tmp.second] = true;
                        bfs_queue.emplace(tmp);
                    }
                    if(snapshot[mid][tmp.first][tmp.second] == door){
                        old_source_num=0;   //get out of outer loop
                        find_door= true;
                        break;
                    }
                }
            }
            if(find_door){
                left=mid;
                break;
            }
        }
        if(!find_door)  right=mid;
    }
    if(left==0) cout << -1 << '\n';
    else cout << left << '\n';
    cout << "binaryCnt= " << binaryCnt << " bfsCnt= " << bfsCnt << "\n";
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

const string NONE="NONE", DISH="DISH", BLUEBERRIES="BLUEBERRIES", ICE_CREAM="ICE_CREAM", STRAWBERRIES="STRAWBERRIES", CHOPPED_STRAWBERRIES="CHOPPED_STRAWBERRIES", DOUGH="DOUGH", CROISSANT="CROISSANT", PARSE_cROISSANT="cROISSANT";
const int height=7,width=11;

set<string> dash_parser(string Name){
    if(Name==NONE){
        return {};
    }
    set<string> tmp_str;
    int flag=-1,Name_len=(int)Name.length();
    for(int i=0;i<=Name_len;i++){
        if(Name[i]=='-' || i==Name_len){
            string tmp1=Name.substr(flag+1, i-flag-1);
            if(tmp1==CROISSANT){
                tmp1[0]='c';
            }
            tmp_str.insert(tmp1);
            flag=i;
        }
    }
    return tmp_str;
}
bool Contain_Ingredient(const set<string> a, const set<string> b){
    for(string i:b){
        if(!a.count(i)){
            return false;
        }
    }
    return true;
}
void USE(const int i,const int j){
    cout << "USE " << j << " " << i << endl;
}




class Customers{
    private:
        set<string> item;
        string tmp;
        int item_award;
    public:
        void Input(void){
            cin >> tmp >> item_award;
            cin.ignore();
            item=dash_parser(tmp);
        }
        set<string> Get_customer_item(void){
            return item;
        }
        bool Contain_item(string tmp){
            return item.find(tmp)!=item.end();
        }
};

class Player{
    private:
        int x,y;
        string tmp;
        set<string> item;
    public:
        void Input(void){
            cin >> x >> y >> tmp;
            cin.ignore();
            item=dash_parser(tmp);
        }
        char Find_Player_Need(string player_item){
            if(player_item == "NONE"){
                return 'D';
            }
            else if(player_item == "DISH"){
                return 'B';
            }
            else if(player_item == "DISH-BLUEBERRIES"){
                return 'I';
            }
            else if(player_item == "DISH-BLUEBERRIES-ICE_CREAM"){
                return 'W';
            }
        }
        set<string> Get_player_item(void){
            return item;
        }
        bool Contain_item(string tmp){
            return item.find(tmp)!=item.end();
        }
        bool Contain_nothing(){
            return item.empty();
        }
};

class Cells{
    private:
        int x,y;
        string tmp;
        set<string> item;
    public:
        void Input(void){
            cin >> x >> y >> tmp;
            cin.ignore();
            item=dash_parser(tmp);
        }
        set<string> Get_Cells_item(void){
            return item;
        }
        bool Contain_item(string tmp){
            return item.find(tmp)!=item.end();
        }
        pair<int,int> Get_Cell_Position(){
            return make_pair(y,x);
        }
};

int main()
{
    int num_all_customers;
    cin >> num_all_customers;
    
    vector<Customers> _customer_all(num_all_customers);
    
    for (Customers& i:_customer_all) {
        i.Input();
    }

    vector<string> kitchen_line(height);
    for (int i = 0; i < 7; i++) {
        cin >> kitchen_line[i];
    }

    // game loop
    Customers _origin_last_customer_need;
    while (1) {
        int turns_remaining;
        cin >> turns_remaining; cin.ignore();
        Player _player, partener;
        _player.Input();
        partener.Input();
        
        int num_tables_with_items; // the number of tables in the kitchen that currently hold an item
        cin >> num_tables_with_items; cin.ignore();
        vector<Cells> _table(num_tables_with_items);
        for (Cells& i:_table) {
            i.Input();
        }

        string ovenContents;
        int Overtimer;
        cin >> ovenContents >> Overtimer; cin.ignore();


        int num_customers; // the number of customers currently waiting for food
        cin >> num_customers; cin.ignore();
        vector<Customers> _customer_current(num_customers);
        for (Customers& i:_customer_current) {
            i.Input();
        }

        //Write an action using cout. DON'T FORGET THE "<< endl"
        //To debug: cerr << "Debug messages..." << endl;
        bool determine_work=false;
        char Player_need=0;
        Customers _customer_need;
        _customer_need=_customer_current.back();
        if(_customer_need.Contain_item(PARSE_cROISSANT) && ovenContents==CROISSANT && _player.Contain_item(DISH) && !_player.Contain_item(PARSE_cROISSANT)){
            // 顧客要 CROISSANT
            // oven 有 CROISSANT
            // player 手上有 DISH 且沒有 CROISSANT
            Player_need='c';
        }
        else if(_customer_need.Contain_item(PARSE_cROISSANT) && (ovenContents==CROISSANT||ovenContents==DOUGH) && _player.Contain_nothing()){
            // 顧客要 CROISSANT
            // oven 有 CROISSANT
            // player 手上啥都沒有
            cerr << "I DONT HAVE DISH, I NEED DISH TO PLACE CROISSANT" << endl;
            for(Cells ITEM:_table){
                if(determine_work) break;
                set<string> tmp_set=ITEM.Get_Cells_item();
                if(tmp_set.count(DISH)){
                    pair<int,int> tmp_pos=ITEM.Get_Cell_Position();
                    cerr << "TAKE IT!!! pos= " << tmp_pos.second << " " << tmp_pos.first << endl; 
                    USE(tmp_pos.first,tmp_pos.second);
                    determine_work=true;
                }
            }
            if(determine_work) continue;
            Player_need='D';
        }
        else if(!partener.Contain_item(DOUGH) && _customer_need.Contain_item(PARSE_cROISSANT) && ovenContents==NONE && _player.Contain_nothing()){
            // 夥伴沒有拿著 DOUGH (我就不用拿，交給他即可)
            // 顧客要 CROISSANT
            // oven nothing
            // player 手上啥都沒有
            cerr << "NEED DOUGH" << endl;
            Player_need='H';
        }
        else if(ovenContents==NONE && _player.Contain_item(DOUGH)){
            for(string i:_player.Get_player_item()){
                cerr << i << endl;
            }
            cerr << "NEED OVEN" << endl;
            Player_need='O';
        }
        else if(_customer_need.Contain_item(CHOPPED_STRAWBERRIES) && !_player.Contain_item(CHOPPED_STRAWBERRIES)){
            for(Cells ITEM:_table){
                set<string> ITEM_item=ITEM.Get_Cells_item();
                pair<int,int> ITEM_row_col=ITEM.Get_Cell_Position();
                if(ITEM_item==(set<string>){CHOPPED_STRAWBERRIES}){
                    if(_player.Contain_item(DISH)){
                        USE(ITEM_row_col.first,ITEM_row_col.second);
                        determine_work=true;
                        break;
                    }
                }
            }
            if(determine_work){
                continue;
            }
            else if(_player.Contain_item(CHOPPED_STRAWBERRIES)){
                Player_need='#';
            }
            else if(_player.Contain_item(STRAWBERRIES)){
                // cerr << "huh??" << endl;
                Player_need='C';
            }
            else if(_player.Contain_nothing()){
                Player_need='S';
            }
        }
        cerr << Player_need << endl;
        if(determine_work){
            continue;
        }
        if(!Player_need){
            set<string> custom_Need_cmp=_customer_need.Get_customer_item();
            set<string> player_Need_cmp=_player.Get_player_item();
            if(custom_Need_cmp==player_Need_cmp || player_Need_cmp.size()>custom_Need_cmp.size()){
                // 後者是因為當下的餐點被敵方送了，得特判掉
                Player_need='W';
            }
            else if(!_player.Contain_item(DISH)){
                Player_need='D';
            }
            else{
                for(string i:custom_Need_cmp){
                    if(!_player.Contain_item(i)){
                        Player_need=i[0];
                    }
                }
            }
        }
        cerr << Player_need << endl;
        if(determine_work){
            continue;
        }


        if(Player_need=='c' && _player.Contain_item(DISH)){
            cerr << "We need CROISSANT" << endl;
            for(Cells& i:_table){
                set<string> tmp1=i.Get_Cells_item();
                for(string j:tmp1)
                    cerr << "I have Dish and _table= " << j << endl;
                if(determine_work) break;
                else if(i.Contain_item(PARSE_cROISSANT)){
                    pair<int,int> tmp_pos=i.Get_Cell_Position();
                    USE(tmp_pos.first, tmp_pos.second);
                    determine_work=true;
                }
            }
            if(determine_work) continue;
            if(ovenContents==CROISSANT){
                for(int i=0;i<height;i++){
                    if(determine_work) break;
                    for(int j=0;j<width;j++){
                        if(determine_work) break;
                        if(kitchen_line[i][j] == 'O'){
                            USE(i,j);
                            determine_work=true;
                        }
                    }
                }
            }
            else if(partener.Contain_item(DOUGH) || ovenContents==DOUGH){
                cout << "WAIT" << endl;
                determine_work=true;
            }
            else{
                Player_need='#';
                for(int i=0;i<height;i++){
                    if(determine_work) break;
                    for(int j=0;j<width;j++){
                        if(determine_work) break;
                        if(kitchen_line[i][j] == Player_need){
                            bool deter_table_have_thing=false;
                            for(Cells ITEM:_table){
                                pair<int,int> tmp_pos=ITEM.Get_Cell_Position();
                                if(tmp_pos.first==i && tmp_pos.second==j){
                                    deter_table_have_thing=true;
                                    break;
                                }
                            }
                            if(!deter_table_have_thing){
                                USE(i,j);
                                determine_work=true;
                            }
                        }
                    }
                }
            }
        }
        
        if(determine_work){
            continue;
        }

        for(int i=0;i<height;i++){
            if(determine_work) break;
            for(int j=0;j<width;j++){
                if(determine_work) break;
                if(kitchen_line[i][j] == Player_need){
                    USE(i,j);
                    determine_work=true;
                }
            }
        }
        
        if(!determine_work){
            cout << "WAIT" << endl;
        }
        //cout << "WAIT" << endl;
    }
}
#include "chef.h"
using namespace std;
int main(){
    chef maker;
    maker.gameInit();
    while(true) {
        maker.roundInit();
        if(maker.chefState == chef::state::ALLDONE) {
            maker.recipeStratege("MaxAward");
            maker.checkLackList();
            for(auto &it : maker.lackList) {
                if(it == "CHOPPED_STRAWBERRIES")
                    maker.chopList.emplace_back("STRAWBERRIES");
            }
        }
        if(maker.useOvenFlag) maker.take("OVEN");
        else if(maker.foodDelivery()) continue;
        else if(!maker.chopList.empty()) maker.chop();
        else maker.action("WAIT");
    }
    return 0;
}
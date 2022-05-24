#include "Robot.h"
Robot::Robot(const std::pair<const int,const int> pos, const int face):x(pos.first), y(pos.second), Face(face){}
bool Robot::isVisitedAndSameToward(const int _x, const int _y, const int _face)const{
    for(auto i:visited){
        if(i.first.first==_x && i.first.second==_y && i.second==_face){
            return true;
        }
    }
    return false;
}
std::pair<const int,const int> Robot::getPosition(void)const{
    return std::make_pair(x,y);
}
std::pair<const int,const int> Robot::nextPosition(void)const{
    return std::make_pair(x+faceToward[Face][xQuadrant],y+faceToward[Face][yQuadrant]);
}
void Robot::walkNextPosition(void){
    x+=faceToward[Face][xQuadrant];
    y+=faceToward[Face][yQuadrant];
}
void Robot::turnRight(void){
    Face=(Face+1)%4;
}
int Robot::getRobotToward(void)const{
    return Face;
}
void Robot::storeVisited(const std::pair<const int,const int> robotPosition){
    visited.emplace_back(std::make_pair(robotPosition,Face));
}
void Robot::findFinalState(const long long totalStep, const long long currentTotalStep){
    long long i,loopSize=1,remainTotalStep=totalStep-currentTotalStep;
    const long long visited_length=visited.size();
    for(i=visited_length-1;i>=0;i--){
        if(visited[i].first.first==x && visited[i].first.second==y && visited[i].second==Face){
            break;
        }
        loopSize++;
    }
    long long finalState=(remainTotalStep%loopSize)+i;
    x=visited[finalState].first.first;
    y=visited[finalState].first.second;
    Face=visited[finalState].second;
}
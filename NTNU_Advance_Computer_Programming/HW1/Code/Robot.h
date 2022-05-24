#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include <vector>
class Robot{
    private:
        int x,y,Face; // robot position
        const int xQuadrant=0, yQuadrant=1;
        const int faceToward[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
        std::vector<std::pair<std::pair<int,int>,int>> visited; 
        //first.first=>x, first.second=>y, second=>face direction which have visited 
    public:
        Robot(const std::pair<const int,const int> pos, const int face);
        bool isVisitedAndSameToward(const int _x, const int _y, const int _Face)const;
        std::pair<const int,const int> getPosition(void)const;
        std::pair<const int,const int> nextPosition(void)const;
        void walkNextPosition(void);        
        void turnRight(void);
        int getRobotToward(void)const;
        void storeVisited(const std::pair<const int,const int> robotPosition);
        void findFinalState(const long long n, const long long current_n);
};
#endif
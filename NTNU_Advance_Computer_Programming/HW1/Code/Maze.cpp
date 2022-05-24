#include "Maze.h"
Maze::Maze(const int _width, const int _height):width(_width), height(_height){}
std::pair<const int,const int> Maze::findRobotLocation(void)const{
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            if(mazeMap[y][x]=='O'){
                return std::make_pair(x,y);
            }
        }
    }
    return std::make_pair(0,0);
}
void Maze::generateMazeMap(const std::string str){
    mazeMap.emplace_back(str);
}
bool Maze::isObstacle(const std::pair<int,int> robotPosition)const{
    return mazeMap[robotPosition.second][robotPosition.first]=='#';
}
bool Maze::isRobotInMaze(const std::pair<int,int> robotPosition)const{
    return (robotPosition.first>=0 && robotPosition.first<width 
            && robotPosition.second>=0 && robotPosition.second<height);
}
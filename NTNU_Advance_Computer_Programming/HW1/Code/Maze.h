#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <string>
#include <vector>
class Maze{
    private:
        const int width, height;
        std::vector<std::string> mazeMap;
    public:
        Maze(const int _width, const int _height);
        std::pair<const int,const int> findRobotLocation(void)const;
        void generateMazeMap(const std::string str);
        bool isObstacle(const std::pair<int,int> robotPosition)const;
        bool isRobotInMaze(const std::pair<int,int> robotPosition)const;
};
#endif
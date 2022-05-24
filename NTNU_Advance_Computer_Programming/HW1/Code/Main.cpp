#include <iostream>
#include <string>
#include <vector>
#include "Maze.h"
#include "Robot.h"

int main()
{
    int direction=0; // direction 0,1,2,3 -> up, right, down, left
    std::pair<int,int> targetPosition;
    const int width = []() -> int{ 
        int tmp;
        std::cin >> tmp;
        return tmp;
    }();
    const int height = []() -> int{ 
        int tmp;
        std::cin >> tmp;
        return tmp;
    }();
    const long long totalStep = []() -> long long{ 
        long long tmp;
        std::cin >> tmp;
        return tmp;
    }();
    Maze _maze(width,height);
    for (int i = 0; i < height; i++) {
        std::string lineOfMap;
        std::cin >> lineOfMap;
        _maze.generateMazeMap(lineOfMap);
    }
    std::pair<int,int> nowRobotPosition=_maze.findRobotLocation();
    Robot _robot(nowRobotPosition, direction);
    for(long long i=0;i<totalStep;i++){
        std::pair<int,int> nextPos=_robot.nextPosition();
        while(!_maze.isRobotInMaze(nextPos) || _maze.isObstacle(nextPos)){
            _robot.turnRight();
            direction=_robot.getRobotToward();
            nextPos=_robot.nextPosition();
        }
        if(_robot.isVisitedAndSameToward(nowRobotPosition.first, nowRobotPosition.second, direction)){
            _robot.findFinalState(totalStep,i);
            break;
        }
        else{
            _robot.storeVisited(nowRobotPosition);
            _robot.walkNextPosition();
            nowRobotPosition=_robot.getPosition();
        }
    }
    targetPosition=_robot.getPosition();
    std::cout << targetPosition.first << " " << targetPosition.second <<  std::endl;
}
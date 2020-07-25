#ifndef __MAZE_FINALPROJECT_MAZE_MAZE_H__
#define __MAZE_FINALPROJECT_MAZE_MAZE_H__

#include <iostream>
#include <vector>
#include <stack>

#include "../mobileRobot/mobileRobot.h"
#include "../utils/travel.h"

class Maze {
  public:
    Maze(const std::string, const std::size_t, const std::size_t);
    ~Maze();
    bool createMaze();
    void displayMaze();
    bool checkCoordinates(std::size_t, std::size_t);
    bool canMove(std::size_t, std::size_t);
    bool isTarget(std::size_t, std::size_t, std::size_t, std::size_t);
    bool initMobileRobot();
    bool findPath(char);
    bool findPathBFS(char);
    void updateMaze(char);
    std::pair<std::size_t, std::size_t> getCoordinates(char);
  private:
    const std::size_t rows_, cols_;
    const std::string mazeFileName_;
    std::vector<std::vector<char>> maze_;
    MobileRobot trackedRobot_;
    MobileRobot wheeledRobot_;
    std::stack<std::pair<std::size_t, std::size_t>> currentStackCoordinate_;
};

#endif // __MAZE_FINALPROJECT_MAZE_MAZE_H__

/**
 * @file main.cpp
 * @brief Final Project: Solving a Maze
 * 
 * #<description> 
 * @copyright Copyright (c) 2019 ENPM808Y:Group 4
 *            This project is released under the MIT License.
 *
 * @author Mohammad Salman
 * @author Lih-Narn Wang
 * @author Kamesh Sarangan
 * @author Yashaarth Todi
 * @author Ashish Patel
 * 
 * @bug No known bugs.
 * @date 05-12-2019
 */

/* -- Includes -- */
#include <iostream>
#include <vector> /* for vector variables */
#include <limits> /* for std::numeric_limits<std::streamsize() */
#include "maze/maze.h"

/**
 * @brief Main function, its a entry point of the program
 * 
 * The function is used to initialize the map of the environment and call the
 * algorithm.
 *
 * @return 0 Exit success
 */
int main() {
  std::string fileLocation = "../maze/maze.txt";
  Maze obj(fileLocation, 31, 46);
  //Maze obj(fileLocation, 9, 18);
  std::cout << "\n\n";
  
  obj.displayMaze();
  
  bool wheeledRobotStatus = obj.findPathBFS('w');
  std::cout << "[LOG]: Finding the path for wheeled robot...\n";
  if(wheeledRobotStatus) {
    std::cout << "[LOG]: Path found for wheeledRobot\n";
    obj.updateMaze('w');
    obj.displayMaze();
  } else {
    std::cout << "[LOG]: Sorry, path doesn't exit for Wheeled Robot\n";
  }
  
  bool trackedRobotStatus = obj.findPathBFS('t');
  std::cout << "[LOG]: Finding the path for tracked robot...\n";
  if(trackedRobotStatus) {
    std::cout << "[LOG]: Path found for tracked robot\n";
    obj.updateMaze('t');
    obj.displayMaze();
  } else {
    std::cout << "[LOG]: Sorry, path doesn't exit for tracked robot\n";
  }
  
  return 0;
}

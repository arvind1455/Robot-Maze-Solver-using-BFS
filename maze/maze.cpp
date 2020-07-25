/* -- Includes -- */
#include <iostream>
#include <vector> /* for vector variables */
#include <limits> /* for std::numeric_limits<std::streamsize() */
#include <fstream> /* for reading the map file */
#include <cstdlib> /* for call system to stop */
#include <utility> /* for std::pair, std::make_pair */
#include <cstdlib> /* for abs function */
#include <list>
#include "maze.h"

Maze::Maze(const std::string file, const std::size_t rows=31, const std::size_t cols=46)
: rows_{rows}, cols_{cols}, mazeFileName_{file} {
  if(createMaze()) {
    std::cout << "[LOG]: Map developed!!!\n";
  } else {
    std::cout << "[FAILED]: Sorry, Map can't be developed. Invalid file\n";
    exit(EXIT_FAILURE); // call the system to stop
  }
  displayMaze();
  if(initMobileRobot()) {
    std::cout << "[LOG]: Start and goal position of MobileRobots are initialized.\n";
  } else {
    std::cout << "[FAILED]: Problem with the MobileRobots initialization.\n";
    exit(EXIT_FAILURE); // call the system to stop
  }
}

Maze::~Maze() {
  std::cout << "[LOG]: Maze Destroyed\n";
}

bool Maze::createMaze() {
  // resize the maze according to rows & columns
  maze_.resize(rows_, std::vector<char>(cols_));
  
  // ifstream is used for reading files
  // we will read from a file stored in mazeFileName_
  std::ifstream inputFile(mazeFileName_.c_str());
  
  // temporary variable to store a map as a string from the file
  std::string line{};
  std::size_t r{0}, c{0};
  
  // open the file stream
  if (inputFile.is_open()) {
    // read the maze from the file into a 2D vector
    while(std::getline(inputFile, line, '\n')){
      c = 0;
      for (auto mazeElement : line) {
        maze_.at(r).at(c) = mazeElement;
        c += 1;
      }
      r += 1;
    }
    // close the file stream
    inputFile.close();
    return true;
  } else {
    std::cerr << "[FAILED]: Couldn't open the file\n";
    return false;
  }
}

void Maze::displayMaze() {
  for(std::size_t i = 0; i < maze_.size(); ++i) {
    // printing coordinates
    if(i < 10) {
      std::cout << i << "  ";
    } else {
      std::cout << i << " ";
    }

    // printing maze
    for(std::size_t j = 0; j < maze_.at(0).size(); ++j) {
      std::cout << maze_.at(i).at(j) << " ";
    }
    std::cout << "\n";
  }
  
  // printing coordinates
  std::cout << "   ";
  for(std::size_t k = 0; k < maze_.at(0).size(); ++k) {
    if (k < 10) {
      std::cout << k << " ";
    } else {
      std::cout << (k/10) << " ";
    }
  }
  std::cout << "\n                       ";
  for(std::size_t f = 10; f < maze_.at(0).size(); ++f) {
    std::cout << f%10 << " ";
  }
  std::cout << "\n";
}

bool Maze::checkCoordinates(std::size_t row, std::size_t column) {
  if((row < rows_ && row >= 0) && (column < cols_ && column >= 0)) {
    return true;
  } else {
    return false;
  }
}

bool Maze::canMove(std::size_t row, std::size_t column) {
  if(maze_.at(row).at(column) != '#') {
    return true;
  } else {
    return false;
  }
}

bool Maze::isTarget(std::size_t row, std::size_t column, std::size_t currentY, std::size_t currentX) {
  if(row == currentY && column == currentX)
    return true;
  else
    return false;
}

bool Maze::initMobileRobot() {
  std::cout << "\nNote:"
            << "\ny_coordinate corresponds to rows in the map above."
            << "\nx_coordinate corresponds to columns in the map above."
            << "\n\n";
  std::pair<std::size_t, std::size_t> coordinateW, coordinateT, coordinateP, coordinateB;
  std::cout << "Enter the start position for the Wheeled x y: ";
  coordinateW = getCoordinates('w');
  std::cout << "Enter the start position for the Tracked x y: ";
  coordinateT = getCoordinates('t');
  std::cout << "Enter the position for plate object x y: ";
  coordinateP = getCoordinates('p');
  std::cout << "Enter the position for bottle object x y: ";
  coordinateB = getCoordinates('b');
  
  wheeledRobot_.setStartLocationX(coordinateW.first);
  wheeledRobot_.setStartLocationY(coordinateW.second);
  trackedRobot_.setStartLocationX(coordinateT.first);
  trackedRobot_.setStartLocationY(coordinateT.second);
    
  char character{}; 
  std::cout << "Please enter 'w' if you want wheeled robot to pick plate object or else enter other character: ";
  std::cin >> character;
  if(character == 'w' || character == 'W') {
    wheeledRobot_.setGoalLocationX(coordinateP.first);
    wheeledRobot_.setGoalLocationY(coordinateP.second);
    trackedRobot_.setGoalLocationX(coordinateB.first);
    trackedRobot_.setGoalLocationY(coordinateB.second);
    return true;
  } else {
    wheeledRobot_.setGoalLocationX(coordinateB.first);
    wheeledRobot_.setGoalLocationY(coordinateB.second);
    trackedRobot_.setGoalLocationX(coordinateP.first);
    trackedRobot_.setGoalLocationY(coordinateP.second);
    return true;
  }
}

bool Maze::findPath(char robot) {
  std::size_t xSCoordinate{}, ySCoordinate{}, xGCoordinate{}, yGCoordinate{};
  
  // vector to store visited Nodes
  std::vector<std::vector<bool>> visitedSet(rows_, std::vector<bool>(cols_, false));
  
  // this stack is used to store all possible action
  std::stack<Travel> trailStack;
  trailStack.push(STAND);
  
  // a stack to store the coordinates
  std::pair<std::size_t, std::size_t> pairCoordinate;
  std::stack<std::pair<std::size_t, std::size_t>> trailStackCoordinate;
  
  // a variable to store the current coordinates
  std::size_t currentXCoordinate{}, currentYCoordinate{};

  // a variable used to store the status of robot stuck case
  bool stuck{true};
  
  // define the direction vectors for Up, Right, Down & Left
  std::vector<int> dx{0, 1, 0, -1};
  std::vector<int> dy{-1, 0, 1, 0};

  if(robot == 'w') {
    xSCoordinate = wheeledRobot_.getStartLocationX();
    ySCoordinate = wheeledRobot_.getStartLocationY();
    xGCoordinate = wheeledRobot_.getGoalLocationX();
    yGCoordinate = wheeledRobot_.getGoalLocationY();
  } else {
    xSCoordinate = trackedRobot_.getStartLocationX();
    ySCoordinate = trackedRobot_.getStartLocationY();
    xGCoordinate = trackedRobot_.getGoalLocationX();
    yGCoordinate = trackedRobot_.getGoalLocationY();
  }
  
  pairCoordinate = std::make_pair(ySCoordinate, xSCoordinate);
  trailStackCoordinate.push(pairCoordinate);
  
  while(!trailStack.empty()) {
    std::size_t neighborX{}, neighborY{};
    
    pairCoordinate = trailStackCoordinate.top();
    currentYCoordinate = pairCoordinate.first;
    currentXCoordinate = pairCoordinate.second;

    // update the current stack
    if(robot == 'w')
      wheeledRobot_.handleMotion(trailStack.top());
    else
      trackedRobot_.handleMotion(trailStack.top());
    currentStackCoordinate_.push(trailStackCoordinate.top());
    
    // remove the coordinates from trail stack
    trailStack.pop();
    trailStackCoordinate.pop();
    
    // mark the current set as visited
    visitedSet.at(currentYCoordinate).at(currentXCoordinate) = true;
    
    // Exploring all four directions horizontally & vertically
    // UP -> RIGHT -> DOWN -> LEFT direction
    for(auto i=0; i<4; ++i) {
      neighborX = currentXCoordinate + dx.at(i);
      neighborY = currentYCoordinate + dy.at(i);
      if(checkCoordinates(neighborY, neighborX)) {
        if(!visitedSet.at(neighborY).at(neighborX)) {
          if(canMove(neighborY, neighborX)) {
            // Update the trailStack
            if(i == 0)
              trailStack.push(UP);
            else if(i == 1)
              trailStack.push(RIGHT);
            else if(i == 2)
              trailStack.push(DOWN);
            else
              trailStack.push(LEFT);
            
            pairCoordinate = std::make_pair(neighborY, neighborX);
            trailStackCoordinate.push(pairCoordinate);
            stuck = false;
            
            if(isTarget(neighborY, neighborX, yGCoordinate, xGCoordinate)) {
              if(robot == 'w') {
                wheeledRobot_.handleMotion(trailStack.top());
                wheeledRobot_.handleMotion(STAND);
                wheeledRobot_.printStack(wheeledRobot_.getStack());
              } else {
                trackedRobot_.handleMotion(trailStack.top());
                trackedRobot_.handleMotion(STAND);
                trackedRobot_.printStack(trackedRobot_.getStack());
              }
              currentStackCoordinate_.push(trailStackCoordinate.top());
              return true;
            }
          }
        }
      }
    }

    while(stuck) {
      if(trailStack.empty())
        return false;
      std::pair<std::size_t, std::size_t> topCurrent = currentStackCoordinate_.top();
      std::pair<std::size_t, std::size_t> topTrail = trailStackCoordinate.top();
      if(abs(topCurrent.first - topTrail.first) + abs(topCurrent.second - topTrail.second) == 1) {
        stuck = false;
        break;
      }
      if(robot == 'w')
        wheeledRobot_.removeOne();
      else
        trackedRobot_.removeOne();
      currentStackCoordinate_.pop();
    }
  }
  return false;
}

bool Maze::findPathBFS(char Robot) {
  // x is the row of the map and y is the column.
  std::size_t xSCoordinate{}, ySCoordinate{}, xGCoordinate{}, yGCoordinate{};
  std::pair<std::size_t, std::size_t> pairCoordinate;
  if(Robot == 'w') {
    xSCoordinate = wheeledRobot_.getStartLocationX();
    ySCoordinate = wheeledRobot_.getStartLocationY();
    xGCoordinate = wheeledRobot_.getGoalLocationX();
    yGCoordinate = wheeledRobot_.getGoalLocationY();
  }
  else {
    xSCoordinate = trackedRobot_.getStartLocationX();
    ySCoordinate = trackedRobot_.getStartLocationY();
    xGCoordinate = trackedRobot_.getGoalLocationX();
    yGCoordinate = trackedRobot_.getGoalLocationY();
  }
  
  // Other variables to initialize.
  std::vector<std::vector<bool>> visited (rows_, std::vector<bool>(cols_, false));
  std::vector<std::vector<std::size_t>> parent (rows_, std::vector<std::size_t>(cols_, 0));

  // Push the start positino into queue
  std::list<std::size_t> queue;
  visited.at(ySCoordinate).at(xSCoordinate) = true;
  queue.push_back(ySCoordinate*100+xSCoordinate);

  // coordinateKey will hold the value of the first element in the queue
  std::size_t coordinateKey{0};
  std::size_t parentIndex{}; 

  // BFS search
  while(!queue.empty()){
    // Assigning value
    coordinateKey = queue.front();
    queue.pop_front();

    // Transform to the coordinate
    ySCoordinate = coordinateKey/100;
    xSCoordinate = coordinateKey%100;

    // This part is for backtracking to get the path
    if (isTarget(ySCoordinate, xSCoordinate, yGCoordinate, xGCoordinate)){
      do{
        parentIndex = parent.at(ySCoordinate).at(xSCoordinate);
        ySCoordinate = parentIndex/100; 
        xSCoordinate = parentIndex%100;
        pairCoordinate = std::make_pair(ySCoordinate, xSCoordinate);
        currentStackCoordinate_.push(pairCoordinate);
        parentIndex = parent.at(ySCoordinate).at(xSCoordinate);
      }while(parentIndex != 0);
      return true;
    }
	
	// Four connected movement
    for (int i=0; i<=3; i++){
      std::size_t yTmp{0}, xTmp{0};
      if (i==0) {yTmp = ySCoordinate + 1; xTmp = xSCoordinate;}
	  else if (i==1) {yTmp = ySCoordinate ; xTmp = xSCoordinate + 1;}
	  else if (i==2) {yTmp = ySCoordinate ; xTmp = xSCoordinate - 1;}
	  else{yTmp = ySCoordinate - 1; xTmp = xSCoordinate;}

      if (checkCoordinates(yTmp, xTmp) && canMove(yTmp, xTmp) && !visited.at(yTmp).at(xTmp))
        {queue.push_back(yTmp*100+xTmp); visited.at(yTmp).at(xTmp) = true; parent.at(yTmp).at(xTmp) = ySCoordinate*100+xSCoordinate;}
    }
  }
  return false;
}

void Maze::updateMaze(char character) {
  if(character == 'w') {
    character = '-';
  } else {
    character = '|';
  }
  while(!currentStackCoordinate_.empty()) {
    std::pair<std::size_t, std::size_t> val = currentStackCoordinate_.top();
    currentStackCoordinate_.pop();
    std::cout << "(" << val.second << ", " << val.first << ")" << "\n";
    if(character == '|') {
      if(maze_.at(val.first).at(val.second) == '-') {
        maze_.at(val.first).at(val.second) = '+';
        continue;
      }
    }
    if(maze_.at(val.first).at(val.second) == 'w' || maze_.at(val.first).at(val.second) == 'p' ||
       maze_.at(val.first).at(val.second) == 'b' || maze_.at(val.first).at(val.second) == 't')
      continue;
    maze_.at(val.first).at(val.second) = character;
  }
}

std::pair<std::size_t, std::size_t> Maze::getCoordinates(char name) {
  std::pair<std::size_t, std::size_t> coordinate;
  std::size_t xCoordinate{}, yCoordinate{};
  // ask user for start position coordinates
  do {
    std::cin >> xCoordinate >> yCoordinate;
    // check for failed extraction
    if (std::cin.fail()) {
      // a) Put us back in 'normal' operation mode
      std::cin.clear();
      // b) remove the bad input
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      // c) request for input again
      std::cout << "Invalid Input, enter integers please.\n";
      std::cout << "Please re-enter the coordinates again: ";
    } else {
      std::cout << "Entered Coordinates (x,y): (" << xCoordinate
                << "," << yCoordinate << ")"
                << "\n";
      // check whether the entered cooridinates are valid or not
      if (checkCoordinates(yCoordinate, xCoordinate)) {
        if (maze_.at(yCoordinate).at(xCoordinate) != 't' && 
            maze_.at(yCoordinate).at(xCoordinate) != 'w' &&
            maze_.at(yCoordinate).at(xCoordinate) != 'p' &&
            maze_.at(yCoordinate).at(xCoordinate) != 'b' && 
            maze_.at(yCoordinate).at(xCoordinate) != '#') {
          maze_.at(yCoordinate).at(xCoordinate) = name;
          coordinate = std::make_pair(xCoordinate, yCoordinate);
          break;
        } else {
          std::cout << "Invalid: Position is occupied.\n";
          std::cout << "Please re-enter the coordinates again: ";
        }
      } else {
        std::cout << "Invalid: Entered coordinates are outside the maze.\n";
        std::cout << "Please re-enter the coordinates again: ";
      }
      // remove any extraneous input so that it doesn't impact next input.
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while (true);
  return coordinate;
}

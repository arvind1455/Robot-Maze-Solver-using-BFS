#include "mobileRobot.h"
#include <iostream>

MobileRobot::MobileRobot() {
  std::cout << "[LOG]: MobileRobot object created using default constructor\n";
}

MobileRobot::MobileRobot(std::size_t startX, std::size_t startY, 
std::size_t goalX, std::size_t goalY)
: startLocationX_(startX), startLocationY_(startY), goalLocationX_(goalX), 
goalLocationY_(goalY){
  std::cout << "[LOG]: MobileRobot object created using parameterized constructor\n";
}

void MobileRobot::handleMotion(Travel travel) {
  stackfsm::state::RobotState* state = new stackfsm::state::StandState();
  if(stack_.empty()) {
    state -> handleMotion(stack_, travel);
  } else {
    stack_.top() -> handleMotion(stack_, travel);
  }
}

void MobileRobot::printStack(std::stack<stackfsm::state::RobotState*> s) {
  while(!s.empty()) {
    std::cout << "[STACK]: " << s.top()-> getName() << "\n";
    s.pop();
  }
}

MobileRobot::~MobileRobot() {
  std::cout << "[LOG]: MobileRobot object destroyed\n";
}


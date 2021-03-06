/* -- Includes -- */
#include "moveDownState.h"
#include "moveLeftState.h"
#include "moveRightState.h"
#include "moveUpState.h"
#include "standState.h"

namespace stackfsm {
  namespace state {
    void MoveUpState::handleMotion(std::stack<RobotState*>& stack, Travel travel) {
      if(travel == RIGHT) {
        if (!stack.empty()){
          stackfsm::state::RobotState* topState = stack.top();
          if (topState->getName() == "MoveUpState"){
            stackfsm::state::RobotState* nextState = new stackfsm::state::MoveRightState();
            stack.push(nextState);
          }
        }
      } else if(travel == DOWN) {
        if (!stack.empty()){
          stackfsm::state::RobotState* topState = stack.top();
          if (topState->getName() == "MoveUpState"){
            stackfsm::state::RobotState* nextState = new stackfsm::state::MoveDownState();
            stack.push(nextState);
          }
        }
      } else if(travel == LEFT) {
        if (!stack.empty()){
          stackfsm::state::RobotState* topState = stack.top();
          if (topState->getName() == "MoveUpState"){
            stackfsm::state::RobotState* nextState = new stackfsm::state::MoveLeftState();
            stack.push(nextState);
          }
        }
      } else if(travel == UP) {
        if (!stack.empty()) {
          stackfsm::state::RobotState* topState = stack.top();
          if (topState->getName() == "MoveUpState"){
            stackfsm::state::RobotState* nextState = new stackfsm::state::MoveUpState();
            stack.push(nextState);
          }
        }
      } else {
        if (!stack.empty()) {
          stackfsm::state::RobotState* topState = stack.top();
          if (topState->getName() == "MoveUpState"){
            stackfsm::state::RobotState* nextState = new stackfsm::state::StandState();
            stack.push(nextState);
          }
        }
      }
    }
  } // __namespace state
} // __namespace stackfsm


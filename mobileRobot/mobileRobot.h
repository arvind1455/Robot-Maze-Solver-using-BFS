#ifndef __MAZE_FINALPROJECT_MOBILEROBOT_MOBILEROBOT_H__
#define __MAZE_FINALPROJECT_MOBILEROBOT_MOBILEROBOT_H__

/* -- Includes -- */
#include <stack>
#include <string>
#include "../robotState/robotState.h" /* for including RobotState class */
#include "../robotState/moveDownState.h"
#include "../robotState/moveLeftState.h"
#include "../robotState/moveUpState.h"
#include "../robotState/moveRightState.h"
#include "../robotState/standState.h"
#include "../utils/travel.h" /*for including robot states */

class MobileRobot {
  public:
    MobileRobot();
    MobileRobot(std::size_t, std::size_t, std::size_t, std::size_t);
    
    inline void setStartLocationX(const std::size_t val) {
      startLocationX_ = val;
    }
    
    inline void setStartLocationY(const std::size_t val) {
      startLocationY_ = val;
    }
  
    inline void setGoalLocationX(const std::size_t val) {
      goalLocationX_ = val;
    }
  
    inline void setGoalLocationY(const std::size_t val) {
      goalLocationY_ = val;
    }
  
    inline std::size_t getStartLocationX() const {
      return startLocationX_;
    }
  
    inline std::size_t getStartLocationY() const {
      return startLocationY_;
    }
  
    inline std::size_t getGoalLocationX() const {
      return goalLocationX_;
    }
  
    inline std::size_t getGoalLocationY() const {
      return goalLocationY_;
    }
  
    void handleMotion(Travel);
    void printStack(std::stack<stackfsm::state::RobotState*>);
  
    inline std::stack<stackfsm::state::RobotState*> getStack() {
      return stack_;
    }
  
    inline void removeOne() {
      stack_.pop();
    }
  
    inline void setStack(std::stack<stackfsm::state::RobotState*> stack){
      stack_ = stack;
    }
  
    virtual ~MobileRobot();

  private:
    const std::string name_;
    std::size_t startLocationX_, startLocationY_;
    std::size_t goalLocationX_, goalLocationY_;
    std::stack<stackfsm::state::RobotState*> stack_;
};

#endif // __MAZE_FINALPROJECT_MOBILEROBOT_MOBILEROBOT_H__

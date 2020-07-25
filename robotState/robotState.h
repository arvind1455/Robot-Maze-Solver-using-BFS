#ifndef __MAZE_FINALPROJECT_ROBOTSTATE_ROBOTSTATE_H__
#define __MAZE_FINALPROJECT_ROBOTSTATE_ROBOTSTATE_H__

#include <stack>
#include <string>
#include "../utils/travel.h"

namespace stackfsm { 
  namespace state {
    class RobotState {
    public:
      virtual void handleMotion(std::stack<RobotState*>&, Travel) {}
      RobotState(std::string name = "RobotState"):name_{name}{}
      inline std::string getName() {
        return name_;
      }
      virtual ~RobotState(){}
    protected:
      std::string name_;
    }; // __RobotState
  } // __state Namespace
} // __stackfsm Namespace

#endif // __MAZE_FINALPROJECT_ROBOTSTATE_ROBOTSTATE_H__

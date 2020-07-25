#ifndef __MAZE_FINALPROJECT_ROBOTSTATE_MOVEUPSTATE_H__
#define __MAZE_FINALPROJECT_ROBOTSTATE_MOVEUPSTATE_H__

/* -- Includes -- */
#include "robotState.h" /* for including base class: RobotState */
#include "../utils/travel.h"

namespace stackfsm {
  namespace state {
    class MoveUpState: public RobotState {
      public:
        MoveUpState():RobotState("MoveUpState"){}
        virtual ~MoveUpState() {}
        virtual void handleMotion(std::stack<RobotState*>&, Travel) override;
    }; // __MoveUpState class
  } // __state Namespace
} // __stackfsm Namespace

#endif // __MAZE_FINALPROJECT_ROBOTSTATE_MOVEUPSTATE_H__

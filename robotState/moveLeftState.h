#ifndef __MAZE_FINALPROJECT_ROBOTSTATE_MOVELEFTSTATE_H__
#define __MAZE_FINALPROJECT_ROBOTSTATE_MOVELEFTSTATE_H__

/* -- Includes -- */
#include "robotState.h" /* for including base class: RobotState */
#include "../utils/travel.h"

namespace stackfsm {
  namespace state {
    class MoveLeftState: public RobotState {
      public:
        MoveLeftState():RobotState("MoveLeftState"){}
        virtual ~MoveLeftState(){}
        virtual void handleMotion(std::stack<RobotState*>&, Travel) override;
    }; // __MoveLeftState
  } // __state Namespace
} // __stackfsm Namespace

#endif // __MAZE_FINALPROJECT_ROBOTSTATE_MOVELEFTSTATE_H__

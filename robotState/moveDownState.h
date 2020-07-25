#ifndef __MAZE_FINALPROJECT_ROBOTSTATE_MOVEDOWNSTATE_H__
#define __MAZE_FINALPROJECT_ROBOTSTATE_MOVEDOWNSTATE_H__

/* -- Includes -- */
#include "robotState.h" /* for including base class: RobotState */
#include "../utils/travel.h"

namespace stackfsm {
  namespace state {
    class MoveDownState: public RobotState {
      public:
        MoveDownState():RobotState("MoveDownState"){}
        virtual ~MoveDownState(){}
        virtual void handleMotion(std::stack<RobotState*>&, Travel) override;
    }; // __MoveDownState class
  } // __state Namespace
} // __stackfsm Namespace

#endif // __MAZE_FINALPROJECT_ROBOTSTATE_MOVEDOWNSTATE_H__

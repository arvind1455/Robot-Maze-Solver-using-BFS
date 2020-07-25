#ifndef __MAZE_FINALPROJECT_ROBOTSTATE_STANDSTATE_H__
#define __MAZE_FINALPROJECT_ROBOTSTATE_STANDSTATE_H__

/* -- Includes -- */
#include "robotState.h" /* for including base class: RobotState */
#include "../utils/travel.h"

namespace stackfsm {
  namespace state {
    class StandState: public RobotState {
      public:
        StandState(): RobotState("StandState"){}
        virtual ~StandState() {}
        virtual void handleMotion(std::stack<RobotState*>&, Travel) override;
    }; // __StandState class
  } // __state Namespace
} // __stackfsm Namespace

#endif // __MAZE_FINALPROJECT_ROBOTSTATE_STANDSTATE_H__

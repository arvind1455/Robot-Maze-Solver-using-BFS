#ifndef __MAZE_FINALPROJECT_ROBOTSTATE_MOVERIGHTSTATE_H__
#define __MAZE_FINALPROJECT_ROBOTSTATE_MOVERIGHTSTATE_H__

/* -- Includes -- */
#include "robotState.h" /* for including base class: RobotState */
#include "../utils/travel.h"

namespace stackfsm {
  namespace state {
    class MoveRightState: public RobotState{
      public:
        MoveRightState():RobotState("MoveRightState"){}
        virtual ~MoveRightState() {}
        virtual void handleMotion(std::stack<RobotState*>&, Travel) override;
    }; // __MoveRightState
  } // __state Namespace
} // __stackfsm Namespace

#endif // __MAZE_FINALPROJECT_ROBOTSTATE_MOVERIGHTSTATE_H__

#ifndef CHECPOINTMANAGER_H
#define CHECKPOINTMANAGER_H

#include <vector>
#include "RunCheckpoint.h"
using namespace std;

class CheckpointManager{
    private:
      vector<RunCheckpoint*> history;

    public:
      CheckpointManager();
      void save(RunCheckpoint* cp);
      RunCheckpoint* undo();
      ~CheckpointManager();
};

#endif
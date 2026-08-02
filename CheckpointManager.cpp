#include "CheckpointManager.h"

CheckpointManager::CheckpointManager() {}

void CheckpointManager::save(RunCheckpoint* cp){
    history.push_back(cp); 
}

RunCheckpoint* CheckpointManager::undo(){
    if (history.empty()){
        return nullptr;
    }

    RunCheckpoint* recent = history.back();
    history.pop_back();
    return recent;
}

CheckpointManager::~CheckpointManager(){
    for (RunCheckpoint* cp : history){
        delete cp;
    }
}
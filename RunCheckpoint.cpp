#include "RunCheckpoint.h"

RunCheckpoint::RunCheckpoint(int stage, vector<string> records) : stage(stage), records(records) {}

int RunCheckpoint::getStage() const{
    return stage;
}

vector<string> RunCheckpoint::getRecords() const{
    return records;
}

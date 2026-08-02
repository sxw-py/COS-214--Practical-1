#ifndef RUNCHECKPOINT_H
#define RUNCHECKPOINT_H

#include <string> 
#include <vector>
using namespace std;

class RunCheckpoint{
    private:
      int stage;
      vector<string> records;
    
    public:
       RunCheckpoint(int state, vector<string> records);
       int getStage() const;
       vector<string> getRecords() const;

};
#endif
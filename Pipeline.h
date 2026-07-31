#ifndef Pipeline_h
#define Pipeline_h
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Task1/ConnectorFactory.h"
#include "Transformation.h"
//#include "Task4/RunCheckpoint.h"

using namespace std;


class Pipeline{
    protected:
        ConnectorFactory *factory;
        vector<Transformation*> steps;
        int stage;
        vector<string> records;
        void connect();
        virtual void extract() = 0;
        void transform();
        virtual void load() = 0;
    public:
        Pipeline(ConnectorFactory*);
        void run();
        void addStep(Transformation*);
        //RunCheckpoint* createCheckpoint();
        //void restore(RunCheckpoint*);
        virtual ~Pipeline();
    
};

class BatchPipeline : public Pipeline{
    protected:
        void extract() override;
        void load() override;
};

class StreamingPipeline : public Pipeline{
    protected:
        void extract() override;
        void load() override;
};




#endif
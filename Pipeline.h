#ifndef Pipeline_h
#define Pipeline_h
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Task1/ConnectorFactory.h"
#include "Transformation.h"

using namespace std;


class Pipeline{
    protected:
        ConnectorFactory *factory;
        vector<Transformation*> steps;
        int stage;
        vector<string> records;
};




#endif
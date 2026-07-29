#ifndef TransformationRegistry_h
#define TransformationRegistry_h
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Transformation.h"

using namespace std;

class TransformationRegistry{
    private:
        map<string, Transformation*> prototypes;
    public:
        void registerStep(string, Transformation*);
        Transformation* create(string);
        ~TransformationRegistry();

};



#endif
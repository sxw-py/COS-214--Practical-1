#ifndef Transformation_h
#define Transformation_h
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Transformation{
    protected:
        string name;
    public:
        Transformation(string);
        virtual Transformation* clone() const = 0;
        virtual vector<string> apply(vector<string> ) = 0;
        string getName();
        virtual ~Transformation();

};

class DeduplicateStep: public Transformation {
    public:
        using Transformation::Transformation; // FIX FOR: base class has parameterised constructor!
                                              //Derived class won't be able to be instantiate without compilation error

        Transformation* clone() const override; 
        vector<string> apply(vector<string> ) override;
};

class AggregateByRegionStep: public Transformation {
    public:
        using Transformation::Transformation; //Same fix as dedup
    
        Transformation* clone() const override; 
        vector<string> apply(vector<string> ) override;
};





#endif
//Task 2 
#include "Transformation.h"

Transformation::Transformation(string name){
    this->name = name;
}

string Transformation::getName(){
    return name;
}

vector<string> DeduplicateStep::apply(vector<string> arr) {
    if (arr.empty()){
        return arr;
    }

    vector<string> trans{};
    trans.push_back(arr[0]);

    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] != arr[i-1]) 
            trans.push_back(arr[i]);
    }


return trans;

} 

Transformation* DeduplicateStep::clone() const{
    return new DeduplicateStep(*this);
}


vector<string> AggregateByRegionStep::apply(vector<string> arr){
    string out = "COUNT=";
    out += to_string(arr.size());
    vector<string> trans{out};
    return trans;
}

Transformation* AggregateByRegionStep::clone() const{
    return new AggregateByRegionStep(*this);
}

Transformation::~Transformation(){
   
}
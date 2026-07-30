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
    for (int i = 0; i < arr.size() - 1; ++i){
        if (arr[i] != arr[i+1]){
            trans.push_back(arr[i]);
        }
    }

    if (arr.size() > 2){ //handles pushing of last element onto the vector 
        if (arr[arr.size()-1] != arr[arr.size()-2]){
            trans.push_back(arr[arr.size()-1]);
        }
    } else if (arr.size() == 2) {
        trans.push_back(arr[0]);
    }

return trans;

} 

Transformation* DeduplicateStep::clone() const{
    return new DeduplicateStep(*this);
}


vector<string> AggregateByRegionStep::apply(vector<string> arr){
    string out = "COUNT=";
    out += to_string(arr.capacity());
    vector<string> trans{out};
    return trans;
}

Transformation* AggregateByRegionStep::clone() const{
    return new AggregateByRegionStep(*this);
}

Transformation::~Transformation(){
   
}
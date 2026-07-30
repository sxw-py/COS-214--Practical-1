#include "TransformationRegistry.h"

void TransformationRegistry::registerStep(string key, Transformation* proto){
    auto iter = prototypes.find(key);

    if (iter != prototypes.end() && iter->second != nullptr){
        delete iter->second;
        iter->second = proto;
    } else{
        prototypes.insert({key,proto});
    }
}

Transformation* TransformationRegistry::create(string key){
     auto iter = prototypes.find(key);

    if (iter != prototypes.end() && iter->second != nullptr){
        return iter->second->clone();
    }else{
        return nullptr;
    }
}

TransformationRegistry::~TransformationRegistry(){
    for (auto &i : prototypes){
        delete i.second;
    }
    prototypes.clear();
}
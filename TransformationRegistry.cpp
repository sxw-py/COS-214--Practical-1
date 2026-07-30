#include "TransformationRegistry.h"

void TransformationRegistry::registerStep(string key, Transformation* proto){
    if (prototypes[key] != NULL){
        delete prototypes[key];
        prototypes[key] = nullptr;
    }

    prototypes[key] = proto;
}

Transformation* TransformationRegistry::create(string key){
    if (prototypes[key] != NULL){
        return prototypes[key]->clone();
    } else {
        return nullptr;
    }
}

TransformationRegistry::~TransformationRegistry(){
    
}
#include "Pipeline.h"

Pipeline:: Pipeline(ConnectorFactory* fact){
    this->factory = fact;
    this->stage = 0;
    this->records = {};
}

void Pipeline::addStep(Transformation* step){
    steps.push_back(step);
}

Pipeline::~Pipeline(){
    for (auto step : steps){
        delete step;
    }

    delete factory;
}

void Pipeline::run(){
    connect();
    extract();
    transform();
    load();
}

void Pipeline::connect() {
    Connector* connector = factory->createConnector();
    cout << "Connecting to " << connector->getSource() << "\n";
    stage = 1;
    delete connector;
}

void Pipeline::transform(){
    for (auto step : steps){
        records = step->apply(records);
    }

    stage = 3;
}

 void BatchPipeline::extract(){
     Connector* connector = factory->createConnector();
     records = connector->extract();
     cout << "Batch extract: " << records.size() << " records\n";
     stage = 2;
     delete connector;
 }

 void BatchPipeline::load(){
    cout << "Batch load: " << records.size() << " records written\n";
    stage = 4;
 }

  void StreamingPipeline::extract(){
     Connector* connector = factory->createConnector();
     records = connector->extract();
     cout << "Streaming extract: " << records.size() << " records\n";
     stage = 2;
     delete connector;
 }

  void StreamingPipeline::load(){
    cout << "Streaming load: " << records.size() << " records streamed\n";
    stage = 4;
 }

 //Task 4 implementations
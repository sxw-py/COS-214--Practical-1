#ifndef CSVCONNECTOR_H
#define CSVCONNECTOR_H

#include "Connector.h"


class CsvConnector : public Connector{
    public:
      CsvConnector();
      vector<string> extract() override; 
};

#endif
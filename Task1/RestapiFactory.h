#ifndef RESTAPIFACTORY_H
#define RESTAPIFACTORY_H

#include "ConnectorFactory.h"

class RestApiFactory : public  ConnectorFactory{
    public:
      Connector* createConnector() override;
};

#endif

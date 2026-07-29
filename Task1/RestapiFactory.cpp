#include "RestapiFactory.h"
#include "RestapiConnector.h"

Connector* RestApiFactory::createConnector(){
    return new RestApiConnector();
}

#include "Connector.h"

Connector::Connector(string source) : source(source) {}


string Connector::getSource() const{
    return source;
}

Connector::~Connector() {}


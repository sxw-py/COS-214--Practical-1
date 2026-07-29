#ifndef POSTGRESCONNECTOR_H
#define POSTGRESCONNECTOR_H

#include "Connector.h"

class PostgresConnector : public Connector{
    public:
      PostgresConnector();
      vector<string> extract() override;
};

#endif 
#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <string>
#include <vector>
using namespace std;

class Connector {
    protected:
     string source;

    public:
     Connector(string source);
     virtual vector<string> extract() = 0;
     string getSource() const;
     virtual ~Connector();
};

#endif
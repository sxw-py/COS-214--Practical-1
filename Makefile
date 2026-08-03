CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

TARGET = engine

SOURCES = \
	main.cpp \
	Transformation.cpp \
	TransformationRegistry.cpp \
	Pipeline.cpp \
	RunCheckpoint.cpp \
	CheckpointManager.cpp \
	Task1/Connector.cpp \
	Task1/ConnectorFactory.cpp \
	Task1/CsvConnector.cpp \
	Task1/CsvFactory.cpp \
	Task1/PostgresConnector.cpp \
	Task1/PostgresFactory.cpp \
	Task1/RestapiConnector.cpp \
	Task1/RestapiFactory.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean

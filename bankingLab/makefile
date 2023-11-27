CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = banking_system

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
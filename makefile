
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

COMPILER=g++
COMPILER_FLAGS=--std=gnu++17 -I includes -I ./../cpp-test/dist -g -O0
LINKER_FLAGS=

SOURCES_TESTS= $(call rwildcard, ./../cpp-test/sources/, *.cpp *.hpp) $(call rwildcard, tests/, *.cpp *.hpp)
SOURCES_APP= $(call rwildcard, sources/, *.cpp *.hpp)

BOOTSTRAP_TESTS= bootstrap/tests.cpp

OBJECTS_TESTS= $(BOOTSTRAP_TESTS:.cpp=.o) $(SOURCES_APP:.cpp=.o) $(SOURCES_TESTS:.cpp=.o)

BIN_TESTS=bin/tests

all: test_run clean

$(BIN_TESTS): $(OBJECTS_TESTS) 
	$(COMPILER) -o $@ $^ $(LINKER_FLAGS)

%.o: %.cpp 
	$(CC) -o $@ -c $< $(COMPILER_FLAGS)

.PHONY: clean all mrproper

test_run: $(BIN_TESTS)
	@$(BIN_TESTS)

clean:
	find . -iname "*.o" | xargs rm

mrproper: clean
	rm -rf $(BIN_TESTS)

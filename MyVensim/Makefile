all: lib_MyLibrary functional_tests  unit_test
	
	@g++ -o bin/fTests test/funcional/mainFTest.cpp bin/functional_tests.o -Lbin -l_myLibrary
	@g++ -o bin/uTests test/unit/mainUTest.cpp bin/unit_system.o bin/unit_flow.o bin/unit_model.o bin/unit_test.o -Lbin -l_myLibrary
	@export LD_LIBRARY_PATH=:"../MyVensim/bin"

#Unit Tests

unit_test: test/unit/unit_system.cpp test/unit/unit_flow.cpp test/unit/unit_model.cpp test/unit/unit_test.cpp
	@g++ -c test/unit/unit_system.cpp -o bin/unit_system.o -Wall
	@g++ -c test/unit/unit_flow.cpp -o bin/unit_flow.o -Wall
	@g++ -c test/unit/unit_model.cpp -o bin/unit_model.o -Wall
	@g++ -c test/unit/unit_test.cpp -o bin/unit_test.o -Wall

#Functional Tests

functional_tests: test/funcional/functional_tests.cpp
	@g++ -c test/funcional/functional_tests.cpp -o bin/functional_tests.o -Wall

#Classes

lib_MyLibrary: src/FlowImpl.cpp src/ModelImpl.cpp src/SystemImpl.cpp
	@g++ -c -fPIC src/SystemImpl.cpp -o bin/SystemImpl.o -Wall 
	@g++ -c -fPIC src/FlowImpl.cpp -o bin/FlowImpl.o -Wall
	@g++ -c -fPIC src/ModelImpl.cpp -o bin/ModelImpl.o -Wall 
	@g++ -shared -o bin/lib_myLibrary.so bin/SystemImpl.o bin/ModelImpl.o bin/FlowImpl.o
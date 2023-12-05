all: FlowImpl.o ModelImpl.o SystemImpl.o lib_MyVensim.so functional_tests.o unit_system.o unit_flow.o unit_model.o unit_test.o
	
	@g++ -o bin/fTests test/funcional/mainFTest.cpp bin/functional_tests.o -Lbin -l_myLibrary

	@g++ -o bin/uTests test/unit/mainUTest.cpp bin/unit_system.o bin/unit_flow.o bin/unit_model.o bin/unit_test.o -Lbin -l_myLibrary

	@export LD_LIBRARY_PATH=:'../MyVensim/bin'

#Unit Tests

unit_system.o: test/unit/unit_system.cpp
	@g++ -c test/unit/unit_system.cpp -o bin/unit_system.o -Wall

unit_flow.o: test/unit/unit_flow.cpp
	@g++ -c test/unit/unit_flow.cpp -o bin/unit_flow.o -Wall

unit_model.o: test/unit/unit_model.cpp
	@g++ -c test/unit/unit_model.cpp -o bin/unit_model.o -Wall

unit_test.o: test/unit/unit_test.cpp
	@g++ -c test/unit/unit_test.cpp -o bin/unit_test.o -Wall

# #Functional Tests

functional_tests.o: test/funcional/functional_tests.cpp
	@g++ -c test/funcional/functional_tests.cpp -o bin/functional_tests.o -Wall

#Classes

lib_MyVensim.so: src/FlowImpl.cpp src/ModelImpl.cpp src/SystemImpl.cpp
	@g++ -shared -o bin/lib_myLibrary.so bin/SystemImpl.o bin/ModelImpl.o bin/FlowImpl.o

SystemImpl.o: src/SystemImpl.cpp
	@g++ -c -fPIC src/SystemImpl.cpp -o bin/SystemImpl.o -Wall 

ModelImpl.o: src/ModelImpl.cpp
	@g++ -c -fPIC src/ModelImpl.cpp -o bin/ModelImpl.o -Wall 

FlowImpl.o: src/FlowImpl.cpp
	@g++ -c -fPIC src/FlowImpl.cpp -o bin/FlowImpl.o -Wall

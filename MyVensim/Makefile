all: bin/FlowImpl.o bin/ModelImpl.o bin/SystemImpl.o bin/functional_tests.o bin/mainFTest.o 
	@g++ bin/FlowImpl.o bin/ModelImpl.o bin/SystemImpl.o bin/functional_tests.o bin/mainFTest.o -o bin/fTests
	@rm -r bin/*.o

#Functional Tests

bin/mainFTest.o: test/funcional/mainFTest.cpp
	@g++ -c test/funcional/mainFTest.cpp -o bin/mainFTest.o -Wall


bin/functional_tests.o: test/funcional/functional_tests.cpp
	@g++ -c test/funcional/functional_tests.cpp -o bin/functional_tests.o -Wall




#Classes

bin/SystemImpl.o: src/SystemImpl.cpp
	@g++ -c src/SystemImpl.cpp -o bin/SystemImpl.o -Wall


bin/ModelImpl.o: src/ModelImpl.cpp
	@g++ -c src/ModelImpl.cpp -o bin/ModelImpl.o -Wall


bin/FlowImpl.o: src/FlowImpl.cpp
	@g++ -c src/FlowImpl.cpp -o bin/FlowImpl.o -Wall


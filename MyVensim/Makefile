all: bin/flow.o bin/model.o bin/system.o bin/functional_tests.o bin/mainFTest.o 
	@g++ bin/flow.o bin/model.o bin/system.o bin/functional_tests.o bin/mainFTest.o -o bin/fTests


#Functional Tests

bin/mainFTest.o: test/funcional/mainFTest.cpp
	@g++ -c test/funcional/mainFTest.cpp -o bin/mainFTest.o -Wall


bin/functional_tests.o: test/funcional/functional_tests.cpp
	@g++ -c test/funcional/functional_tests.cpp -o bin/functional_tests.o -Wall




#Classes

bin/system.o: src/system.cpp
	@g++ -c src/system.cpp -o bin/system.o -Wall


bin/model.o: src/model.cpp
	@g++ -c src/model.cpp -o bin/model.o -Wall


bin/flow.o: src/flow.cpp
	@g++ -c src/flow.cpp -o bin/flow.o -Wall


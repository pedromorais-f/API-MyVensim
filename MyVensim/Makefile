all: bin/Flow.o bin/Model.o bin/System.o bin/functional_tests.o bin/mainFTest.o 
	@g++ bin/Flow.o bin/Model.o bin/System.o bin/functional_tests.o bin/mainFTest.o -o bin/fTests
	@rm -r bin/*.o

#Functional Tests

bin/mainFTest.o: test/funcional/mainFTest.cpp
	@g++ -c test/funcional/mainFTest.cpp -o bin/mainFTest.o -Wall


bin/functional_tests.o: test/funcional/functional_tests.cpp
	@g++ -c test/funcional/functional_tests.cpp -o bin/functional_tests.o -Wall




#Classes

bin/System.o: src/System.cpp
	@g++ -c src/System.cpp -o bin/System.o -Wall


bin/Model.o: src/Model.cpp
	@g++ -c src/Model.cpp -o bin/Model.o -Wall


bin/Flow.o: src/Flow.cpp
	@g++ -c src/Flow.cpp -o bin/Flow.o -Wall


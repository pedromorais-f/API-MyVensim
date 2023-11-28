all: 
	g++ -c src/*.cpp test/funcional/*.cpp test/unit/*.cpp -fpic -g -Wall
	g++ FlowImpl.o ModelImpl.o SystemImpl.o functional_tests.o unit_test.o unit_flow.o unit_system.o unit_model.o -shared -o lib_MyVensim.so -g -Wall
	
	g++ functional_tests.o  test/funcional/mainFTest.cpp -L. -l_MyVensim -o fTests -g -Wall
	export LD_LIBRARY_PATH=:'/home/projeto/framework-para-construcao-de-simulacoes-baseadas-na-dinamica-de-sistemas/MyVensim'
	
	g++  unit_test.o unit_flow.o unit_system.o unit_model.o test/unit/mainUTest.cpp -L. -l_MyVensim -o uTests -Wall -g
	export LD_LIBRARY_PATH=:'/home/projeto/framework-para-construcao-de-simulacoes-baseadas-na-dinamica-de-sistemas/MyVensim'
	
	rm -r *.o




# all: bin/FlowImpl.o bin/ModelImpl.o bin/SystemImpl.o bin/functional_tests.o bin/mainFTest.o bin/unit_system.o bin/unit_flow.o bin/unit_test.o bin/unit_model.o bin/mainUTest.o
# 	@g++ bin/FlowImpl.o bin/ModelImpl.o bin/SystemImpl.o bin/functional_tests.o bin/mainFTest.o -o bin/fTests
	
# 	@g++ bin/FlowImpl.o bin/ModelImpl.o bin/SystemImpl.o bin/unit_system.o bin/unit_flow.o bin/unit_test.o bin/unit_model.o bin/mainUTest.o -o bin/uTests
	
# 	@rm -r bin/*.o

#Unit Tests


# bin/unit_system.o: test/unit/unit_system.cpp
# 	@g++ -c test/unit/unit_system.cpp -o bin/unit_system.o -Wall

# bin/unit_flow.o: test/unit/unit_flow.cpp
# 	@g++ -c test/unit/unit_flow.cpp -o bin/unit_flow.o -Wall

# bin/unit_model.o: test/unit/unit_model.cpp
# 	@g++ -c test/unit/unit_model.cpp -o bin/unit_model.o -Wall

# bin/unit_test.o: test/unit/unit_test.cpp
# 	@g++ -c test/unit/unit_test.cpp -o bin/unit_test.o -Wall

# bin/mainUTest.o: test/unit/mainUTest.cpp
# 	@g++ -c test/unit/mainUTest.cpp -o bin/mainUTest.o -Wall

# #Functional Tests


# bin/mainFTest.o: test/funcional/mainFTest.cpp
# 	@g++ -c test/funcional/mainFTest.cpp -o bin/mainFTest.o -Wall


# bin/functional_tests.o: test/funcional/functional_tests.cpp
# 	@g++ -c test/funcional/functional_tests.cpp -o bin/functional_tests.o -Wall


# #Classes

# bin/SystemImpl.o: src/SystemImpl.cpp
# 	@g++ -c src/SystemImpl.cpp -o bin/SystemImpl.o -Wall


# bin/ModelImpl.o: src/ModelImpl.cpp
# 	@g++ -c src/ModelImpl.cpp -o bin/ModelImpl.o -Wall


# bin/FlowImpl.o: src/FlowImpl.cpp
# 	@g++ -c src/FlowImpl.cpp -o bin/FlowImpl.o -Wall


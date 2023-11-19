
#Unit Tests

unit_tests: bin/FlowImpl.o bin/ModelImpl.o bin/SystemImpl.o bin/unit_system.o bin/unit_flow.o bin/unit_test.o bin/unit_model.o bin/main.o
	@g++ bin/FlowImpl.o bin/ModelImpl.o bin/SystemImpl.o bin/unit_system.o bin/unit_flow.o bin/unit_test.o bin/unit_model.o bin/main.o -o bin/uTests
	@rm -r bin/*.o

bin/unit_system.o: test/unit/unit_system.cpp
	@g++ -c test/unit/unit_system.cpp -o bin/unit_system.o -Wall

bin/unit_flow.o: test/unit/unit_flow.cpp
	@g++ -c test/unit/unit_flow.cpp -o bin/unit_flow.o -Wall

bin/unit_model.o: test/unit/unit_model.cpp
	@g++ -c test/unit/unit_model.cpp -o bin/unit_model.o -Wall

bin/unit_test.o: test/unit/unit_test.cpp
	@g++ -c test/unit/unit_test.cpp -o bin/unit_test.o -Wall

bin/main.o: test/unit/main.cpp
	@g++ -c test/unit/main.cpp -o bin/main.o -Wall

#Functional Tests

# functional_tests: bin/FlowImpl.o bin/ModelImpl.o bin/SystemImpl.o bin/functional_tests.o bin/mainFTest.o 
# 	@g++ bin/FlowImpl.o bin/ModelImpl.o bin/SystemImpl.o bin/functional_tests.o bin/mainFTest.o -o bin/fTests
# 	@rm -r bin/*.o

# bin/mainFTest.o: test/funcional/mainFTest.cpp
# 	@g++ -c test/funcional/mainFTest.cpp -o bin/mainFTest.o -Wall


# bin/functional_tests.o: test/funcional/functional_tests.cpp
# 	@g++ -c test/funcional/functional_tests.cpp -o bin/functional_tests.o -Wall


#Classes

bin/SystemImpl.o: src/SystemImpl.cpp
	@g++ -c src/SystemImpl.cpp -o bin/SystemImpl.o -Wall


bin/ModelImpl.o: src/ModelImpl.cpp
	@g++ -c src/ModelImpl.cpp -o bin/ModelImpl.o -Wall


bin/FlowImpl.o: src/FlowImpl.cpp
	@g++ -c src/FlowImpl.cpp -o bin/FlowImpl.o -Wall


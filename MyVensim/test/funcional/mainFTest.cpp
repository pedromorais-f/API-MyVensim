#include "functional_tests.hpp"


int main(int argc, char const *argv[]){
    
    logisticTest();
    exponentialTest();
    complexTest();

    cout << "\nAll tests passed\n" << endl; 
    return 0;
}

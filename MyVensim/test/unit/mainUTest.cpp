#include "unit_test.hpp"

int main(){
    
    cout << "Starting System Unit Test\n" << endl;
    run_test_System();
    cout << "Passed All System Tests\n" << endl;

    cout << "Starting Flow Unit Test\n" << endl;
    run_test_Flow();
    cout << "Passed All Flow Tests\n" << endl;

    cout << "Starting Model Unit Test\n" << endl;
    run_test_Model();
    cout << "Passed All Model Tests\n" << endl;
    
    return 0;
}

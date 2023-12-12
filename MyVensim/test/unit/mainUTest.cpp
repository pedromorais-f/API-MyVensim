#include "unit_test.hpp"
#include<iostream>
#include "unit_handlebody.hpp"

using namespace std;

int main(){
    cout << "Starting HandleBody Unit Test\n" << endl;
    run_unit_test_HandleBody();
    cout << "Passed All HandleBody Tests\n" << endl;
    
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

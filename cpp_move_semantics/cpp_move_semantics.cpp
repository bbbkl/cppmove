#include <iostream>

//#include "basics/customer.hpp"
//#include "basics/customerimpl.hpp"
//#include "basics/customer1.cpp"
#include "basics/customerimpl.cpp"
//#include "param_passing.h"

#include "basics/initclassicperf.cpp"
//#include "basics/initallperf.cpp"
//#include "basics/initmoveperf.cpp"

using namespace std;


int main(int argc, const char** argv)
{
    cout << "sample start ...\n";

    run_sample_customerimpl();

    /*int num = (argc > 1 ? atoi(argv[1]) : 1000);
    show_performance_classic(num);*/

    cout << "\n... sample end.\n";
}


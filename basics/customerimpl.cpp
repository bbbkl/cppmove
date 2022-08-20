//********************************************************
// The following code example is taken from the book
//  C++ Move Semantics - The Complete Guide
//  by Nicolai M. Josuttis (www.josuttis.com)
//  http://www.cppmove.com
//
// The code is licensed under a
//  Creative Commons Attribution 4.0 International License
//  http://creativecommons.org/licenses/by/4.0/
//********************************************************


#include "customerimpl.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int run_sample_customerimpl()
{
  const size_t count = 12;
  std::vector<Customer> coll;
  //coll.reserve(count);
  for (int i=0; i< count; ++i) {
    coll.push_back(Customer{"TestCustomer " + std::to_string(i-5)}); 
  }

  cout << "\n" << "container initial # = " << coll.size();
  for(auto& item : coll)
    cout << "\n" << item;

  std::cout << "\n\n" << "---- sort():\n";
  std::sort(coll.begin(), coll.end(),
            [] (const Customer& c1, const Customer& c2) {
              return c1.getName() < c2.getName();
            });

  cout << "\n\n" << "container after # = " << coll.size();
  for(auto& item : coll)
    cout << "\n" << item;

  return 0;
}


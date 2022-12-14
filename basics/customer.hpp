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
#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cassert>

class Customer {
 private:
  std::string name;         // name of the customer
  std::vector<int> values;  // some values of the customer
 public:
  Customer(const std::string& n)
   : name{n} {
      assert(!name.empty());
  }

  // stops move to work!
  // Customer(const Customer& other) : name(other.name), values(other.values) {}; 
  
  // stops move to work!
  // ~Customer() = default; // stops move to work!
  
  // stops move to work!
  // Customer& operator=(const Customer& other) { if(this != &other) { name = other.name; values = other.values; } }

  std::string getName() const {
    return name;
  }

  void addValue(int val) {
    values.push_back(val);
  }

  friend std::ostream& operator<< (std::ostream& strm, const Customer& cust) {
    strm << '[' << cust.name << ": ";
    for (int val : cust.values) {
      strm << val << ' ';
    }
    strm << ']';
    return strm;
  }
};


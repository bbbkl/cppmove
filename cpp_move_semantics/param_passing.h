#pragma once

#include <string>
#include <iostream>

class A
{
public:
  A(const std::string& name) : _name(name) { std::cout << "ctor A " << _name << '\n'; }
  std::string name() const { return _name; }
private:
  std::string _name;
};

class B
{
public:
  B(A a) : _a(std::move(a)) {}

  std::string name() const { return _a.name(); }
private:
  A _a;
};

void show_param_passing()
{
  A a("my_a");
  B b(a);
  std::cout << "name a=" << a.name()
    << " name b=" << b.name() << '\n';

  A a2("my_a2");
  B b2(std::move(a2));
  std::cout << "name a2=" << a2.name()
    << " name b2=" << b2.name() << '\n';

  B b3(A("my_a3"));
  std::cout << "name b3=" << b3.name() << '\n';
}
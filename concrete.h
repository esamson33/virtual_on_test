#include <iostream>
class a
{
public:
  virtual ~a() = default;
  
  void something() {
    std::cout << "<a> do something" << std::endl;
    do_something();
  }
  
private:
  VIRTUAL_ON_TEST void do_something() {
    std::cout << "<a> doing something" << std::endl;
  }
};

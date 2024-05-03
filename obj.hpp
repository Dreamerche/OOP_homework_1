#include <iostream>

class Object3d {
public:
  Object3d(char*);


private:
  int numerator;
  int denominator;

  void simplify();
  int find_gcd() const;
};
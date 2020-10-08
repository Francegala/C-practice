//
//  polimorph.cpp
//  HelloWorld
//
//  Created by Francesco Galassi on 07/10/2020.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// Base class
class Modules {
  public:
    void worth() {
    cout << "Usually around 20 credits" <<endl;
  }
};

// Derived class
class SoftwareEng : public Modules {
  public:
    void worth() {
    cout << "from 20 to 40" <<endl;
   }
};

// Derived class
class Cpp : public Modules {
  public:
    void worth() {
    cout << "just 10" <<endl;
  }
};

int poliTest() {
  Modules myModule;
  SoftwareEng firstYear;
  Cpp thirdYear;

  myModule.worth();
  firstYear.worth();
  thirdYear.worth();
  return 0;
}

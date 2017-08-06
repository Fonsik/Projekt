#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Statek {
  char znak;
 public:
  int rozmiar;
  int ruch;
  int atak;
  Statek (char, int, int, int) ;
  virtual ~Statek() {};
  int trafienie ;
  void hit ();

 Statek::Statek (char _c, int _r, int _x, int _a) : znak (_c), rozmiar (_r), ruch (_x), atak (_a) {}


};

int main ()
{
    Statek Motorowka ('M',2,2,0);
    Statek Niszczyciel ('#',3,1,1);
    Statek Torpedowiec ('%',4,0,2);
    return 0;
}



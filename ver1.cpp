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
  Statek () {};
  Statek (char, int, int, int) ;
  ~Statek () {};
  int trafienie=0 ;
  bool status ();

  void hit ()
  {
      trafienie++;
  }
};

 Statek::Statek (char c, int r, int x, int a)
 {
     znak=c;
     rozmiar=r;
     ruch=x;
     atak=a;
 }
bool Statek::status()
{
 if (trafienie>0)
    {
       return 1;
    }
 else
    {
       return 0;
    }
}
int main ()
{
    Statek Motorowka ('M',2,2,0);
    Statek Niszczyciel ('#',3,1,1);
    Statek Torpedowiec ('%',4,0,2);
    return 0;
}



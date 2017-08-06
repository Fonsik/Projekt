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
    const int pl=8;
    int board[pl][pl];

    for (int i=0; i<pl; i++)
    {
        for (int j=0; j<pl; j++)
        {
            board[i][j]=46;
        }
    }

    char kol=65;

    for (int i=0; i<pl; i++)
    {
        char z=kol+i;
        cout<<z;
        cout<<" ";
        for (int j=0; j<pl; j++)
        {
            char z=board[i][j];
            cout <<z;
            cout<<" ";
        }
        cout <<""<< endl;
    }

    return 0;
}



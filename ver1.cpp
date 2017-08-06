#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Statek {

 public:
  char znak;
  int rozmiar;
  int ruch;
  int atak;
  Statek () {};
  Statek (char, int, int, int) ;
  ~Statek () {};
  int trafienie=0 ;
  bool status ();
  char zwzn ();

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
    srand(time(0));
    Statek Motorowka ('M',2,2,0);
    Statek Niszczyciel ('#',3,1,1);
    Statek Torpedowiec ('%',4,0,2);

    const int pl=8;
    const int lst=4;
    int board[pl][pl];

    cout<<"  ";

    for (int i=0; i<pl; i++)
    {

        cout<<i+1;
        cout<<" ";
    }

    cout<<""<<endl;

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
        kol+=i;
        cout<<kol;
        cout<<" ";
        for (int j=0; j<pl; j++)
        {
            char z=board[i][j];
            cout <<z;
            cout<<" ";
        }
        cout <<""<< endl;
    }
    int wspl;

    for (int i=0; i<lst; i++)
    {
        wspl=rand()%10+1;
    }


    return 0;
}




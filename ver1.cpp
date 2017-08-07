#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Statek {

 public:
  char znak;
  int rozmiar;          //Klasa Statek uniwersalna dla kazdego typu statku
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
      trafienie++;      // Licznik trafien
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
       return 1;      //Status, czy zatopiony.
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
    Statek Niszczyciel ('#',3,1,1);   //Tworzenie statkow na samym poczatku, wygodniej tak, niz tworzyc podklasy.
    Statek Torpedowiec ('%',4,0,2);

    const int pl=8;   //Rozmiar planszy
    const int lst=4;  //Liczba statkow
    int board[pl][pl];  //Plansza

    cout<<"  ";

    for (int i=0; i<pl; i++)
    {

        cout<<i+1;
        cout<<" ";              //Tworzenie wspolrzednych
    }

    cout<<""<<endl;

    for (int i=0; i<pl; i++)
    {
        for (int j=0; j<pl; j++)
        {
            board[i][j]=46;         //Rysowanie planszy
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

    cout<<""<<endl;
    cout << "Nacisnij ENTER, by rozpoczac losowanie." << endl;      //Sprawia wrazenie profesjonalizmu
    cin.ignore();

    int kier; //Wskazuje na polozenie statku, 0 dla pionu, 1 dla poziomu.

    for (int i=0; i<lst; i++)
    {
        kier=rand()%2;
        wspl=rand()%pl+1;
        cout<<kier<<endl;
    }


    return 0;
}




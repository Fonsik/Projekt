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
  int ilosc;
  Statek () {};
  Statek (char, int, int, int, int) ;
  ~Statek () {};
  int trafienie=0 ;
  bool status ();
  char zwzn ();

  void hit ()
  {
      trafienie++;      // Licznik trafien
  }
};

 Statek::Statek (char c, int r, int x, int a, int b)
 {
     znak=c;
     rozmiar=r;
     ruch=x;
     atak=a;
     ilosc=b;
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
    Statek Motorowka ('M',2,2,0,2);
    Statek Niszczyciel ('#',3,1,1,1);   //Tworzenie statkow na samym poczatku, wygodniej tak, niz tworzyc podklasy.
    Statek Torpedowiec ('%',4,0,2,1);
    char woda = '.';
    const int pl=8;      //Rozmiar planszy
    int board[pl][pl];  //Plansza
    vector <Statek> Magazyn {Motorowka, Niszczyciel,Torpedowiec};
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
            board[i][j]=woda;         //Rysowanie planszy
        }
    }



    for (int i=0; i<pl; i++)
    {
        char kol=65;
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
    int wspl1, wspl2;

    cout<<""<<endl;
    cout << "Nacisnij ENTER, by rozpoczac losowanie." << endl;      //Sprawia wrazenie profesjonalizmu
    cin.ignore();

    int kier; //Wskazuje na polozenie statku, 0 dla pionu, 1 dla poziomu.

    for(int x=0; x<Magazyn.size(); x++)
    {
        for (int i=0; i<(Magazyn[x]).ilosc; i++)
        {
            p:
            kier=rand()%2;
            wspl1=rand()%pl;
            wspl2=rand()%pl;

            if (board[wspl1][wspl2]!=woda ||board[wspl1+1][wspl2]!=woda ||board[wspl1-1][wspl2]!=woda ||board[wspl1][wspl2+1]!=woda ||board[wspl1][wspl2-1]!=woda )
            {
                goto p;
            }
            else{

            if (kier==0 && wspl2 <= (Magazyn[x]).rozmiar )         //Sprawdzenie warunku, czy statek nie wyjdzie poza plansze.
            {
                for(int j=0; j<(Magazyn[x]).rozmiar; j++)
                {
                    board [wspl1][wspl2+j]=(Magazyn[x]).znak;
                }
            }

            else if (kier==0 && wspl2 > (Magazyn[x]).rozmiar)
            {
            for(int j=0; j<(Magazyn[x]).rozmiar; j++)
                {
                    board [wspl1][wspl2-j]=(Magazyn[x]).znak;
                }
            }

            else if (kier==1 && wspl1 <= (Magazyn[x]).rozmiar)
            {
                for(int j=0; j<(Magazyn[x]).rozmiar; j++)
                {
                    board [wspl1+j][wspl2]=(Magazyn[x]).znak;
                }
            }

            else
            {
                for(int j=0; j<(Magazyn[x]).rozmiar; j++)
                {
                    board [wspl1-j][wspl2]=(Magazyn[x]).znak;
                }
            }
        }
        }
    }

     cout<<"  ";

    for (int i=0; i<pl; i++)
    {

        cout<<i+1;
        cout<<" ";
    }

    cout<<""<<endl;


    for (int i=0; i<pl; i++)
    {
        char kol=65;
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


    return 0;
}




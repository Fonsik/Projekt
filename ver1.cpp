#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Statek {

 public:

  string nazwa;
  char znak;
  int rozmiar;          //Klasa Statek uniwersalna dla kazdego typu statku
  int ruch;
  int atak;
  int ilosc;
  Statek () {};
  Statek (string, char, int, int, int, int) ;
  ~Statek () {};
  int trafienie=0 ;
  bool status ();
  char zwzn ();

  void hit ()
  {
      trafienie++;      // Licznik trafien
  }
};

 Statek::Statek (string s, char c, int r, int x, int a, int b)
 {
     nazwa=s;
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
    Statek Motorowka ("Motorowka", 'M',2,2,0,2);
    Statek Niszczyciel ("Niszczyciel",'#',3,1,1,1);   //Tworzenie statkow na samym poczatku, wygodniej tak, niz tworzyc podklasy.
    Statek Torpedowiec ("Torpedowiec",'%',4,0,2,1);
    char woda = '.';
    const int pl=8;      //Rozmiar planszy
    char board[pl][pl];  //Plansza
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


    cout<<""<<endl;

    cout << "Nacisnij ENTER, by rozpoczac losowanie." << endl;      //Sprawia wrazenie profesjonalizmu
    cin.ignore();


    int wspl1, wspl2, kier; //Wskazuje na polozenie statku; kier 0 dla pionu, 1 dla poziomu.

    for(unsigned int x=0; x<Magazyn.size(); x++)
    {
        for (int i=0; i<(Magazyn[x]).ilosc; i++)
        {
            r:

            kier=rand()%2;
            wspl1=rand()%pl;
            wspl2=rand()%pl;

            if(board[wspl1][wspl2]!=woda)
            {
                goto r;
            }


            if (kier==0 && wspl2 <= (Magazyn[x]).rozmiar )              //Sprawdzenie warunku, czy statek nie wyjdzie poza plansze
            {
                for (unsigned int q=0; q<Magazyn.size(); q++)                            //Wybor znaku
                    {
                       for (int w=-1; w<2; w++)                                      //Test wzdluz jednej wspolrzednej
                            {
                                for (int y=-1; y<(Magazyn[x]).rozmiar+2; y++)       //Test wzdluz statku
                                {
                                    if(board[wspl1+w][wspl2+y]==(Magazyn[q]).znak)
                                    {
                                        goto r;                                       //Ostateczny test kolizji i powrot do losowania
                                    }
                                }
                            }
                    }

                for(int j=0; j<(Magazyn[x]).rozmiar; j++)
                {
                    board [wspl1][wspl2+j]=(Magazyn[x]).znak;
                }
            }
            else if (kier==0 && wspl2 > (Magazyn[x]).rozmiar)
            {
                for (unsigned int q=0; q<Magazyn.size(); q++)
                    {
                       for (int w=-1; w<2; w++)
                            {
                                for (int y=-1; y<(Magazyn[x]).rozmiar+2; y++)
                                {
                                    if(board[wspl1+w][wspl2-y]==(Magazyn[q]).znak)
                                    {
                                        goto r;
                                    }
                                }
                            }
                    }
            for(int j=0; j<(Magazyn[x]).rozmiar; j++)
                {
                    board [wspl1][wspl2-j]=(Magazyn[x]).znak;
                }
            }

            else if (kier==1 && wspl1 <= (Magazyn[x]).rozmiar)
            {
               for (unsigned int q=0; q<Magazyn.size(); q++)
                    {
                       for (int w=-1; w<2; w++)
                            {
                                for (int y=-1; y<(Magazyn[x]).rozmiar+2; y++)
                                {
                                    if(board[wspl1+y][wspl2+w]==(Magazyn[q]).znak)
                                    {
                                        goto r;
                                    }
                                }
                            }
                    }
                for(int j=0; j<(Magazyn[x]).rozmiar; j++)
                {
                    board [wspl1+j][wspl2]=(Magazyn[x]).znak;
                }
            }

            else
            {
               for (unsigned int q=0; q<Magazyn.size(); q++)
                    {
                       for (int w=-1; w<2; w++)
                            {
                                for (int y=-1; y<(Magazyn[x]).rozmiar+2; y++)
                                {
                                    if(board[wspl1-y][wspl2+w]==(Magazyn[q]).znak)
                                    {
                                        goto r;
                                    }
                                }
                            }
                    }
                for(int j=0; j<(Magazyn[x]).rozmiar; j++)
                {
                    board [wspl1-j][wspl2]=(Magazyn[x]).znak;
                }
            }

        }
    }

     cout<<"  ";

    for (int i=0; i<pl; i++)        //Ponowne rysowanie planszy
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

    p:
    cout<< "Wybierz statek. Wspolrzedne sa postaci [znak][liczba] "<< endl;
    int w2;
    unsigned char w;
    cout << "Podaj pierwsza wspolrzedna: ";
    cin >> w;
    cout << "Podaj druga wspolrzedna: ";
    cin >> w2;
    cout <<""<< endl;
    w2-=1;

    if (w>=65 && w<97)
    {
        w-=65;
    }
    else
    {
        w-=97;
    }



if (w2>pl-1 || w>pl-1 ||w2<0 ||w<0)
    {
       cout << "To nie sa poprawne wspolrzedne" << endl;
       cout<<""<<endl;
       goto p;
    }
    else if (board[w][w2]==woda)
    {
        cout << "Wybierz statek, nie wode." << endl;
        cout<<""<<endl;
        goto p;
    }
    else
    {
        for (unsigned int i=0; i<Magazyn.size(); i++)
        {
            if (board[w][w2]==(Magazyn[i]).znak)
                {
                    cout << (Magazyn[i]).nazwa <<endl;
                }
        }
    }



    return 0;
}




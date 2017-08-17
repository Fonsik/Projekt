/** @file */

/**

* @file ver1.cpp
* @author Tomasz Fas
* @date 17.08.2017
* @brief Podstawowa wersja projektu "Statki".
*
* \mainpage Opis
* Jedyne co robi ten program, to rysowanie planszy i losowanie pozycji statkow.
* No i jeszcze statek mozna wybrac.
*
* Na program skalada sie jedna klasa: Statek i dwie funcje: plansza() oraz losowanie().
*
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

/**
*Klasa Statek uniwersalna dla kazdego typu statku.

*Dla wersji uproszczonej wygodniej jest stworzyc uniwersaslna klase, niz rozne podklasy.

*/
class Statek {

 public:

  string nazwa;
  char znak;
  int rozmiar; /**< Dlugosc statku */
  int ruch;  /**< O ile pol moze sie statek przemiescic */
  int atak; /**< Ile strzalow moze oddac statek */
  int ilosc; /**< Ile jest statkow danego typu */
  Statek () {};
  Statek (string, char, int, int, int, int) ;
  ~Statek () {};
  int trafienie=0 ;
  bool status ();

  /**
   *Licznik trafien

   *Dodany dla ozdoby
   */
  void hit ()
  {
      trafienie++;
  }
};
/**
* Konstruktor klasy Statki
*
* \param s Nazwa
* \param c Znak
* \param r Rozmiar
* \param x Liczba pol ruchu
* \param a Liczba atakow
* \param b Liczba statkow
*/
 Statek::Statek (string s, char c, int r, int x, int a, int b)
 {
     nazwa=s;
     znak=c;
     rozmiar=r;
     ruch=x;
     atak=a;
     ilosc=b;
 }

 /**
 *Status, czy zatopiony.

 *Niezbyt przydatny w tej wersji

 */
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

const char woda = '.'; /**< Uniwersalny znak dla wody. */
const int pl=8; /**< Stala wielkosc planszy. */


/** \brief Funkcja rysuje plansze do gry.
 *
 * Argumentem wejscia jest tablica znakow,
 * Rozmiar tablicy jest uzalezniony
 * od globalnej stalej /param pl.
 *
 */
int plansza (char board [pl][pl])
{
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

    cout<<""<<endl;

    return 0;
}

/** \brief Funkcja losuje pozycja statkow
 * \param Magazyn wektor gromadzacy wszystkie statki.
 * \param board to plansza.
 *
 * Funkcja ta losuje poczatkowe wspolrzedne statku oraz jego kierunek,
 * a nastepnie na podstawie tych danych oraz wielkosci statku okresla,
 * czy wystepuja kolizje z innymi obiektami. Jesli nie funkcja ta wpisuje statek
 * do tablicy, czyli planszy.
 */
int losowanie (vector <Statek> Magazyn, char board [pl][pl])
{
   int wspl1, wspl2, kier;

    // Poczatek losowania pozycji statk�w.

    for(unsigned int x=0; x<Magazyn.size(); x++)
    {
        for (int i=0; i<(Magazyn[x]).ilosc; i++)
        {
            r:

            kier=rand()%2;       // Wskazuje na polozenie statku. 0 dla pionu, 1 dla poziomu.
            wspl1=rand()%pl;
            wspl2=rand()%pl;

            if(board[wspl1][wspl2]!=woda)
            {
                goto r;
            }



            if (kier==0 && wspl2 <= (Magazyn[x]).rozmiar )  // Sprawdzenie warunku, czy statek nie wyjdzie poza plansz�.
            {
                for (unsigned int q=0; q<Magazyn.size(); q++)   // Wszystkie znaki statkow zostana sprawdzone.
                    {
                       for (int w=-1; w<2; w++)     //Test z bokow statku i wzdluz statku.
                            {
                                for (int y=-1; y<(Magazyn[x]).rozmiar+2; y++)   // Test jednej kolumny\wiersza.
                                {

                                    if(board[wspl1+w][wspl2+y]==(Magazyn[q]).znak)  // Ostateczny test kolizji i ewentualny powrot do losowania.
                                    {
                                        goto r;
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

    return 0;
}

/** \brief Funkcja glowna.
 *
 * W funkcji glownej powolano do istnienia statki oraz plansze.
 * Korzystajac z funkcji narysowano plansze oraz wylosowano pozycje statkow.
 * W funkcji main() jest zaimplementowana funkcja wyboru statku.
 *
 */
int main ()
{
    srand (time(0));

    Statek Motorowka ("Motorowka", 'M',2,2,0,2);    //Tworzenie potrzebnych statkow
    Statek Niszczyciel ("Niszczyciel",'#',3,1,1,1); // Mozna latwo dodac nowy statek, stworzyc po prostu nowy obiekt.
    Statek Torpedowiec ("Torpedowiec",'%',4,0,2,1);

    char board[pl][pl]; // Tablica znakow jako plansza.

    vector <Statek> Magazyn {Motorowka, Niszczyciel,Torpedowiec};    // Latwy dostep do wszystkich statkow.

    for (int i=0; i<pl; i++) // Wypelnianie planszy woda.
    {
        for (int j=0; j<pl; j++)
        {
            board[i][j]=woda;
        }
    }

    plansza (board);

    cout << "Nacisnij ENTER, by rozpoczac losowanie." << endl;  // Sprawia wrazenie profesjonalizmu
    cin.ignore();

    losowanie(Magazyn, board);
    plansza (board);

    p:
    cout <<""<< endl;
    cout<< "Wybierz statek. Wspolrzedne sa postaci [znak][liczba] "<< endl; // Wybor statku.
    unsigned char w1, w2;   // Takie wspolrzedne powoduja najmniej bledow
    cout << "Podaj pierwsza wspolrzedna: ";
    cin >> w1;
    cout << "Podaj druga wspolrzedna: ";
    cin >> w2;
    cout <<""<< endl;
    w2-=49;

    if (w1>=65 && w1<97)
    {
        w1-=65;
    }
    else
    {
        w1-=97;
    }



if (w2>pl-1 || w1>pl-1 ||w2<0 ||w1<0) // Warunek poprawnosci wspolrzednych.
    {
       cout << "To nie sa poprawne wspolrzedne" << endl;
       cout<<""<<endl;
       goto p;
    }
    else if (board[w1][w2]==woda)
    {
        cout << "Wybierz statek, nie wode." << endl;
        cout<<""<<endl;
        goto p;
    }
    else
    {
        for (unsigned int i=0; i<Magazyn.size(); i++)
        {
            if (board[w1][w2]==(Magazyn[i]).znak)
                {
                    cout << (Magazyn[i]).nazwa <<endl;
                }
        }
    }




    return 0;
}




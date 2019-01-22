#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;
string litera[37][9];
string litery[9];
short int n=0;
// n - ilosc wierszy w trojkacie

string dzielnik[2];
// dzielnik - tablica liczb, które mają być dzielnikami zaznaczonych liczb w trojkacie

string liczba[2000][2000];
// liczba[][] - tablica liczb w trojkacie pascala

string odpowiedz="";

void pobierz_dane()
{
    ifstream plik;
    plik.open("litery.txt");
    for(int i=0; i<36; i++)
    {
        for(int j=0; j<9; j++)
        {
            getline(plik,litera[i][j]);
            litera[i][j]+=" ";
        }
    }
    plik.close();
}

void wypisz(string napis)
{
    for(int i=0; i<9; i++)
    {
        litery[i]="";
    }
    int dlugosc = napis.size();
    int ktora=0;
    for(int i=0; i<dlugosc; i++)
    {
        switch(napis[i])
        {
        case 'A':
            ktora=0;
            break;
        case 'B':
            ktora=1;
            break;
        case 'C':
            ktora=2;
            break;
        case 'D':
            ktora=3;
            break;
        case 'E':
            ktora=4;
            break;
        case 'F':
            ktora=5;
            break;
        case 'G':
            ktora=6;
            break;
        case 'H':
            ktora=7;
            break;
        case 'I':
            ktora=8;
            break;
        case 'J':
            ktora=9;
            break;
        case 'K':
            ktora=10;
            break;
        case 'L':
            ktora=11;
            break;
        case 'M':
            ktora=12;
            break;
        case 'N':
            ktora=13;
            break;
        case 'O':
            ktora=14;
            break;
        case 'P':
            ktora=15;
            break;
        case 'R':
            ktora=16;
            break;
        case 'S':
            ktora=17;
            break;
        case 'T':
            ktora=18;
            break;
        case 'U':
            ktora=19;
            break;
        case 'V':
            ktora=20;
            break;
        case 'W':
            ktora=21;
            break;
        case 'X':
            ktora=22;
            break;
        case 'Y':
            ktora=23;
            break;
        case 'Z':
            ktora=24;
            break;
        case '0':
            ktora=25;
            break;
        case '1':
            ktora=26;
            break;
        case '2':
            ktora=27;
            break;
        case '3':
            ktora=28;
            break;
        case '4':
            ktora=29;
            break;
        case '5':
            ktora=30;
            break;
        case '6':
            ktora=31;
            break;
        case '7':
            ktora=32;
            break;
        case '8':
            ktora=33;
            break;
        case '9':
            ktora=34;
            break;
        case ' ':
            ktora=36;
            break;
        default:
            ktora=35;
            break;
        }
        for(int j=0; j<9; j++)
        {
            if(ktora==36)
            {
                litery[j]+="     ";
            }
            else
            {
                litery[j]+=litera[ktora][j];
            }
        }
    }
    for(int i=0; i<9; i++)
    {
        cout<<litery[i]<<endl;
    }
}

string dodaj(string pierwsza, string druga)
{
    pierwsza="0"+pierwsza;
    druga="0"+druga;
    int dlugosc=0;
    string pomocnicza="";
    if(pierwsza.size()>druga.size())
    {
        dlugosc=pierwsza.size();
        for(int i=0; i<(dlugosc-druga.size());i++)
        {
            pomocnicza+="0";
        }
        druga=pomocnicza+druga;
    }
    else
    {
        dlugosc=druga.size();
        for(int i=0; i<(dlugosc-pierwsza.size());i++)
        {
            pomocnicza+="0";
        }
        pierwsza=pomocnicza+pierwsza;
    }
    int suma=0;
    int pomocnicza1=0;
    string liczba="";
    for(int i=1;i<dlugosc;i++)
    {
        char liczba_p=pierwsza.at(dlugosc-i)-48;
        char liczba_d=druga.at(dlugosc-i)-48;
        int p = static_cast<int>(liczba_p);
        int d = static_cast<int>(liczba_d);
        suma = p+d+pomocnicza1;
        pomocnicza1=0;
        if(suma>9)
        {
            pomocnicza1=(suma-suma%10)/10;
            suma=suma%10;
        }
        stringstream asd ;
        asd<<suma;
        string dsa ="";
        asd>>dsa;
        liczba=dsa+liczba;
    }
    if(pomocnicza1!=0)
    {
        stringstream asd ;
        asd<<pomocnicza1;
        string dsa ="";
        asd>>dsa;
        liczba=dsa+liczba;
    }
    return liczba;
}

string modulo(string pierwsza, string druga)
{
    int p_s=pierwsza.size(), d_s=druga.size();
    int reszta=0, dzielnik=0, pomocnicza=1;
    for(int i=1; i<=d_s; i++)
    {
        char liczba_d=druga.at(d_s-i)-48;
        int d = static_cast<int>(liczba_d)*pomocnicza;
        dzielnik+=d;
        pomocnicza*=10;
    }
    for(int i=p_s; i>0;i--)
    {
        char liczba_p=pierwsza.at(p_s-i)-48;
        int p = static_cast<int>(liczba_p);
        reszta= ((reszta*10)+p)%dzielnik;
    }
    stringstream asd ;
    asd<<reszta;
    string dsa ="";
    asd>>dsa;
    return dsa;
}

//funkcja zapelniajaca tablice liczba[][], wyliczonymi przez nia liczbami
void zapelnij_tablice()
{
    int x=0,y=0;
    // x - wiersz w tablicy
    // y - kolumna w tablicy
    while(y<500)
    {
        if(x==y)
        {
            liczba[x][y]="1";
            y++;
            x=-1;
        }
        else if(x==0)
        {
            liczba[x][y]="1";
        }
        else
        {
            liczba[x][y]= dodaj(liczba[x][y-1],liczba[x-1][y-1]);
        }
        x++;
    }
}

//funkcja wypisujaca zadana liczbe spacji
void wypisz_spacje(int ile)
{
    for(int i=0;i<ile;i++)
    {
        cout<<" ";
    }
}

int main()
{
    pobierz_dane();
    HANDLE uchwyt;
    uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(uchwyt,240);
    ofstream plik;
    wypisz("LICZE");
    cout<<endl;
     /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                         czyszczenie tablicy liczba[][]                                                  //
    for(int x=0;x<500;x++)
    {
        for(int y=0;y<500;y++)
        {
            liczba[x][y]="0";
        }
    }
     /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                         zapelnianie tablicy liczba[][]                                                  //
    zapelnij_tablice();
    wypisz("PROGRAM NAPISAL ADAM NOWAK KL 2A");
     /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                              glowna petla programu                                                      //
    do
    {
         /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //                                              podawanie danych                                                           //
        do
        {
            wypisz("PODAJ LICZBE WIERSZY");
            cout <<endl;
            cin>>n;
        }  while(n<=0||n>=500);
        do
        {
            wypisz("WPISZ PIERWSZA LICZBE PRZEZ KTORA MAJA BYC PODZIELNE ZAZNACZONE LICZBY");
            cout<<endl;
            cin>>dzielnik[0];
            wypisz("WPISZ DROGA LICZBE PRZEZ KTORA MAJA BYC PODZIELNE ZAZNACZONE LICZBY");
            cout<<endl;
            cin>>dzielnik[1];
        }while(dzielnik[0]=="0"||dzielnik[1]=="0");

         /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //                                              wypisywanie wynikow                                                        //
        cout<<endl<<endl;
        for(int y=0;y<n;y++)
        {
            cout<<endl;
            wypisz_spacje(n-y);
            for(int x=0;x<n;x++)
            {
                if(liczba[x][y]!="0")//wypisuje tylko te liczby z tablicy, ktore nie sa zerami
                {
                    if(modulo(liczba[x][y],dzielnik[0])=="0")
                    {
                        SetConsoleTextAttribute(uchwyt,153);
                    }
                    else if(modulo(liczba[x][y],dzielnik[1])=="0")
                    {
                        SetConsoleTextAttribute(uchwyt,238);
                    }
                    else
                    {
                        SetConsoleTextAttribute(uchwyt,119);
                    }
                    if((modulo(liczba[x][y],dzielnik[0])=="0")&&(modulo(liczba[x][y],dzielnik[1])=="0"))
                    {
                        SetConsoleTextAttribute(uchwyt,170);
                    }
                    cout<<"x";
                    SetConsoleTextAttribute(uchwyt,255);
                    if(x!=y)
                    {
                        cout<<" ";
                    }
                }
                SetConsoleTextAttribute(uchwyt,255);
            }
        }
        SetConsoleTextAttribute(uchwyt,240);
        cout<<endl;
    }while(1);
    return 0;
}

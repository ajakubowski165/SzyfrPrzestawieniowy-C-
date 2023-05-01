//Szyfr przestawieniowy zapisany w tablicy jednowymiarowej 3-elementowej.

#include<iostream>
#include<string>
#include<cstdlib> //do atoi
#include<windows.h> //do sleep
#include<conio.h> //do exit

using namespace std;

void kreska();
void alfabet();
void cyfry();
void wersja1(string tekst, int tab[]);
void wersja2(string tekst, int tab[]);
void wersja3(string tekst, int tab[]);
void wersja4(string tekst, int tab[]);

//male litery: 97-122
//duze litery: 65-90
//cyfry: 48-57

int main()
{

    string tekst;
    int a,b,c,decyzja;
    string aS,bS,cS,decyzjaS;

    cout<<"=========SZYFR=======PRZESTAWIENIOWY======="<<endl<<endl;

    cout<<"Wprowadz tekst do zaszyfrowania:"<<endl;
    getline(cin, tekst);

    kreska();

    cout<<"Wypelnij tablice tab[a,b,c] liczbami calkowitymi dodatnimi:"<<endl;
    cout<<"a:";
    cin>>aS;
    a=atoi(aS.c_str()); //konwertuje wartość zapisaną w łańcuchu znaków do postaci liczby typu int, zwraca 0 jesli to nie mozliwe
    while(a<=0)
    {
        cout<<"Nieprawidlowe a! Podaj prawidlowa liczbe!"<<endl;
        cin>>aS;
        a=atoi(aS.c_str());
    }

    cout<<"b:";
    cin>>bS;
    b=atoi(bS.c_str());
    while(b<=0)
    {
        cout<<"Nieprawidlowe b! Podaj liczbe dodatnia!"<<endl;
        cin>>bS;
        b=atoi(bS.c_str());
    }

    cout<<"c:";
    cin>>cS;
    c=atoi(cS.c_str());
    while(c<=0)
    {
        cout<<"Nieprawidlowe c! Podaj liczbe dodatnia!"<<endl;
        cin>>cS;
        c=atoi(cS.c_str());
    }

    int tab[3]= {a,b,c};

    kreska();

    cout<<"Wybierz w jaki sposob chcesz zaszyfrowac swoj tekst?"<<endl;
    cout<<"1. Szyfr cyfr oraz liter"<<endl;
    cout<<"2. Szyfr cyfr"<<endl;
    cout<<"3. Szyfr malych liter"<<endl;
    cout<<"4. Szyfr wielkich liter"<<endl<<endl;
    cout<<"Wpisz liczbe przyporzadkowana danej opcji: ";
    cin>>decyzjaS;
    decyzja=atoi(decyzjaS.c_str());

    while((decyzja!=1) && (decyzja!=2) && (decyzja!=3) && (decyzja!=4))
    {
        cout<<"Nieprawidlowy wybor! Wybierz opcje z przedzialu 1-4"<<endl;
        cin>>decyzjaS;
        decyzja=atoi(decyzjaS.c_str());
    }

    kreska();

    if(decyzja==1)wersja1(tekst, tab);
    if(decyzja==2)wersja2(tekst, tab);
    if(decyzja==3)wersja3(tekst, tab);
    if(decyzja==4)wersja4(tekst, tab);

    return 0;
}


void kreska()
{
    cout<<endl;
    cout<<"==========================================="<<endl<<endl;
}

void alfabet()
{
    cout<<endl;
    cout<<"Alfabet:"<<endl;
    cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"<<endl<<endl;
}

void cyfry()
{
    cout<<"Cyfry:"<<endl;
    cout<<"0 1 2 3 4 5 6 7 8 9"<<endl<<endl;
}


void wersja1(string tekst, int tab[])
{
    int m,k,x;

    m=0;

    for(int i=0; i<tekst.size(); i++)
    {
        x=tekst[i];

        if(x!=32) //jesli dany znak nie jest spacj¹
        {

            if(x>=48 && x<=57)//SZYFR CYFRY
            {
                 m=m%3;
                 k=x+tab[m];

                if(k>57)
                {
                    while(k>67)k=k-10; //odejmujemy ilosc cyfr
                    k=k%57; //reszta z dzielenia przez 57
                }
                else k=k-47;

                x=47+k;
                m++;
            }

            if(x>=65 && x<=90)//SZYFR WIELKIEJ LITERY
            {
                 m=m%3;
                 k=x+tab[m];
                if(k>90)
                {
                    while(k>116)k=k-26;
                    k=k%90;
                }
                else k=k-64;
                x=64+k;
                m++;
            }

            if(x>=97 && x<=122)//SZYFR MALEJ LITERY
            {
                 m=m%3;
                 k=x+tab[m];
                if(k>122)
                {
                    while(k>148)k=k-26;
                    k=k%122;
                }
                else k=k-96;
                x=96+k;
                m++;
            }
            tekst[i]=x;
        }
    }

    alfabet();
    cyfry();
    kreska();


    cout<<endl;

    cout<<"Zaszyfrowany tekst:"<<endl;
    for(int i=0; i<tekst.size(); i++)
    {
        Sleep(100);

        while(!((tekst[i]==32) || (tekst[i]>=48 && tekst[i]<=57) || (tekst[i]>=65 && tekst[i]<=90) || (tekst[i]>=97 && tekst[i]<=122))) //omijamy te elementy, ktore nie naleza do danych kategorii
           {
            if(i==tekst.size())exit(0);
            if(i<tekst.size())i++;
        }
        cout<<tekst[i];
    }
}

void wersja2(string tekst, int tab[])
{
    int m,k,x;

     m=0;

    for(int i=0; i<tekst.size(); i++)
    {
        x=tekst[i];

        if(x!=32) //jesli dany znak nie jest spacj¹
        {
            if(x>=48 && x<=57)//SZYFR CYFRY
            {
                m=m%3;
                 k=x+tab[m];

                if(k>57)
                {
                    while(k>67)k=k-10;
                    k=k%57;
                }
                else k=k-47;

                x=47+k;
                m++;
            }
            tekst[i]=x;
        }
    }

    cyfry();
    kreska();

    cout<<endl;

    cout<<"Zaszyfrowany tekst:"<<endl;

    for(int i=0; i<tekst.size(); i++)
    {
        Sleep(100);
        while(!((tekst[i]==32) || (tekst[i]>=48 && tekst[i]<=57)))
        {
            if(i<tekst.size())i++;
        }

        cout<<tekst[i];
    }
}

void wersja3(string tekst, int tab[])
{
    int m,k,x;

    m=0;

    for(int i=0; i<tekst.size(); i++)
    {
        x=tekst[i];

        if(x!=32) //jesli dany znak nie jest spacj¹
        {

            if(x>=97 && x<=122)//SZYFR MALEJ LITERY
            {
                 m=m%3;
                 k=x+tab[m];

                if(k>122)
                {
                    while(k>148)k=k-26;
                    k=k%122;
                }
                else k=k-96;
                x=96+k;
                m++;
            }
            tekst[i]=x;
        }
    }

    alfabet();
    kreska();


    cout<<endl;

    cout<<"Zaszyfrowany tekst:"<<endl;
    for(int i=0; i<tekst.size(); i++)
    {
        Sleep(100);

        while(!((tekst[i]==32)  || (tekst[i]>=97 && tekst[i]<=122)))
            {
            if(i==tekst.size())exit(0);
            if(i<tekst.size())i++;
        }
        cout<<tekst[i];
    }
}

void wersja4(string tekst, int tab[])
{

    int m,k,x;
    m=0;

    for(int i=0; i<tekst.size(); i++)
    {
        x=tekst[i];

        if(x!=32) //jesli dany znak nie jest spacj¹
        {

            if(x>=65 && x<=90)//SZYFR WIELKIEJ LITERY
            {
                 m=m%3;
                 k=x+tab[m];

                if(k>90)
                {
                    while(k>116)k=k-26;
                    k=k%90;
                }
                else k=k-64;
                x=64+k;
                m++;
            }
            tekst[i]=x;
        }
    }

    alfabet();
    kreska();


    cout<<endl;

    cout<<"Zaszyfrowany tekst:"<<endl;
    for(int i=0; i<tekst.size(); i++)
    {
        Sleep(100);

        while(!((tekst[i]==32)  || (tekst[i]>=65 && tekst[i]<=90) ))
           {
            if(i==tekst.size())exit(0);
            if(i<tekst.size())i++;
        }

        cout<<tekst[i];
    }
}


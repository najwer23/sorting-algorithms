// Sorotwanie towarow po wadze.
// Od najmiejszej lub od najwiekszej. warto nie uruchamiac dwoch sortowan dla duzej liczby produktow
// Towar posiada id, wage i nazwe.
// Sortowanie glupie babelkowe.
// Jest zlym algorytmem sortujacym, ale wartym uwagi
// optymistycznie O(n), pesymistycznie O(n^3)

//DZIALANIE
// jesli przegladana para jest zlej kolejnosci, zamien miejscami i rozpocznij od nowa.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


// definicja klasy
// hermetyzacja, czyli public, private i protected
class Product
{
    string name;
    int id;
    int weight;
public:
    Product();
    ~Product();
    void load(int tag);
    void show();
    friend void stupidSort(vector <Product>& products, string howToSort);
};

// zastanowic sie nad przeciazeniem operatora wysw.
void Product::show()
{
    cout <<"Id: "<<id<<" ";
    cout <<"Name: "<<name<<" ";
    cout <<"Weight: "<<weight<<endl;
}

void Product::load(int tag)
{
    // tutaj mozna rozwinac o losowanie nazwy
    // nie zajmuje sie tym
    name="A";
    weight=rand()%100000+1;
    id=tag;
}


// konstruktor
Product::Product()
    : name("test")
    , id(-1)
    , weight (-1)
{
    ;
}

// destruktor
Product::~Product()
{
    ;
}

// funkcja zaprzyjazniona pozwala korzystac z pol klasy Product
void stupidSort(vector <Product>& products, string howToSort)
{
    for( int i=0; i<products.size(); i++ )
    {
        //od najmniejszej wagi do najwiekszej
        if(howToSort=="down")
        {
            if(products[i].weight>products[i+1].weight)
            {
                swap(products[i],products[i+1]);
                // tutaj warto wiedziec kiedy inkrementuje for
                i=-1;
            }
        }

        //od najwiekszej wagi do najmniejszej
        if(howToSort=="up")
        {
            if(i!=products.size()-1)
            {
                if(products[i].weight<products[i+1].weight)
                {
                    swap(products[i],products[i+1]);
                    i=-1;
                }
            }

        }


    }

}


int main()
{
    //DANE
    srand(time(NULL));
    Product product;
    vector <Product> products;
    // ile produktow
    // dla 2000 towarow okolo 5s
    int N=5;

    // wczytaj produkty do vectora
    for (int i=0; i<N; i++ )
    {
        // losowe wartosci produktu
        product.load(i);
        products.push_back(product);
    }


    cout<<"Produkty przed sortowaniem po wadze:"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }

    // SORTOWANIE od najmniejszej wagi do najwiekszej
    string howToSort="down";
    stupidSort(products, howToSort);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najmniejszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }


    // SORTOWANIE od najwiekszej do najmniejszej
    howToSort="up";
    stupidSort(products, howToSort);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najwiekszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }

}

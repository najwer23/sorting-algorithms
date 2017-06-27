// Sorotwanie towarow po wadze.
// Od najmiejszej lub od najwiekszej. warto nie uruchamiac dwoch sortowan dla duzej liczby produktow
// Towar posiada id, wage i nazwe.
// Sortowanie glupie babelkowe.
// Jest zlym algorytmem sortujacym powy¿ej 5000 produktów
// optymistycznie O(n), pesymistycznie O(n^2)

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
    friend void bubbleSort(vector <Product>& products, string howToSort);
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
void bubbleSort(vector <Product>& products, string howToSort)
{
    for( int i=0; i<products.size()-1; i++ )
    {
        for (int j=0; j<products.size()-1; j++)
        {
            //od najmniejszej wagi do najwiekszej
            if(howToSort=="down")
            {
                if(products[j].weight>products[j+1].weight)
                    swap(products[j],products[j+1]);
            }

            if(howToSort=="up")
            {
                if(products[j].weight<products[j+1].weight)
                    swap(products[j],products[j+1]);
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
    // dla 5000 towarow okolo 2s
    // dla 10000 towarow 7s
    // dla 50000 +100s wylaczylem po 100s.
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
    bubbleSort(products, howToSort);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najmniejszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }


    // SORTOWANIE od najwiekszej do najmniejszej
    howToSort="up";
    bubbleSort(products, howToSort);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najwiekszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }

}

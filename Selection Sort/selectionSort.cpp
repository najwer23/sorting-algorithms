// Sorotwanie towarow po wadze.
// Od najmiejszej lub od najwiekszej. warto nie uruchamiac dwoch sortowan dla duzej liczby produktow
// Towar posiada id, wage i nazwe.

// WAZNE dla nieskomplikowanych zastosowan sortowanie przez wybieranie jest najlepszym wyborem
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
    friend void selectionSort(vector <Product>& products, string howToSort);
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
// dla coraz mniejszych fragmentow tablicy znajdz element najmnijeszy
// i zamien go z pierwszym elementem rozpatrywanwgo fragmentu
void selectionSort(vector <Product>& products, string howToSort)
{

    int i=0;
    int j;
    int minPosition;
    // od najmniejszej wagi do najwiekszej
    if(howToSort=="down")
    {
        while(i<products.size()-1)
        {
            minPosition=i;
            j=i+1;
            while(j<=products.size()-1)
            {
                if(products[j].weight<products[minPosition].weight)
                    minPosition=j;
                j++;
            }
            // zamiana minimalnego z pierwszym
            if(minPosition!=i)
                swap(products[i],products[minPosition]);
            i++;
        }
    }

    if(howToSort=="up")
    {
        while(i<products.size()-1)
        {
            minPosition=i;
            j=i+1;
            while(j<=products.size()-1)
            {
                if(products[j].weight>products[minPosition].weight)
                    minPosition=j;
                j++;
            }
            // zamiana minimalnego z pierwszym
            if(minPosition!=i)
                swap(products[i],products[minPosition]);
            i++;
        }
    }
}


int main()
{
    //DANE
    srand(time(NULL));
    Product product;
    vector <Product> products;

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
    selectionSort(products, howToSort);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najmniejszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }


    // SORTOWANIE od najwiekszej do najmniejszej
    howToSort="up";
    selectionSort(products, howToSort);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najwiekszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }

}

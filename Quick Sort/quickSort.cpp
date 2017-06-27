// Sorotwanie towarow po wadze.
// Od najmiejszej lub od najwiekszej. warto nie uruchamiac dwoch sortowan dla duzej liczby produktow
// Towar posiada id, wage i nazwe.
// Sortowanie qucik Sort.
// O(nlogn), pesymistycznie O(n^2), a nawet przepelnieie

//DZIALANIE
// dzialanie oparte na piwocie
// metoda dziel i zwyciezaj
// dzieli zbior sortujacy na 2 podzbiory

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
    friend void quick(vector <Product>& products, string howToSort, int left, int right);
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
void quick(vector <Product>& products, string howToSort, int left, int right)
{
    if(howToSort=="down")
    {
        if(right<=left)
            return;

        int i=left-1;
        int j=right+1;
        Product pivot;
        pivot.weight=products[(left+right)/2].weight;

        while(1)
        {
            while(pivot.weight>products[++i].weight);
            while(pivot.weight<products[--j].weight);
            if(i<=j)
            {
                swap(products[i],products[j]);
            }
            else
                break;
        }

        if(j > left)
            quick(products, "down", left, j);
        if(i < right)
            quick(products, "down", i, right);
    }


    if(howToSort=="up")
    {
        if(right<=left)
            return;

        int i=left-1;
        int j=right+1;
        Product pivot;
        pivot.weight=products[(left+right)/2].weight;

        while(1)
        {
            while(pivot.weight<products[++i].weight);
            while(pivot.weight>products[--j].weight);
            if(i<=j)
            {
                swap(products[i],products[j]);
            }
            else
                break;
        }

        if(j > left)
            quick(products, "up", left, j);
        if(i < right)
            quick(products, "up", i, right);
    }
}


int main()
{
    //DANE
    srand(time(NULL));
    Product product;
    vector <Product> products;
    // ile produktow
    // dla 2000 od razu
    // dla 5000 od razu
    // dla 10000 od razu
    // dla 50000 od razu
    // dla 100000 od razu
    // dla 500000 od razu
    // dla 1000000 1s
    // dla 5000000 2s
    // dla 10000000 6s

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
    quick(products, howToSort, 0,products.size()-1);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najmniejszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }


    // SORTOWANIE od najwiekszej do najmniejszej
    howToSort="up";
    quick(products, howToSort, 0,products.size()-1);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najwiekszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }

}

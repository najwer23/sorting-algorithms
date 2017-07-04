// Sorotwanie towarow po wadze.
// Od najmiejszej lub od najwiekszej. warto nie uruchamiac dwoch sortowan dla duzej liczby produktow
// Towar posiada id, wage i nazwe.

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
    friend void shellSort(vector <Product>& products, string howToSort);
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
void shellSort(vector <Product>& products, string howToSort)
{
    //ciag odstepow
    int h, k, j;
    Product testElement;
    for(h=1; h<products.size(); h=3*h+1)
        ;
    //nasze h, nasz przyrost w sortowaniu
    h/=9;

    //od najmniejszej wagi do najwiekszej
    if(howToSort=="down")
    {
        while(h)
        {
            for(j = products.size()-h-1; j >= 0; j--)
            {
                testElement=products[j];
                k=j+h;
                while((k<products.size())&&testElement.weight>products[k].weight)
                {
                    products[k-h]=products[k];
                    k=k+h;

                }
                products[k-h]=testElement;
            }
            h/=3;

        }
    }

    if(howToSort=="up")
    {
        while(h)
        {
            for(j = products.size()-h-1; j >= 0; j--)
            {
                testElement=products[j];
                k=j+h;
                while((k<products.size())&&testElement.weight<products[k].weight)
                {
                    products[k-h]=products[k];
                    k=k+h;

                }
                products[k-h]=testElement;
            }
            h/=3;

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
    shellSort(products, howToSort);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najmniejszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }


    // SORTOWANIE od najwiekszej do najmniejszej
    howToSort="up";
    shellSort(products, howToSort);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najwiekszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }

}

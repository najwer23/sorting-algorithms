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
    friend void insertionSort(vector <Product>& products, string howToSort);
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
void insertionSort(vector <Product>& products, string howToSort)
{
    Product saveElement;
    int i=1;
    int j;
    int k;
    //od najmniejszej wagi do najwiekszej
    if(howToSort=="down")
    {
        while(i<=products.size()-1)
        {
            j=0;
            while(products[j].weight<products[i].weight)
                j++;

            //zapamietaj miejsce wstawianego
            saveElement=products[i];

            //przepycham wieksze
            k=i-1;
            while(k>=j)
            {
                products[k+1]=products[k];
                k--;
            }
            //wstaw
            products[j]=saveElement;
            i++;
        }
    }

    if(howToSort=="up")
    {
        while(i<=products.size()-1)
        {
            j=0;
            while(products[j].weight>products[i].weight)
                j++;

            //zapamietaj miejsce wstawianego
            saveElement=products[i];

            //przepycham wieksze
            k=i-1;
            while(k>=j)
            {
                products[k+1]=products[k];
                k--;
            }
            //wstaw
            products[j]=saveElement;
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
    insertionSort(products, howToSort);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najmniejszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }


    // SORTOWANIE od najwiekszej do najmniejszej
    howToSort="up";
    insertionSort(products, howToSort);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najwiekszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }

}

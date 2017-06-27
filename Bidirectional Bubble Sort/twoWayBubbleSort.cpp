// Sorotwanie towarow po wadze.
// Od najmiejszej lub od najwiekszej. warto nie uruchamiac dwoch sortowan dla duzej liczby produktow
// Towar posiada id, wage i nazwe.
// Koktajlowe sortowanie
// optymistycznie O(n), pesymistycznie O(n^2)

//DZIALANIE
// jesli przegladana para jest zlej kolejnosci, zamien miejscami.
// roznica miedzy zwyklym babelkowym jest taka, ze algorytm sortuje od lewej i tez od prawej

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
    friend void twoWayBubbleSort(vector <Product>& products, string howToSort);
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
void twoWayBubbleSort(vector <Product>& products, string howToSort)
{
    int stop;
    int leftEdge=0;
    int rightEdge=products.size()-2; //zabezpieczenie przed wypadnieciem

    while (stop>=0)
    {
        stop=-1;
        //od najmniejszej wagi do najwiekszej
        if(howToSort=="down")
        {
            for(int i=leftEdge; i<=rightEdge; i++)
                if(products[i].weight>products[i+1].weight)
                {
                    swap(products[i],products[i+1]);
                    stop=i;
                }

            if(stop<0)
                break;

            rightEdge=stop-1;
            for(int i=rightEdge; i>=leftEdge; i--)
                if(products[i].weight>products[i+1].weight)
                {
                    swap(products[i],products[i+1]);
                    stop=i;
                }

            leftEdge = stop+1;
        }


        if(howToSort=="up")
        {
            for(int i=leftEdge; i<=rightEdge; i++)
                if(products[i].weight<products[i+1].weight)
                {
                    swap(products[i],products[i+1]);
                    stop=i;
                }

            if(stop<0)
                break;

            rightEdge=stop-1;
            for(int i=rightEdge; i>=leftEdge; i--)
                if(products[i].weight<products[i+1].weight)
                {
                    swap(products[i],products[i+1]);
                    stop=i;
                }

            leftEdge = stop+1;
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
    // dla 5000 towarow okolo 1s
    // dla 10000 towarow 2s
    // dla 50000 46s.
    // dla 100000 +180s
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
    twoWayBubbleSort(products, howToSort);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najmniejszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }



    // SORTOWANIE od najwiekszej do najmniejszej
    howToSort="up";
    twoWayBubbleSort(products, howToSort);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najwiekszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }

}

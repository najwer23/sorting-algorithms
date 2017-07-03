// Sorotwanie towarow po wadze.
// Od najmiejszej lub od najwiekszej. warto nie uruchamiac dwoch sortowan dla duzej liczby produktow
// Towar posiada id, wage i nazwe.
// HeapSort

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

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
    friend void heapSort(vector <Product>& products, string howToSort);
    friend void Heapify(vector <Product>& products, int first, int last, string howToSort);
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


void Heapify(vector <Product>& products, int first, int last, string howToSort)
{
    int parent = first;
    int lefChild;
    int rightChild;
    int checkChild; //potomek
    bool correct=false; //wlasnosc stogu

    if(howToSort=="down")
    {
        while ((2*parent+1<=last)&&(correct==false))
        {
            lefChild=2*parent+1;
            rightChild=lefChild+1;
            if(rightChild<=last)
            {
                if(products[lefChild].weight>products[rightChild].weight)
                {
                    checkChild=lefChild;
                }
                else
                {
                    checkChild=rightChild;
                }
            }
            else
            {
                checkChild=lefChild;
            }
            if (products[parent].weight<products[checkChild].weight)
            {
                swap(products[parent],products[checkChild]);
                parent=checkChild;
            }
            else
                correct=true;
        }
    }


    if(howToSort=="up")
    {
        while ((2*parent+1<=last)&&(correct==false))
        {
            lefChild=2*parent+1;
            rightChild=lefChild+1;
            if(rightChild<=last)
            {
                if(products[lefChild].weight<products[rightChild].weight)
                {
                    checkChild=lefChild;
                }
                else
                {
                    checkChild=rightChild;
                }
            }
            else
            {
                checkChild=lefChild;
            }
            if (products[parent].weight>products[checkChild].weight)
            {
                swap(products[parent],products[checkChild]);
                parent=checkChild;
            }
            else
                correct=true;
        }
    }



}


// funkcja zaprzyjazniona pozwala korzystac z pol klasy Product
void heapSort(vector <Product>& products, string howToSort)
{

    //od najmniejszej wagi do najwiekszej
    if(howToSort=="down")
    {
        int i = (products.size()-1)/2;
        while(i>=0)
        {
            Heapify(products,i,products.size()-1,howToSort);
            i=i-1;
        }
        i=products.size()-1;
        while(i>=1)
        {
            swap(products[0],products[i]);
            Heapify(products,0,i-1,howToSort);
            i=i-1;
        }
    }

    if(howToSort=="up")
    {
        //budowa stogu
        int i = (products.size()-1)/2;
        while(i>=0)
        {
            Heapify(products,i,products.size()-1,howToSort);
            i=i-1;
        }
        i=products.size()-1;
        //sortowanie
        while(i>=1)
        {
            swap(products[0],products[i]);
            Heapify(products,0,i-1,howToSort);
            i=i-1;
        }
    }

}


int main()
{
    //DANE
    srand(time(NULL));
    Product product;
    vector <Product> products;
    int N=10;

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
    heapSort(products, howToSort);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najmniejszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }


    // SORTOWANIE od najwiekszej do najmniejszej
    howToSort="up";
    heapSort(products, howToSort);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najwiekszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
       products[i].show();
    }

}

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
    friend void mergeSort(vector <Product>& bonusTab, vector <Product>& products, int first, int last, string howToSort);
    friend void mS(vector <Product>& bonusTab, vector <Product>& products, int first, int mid, int last, string howToSort);
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

void mS(vector <Product>& bonusTab, vector <Product>& products, int first, int mid, int last, string howToSort)
{
    int i, j;
    // lewa czesc w tablicy pomocniczej
    for(i=mid+1; i>first; i--)
    {
        bonusTab[i-1] = products[i-1];
    }

    // prawa czesc w tablicy pomocniczej
    for(j = mid; j<last; j++)
        bonusTab[last+mid-j] = products[j+1];



    if(howToSort=="down")
    {
        //scalanie i zapisanie ich we wlasciwy sposob
        for(int k=first; k<=last; k++)
            if(bonusTab[j].weight<bonusTab[i].weight)
                products[k] = bonusTab[j--];
            else
                products[k] = bonusTab[i++];
    }

    if(howToSort=="up")
    {
        //scalanie i zapisanie ich we wlasciwy sposob
        for(int k=first; k<=last; k++)
            if(bonusTab[j].weight>bonusTab[i].weight)
                products[k] = bonusTab[j--];
            else
                products[k] = bonusTab[i++];
    }


}

void mergeSort(vector <Product>& bonusTab, vector <Product>& products, int first, int last, string howToSort)
{
    if(howToSort=="down" || howToSort=="up")
    {
        if(last<=first)
            return;

        int mid=(last+first)/2;
        mergeSort(bonusTab, products, first, mid, howToSort);
        mergeSort(bonusTab, products, mid+1, last, howToSort);

        mS(bonusTab, products, first, mid, last, howToSort);
    }
}


int main()
{
    //DANE
    srand(time(NULL));
    Product product;
    vector <Product> products;
    int N=5;

    // bo nie moge odwolac sie do elementow tablicy ktorej nie ma tablica
    // inicjalizacja na sztywno "zerami"
    vector <Product> bonusTab;
    Product help;

    // wczytaj produkty do vectora
    for (int i=0; i<N; i++ )
    {
        // losowe wartosci produktu
        product.load(i);
        products.push_back(product);
        help.load(i);
        bonusTab.push_back(help);
    }


    cout<<"Produkty przed sortowaniem po wadze:"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
       products[i].show();
    }


    // SORTOWANIE od najmniejszej wagi do najwiekszej
    string howToSort="down";
    mergeSort(bonusTab, products,0,products.size()-1, howToSort);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najmniejszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }


    // SORTOWANIE od najwiekszej do najmniejszej
    howToSort="up";
    mergeSort(bonusTab, products,0,products.size()-1,howToSort);

    cout<<endl<<"Produkty po sortowaniem po wadze (od najwiekszej):"<<endl;
    for( int i=0; i<products.size(); i++ )
    {
        products[i].show();
    }

}

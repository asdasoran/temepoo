#include <iostream>
using namespace std;
class lista
{
    public:
    int next[100],*content;
    int nr=0;
    int initl()
    {
        content=new int[100];
        cout<<"Lista initializata"<<endl;
    }
    int adauga(int x)
    {
        if(nr==0)
        {
            content[1]=x;
            cout<<"Element adaugat"<<endl;
            nr++;
        }
        else
        {   content[nr+1]=x;
            nr++;
            cout<<"Element adaugat"<<endl;
            for(int i=1;i<=nr;i++)
            {
                next[i]=content[i+1];
            }
        }
    }
    int scoate(int x)
    {
        int aux[100];
        int j=1;
        for(int i=1;i<=nr;i++)
        {
            aux[i]=content[i];
        }
        for(int i=1;i<=nr;i++)
        {
            if(aux[i]==x)
            {
                aux[i]=0;
            }
        }
        for(int i=1;i<=nr;i++)
        {
            if(aux[i] != 0)
            {
                content[j]=aux[i];
                j++;
            }
        }
        cout<<"Element scos"<<endl;
        nr--;
    }
    ~lista()
    {
        delete content;
    }
} lista;
int main()
{
    int quit=0;
    int optiune;
    int el;
    while(quit != 1)
    {
        cout<<endl;
        cout<<"Ce doriti sa faceti?"<<endl;
        cout<<"1. Initializez lista"<<endl;
        cout<<"2. Adaug un element in lista"<<endl;
        cout<<"3. Scot un element din lista"<<endl;
        cout<<"4. Afisare lista"<<endl;
        cout<<"5. Iesire"<<endl;
        cin>>optiune;
        switch(optiune)
        {
        case 1: lista.initl();break;
        case 2: cout<<"Introduceti elementul pe care doriti sa il adaugati: ";cin>>el;
        lista.adauga(el);break;
        case 3: if(lista.nr==0)
        {
            cout<<"Nu exista elemente"<<endl;
            break;
        }
        cout<<"Introduceti elementul pe care doriti sa il stergeti: ";cin>>el;
        lista.scoate(el);
        break;
        case 4: for(int i=1;i<=lista.nr;i++)
        {
            cout<<lista.content[i]<<" ";
        }
        cout<<endl;break;
        case 5: quit=1;break;
        default: cout<<"Optiune invalida"<<endl;break;
        }
    }
}

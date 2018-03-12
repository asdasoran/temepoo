#include <iostream>
using namespace std;
class coada
{
    public:
    int first;
    int *p;
    int nr;
    int initc()
    {
        p=new int[100];
    for(int i=0;i<=100;i++)
    {
        p[i]=0;
    }
    }
    int adauga(int x)
    {
        int i=2,aux;
        if(first!=0)
        {
            for(int i=nr+1;i>=1;i--)
            {
                p[i]=p[i-1];
            }
            p[1]=x;
            nr++;
            cout<<"Am adaugat"<<x<<" in coada"<<endl;
        }
        else
        {
            first=x;
            p[1]=x;
            nr++;
            cout<<"Am adaugat "<<x<<" in coada"<<endl;
        }
    }
    int scoate(int x)
    {
        int ct=0;
        for(int i=1;i<=nr;i++)
        {
            if(p[i]==x)
            {
                ct=1;
            }
        }
        if(ct==0)
        {
            cout<<x<<" nu este in coada"<<endl;
            return 0;
        }
        if(nr==1)
        {
            p[1]=0;
            first=p[1];
            cout<<"Am scos elementul "<<x<<endl;
            nr--;
        }
        if(nr>1)
        {
            p[1]=0;
            first=p[1];
            cout<<"Am scos elementul "<<x<<endl;
            for(int i=1;i<=nr;i++)
            {
                p[i]=p[i+1];
            }
            nr--;
        }
    }
    coada()
    {
        first=0;
        nr=0;
    }
    ~coada()
    {
        delete[] p;
    }
} c;
int main()
{
    int optiune,el;
    optiune=0;
    int quit;
    quit=0;
    while(quit != 1)
    {
        cout<<"Coada are in prezent "<<c.nr;
        if(c.nr==1)
        {
            cout<<" element";
        }
        else cout<<" elemente";
        if(c.nr>0)
        {
            cout<<": ";
            for(int i=1;i<=c.nr;i++)
            {
                cout<<c.p[i]<<" ";
            }
            cout<<endl;
        }
        else cout<<endl;
        cout<<"Ce doriti sa faceti?"<<endl;
        cout<<"1. Initializez pointerul"<<endl;
        cout<<"2. Adaug un element in coada"<<endl;
        cout<<"3. Scot un element din coada"<<endl;
        cout<<"4. Iesire"<<endl;
        cin>>optiune;
        switch(optiune)
        {
        case 1: c.initc();
        cout<<"Pointerul a fost initializat cu succes."<<endl;break;
        case 2: cout<<"Introduceti elementul pe care doriti sa il adaugati: ";cin>>el;
        c.adauga(el);
        break;
        case 3: if(c.nr>0) {c.scoate(el);break;}
        else {cout<<"Nu exista elemente in coada"<<endl;break;}
        case 4: quit=1;break;
        default: cout<<"Optiune invalida"<<endl;break;
        }
    }
}

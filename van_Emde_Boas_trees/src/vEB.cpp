#include "vEB.h"

vEB::vEB(int tam)
{
    u=tam;
    min=NULL;
    max=NULL;
    cout<<"creando el de "<<u<<endl;
    if (u>2)
    {
        int tam2=pow(tam,0.5);
        for (int i=0;i<tam;i=i+tam2)
        {
            cluster.push_back(new vEB(tam2));
        }
        summary=new vEB(tam2);
    }
}

int vEB::vEB_Tree_Minimum(vEB* V)
{
    return (V->min);
}

int vEB::vEB_Tree_Maximum(vEB* V)
{
    return (V->max);
}

int vEB::high(int x)
{
    return u/pow(u,0.5);
}

int vEB::low(int x)
{
    return x%int(pow(u,0.5));
}

int vEB::index(int x,int y)
{
    return x*pow(u,0.5)+y;
}


void vEB::vEB_Empty_Tree_insert(vEB* V, int x)
{
    V->min=x;
    V->max=x;
}

void vEB:: vEB_Tree_Insert(vEB* V, int x)
{
    if (V->min==NULL)
    {
        vEB_Empty_Tree_insert(V,x);
    }
    else
    {
        if(x<V->min)
        {
            int aux=V->min;
            V->min=x;
            x=aux;
        }
        if(V->u>2)
        {
            if ((vEB_Tree_Minimum(V->cluster[high(x)]))==NULL)
            {
                vEB_Tree_Insert(V->summary,high(x));
                vEB_Empty_Tree_insert(V->cluster[high(x)],low(x));
            }
        }
    }

}

void vEB::print(vEB* V)
{
    for (i=0;i<u;i+i)
}

vEB::~vEB()
{
    //dtor
}

#include "/home/paulacv/San Pablo/analisis y diseño de algoritmos/VAN_EMDE_BOAS_TREE/van_Emde_Boas_trees/include/vEB.h"

vEB::vEB(int tam)
{
    cout<<"creando el de "<<tam<<endl;
    u=tam;
    min=NULL;
    max=NULL;
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
    return x/pow(u,0.5);
}

int vEB::low(int x)
{
    return x%int(pow(this->u,0.5));
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
        if (x<V->min)
        {
            int aux=V->min;
            V->min=x;
            x=aux;
        }

        if(V->u>2)
        {
            if ((vEB_Tree_Minimum(V->cluster[V->high(x)]))==NULL)
            {
                vEB_Tree_Insert(V->summary,V->high(x));
                vEB_Empty_Tree_insert(V->cluster[V->high(x)],V->low(x));
            }
            else vEB_Tree_Insert(V->cluster[V->high(x)],V->low(x));

        }
        if (x>V->max)
        {
            V->max=x;
        }
    }
}
bool vEB:: vEB_Tree_Member(vEB* V, int x)
{
    if (x == V->min or x == V->max)
        return true;
    else if (V->u == 2)
        return false;
    else return vEB_Tree_Member(V->cluster[V->high(x)],V->low(x));
}

int vEB:: vEB_Tree_Successor(vEB* V, int x)
{
    int offset;
    if (V->u == 2)
    {
        if (x == 0 and V->max == 1) return 1;
        else return NULL;
    }
    else if (V->min !=NULL and x < V->min) return V->min;

    else
    {
        int max_low = vEB_Tree_Maximum(V->cluster[high(x)]);
        if (max_low != NULL and low(x) < max_low)
        {
            offset=vEB_Tree_Successor(V->cluster[high(x)],low(x));
            return index(high(x), offset);
        }
        else
        {
            int succ_cluster=vEB_Tree_Successor(V->summary,high(x));
            if (succ_cluster == NULL)
                return NULL;

            else
            {
                offset=vEB_Tree_Minimum(V->cluster[succ_cluster]);
                return index(succ_cluster,offset);
            }
        }
    }
}
int vEB:: vEB_Tree_Predecessor(vEB* V, int x)
{
    int offset;
    if (V->u == 2)
    {
        if (x == 0 and V->max == 1) return 0;
        else return NULL;
    }
    else if (V->max !=NULL and x > V->max) return V->max;

    else
    {
        int min_low = vEB_Tree_Minimum(V->cluster[high(x)]);
        if (min_low != NULL and low(x) > min_low)
        {
            offset=vEB_Tree_Predecessor(V->cluster[high(x)],low(x));
            return index(high(x), offset);
        }
        else
        {
            int pred_cluster=vEB_Tree_Predecessor(V->summary,high(x)-1);
            if (pred_cluster == NULL)
            {
                if( V->min!= NULL and x > V->min) return V->min;
                else return NULL;
            }
            else
            {
                offset=vEB_Tree_Maximum(V->cluster[pred_cluster]);
                return index(pred_cluster,offset);
            }
        }
    }
}

void vEB::vEB_Tree_Delete(vEB* V,int x)
{
    if(V->min ==V->max)
    {
        V->min=NULL;
        V->max=NULL;
    }
    else if (V->u==2)
    {
            if (x==0)
            {
                V->min=1;
            }
            else
            {
                V->min=0;
            }
            V->max=V->min;
    }
    else
    {
        if (x==V->min)
        {
            int first_cluster=vEB_Tree_Minimum(V->summary);
            x=index(first_cluster,vEB_Tree_Minimum(V->cluster[first_cluster]));
            V->min=x;
        }
        vEB_Tree_Delete(V->cluster[V->high(x)],V->low(x));
        if (vEB_Tree_Minimum(V->cluster[V->high(x)])==NULL)
        {
            vEB_Tree_Delete(V->summary,V->high(x));
            if (x==V->max)
            {
                int summary_max=vEB_Tree_Minimum(V->summary);
                if (summary_max==NULL)
                {
                    V->max=V->min;
                }
                else
                {
                    V->max=V->index(summary_max,vEB_Tree_Maximum(V->cluster[summary_max]));
                }
            }

        }
        else if(x==V->max)
        {
            V->max=index(high(x),vEB_Tree_Maximum(V->cluster[V->high(x)]));
        }
    }
}


void vEB::print(vEB* V)
{
    cout<<"\nvEB "<<V->u<<"\nMin="<<V->min<<" Max="<<V->max<<endl;
    if(V->u>2)
    {
        print(V->summary);
        for (int i=0;i<pow(V->u,0.5);i=i+1)
        {
            print(V->cluster[i]);
        }
    }
}

vEB::~vEB()
{
    //dtor
}

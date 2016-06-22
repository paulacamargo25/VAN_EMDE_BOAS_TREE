#include <iostream>
#include "/home/paulacv/San Pablo/analisis y diseño de algoritmos/VAN_EMDE_BOAS_TREE/van_Emde_Boas_trees/include/vEB.h"
using namespace std;




int main()
{
    vEB* V= new vEB(16);
    V->print(V);
    V->vEB_Tree_Insert(V,2);
    V->vEB_Tree_Insert(V,3);
    V->vEB_Tree_Insert(V,4);
    V->vEB_Tree_Insert(V,5);
    V->vEB_Tree_Insert(V,7);
    V->vEB_Tree_Insert(V,14);
    V->vEB_Tree_Insert(V,15);

    cout<<"Luego de insertar"<<endl<<endl;
    V->print(V);
    return 0;
}

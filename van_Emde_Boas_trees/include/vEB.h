#ifndef VEB_H
#define VEB_H

#include "math.h"
#include <vector>
#include <iostream>

using namespace std;
class vEB
{
    public:
        int u;
        int min;
        int max;
        int raiz_u=pow(u,0.5);
        vector <vEB*> cluster;
        vEB *summary;
        vEB(int tam);
        void vEB_Empty_Tree_insert(vEB* V, int x);
        void vEB_Tree_Insert(vEB* V, int x);
        int vEB_Tree_Minimum(vEB* V);
        int vEB_Tree_Maximum(vEB* V);
        int high(int x);
        int low(int x);
        int index(int x,int y);

        virtual ~vEB();
    protected:
    private:
};

#endif // VEB_H

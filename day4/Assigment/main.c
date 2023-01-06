#include <stdio.h>
#include <stdlib.h>

#include "Tree.h"

int main()
{
    Tree tree;
    tree.Root = NULL;

    Add(&tree, 50);
    Add(&tree, 40);
    Add(&tree, 30);
    Add(&tree, 60);
    Add(&tree, 70);
    Add(&tree, 65);

    Display(tree.Root);
   int mx= GetMaxDepth(tree.Root);
   printf("%d ",mx);

    return 0;
}

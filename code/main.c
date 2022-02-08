#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
extern node *external;

int main()
{
    external = (node*)(malloc(sizeof(node)));
    external->color = 'N';
    node *root = external;

    int node_quanity = 20;

    int count;
    for(count = 0; count < node_quanity; count++)
    {
        node *new_node = (node*)(malloc(sizeof(node)));
        new_node->value = 10;
        InsertRN(&new_node, &root);
    }

    InOrder(&root);
    return 0;
}

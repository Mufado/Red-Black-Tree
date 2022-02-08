#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
extern node *external;

int main()
{
    external = (node*)(malloc(sizeof(node)));
    external->color = 'N';
    node *root = external;

    /*int node_quanity = 20;

    int count;
    for(count = 0; count < node_quanity; count++)
    {
        node *new_node = (node*)(malloc(sizeof(node)));
        new_node->value = 10;
        InsertRN(&new_node, &root);
    }*/

    CreateNodeAndInsert(10, &root);
    CreateNodeAndInsert(1, &root);
    //PreOrder(root);
    //printf("\n");

    CreateNodeAndInsert(4, &root);
    PreOrder(root);
    printf("\n");
    // CreateNodeAndInsert(, &root);
    // CreateNodeAndInsert(, &root);
    // CreateNodeAndInsert(, &root);
    // CreateNodeAndInsert(, &root);
    // CreateNodeAndInsert(, &root);

    return 0;
}

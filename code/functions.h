#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef struct no
{
    struct no *dir;
    struct no *esq;
    struct no *dad;
    char color;
    int value;
}node;

void MoveDad(node **losedad_pt, node **gaindad_pt, node **root);

void InsertRN(node **new_node, node **root);

void RotationL(node **pt, node **root);

void RotationR(node **pt, node **root);

void RotaRN(node **new_node, node **root);

void InOrder(node **pt);

#endif // FUNCTIONS_H_INCLUDED

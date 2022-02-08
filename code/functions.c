#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    struct no *dir;
    struct no *esq;
    struct no *dad;
    char color;
    int value;
}node;

node *external = NULL;

void MoveDad(node *losedad_pt, node *gaindad_pt, node **root)
{
    if (losedad_pt->dad == external)
    {
        *root = gaindad_pt;
        // printf("\n%d %c\n", gaindad_pt->dad->value, gaindad_pt->dad->color);
    }else
    {
        if (losedad_pt == losedad_pt->dad->esq)
        {
            losedad_pt->dad->esq = gaindad_pt;
        }
        else
        {
            losedad_pt->dad->dir = gaindad_pt;
        }
    }
    gaindad_pt->dad = losedad_pt->dad;
}

void RotationL(node *pt, node **root)
{
    MoveDad(pt, pt->dir, &(*root));
    pt->dir = pt->dir->esq;
    if (pt->dir != external)
        pt->dir->dad = pt;
    if (pt->dad->value > pt->value)
    {
        pt->dad->esq->esq = pt;
        pt->dad = (pt->dad->esq);
    }
    else
    {
        pt->dad->dir->esq = pt;
        pt->dad = (pt->dad->dir);
    }
}

void RotationR(node *pt, node **root)
{
    MoveDad(pt, pt->esq, &(*root));
    //printf("\n%d %c\n", pt->value, pt->color);
    pt->esq = pt->esq->dir;
    if (pt->esq != external)
        pt->esq->dad = pt;
    if (pt->dad->value > pt->value)
    {
        pt->dad->esq->dir = pt;
        pt->dad = (pt->dad->esq);
    }
    else
    {
        pt->dad->dir->dir = pt;
        pt->dad = (pt->dad->dir);
    }
}

void RotaRN(node *new_node, node **root)
{
    while(new_node->dad->color == 'R')
    {
        if (new_node->dad == new_node->dad->dad->esq)
        {
            node *aux = new_node->dad->dad->dir;
            if (aux->color == 'R')
            {
                new_node->dad->color = aux->color = 'N';
                new_node->dad->dad->color = 'R';
                new_node = new_node->dad->dad;
            } else
            {
                if (new_node == new_node->dad->dir)
                {
                    new_node = new_node->dad;
                    RotationL(new_node, &(*root));
                }
                new_node->dad->color = 'N';
                new_node->dad->dad->color = 'R';
                RotationR(new_node->dad->dad, &(*root));
            }
        } else
        {
            node *aux = new_node->dad->dad->esq;
            if (aux->color == 'R')
            {
                new_node->dad->color = aux->color = 'N';
                new_node->dad->dad->color = 'R';
                new_node = new_node->dad->dad;
            } else
            {
                if (new_node == new_node->dad->esq)
                {
                    new_node = new_node->dad;
                    RotationR(new_node, &(*root));
                }
                new_node->dad->color = 'N';
                new_node->dad->dad->color = 'R';
                RotationL(new_node->dad->dad, &(*root));
            }
        }
    }
    (*root)->color = 'N';
}

void InsertRN(node *new_node, node **root)
{
    node *aux = external;
    node *pt = *root;
    while (pt != external)
    {
        aux = pt;
        if (new_node->value == pt->value)
        {
            printf("chave existente!");
            aux = NULL;
            pt = external;
        } else {
            if (new_node->value < pt->value)
                pt = pt->esq;
            else
                pt = pt->dir;
        }
    }
    if (aux != NULL)
    {
        new_node->dad = aux;
        if(aux == external)
        {
            *root = new_node;
        } else
        {
            if(new_node->value < aux->value)
                aux->esq = new_node;
            else
                aux->dir = new_node;
        }
        new_node->esq = new_node->dir = external;
        new_node->color = 'R';
        RotaRN(new_node, &(*root));
    }
}

//
// Funções usadas apenas para
// fazer alguns testes
//

void PreOrder(node *pt)
{
    printf("Value %d, color %c\n", pt->value, pt->color);

    if (pt->esq != external)
        PreOrder(pt->esq);

    if (pt->dir != external)
        PreOrder(pt->dir);
}

void InOrder(node *pt)
{
    if (pt->esq != external)
        InOrder(pt->esq);

    printf("Value %d, color %c\n", pt->value, pt->color);

    if (pt->dir != external)
        InOrder(pt->dir);
}

void CreateNodeAndInsert(int value, node **root)
{
    node *new_node = (node*)(malloc(sizeof(node)));
    new_node->value = value;
    InsertRN(new_node, &(*root));
}

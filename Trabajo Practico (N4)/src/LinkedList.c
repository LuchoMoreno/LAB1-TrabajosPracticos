#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"




LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}




int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}




static Node* getNode(LinkedList* this, int nodeIndex)
{
    int len;
    int i;
    Node* pNode = NULL;

    if (this != NULL)
    {
        len = ll_len(this);
        if (nodeIndex>=0 && nodeIndex<len)
        {
            pNode = this->pFirstNode;
            for(i=0; i<nodeIndex; i++)
            {
                pNode=pNode->pNextNode;
            }
        }

    }

    return pNode;
}




Node* test_getNode(LinkedList* this, int nodeIndex)
{

    return getNode(this, nodeIndex);
}




static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len;

    Node* pNewNode= malloc(sizeof(Node));
    Node* pActualNode= NULL;

    pNewNode->pElement=pElement;

    if(this!= NULL && pNewNode!= NULL)
    {
        len = ll_len(this);
        if (nodeIndex>=0 && nodeIndex<= len)
        {
            if (nodeIndex==0)
            {
                pNewNode->pNextNode = this->pFirstNode;
                this->pFirstNode = pNewNode;
            }
            else
            {
                pActualNode=getNode(this,nodeIndex-1);
                pNewNode->pNextNode = pActualNode->pNextNode;
                pActualNode->pNextNode = pNewNode;
            }

            returnAux=0;
            this->size++;
        }

    }
    return returnAux;
}




int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}




int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if (this!= NULL)
    {
        returnAux = addNode(this, this->size, pElement);    // ESTO YA RETORNA EL VALOR NO HACE
    }                                                       // FALTA QUE HAGA IF
    return returnAux;
}




void* ll_get(LinkedList* this, int index)
{
    int len;
    void* returnAux = NULL;
    Node* pNewNode;

    if (this!= NULL)
    {
        len = ll_len(this);
        if (index >= 0 && index < len)
        {
            pNewNode = getNode(this, index);
            if (pNewNode != NULL)
            {
                returnAux = pNewNode -> pElement;
            }
        }
    }
    return returnAux;
}




int ll_set(LinkedList* this, int index,void* pElement)
{
    int len;
    int returnAux = -1;
    Node* pNewNode;

    if (this!= NULL)
    {
        len = ll_len(this);
        if (index >= 0 && index < len)
        {
            pNewNode = getNode(this, index);
            if (pNewNode != NULL)
            {
                returnAux = 0;
                pNewNode -> pElement = pElement;
            }
        }
    }
    return returnAux;
}




int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node *pNodeA;
    Node *pNodeB;

    if(this!= NULL)
    {
        if (index>=0 && index<this->size)
        {
            returnAux=0;
            if(this->size==1)
            {
                this->pFirstNode=NULL;
                free(getNode(this,index));
            }


            else if(index==0)
            {
                pNodeA=getNode(this,index);
                this->pFirstNode=pNodeA->pNextNode;
                free(pNodeA);
            }


            else
            {
                pNodeA=getNode(this,index);
                if(pNodeA!=NULL)
                {
                    pNodeB=getNode(this,index-1);
                    pNodeB->pNextNode=pNodeA->pNextNode;
                    free(pNodeA);
                }
            }
        }
        this->size--;
    }
    return returnAux;
}




int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;
    int i;

    if(this!=NULL)
    {
        len = ll_len(this);
        for(i=len; i>0; i--)
        {
            ll_remove(this,i);
        }
        returnAux=0;
    }
    return returnAux;
}




int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)
    {
        if (ll_clear(this) == 0)
        {
            free(this);
            returnAux = 0;
        }

    }

    return returnAux;
}




int ll_indexOf(LinkedList* this, void* pElement)
{
    int i;
    int returnAux=-1;
    int len;
    Node* pNode=NULL;

    if(this != NULL)
    {
        len = ll_len(this);
        for(i=0; i<len; i++)
        {
            pNode=getNode(this,i);
            if(pNode->pElement == pElement)
            {
                returnAux=i;
                break;
            }
        }
    }
    return returnAux;
}




int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if (this != NULL)
    {
        if (this->size == 0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }
    return returnAux;
}




int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len;

    if(this!=NULL)
    {
        len = ll_len(this);
        if (index>=0 && index<=len)
        {
            returnAux=addNode(this, index, pElement);
        }
    }
    return returnAux;
}




void* ll_pop(LinkedList* this,int index)
{
    int returnAux = NULL;
    int len;

    if(this!=NULL)
    {
        len = ll_len(this);
        if (index>=0 && index<=len)
        {
            returnAux=ll_get(this, index);
            ll_remove(this, index);
        }
    }
    return returnAux;
}




int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if (this!=NULL)
    {

        if (ll_indexOf(this, pElement) != -1)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}




int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int returnAux = -1;
    int i;
    int lenUno;
    int lenDos;
    int contadorElementosIguales=0;

    void* pElementAux;


    if(this!=NULL && this2!=NULL)
    {
        lenUno = ll_len(this);
        lenDos = ll_len(this2);
        returnAux=0;

        if(lenUno >= lenDos)
        {

            for(i=0 ; i<lenDos; i++)
            {
                pElementAux = ll_get(this2, i);
                if(ll_contains(this, pElementAux)==1)
                {
                    contadorElementosIguales++;
                }
            }

            if(contadorElementosIguales==lenUno)
            {
                returnAux=1;
            }
        }
    }
    return returnAux;
}




LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* pNode;
    int i;
    int len;
    int posicionEnNuevaLista=0;

    if(this!=NULL)
    {
        len = ll_len(this);
        if(from>=0 && from<=len && to>=0 && to<=len)
        {
            cloneArray=ll_newLinkedList();

            for(i=from; i<to; i++)
            {
                pNode=getNode(this, i);

                if(pNode!=NULL)
                {
                    addNode(cloneArray, posicionEnNuevaLista, pNode->pElement);
                    posicionEnNuevaLista++;
                }
            }
        }
    }
    return cloneArray;
}




LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this!=NULL)
    {
        cloneArray=ll_subList(this, 0, this->size);
    }

    return cloneArray;
}




int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;

    void* pElementUno;
    void* pElementDos;
    void* pElementAux;
    int i;
    int flag;
    int len;

    if(this!=NULL)
    {
        if (pFunc!= NULL)
        {
            if (order == 0 || order == 1)
            {
                len = ll_len(this);
                if(len > 0)
                {
                    do
                    {
                        flag = 0;
                        for(i=0; i<len-1; i++)
                        {
                            pElementUno = ll_get(this,i);
                            pElementDos = ll_get(this,i+1);

                            if((pFunc(pElementUno, pElementDos) <0 && order==0) || (pFunc(pElementUno, pElementDos) >0 && order==1))
                            {
                                pElementAux = pElementUno;
                                ll_set(this,i,pElementDos);
                                ll_set(this,i+1,pElementAux);
                                flag=1;
                            }
                            returnAux=0;
                        }
                    }while(flag);
                }
            }
        }
    }
    return returnAux;
}



LinkedList* ll_filter(LinkedList* lista, int(*pFunc)(void*))
{
    int len;
    int i;
    void* pElementAux;
    LinkedList* nuevaSubLista;

    if(lista != NULL)
    {
        if(*pFunc != NULL)
        {
            nuevaSubLista = ll_newLinkedList();
            len = ll_len(lista);

            for(i=0; i<len; i++)
            {
                pElementAux = ll_get(lista,i);
                if (pFunc(pElementAux)==1);
                {
                    ll_add(nuevaSubLista,pElementAux);
                }
            }
        }
    }

    return nuevaSubLista;
}



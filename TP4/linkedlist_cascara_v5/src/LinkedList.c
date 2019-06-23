#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
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

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
        returnAux = this->size;
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int tam = ll_len(this);
    if(this != NULL && tam > 0)
    {
        if(nodeIndex >= 0 && nodeIndex < tam)
        {
           pNode = this->pFirstNode;
          for(int i = 0 ; i< nodeIndex; i++)
           {
               pNode = pNode->pNextNode;

           }
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int isOk = -1;
    int tam = ll_len(this);

    if (this != NULL && nodeIndex <= tam && nodeIndex >= 0)
    {
        Node* pNode= (Node*)malloc(sizeof(Node));
        if(pNode != NULL)
        {
            pNode->pElement=pElement;

            if (nodeIndex == 0 && tam == 0)
            {
                pNode->pNextNode= NULL;
                this->pFirstNode = pNode;
                this->size=(this->size)+1;

            }
            else if (nodeIndex == 0 && tam > 0 )
            {
                pNode->pNextNode = this->pFirstNode ;
                this->pFirstNode = pNode;
                this->size=(this->size)+1;
            }
            else if (nodeIndex > 0 && nodeIndex<tam)
            {
                pNode->pNextNode=getNode(this,nodeIndex);
                getNode(this,(nodeIndex-1))->pNextNode=pNode;
                this->size=(this->size)+1;
            }
            else if (nodeIndex==tam)
            {
                getNode(this,(nodeIndex-1))->pNextNode=pNode;
                pNode->pNextNode=NULL;
                this->size=(this->size)+1;
            }

            isOk=0;
        }
    }

    return isOk;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int isOk = -1;
    int tam = ll_len(this);
       if(this != NULL )
          isOk = addNode(this, tam, pElement);
  return isOk;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int tam = ll_len(this);
    if(this != NULL && index >= 0 && index < tam)
    {
        returnAux =  (getNode(this, index))->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int isOk = -1;
    int tam = ll_len(this);
    if(this != NULL && index >= 0 && index < tam)
    {
        getNode(this, index)->pElement = pElement;
        isOk = 0;
    }

    return isOk;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int isOk = -1;
    int tam = ll_len(this);
    Node* pNode;
    if(this != NULL && index >= 0 && index < tam)
    {
       /* if(index == 0)
        {
            this->pFirstNode = (getNode(this, index))->pNextNode;
            free(getNode(this, index));
        }
        else if (index > 0 && index != (tam-1))
        {
            getNode(this, (index-1))->pNextNode = (getNode(this, index))->pNextNode;
            free(getNode(this, index));
        }
        else if(index > 0 && index == (tam-1))
        {
            getNode(this, (index-1))->pNextNode = NULL;
            free(getNode(this, index));
        }
        this->size = (this->size) -1;
        isOk = 0;*/
        if(index == 0)
        {
            pNode = getNode(this, index);
            this->pFirstNode = pNode->pNextNode;
            free(pNode);
        }
        else if (index != (tam-1))
        {
            pNode = getNode(this, index);
            getNode(this, (index-1))->pNextNode = pNode->pNextNode;
            free(pNode);
        }
        else if(index == (tam-1))
        {
            pNode = getNode(this, index);
            getNode(this, (index-1))->pNextNode = NULL;
            free(pNode);
        }
        this->size = (this->size) -1;
        isOk = 0;
    }

    return isOk;

}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int isOk = -1;
    int tam = ll_len(this);
    if(this != NULL)
    {
        for(int i = 0; i<tam; i++)
        {
            isOk = ll_remove(this, i);
        }
    }

    return isOk;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int isOk = -1;
    if(this != NULL)
    {
        ll_clear(this);
        free(this);
        isOk = 0;
    }

    return isOk;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int indice = -1;
    int tam = ll_len(this);
    if(this != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            if(pElement == ll_get(this, i))
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int isOk = -1;
    if(this != NULL)
    {
        isOk = 1;
        if(this->pFirstNode != NULL)
            isOk = 0;
    }

    return isOk;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int isOk = -1;
    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        isOk = addNode(this, index, pElement);

    }

    return isOk;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* isOk = NULL;
    if(this != NULL && index >= 0)
    {
        isOk = ll_get(this, index);
        ll_remove(this, index);
    }

    return isOk;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tam = ll_len(this);
    if(this != NULL)
    {
        returnAux = 0;
        for(int i = 0; i < tam; i++)
        {
            if((ll_get(this, i)) == pElement)
            {
                returnAux = 1;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int tam = ll_len(this);
    int tam2 = ll_len(this2);
    int contador = 0;
    if(this != NULL && this2 != NULL)
    {
        returnAux = 0;
        for(int i = 0; i < tam2; i++)
        {
            for(int j = 0; j < tam; j++)
            {
                if(ll_get(this2, i) == ll_get(this, j))
                    contador ++;
            }
        }
        if(contador == tam2)
            returnAux = 1;
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int tam = ll_len(this);
    if(this != NULL && from >= 0 && from < to && to > 0 && to <= tam)
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            for(int i = from; i < to; i++)
            {
                ll_add(cloneArray, ll_get(this, i));
            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int tam = ll_len(this);
    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            for(int i = 0; i < tam; i++)
            {
                ll_add(cloneArray, ll_get(this, i));
            }
        }
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int isOk =-1;
    int tam = ll_len(this);
    //Node* pNode;
    //Node* pNode2;
    void* aux;
    if(this != NULL && pFunc != NULL && (order == 0 || order == 1) && tam > 0)
    {
        for(int i = 0; i < tam-1; i++)
        {
            //pNode = getNode(this, i);
            for (int j = i +1; j < tam; j++)
            {
                //pNode2 = getNode(this, j);
                //if(pNode2 != NULL && pNode != NULL)
                //{
                if(order == 1 && pFunc(ll_get(this, i), ll_get(this, j)) == 1)
                {
                   aux = ll_get(this, i);
                   ll_set(this, i, ll_get(this, j));
                   ll_set(this, j, aux);
//                   aux = pNode->pElement;
//                   pNode->pElement = pNode2->pElement;
//                   pNode2->pElement = aux;
                   isOk = 0;

                }
                if (order == 0 && pFunc(ll_get(this, i), ll_get(this, j)) == -1)
                {
                   aux = ll_get(this, i);
                   ll_set(this, i, ll_get(this, j));
                   ll_set(this, j, aux);
//                    aux = pNode->pElement;
//                    pNode->pElement = pNode2->pElement;
//                    pNode2->pElement = aux;
                     isOk = 0;
                }
                //}
            }
        }
    }

    return isOk;

}


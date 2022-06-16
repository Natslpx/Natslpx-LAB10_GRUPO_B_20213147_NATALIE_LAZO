#include<iostream>
#include"ListaEnlazada.h"

using namespace std;

Nodo::Nodo(int dat, Nodo *sig = NULL)
{
    dato=dat;
    siguiente=sig;
}

ListaEnlazada::ListaEnlazada()
{
    primero=NULL;
}

ListaEnlazada::~ListaEnlazada()
{
    Nodo *borrar;
    while(primero!=NULL)
    {
        borrar = primero;
        primero = primero -> siguiente;
        delete borrar;
    }
}

void ListaEnlazada::ingresarUltimo(int elem)
{
    Nodo *nuevo = new Nodo(elem);
    Nodo *ultimo;
    if(primero==NULL)
    {
        primero=nuevo;
    }
    else
    {
        ultimo=primero;
        while(ultimo->siguiente!=NULL)
        {
            ultimo=ultimo->siguiente;
        }
        ultimo->siguiente=nuevo;
    }
}

void ListaEnlazada::ingresarPrimero(int elem)
{
    Nodo *nuevo= new Nodo(elem,primero);
    primero = nuevo;
}

void ingresarIndice(int elem, int ind)
{
    if(ind == 0)
    {
        ingresarPrimero(elem);
    }
    else
    {
        Nodo *aux = primero;
        for(int i = 1; i !=ind ; i++)
        {
            aux = aux->siguiente;
        }
        Nodo *nuevo = new Nodo(elem, aux->siguiente);
        aux->siguiente = nuevo;
    }
}

int ListaEnlazada::eliminarUltimo()
{
    if(primero->siguiente==NULL)
    {
        return eliminarPrimero();
    }
    else
    {
        Nodo *penultimo=primero;
        while(penultimo->siguiente->siguiete!=NULL)
        {
            penultimo=penultimo->siguiente;
        }
        Nodo *borrar=penultimo->siguiente;
        penultimo->siguiente=NULL;
        int dato = borrar->dato;
        delete borrar;
        return dato;
    }
}

int ListaEnlazada::eliminarPrimero()
{
    Nodo *borrar=primero;
    primero=primero->siguiente;
    int dato=borrar->dato;
    delete borrar;
    return dato;
}

int ListaEnlazada::eliminarIndice(int ind)
{
    if(ind == 0)
    {
        return eliminarPrimero(elem);
    }
    else
    {
        Nodo *aux = primero;
        for(int i = 1; i !=ind ; i++)
        {
            aux = aux->siguiente;
        }
        Nodo *borrar=aux->siguiente;
        aux->siguiente=borrar->siguiente;
        int dato=borrar->dato;
        delete borrar;
        return dato;
    }
}

void ListaEnlazada::ordenarLista()
{
    Nodo *aux=primero;
    while(aux->siguiente!=NULL)
    {
        if(aux->siguiente->dato < primero->dato)
        {
            Nodo *aux2 = aux->siguiente;
            aux->siguiente=aux2->siguiente;
            aux2->siguiente=primero;
            primero=aux2;
        }
        else
        {
            Nodo *aux2=primero;
            while(aux->siguiente->dato >aux2->siguiente->dato)
            {
                aux2=aux2->siguiente;
            }
            Nodo *aux3=aux->siguiente;
            aux->siguiente=aux3->siguiente;
            aux3->siguiente=aux2->siguiente;
            aux2->siguiente=aux3;
        }
        aux=aux->siguiente;
    }
}

void ListaEnlazada::imprimirLista()
{
    Nodo *aux=primero;
    while(aux != NULL)
    {
        cout<<aux->dato<<" ";
        aux=aux->siguiente;
    }
}

bool ListaEnlazada::estaVacia()
{
    return primero==NULL;
}

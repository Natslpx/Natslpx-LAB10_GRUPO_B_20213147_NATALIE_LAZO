#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

struct Nodo
{
public:
    int dato;
    Nodo *siguiente;
public:
    Nodo(int dat, Nodo *sig);
};

class ListaEnlazada
{
private:
    Nodo *primero;
public:
    bool estaVacia();   // true si la lista esta vacia
    ListaEnlazada();
    ~ListaEnlazada();
    void ingresarUltimo(int elem);
    void ingresarPrimero(int elem);
    void ingresarIndice(int elem, int ind);
    int eliminarUltimo();
    int eliminarPrimero();
    int eliminarIndice(int ind);
    void ordenarLista();
    void imprimirLista(); // imprime toda la lista, separada por un espacio
};

#endif

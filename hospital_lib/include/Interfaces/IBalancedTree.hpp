#pragma once

namespace Interfaces {

    //K=Key (ID del médico)
    //V=Value (todos sus datos)
    template <typename K, typename V>
    class IBalancedTree 
    {
    public:
        virtual ~IBalancedTree() {}
        virtual void insert(const K& key, const V& value) = 0;
        //Busca y devuelve el valor. Lanza error si no existe.
        virtual V search(const K& key) = 0;
        //Elimina por clave
        virtual void remove(const K& key) = 0;
        //Dice si existe o no
        virtual bool contains(const K& key) const = 0;
        //Imprime en orden (para ver que funciona)
        virtual void printInOrder() const = 0;
    };
}
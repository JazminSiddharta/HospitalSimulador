#pragma once
#include <string>

namespace Interfaces {

    template <typename K, typename V>
    class IHashTable {
    public:
        virtual ~IHashTable() {}
        virtual void put(const K& key, const V& value) = 0;
        //Obtiene valor por clave
        virtual V get(const K& key) = 0;
        //Borra
        virtual void remove(const K& key) = 0;
        virtual bool contains(const K& key) const = 0;
    };
}
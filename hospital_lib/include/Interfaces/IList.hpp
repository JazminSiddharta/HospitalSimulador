#pragma once

namespace Interfaces {

    template <typename T>
    class IList {
    public:
        virtual ~IList() {}
        //Agrega al final
        virtual void add(const T& item) = 0;
        //Obtiene el elemento en la posición 'index'
        virtual T get(int index) const = 0;
        //Elimina el elemento en la posición 'index'
        virtual void remove(int index) = 0;

        virtual int size() const = 0;
        virtual bool isEmpty() const = 0;
    };
}
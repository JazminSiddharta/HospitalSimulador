#pragma once

namespace Interfaces {

    template <typename T>
    class IQueue {
    public:
        virtual ~IQueue() {}
        //Mete algo al final de la fila
        virtual void enqueue(const T& item) = 0;
        //Saca al que está al frente de la fila
        virtual T dequeue() = 0;
        //Mira quién está al frente sin sacarlo
        virtual T& peek() = 0;
        //Está vacía?
        virtual bool isEmpty() const = 0;
    };
}
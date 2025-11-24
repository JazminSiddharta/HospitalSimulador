#pragma once

namespace Interfaces {

    template <typename T>
    class IPriorityQueue {
    public:
        virtual ~IPriorityQueue() {}

        // Mete al paciente a la sala de espera y la prioridad que debe de tener
        virtual void enqueue(const T& item, int prioridad) = 0;

        // Saca al paciente MÁS GRAVE (mayor prioridad)
        virtual T dequeue() = 0;
        //Mira quién es el más grave sin sacarlo
        virtual T& peek() = 0;
        virtual bool isEmpty() const = 0;
    };
}

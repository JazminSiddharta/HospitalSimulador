#pragma once

namespace Interfaces {

    template <typename T>
    class IStack {
    public:
        //Destructor virtual
        virtual ~IStack() {}
        virtual void push(const T& item) = 0;
        virtual T pop() = 0;
        virtual T& top() = 0;
        virtual bool isEmpty() const = 0;
    };

}

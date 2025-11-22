#pragma once
#include "IStack.hpp"
#include <vector>
#include <stdexcept>

template <typename T>
class MiPila : public Interfaces::IStack<T> {
private:
    std::vector<T> elementos;

public:
    void push(const T& item) override {
        elementos.push_back(item);
    }

    T pop() override {
        if (elementos.empty()) {
            throw std::runtime_error("Pila vacía");
        }
        T ultimo = elementos.back();
        elementos.pop_back();
        return ultimo;
    }

    T& top() override {
        if (elementos.empty()) {
            throw std::runtime_error("Pila vacía");
        }
        return elementos.back();
    }

    bool isEmpty() const override {
        return elementos.empty();
    }
};
#pragma once
#include <string>

namespace Interfaces {

    template <typename T>
    class IPersistencia {
    public:
        virtual ~IPersistencia() {}
        //Guarda la estructura
        virtual void save(const T& dataStructure, std::string fileName) = 0;
        //Carga
        virtual void load(T& dataStructure, std::string fileName) = 0;
    };
}
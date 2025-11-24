#pragma once
#include <string>

namespace Modelo {

    struct Medico {
        int id_licencia;
        std::string nombre;
        std::string especialidad;
        bool disponible;

        Medico() : id_licencia(0), disponible(true) {}

        //comparar si un médico es "menor" que otro (por ID)
        bool operator<(const Medico& otro) const {
            return this->id_licencia < otro.id_licencia;
        }
        //saber si son iguales
        bool operator==(const Medico& otro) const {
            return this->id_licencia == otro.id_licencia;
        }
    };
}
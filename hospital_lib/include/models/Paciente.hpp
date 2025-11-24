#pragma once
#include <string>
namespace Modelo {

    //Niveles de urgencia
    enum class NivelUrgencia {
        RCP = 1,
        Emergencia = 2,
        Urgencia = 3,
        UrgenciaMenor = 4,
        SinUrgencia = 5
    };

    struct Paciente {
        int id;
        std::string nombre;
        NivelUrgencia urgencia;
        std::string sintoma;

        //Constructor vacio
        Paciente() : id(0), urgencia(NivelUrgencia::SinUrgencia) {}

        //Constructor con datos
        Paciente(int id, std::string nom, NivelUrgencia urg, std::string sin)
            : id(id), nombre(nom), urgencia(urg), sintoma(sin) {
        }

        bool operator<(const Paciente& otro) const {
            return (int)this->urgencia > (int)otro.urgencia;
        }

        bool operator>(const Paciente& otro) const {
            return (int)this->urgencia < (int)otro.urgencia;
        }
    };
}
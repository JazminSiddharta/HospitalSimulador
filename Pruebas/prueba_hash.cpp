#pragma once
#include "pch.h"
#include "CppUnitTest.h"

// ---------------- CORRECCIÓN DE RUTAS ----------------
// Fíjate que cambié todas las "\" por "/"
#include "C:/Users/CixoY/source/repos/HospitalSimuladors/hospital_lib/include/Interfaces/IHashTable.hpp"
#include "C:/Users/CixoY/source/repos/HospitalSimuladors/hospital_lib/include/models/Medico.hpp"
#include "C:/Users/CixoY/source/repos/HospitalSimuladors/hospital_lib/include/models/Paciente.hpp"
#include "C:/Users/CixoY/source/repos/HospitalSimuladors/hospital_lib/include/models/Sala.hpp"
// -----------------------------------------------------

#include <unordered_map>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// IMPORTANTE: Usamos los namespaces para encontrar las clases
using namespace Modelo;
using namespace Interfaces;

class MiHashTable : public IHashTable<int, Paciente> {

private:
    std::unordered_map<int, Paciente> tabla;

public:
    MiHashTable() = default;

    // Insertar o reemplazar
    void put(const int& key, const Paciente& value) override {
        tabla[key] = value;
    }

    // Obtener
    Paciente get(const int& key) override {
        auto it = tabla.find(key);
        if (it != tabla.end()) {
            return it->second;
        }
        // Devuelve un paciente vacío si no existe
        return Paciente{};
    }

    // Eliminar
    void remove(const int& key) override {
        tabla.erase(key);
    }

    // Saber si existe
    bool contains(const int& key) const override {
        return tabla.find(key) != tabla.end();
    }
};


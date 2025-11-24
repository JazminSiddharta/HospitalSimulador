#include <iostream>
#include <models/Paciente.hpp>
#include <interfaces/IStack.hpp> 

int main() {
    std::cout << "PRUEBA" << std::endl;
    Modelo::Paciente p1(1, "Juan Perez", Modelo::NivelUrgencia::Urgencia, "Dolor de pecho");
    std::cout << "Cargado correctamente" << p1.nombre << std::endl;
    //Probar interfaces
    Interfaces::IStack<int>* pilaDePrueba = nullptr;
    std::cout << "Interfaz IStack redi check :)" << std::endl;

    std::cout << "TODO FUNCIONA TILIN!" << std::endl;
    std::cin.get();
    return 0;
}
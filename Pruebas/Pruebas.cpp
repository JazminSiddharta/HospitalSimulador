#include "pch.h" 
#include "CppUnitTest.h"
#include <models/Paciente.hpp> 
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace Pruebas
{
	TEST_CLASS(ClaseDePruebas)
	{
	public:
		TEST_METHOD(PruebaDeConexion)
		{
			//Creamos paciente con estructura
			Modelo::Paciente miPaciente;
			miPaciente.id = 123;
			miPaciente.nombre = "Prueba";
			//Si los valores coinciden, la prueba pasa
			Assert::AreEqual(123, miPaciente.id);
		}
	};
}
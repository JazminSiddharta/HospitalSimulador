#pragma once
#include <string>
#include "IList.hpp" 

namespace Interfaces {
    //T= Tipo de dato
    template <typename T>
    class IGraph 
    {
    public:
        virtual ~IGraph() {}
        virtual void addNode(const T& node) = 0;
        //Conecta dos salas
        virtual void addEdge(const T& from, const T& to, int weight) = 0;

        //Algoritmo BFS (Búsqueda en Anchura)
        //Debe devolver una lista con el camino paso a paso
        virtual std::string bfs(const T& startNode, const T& targetNode) = 0;
    };
}
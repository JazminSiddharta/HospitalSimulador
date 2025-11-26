#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <string>

using namespace std;

template <typename T>
class RutasHospital
{
private:
    struct Arista
    {
        T origen;
        T destino;

        Arista(T o, T d) : origen(o), destino(d) {}
    };

    vector<Arista> listaAristas;
    unordered_map<T, vector<T>> listaAdyacencia;

    unordered_map<T, vector<T>> construirListaAdyacencia(const vector<Arista>& listaAristas)
    {
        unordered_map<T, vector<T>> listaAdyacencia;

        for (const auto& arista : listaAristas)
        {
            listaAdyacencia[arista.origen].push_back(arista.destino);
            listaAdyacencia[arista.destino].push_back(arista.origen);
        }

        return listaAdyacencia;
    }

public:
    RutasHospital()
    {
        inicializarRutas();
    }

    void inicializarRutas()
    {
        listaAristas.clear();

        T R = T("Recepción");
        T SE = T("Sala de Espera");
        T B = T("Baño");
        T E = T("Emergencias");
        T F = T("Farmacia");
        T P = T("Pediatra");
        T Q = T("Quirofano");
        T SR = T("Sala de Radiografía");
        T T_ = T("Sala de terapia");
        T ZH = T("Zona de hospitalización");
        T ZC = T("Zona de Consultarios");

        listaAristas.push_back(Arista(R, SE));
        listaAristas.push_back(Arista(R, B));
        listaAristas.push_back(Arista(R, E));
        listaAristas.push_back(Arista(R, F));
        listaAristas.push_back(Arista(SE, B));
        listaAristas.push_back(Arista(SE, ZC));
        listaAristas.push_back(Arista(SE, Q));
        listaAristas.push_back(Arista(B, ZH));
        listaAristas.push_back(Arista(E, Q));
        listaAristas.push_back(Arista(F, ZC));
        listaAristas.push_back(Arista(P, ZH));
        listaAristas.push_back(Arista(SR, ZC));
        listaAristas.push_back(Arista(SR, T_));
        listaAristas.push_back(Arista(T_, ZH));

        listaAdyacencia = construirListaAdyacencia(listaAristas);
    }

    vector<T> BFS_caminoMasCorto(const T& nodoInicial, const T& nodoDestino) const
    {
        vector<T> camino;

        if (nodoInicial == nodoDestino)
        {
            camino.push_back(nodoInicial);
            return camino;
        }

        unordered_set<T> visitados;
        queue<T> cola;
        unordered_map<T, T> padre;
        unordered_map<T, int> distancia;

        visitados.insert(nodoInicial);
        cola.push(nodoInicial);
        distancia[nodoInicial] = 0;
        padre[nodoInicial] = T();

        bool encontrado = false;

        while (!cola.empty() && !encontrado)
        {
            T nodoActual = cola.front();
            cola.pop();

            auto it = listaAdyacencia.find(nodoActual);
            if (it != listaAdyacencia.end())
            {
                for (const T& vecino : it->second)
                {
                    if (visitados.find(vecino) == visitados.end())
                    {
                        visitados.insert(vecino);
                        cola.push(vecino);
                        padre[vecino] = nodoActual;
                        distancia[vecino] = distancia[nodoActual] + 1;

                        if (vecino == nodoDestino)
                        {
                            encontrado = true;
                            break;
                        }
                    }
                }
            }
        }

        if (encontrado) {
            stack<T> pilaCamino;
            T actual = nodoDestino;

            while (actual != T())
            {
                pilaCamino.push(actual);
                actual = padre.at(actual);
            }

            while (!pilaCamino.empty())
            {
                camino.push_back(pilaCamino.top());
                pilaCamino.pop();
            }
        }

        return camino;
    }

    const unordered_map<T, vector<T>>& obtenerListaAdyacencia() const {
        return listaAdyacencia;
    }

    size_t obtenerNumeroAristas() const {
        return listaAristas.size();
    }

    bool existeNodo(const T& nodo) const {
        return listaAdyacencia.find(nodo) != listaAdyacencia.end();
    }

    vector<T> obtenerVecinos(const T& nodo) const {
        auto it = listaAdyacencia.find(nodo);
        if (it != listaAdyacencia.end()) {
            return it->second;
        }
        return vector<T>();
    }

    void agregarArista(const T& origen, const T& destino) {
        listaAristas.push_back(Arista(origen, destino));
        listaAdyacencia = construirListaAdyacencia(listaAristas);
    }
};
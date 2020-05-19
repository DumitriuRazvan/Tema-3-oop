#include "CatalogIndividual.h"

template<typename T>
int CatalogIndividual<T>::new_nr_matricol = 5000;

template <class T>
unordered_map<int, vector<Elev>> CatalogIndividual<T>::examene;

template<typename T>
CatalogIndividual<T>& CatalogIndividual<T>::operator+=(pair<T,vector<Elev>> p)
    {
        T examen = p.first;
        vector<Elev> elevi = p.second;
        auto it = examene.find(examen.getInc());
        if(it == examene.end())                     // not found
        {
        examene.insert(make_pair(examen.getInc(),vector<Elev>(elevi)));
        }
        else
        {
        it->second.insert(it->second.end(), elevi.begin(), elevi.end());
        }
        return *this;
    }

template <typename T>
CatalogIndividual<T>& CatalogIndividual<T>::operator+=(pair<T,Elev> p)
{
    T* examen = &p.first;
    Elev* elev = &p.second;
    auto it = examene.find(examen->getInc());
    if(it == examene.end())
    {
        examene.emplace(examen->getInc(), vector<Elev>{{ Elev(*elev) }});
    }
    else
    {
        it->second.push_back(*elev);
    }
    return *this;
}

template class CatalogIndividual<Partial>;
template class CatalogIndividual<ExamenFinal>;

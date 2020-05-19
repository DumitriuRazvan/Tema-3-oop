#include <unordered_map>
#include <utility> // pair
#include <vector>
#include <iostream>
#include "Elev.h"
#include "Partial.h"
#include "ExamenFinal.h"
using namespace std;
template <typename T>
class CatalogIndividual
{
private:

    int m_nr_matricol;
    int m_nr_examene;

public:
    static int new_nr_matricol;
    static unordered_map<int,vector<Elev>> examene;
    CatalogIndividual(int nr_examene = 0)
    : m_nr_examene(nr_examene)
    {
    }
    CatalogIndividual(const CatalogIndividual &ob)
        : m_nr_examene(ob.m_nr_examene)
    {
        examene = move(ob.examene);
    }
    CatalogIndividual& operator=(const CatalogIndividual &ob) = delete;
    ~CatalogIndividual()
    {

    }
    static int get_new_nr_matricol()
    {
        return new_nr_matricol++;
    }
    static void print_my_object()
    {
        for(auto &x : examene)
        {
            auto id = x.first;
            auto vect = x.second;
            cout << "Studentii care nu au trecut la examenul cu id-ul " << id << " sunt: ";
            for(auto &el : vect)
            {
                cout << el.getInfo() << " ";
            }
            cout << endl;
        }
    }
    CatalogIndividual& operator+=(pair<T,Elev> p);
    CatalogIndividual& operator+=(pair<T,vector<Elev>> p);
};

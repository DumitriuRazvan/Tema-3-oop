#include "Elev.h"
using namespace std;
Elev::Elev(string nume, string prenume, int grupa)
            : m_nume(nume), m_prenume(prenume), m_grupa(grupa)
        {

        }
Elev::Elev(const Elev& other)
            : m_nume(other.m_nume), m_prenume(other.m_prenume), m_grupa(other.m_grupa)
            {

            }
Elev& Elev::operator=(const Elev& other)
{
    if(this==&other)
        return *this;
    this->m_grupa = other.m_grupa;
    this->m_nume = other.m_nume;
    this->m_prenume = other.m_prenume;
    return *this;

}
istream& operator>>(istream& in, Elev &a)
{
    cout << "Nume: "; in >> a.m_nume;
    cout << "Prenume: "; in >> a.m_prenume;
    cout << "Grupa: "; in >> a.m_grupa;
    return in;
}
ostream& operator<<(ostream& out, Elev &a)
{
    out << "Nume " << a.m_nume << "\n" << "Prenume " << a.m_prenume << "\n" << "Grupa " << a.m_grupa << "\n";
    return out;
}

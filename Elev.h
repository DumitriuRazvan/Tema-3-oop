#ifndef ELEV_H
#define ELEV_H
#include <string>
#include <iostream>
using namespace std;

class Elev
{
private:
    string m_nume;
    string m_prenume;
    int m_grupa;
    public:
        Elev(string nume="", string prenume="", int grupa = 0);
        Elev(const Elev& other);
        Elev& operator=(const Elev& other);
        friend istream& operator>>(istream& in, Elev &a);
        friend ostream& operator<<(ostream& out, Elev &a);
        inline string getInfo()
        {
            return (m_nume + m_prenume + to_string(m_grupa));
        }
};

#endif // ELEV_H

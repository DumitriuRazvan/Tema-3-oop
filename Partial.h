#ifndef PARTIAL_H
#define PARTIAL_H
#include "Examen.h"

class Partial:virtual public Examen
{
    float m_notaOral;
public:
    float get_notaOral() const {return m_notaOral;}
    Partial( std::string denumireExamen ="", float notaScris=0, float notaOral=0);
	Partial(const Partial& other);
	Partial& operator = (const Partial& other);
	friend void citire(Examen* examen);
};

#endif // PARTIAL_H

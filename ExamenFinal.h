#ifndef EXAMENFINAL_H
#define EXAMENFINAL_H
#include "Examen.h"

class ExamenFinal: virtual public Examen
{
private:
    float m_extrapuncte;
public:
    float get_extrapuncte() const {return m_extrapuncte;}
    ExamenFinal( std::string denumireExamen ="", float notaScris=0, float extrapuncte=0);
	ExamenFinal(const ExamenFinal& other);
	ExamenFinal& operator= (const ExamenFinal& other);
	friend void citire(Examen* examen);
};

#endif // EXAMENFINAL_H

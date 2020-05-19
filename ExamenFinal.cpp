#include "ExamenFinal.h"

ExamenFinal::ExamenFinal(std::string denumireExamen, float notaScris, float extrapuncte)
    : Examen(denumireExamen,notaScris), m_extrapuncte(extrapuncte){
}

ExamenFinal::ExamenFinal(const ExamenFinal& other)
    : Examen(other), m_extrapuncte(other.m_extrapuncte){
}

ExamenFinal& ExamenFinal::operator=(const ExamenFinal& other)
{
    if(this==&other)
        return *this;
	m_denumireExamen = other.m_denumireExamen;
	m_idExamen = other.m_idExamen;
	m_notaScris = other.m_notaScris;
	m_extrapuncte = other.m_extrapuncte;
	return *this;
}


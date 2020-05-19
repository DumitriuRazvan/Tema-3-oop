#include "Partial.h"

Partial::Partial(std::string denumireExamen, float notaScris, float notaOral)
    : Examen(denumireExamen,notaScris), m_notaOral(notaOral){
}

Partial::Partial(const Partial& other)
    : Examen(other), m_notaOral(other.m_notaOral){
}

Partial& Partial::operator=(const Partial& other)
{
	m_denumireExamen = other.m_denumireExamen;
	m_idExamen = other.m_idExamen;
	m_notaScris = other.m_notaScris;
	m_notaOral = other.m_notaOral;
	return *this;
}

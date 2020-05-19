#include "Examen.h"
#include "ExamenFinal.h"
#include "Partial.h"
#include <iostream>
#include <exception>

int Examen::m_nextID = 100;
Examen::Examen(std::string denumireExamen, float notaScris)
    : m_denumireExamen(denumireExamen), m_notaScris(notaScris), m_idExamen(get_nextId())
{

}

Examen::Examen(const Examen& other)
    : m_denumireExamen(other.m_denumireExamen), m_idExamen(other.m_idExamen), m_notaScris(other.m_notaScris)
{

}

Examen& Examen::operator=(const Examen& other)
{
    if(this==&other)
        return *this;
	this->m_denumireExamen = other.m_denumireExamen;
	this->m_idExamen = other.m_idExamen;
	this->m_notaScris = other.m_notaScris;
	return *this;
}

Examen::~Examen()
{
}



void Examen::print()
{
    std::cout << "Id examen: " << this->m_idExamen << "\n";
    std::cout << "Denumire examen: " << this->m_denumireExamen << "\n";
    std::cout << "Nota scris: " << this->m_notaScris << "\n";
}


std::ostream& operator<<(std::ostream& out, Examen& examen)
{
	examen.print();
	return out;
}


std::istream& operator>>(std::istream& in, Examen& examen)
{
    citire(&examen);
    return in;
}

void citire(Examen* examen)
{

    std::cout << "Denumire examen: ";
    std::cin.ignore();
    std::getline(std::cin,examen->m_denumireExamen);
    try{
        std::cout << "Nota la scris: "; std::cin >> examen->m_notaScris;
    }
    catch(std::exception &e)
    {
        std::cout << "eroare la citire: " << e.what();
    }
    if(Partial* aux = dynamic_cast<Partial*>(examen)){
        try{
        std::cout << "Nota la oral: "; std::cin >> aux->m_notaOral;
        }
        catch(std::exception &e)
        {
            std::cout << "eroare la citire: " << e.what();
        }
    }
    else if(ExamenFinal *aux = dynamic_cast<ExamenFinal*>(examen)){
        try{
        std::cout << "Extrapuncte proiect: "; std::cin >> aux->m_extrapuncte;
        }
        catch(std::exception &e)
        {
            std::cout << "eroare la citire: " << e.what();
        }
    }
}

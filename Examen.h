#ifndef EXAMEN_H
#define EXAMEN_H
#include <string>

class Examen
{

protected:
    static int m_nextID;
	int m_idExamen;
	std::string m_denumireExamen;
	float m_notaScris;
public:
    float get_notaScris() const { return m_notaScris;}
	Examen( std::string denumireExamen ="", float notaScris=0);
	Examen(const Examen& other);
	Examen& operator = (const Examen& other);
	virtual ~Examen();
	int getInc()const { return m_idExamen;}     //move to .cpp
	static int get_nextId(){return m_nextID++;}; //move to .cpp
	virtual void print();
	friend void citire(Examen* examen);
    friend std::ostream& operator << (std::ostream& out, Examen& examen);
	friend std::istream& operator >>(std::istream& in, Examen& examen);
};



#endif // EXAMEN_H

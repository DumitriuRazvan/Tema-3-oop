#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <utility> // pair
#include "CatalogIndividual.h"
#include "ExamenFinal.h"
#include "Partial.h"
#include "Quiz.h"
#include "Examen.h"
using namespace std;

vector<CatalogIndividual<Partial>> cat_a;
vector<CatalogIndividual<ExamenFinal>> cat_b;

Quiz<3> my_quiz;
void executa_Elev(Elev &a)
{
int nr_partiale=0;
int nr_examene_finale=0;
Partial p;
ExamenFinal e;

cout << "Detaliile partialului" << "\n";
cin >> p;
nr_partiale++;
cout << "Detaliile examenului final" << "\n";
cin >> e;
nr_examene_finale++;
if(p.get_notaOral() < 5 && p.get_notaScris() < 5){
     cout << "Partialul nu a fost luat! " << "\n" << "Se va sustine din nou.";
     cin >> p;
     nr_partiale++;
}

CatalogIndividual<Partial> aux(nr_partiale);
CatalogIndividual<ExamenFinal> aux2(nr_examene_finale);

cout << "Se doreste marirea notei: ";
string marire;
cin >> marire;
if(marire == "da")
{
    my_quiz += a.getInfo();
}
if(p.get_notaOral() < 5 && p.get_notaScris() < 5)
        aux += make_pair(p,a);
if(e.get_notaScris() < 5)
    aux2 += make_pair(e,a);
cat_a.push_back(aux);
cat_b.push_back(aux2);
}


int main()
{
cin >> my_quiz;
cout << my_quiz;
int nr;
cout << "Cati studenti se prezinta in sesiune: "; cin >> nr;
for(int i=0;i<nr;i++)
{
    Elev a;
    cin >>a;
    executa_Elev(a);
}
    CatalogIndividual<Partial>::print_my_object();
    CatalogIndividual<ExamenFinal>::print_my_object();
vector<string> istoric = my_quiz.get_istoric();
sort(istoric.begin(),istoric.end());
cout << "Elevii care au dat quiz-ul sunt: ";
    for(int i=0;i<istoric.size()-1;i++)
    {
        if(istoric[i] == istoric[i+1])
            {
                cout << istoric[i] << " ";
                while(istoric[i] == istoric[i+1])
                    i++;
            }
    }
}

#include <string>
#include <vector>
#include <iostream>
using namespace std;
template<int n>
class Quiz
{
int nr_intrebari;
string *text_intrebari;
bool *bool_intrebari;
vector<string> istoric_elevi;
public:
    Quiz()
        :nr_intrebari(n)
    {
         try
            {
            text_intrebari = new string[nr_intrebari];
            bool_intrebari = new bool[nr_intrebari];
            }
            catch(bad_alloc& e)
            {
                cout << "Eroare de alocare a memoriei!" << "\n" << e.what();
            }
    }
    Quiz(const Quiz& ob);
    ~Quiz()
    {
        delete[] text_intrebari;
        delete[] bool_intrebari;
    }

    /*
     *  Could write definition before class declaration for friend template functions
    */
    friend ostream& operator<< (std::ostream &out,Quiz<n> &obj)
    {
        if(obj.nr_intrebari <= 0)
            return out;
        out<< "\n";
        for(int i=0;i<obj.nr_intrebari;i++)
        {
        out << "Intrebarea " << i+1 << "\n" << obj.text_intrebari[i] << "\n" << "Raspunsul corect "
                "al acesteia este: " << (obj.bool_intrebari[i] ? "adevarat" : "fals") << "\n";
        }
        return out;
    }
    friend istream& operator>>(std::istream &in,Quiz<n> &obj)
    {
    for(int i=0;i<obj.nr_intrebari;i++)
    {
        std:;cout << "Intrebarea " << i+1 << "\n";
        std::cout << "Enuntul este: "; in.ignore(); std::getline(in,obj.text_intrebari[i]);
        std::cout << "Raspunsul(0,1) este: "; in >> obj.bool_intrebari[i];
    }
    return in;
    }
    Quiz& operator+= (string el)
    {
        istoric_elevi.push_back(el);
    }
    auto get_istoric()
    {
        return istoric_elevi;
    }
};

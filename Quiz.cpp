#include "Quiz.h"
#include <cstring> // memset
#include <exception>
using namespace std;
//template <int n>
//Quiz<n>::Quiz()
//    : nr_intrebari(n)
//{
//     try
//        {
//        text_intrebari = new string[nr_intrebari];
//        bool_intrebari = new bool[nr_intrebari];
//        }
//        catch(bad_alloc& e)
//        {
//            cout << "Eroare de alocare a memoriei!" << "\n" << e.what();
//        }
//}
template <int n>
Quiz<n>::Quiz(const Quiz<n> &ob)
    {
        nr_intrebari = ob.nr_intrebari;
        try{
        text_intrebari = new string[nr_intrebari];
        bool_intrebari = new bool[nr_intrebari];
        memcpy(text_intrebari,ob.text_intrebari,sizeof(ob.text_intrebari));
        memcpy(bool_intrebari,ob.bool_intrebari,sizeof(bool_intrebari));
        }
        catch(bad_alloc& e)
        {
            cout << "Eroare de alocare a memoriei!" << e.what();
        }
}

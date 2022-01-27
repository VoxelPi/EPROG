#include <iostream>
using std :: cout;
using std :: endl;
using std :: string;
class Klasse {
private :
    string name ;
public :
    Klasse ( string input = " nobody " ) {
        name = input ;
        cout << " Konstruktor ( " << name << " ) " << endl ;
    }

    Klasse ( const Klasse & rhs ) {
        name = rhs . name ;
        cout << " Kopierkonstruktor ( " << name << " ) " << endl ;
    }

    Klasse& operator =( const Klasse & rhs ) {
        name = rhs . name ;
        cout << " Zuweisungsoperator " << endl ;
        return * this ;
    }

    ~Klasse() {
        cout << " Destruktor ( " << name << " ) " << endl ;
    }

    string get () const {
    return name ;
    }

    string & set () {
        // cout << " Das ist schlechter Stil ." << endl ;
        return name ;
    }

};

void cbv ( Klasse input ) {
    cout << " Call by Value ( " << input . get () << " ) " << endl ;
}

void cbr ( const Klasse & input ) {
    cout << " Call by Reference ( " << input . get () << " ) " << endl ;
}

int main () {
    Klasse dpr ( " Dirk " );
    Klasse mru = dpr ;
    mru . set () = " Michele " ;
    cbv ( mru );
    cbr ( dpr );
    return 0;
}
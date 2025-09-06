#include <iostream>
using namespace std;

template <size_t fil, size_t col>
void print(char (&A)[fil][col]){
    //cout<< sizeof(A)<<endl
    const int columna=(sizeof(A)/sizeof(*A));
    for( char(* i)[columna] = A ; i < A + sizeof(*A) ; i++ ) {
        for( char* j = *i ; j < *i + columna ; j++ ){
            cout<< *j <<" ";
        }   
        cout<<endl;
    }
} 
 
int main() {
    char A[] = {'H', 'O', 'L', 'A'};
    char B[] = "HOLA";  // Aquí se corrige la forma de definir el array de caracteres

    cout << "Tamaño del array A es " << sizeof(A) << endl;
    cout << "Tamaño del array B es " << sizeof(B) << endl;

    cout << "Esto está en B: " << B << "-Fin" << endl;
    cout << "Esto está en A: " << A << "-Fin" << endl;

    // Imprime cada carácter en B
    int j=0;
    char* p=B;
    for (; *p; p++) {
        cout<< &p <<"  "<<p <<" "<< j << endl;
        j++;
    }
    cout<<endl<<"yyy"<<*(p-1) <<" "<< j <<"yyy"<<endl;

    // Imprime cada carácter en A
    int i=0;
    for (char *p = A; *p; p++) {
        cout << *p << endl;
        i++;
    }
    cout <<i<<endl;
    
    cout <<*(B+1)<<endl;  
    cout <<*(A+1)<<endl;
    cout <<*(A+sizeof(A)-1)<<endl; 
    cout <<*(B+sizeof(B)-2)<<endl;
    
    
    
    
    const int fil=10;
    const int col=10;



    char AA[fil][col] = { {'T','P','P','A','P','T','P','I','P','T'},
                         {'O','P','A','T','A','P','O','Z','O','J'},
                         {'S','A','T','A','T','O','T','A','Z','I'},
                         {'A','T','O','P','A','P','A','T','O','S'},
                         {'P','A','T','A','N','O','P','O','T','N'},
                         {'T','A','O','P','A','T','I','P','A','P'},
                         {'R','R','N','A','D','O','T','A','P','O'},
                         {'E','D','N','T','A','P','O','T','A','T'},
                         {'N','I','I','A','T','I','T','A','P','A'},
                         {'P','S','S','N','T','T','T','P','A','P'}  };
                         


    print(AA);
    return 0;
}

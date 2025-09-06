#include <iostream>
using namespace std;


template <size_t fil, size_t col>
void print(char (&A)[fil][col]){
    //cout<< sizeof(A)<<endl
    const int columna = (sizeof(A)/sizeof(*A));
    
    for( char(* i)[columna] = A ; i < A + sizeof(*A) ; i++ ) {
        for( char* j = *i ; j < *i + columna ; j++ ){
            cout<< *j <<" ";
        }   
        cout<<endl;
    }
} 
 
 
    //cout <<*(A+sizeof(A)-1)<<endl; char A[] = {'H', 'O', 'L', 'A'}; size 4
    //cout <<*(B+sizeof(B)-2)<<endl; char B[] = "HOLA"; size 5
        
int tamano_palabra(char* palabra){
    char* i = palabra;
    for(; *i ; i++);
    return i-palabra;
}
    
template <size_t fil, size_t col>
int contar_palabras(char (&A)[fil][col],char* palabra){
    const int palabra_size = tamano_palabra(palabra);
    //cout << sizeof(palabra) <<endl;

    int contador=0;
    const int columna = sizeof(*A);
    const int fila = (sizeof(A)/sizeof(*A));
    //cout << columna <<endl;
    //cout << fila <<endl;
    for( char(* i)[columna] = A ; i < A + sizeof(*A) ; i++ ) {
        cout<< "______"<<endl;
        for( char* j = *i ; j < *i + columna ; j++ ){
            //cout << (*i+columna-1)-(j)<<" ";
            //cout << palabra_size <<endl;
            //cout<< "NO IF ";
            //cout << ( (*i+columna)-(j) ) << " "<<endl;
            
            
            
            if( (*j == *palabra) ){                                      // 1 2 3 4 5 6 78910
                int m=0;
                
                cout<< "1"<< j-*i+1 <<endl; 
                if(  (*i + columna-1) - j +1 >= palabra_size ){               // p p p p p p p000
                    cout<< "IF: " << j << "IF: "<< j-*i+1 <<endl;
                    char* p_ptr = palabra;
                        for( ; *p_ptr ; p_ptr++ ){
                            if( *p_ptr != *(j+m) ) {break;}
                            m++;               
                        }
                        
                        if( palabra_size == m ) contador++;
                        m--;
                }
                cout<< "2"<< j-*i+1 <<endl;                                                                             // p  0 
                if ( ( A + fila-1 ) - i + 1 >= palabra_size ){                                  // p 
                        cout<< "SEC IF " << j << "IF: "<< j-*i+1 <<endl;                    // p 
                        //cout <<  A + fila-1 <<" "<< i<<" "<<( A + fila-1 ) - (i)<<endl;   // p
                        int n=0;                                                            // p
                        char* q = palabra;
                        for( ; *q ; q++ ){                                                  // p
                            if( *q != *( *(i+n) + (j - *i) )) break;                        // p
                            n++;                                                            // 0
                        }
                        
                        cout<< n<<endl; 
                        if( palabra_size == n ) contador++;                                 // 0  9
                }                                                                            
               
                cout<< "3"<< j-*i+1 <<endl;                                                   //1234 5 6 7 8 9 10
                if( (j - *i) + 1 >= palabra_size ){cout<< "TEC IF " << j << "IF: "<< j-*i+1 <<endl;               //000p p p p p p p 
                        int f=0;
                        char* p = palabra;
                        
                        for( ; *p ; p++ ){                         // (j - *i) = 0 / 0+1 =1
                            if( *p != *(j-f) ) break; 
                            f++;               
                        }
                        if( palabra_size == f ) contador++;
                }                                                                           // 0                 
                     cout<< "4"<< j-*i+1 <<endl;                                                                        // 0 
                if ( (  i - A ) + 1 >= palabra_size ){cout<< j << "IF: "<< j-*i+1 <<endl;                                      // 0
                        int piv_up = 0;                                                     // p 
                        char* q = palabra;                                                  // p
                        for( ; *q ; q++ ){                                                  // p
                            if( *q != *( *(i- piv_up) + (j-*i) )   ) break;                 // p                  
                            piv_up++;                                                       // p
                        }                                                                   // p
                        if( palabra_size == piv_up ) contador++;                            // p 
                }   
                
                j=j+m;
            }
        }   
        //cout<<endl;
    }
    return contador;
}  

int main()
{

    const int fil=10;
    const int col=10;



    char A[fil][col] = { {'T','P','P','A','P','T','P','I','P','T'},
                         {'O','P','A','T','A','P','O','Z','O','J'},
                         {'S','A','T','A','T','O','T','A','Z','I'},
                         {'A','T','O','P','A','P','A','T','O','S'},
                         {'P','A','T','A','N','O','P','O','T','N'},
                         {'T','A','O','P','A','T','I','P','A','P'},
                         {'R','R','N','A','D','O','T','A','P','O'},
                         {'E','D','N','T','A','P','O','T','A','T'},
                         {'N','I','I','A','T','I','T','A','P','A'},
                         {'P','S','S','N','T','T','T','P','A','P'}  };
                         
    char palabra[] = "PATA";

    cout << "PATA" <<endl;
    print(A);
    int n = contar_palabras(A,palabra);
    cout<<n;
    //cout<<tamano_palabra(palabra);
    //cout<< sizeof(A)<<endl; 

  
}

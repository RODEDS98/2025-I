#include <iostream>
using namespace std;


template <size_t fil, size_t col>
void print(char (&A)[fil][col]){
    const int columna = (sizeof(A)/sizeof(*A));
    cout<<endl;cout<<endl;
    for( char(* i)[columna] = A ; i < A + sizeof(*A) ; i++ ) {
        cout<<"     ";
        for( char* j = *i ; j < *i + columna ; j++ ){
            cout<< *j <<" ";
        }   
        cout<<endl;
    }
}
        
int tamano_palabra(char* palabra){
    char* i = palabra;
    for(; *i ; i++);
    return i-palabra;
}
    
template <size_t fil, size_t col>
int contar_palabras(char (&A)[fil][col],char* palabra){
    
    const int palabra_size = tamano_palabra(palabra);
    int contador=0;
    const int columna = sizeof(*A);
    const int fila = (sizeof(A)/sizeof(*A));
    
    for( char(* i)[columna] = A ; i < A + sizeof(*A) ; i++ ) {
        for( char* j = *i ; j < *i + columna ; j++ ){
            
            if( (*j == *palabra) ){                                                   // 1 2 3 4 5 6 78910
                int m=0;
                char* tmp_ptr = j;
                
                if(  (*i + columna-1) - j +1 >= palabra_size ){               
                    char* p_ptr = palabra;                                           // p p p p p p p000
                    int n=0;
                    
                    for( ; *p_ptr ; p_ptr++ ){
                        if( *p_ptr != *(j+m) ) break;       
                        if( *p_ptr == *(palabra) && n<2 ) {                          //Solo guarda hasta la segunda vez q encuentre la primera letra de la palabra
                            n++; 
                            tmp_ptr = j+m;
                        }                                               
                        
                        m++;
                    }
                        
                    if( palabra_size == m ) {
                        contador++;                                         //{contador++;cout<<endl<<"("<< (i-A) + 1 <<","<< (j-*i)+1 <<")"<<endl;}   //contador++;
                        
                    } 
                        
                    if(n==2){
                        tmp_ptr--;
                    }
                    m--;
                }                                                                           // p
                                                                                            // p
                if ( ( A + fila-1 ) - i + 1 >= palabra_size ){                              // p 
                        int n=0;                                                            // p
                        char* q = palabra;                                                  // p
                        for( ; *q ; q++ ){                                                  // p
                            if( *q != *( *(i+n) + (j - *i) )) break;                        // p
                            n++;                                                            // 0
                        }                                                                   // 0
                                                                                            // 0
                        if( palabra_size == n ) contador++;                                  // {contador++;cout<<endl<<"("<< (i-A) + 1 <<","<< (j-*i)+1 <<")"<<endl;}   //contador++;                                  
                }  
                                                                                          //1234 5 6 7 8 9 10
                if( (j - *i) + 1 >= palabra_size ){                                       //000p p p p p p p    // (j - *i) = 0 / 0+1 =1
                        int f=0;
                        char* p = palabra;
                        
                        for( ; *p ; p++ ){                         
                            if( *p != *(j-f) ) break; 
                            f++;               
                        }
                        if( palabra_size == f ) contador++;                              // {contador++;cout<<endl<<"("<< (i-A) + 1 <<","<< (j-*i)+1 <<")"<<endl;}   //contador++;
                }                                         
                                                                                            // 0
                                                                                            // 0
                                                                                            // 0 
                if ( (  i - A ) + 1 >= palabra_size ){                                      // p
                        int piv_up = 0;                                                     // p 
                        char* q = palabra;                                                  // p
                        for( ; *q ; q++ ){                                                  // p
                            if( *q != *( *(i- piv_up) + (j-*i) )   ) break;                 // p                  
                            piv_up++;                                                       // p
                        }                                                                   // p
                        if( palabra_size == piv_up )contador++;                              //  {contador++;cout<<endl<<"("<< (i-A) + 1 <<","<< (j-*i)+1 <<")"<<endl;}   //contador++; 
                }
                
                j=tmp_ptr;
                
            }
        }   
    }
    return contador;
}  

int main()
{

    const int fil=10;
    const int col=10;
    
    /*
    char A[fil][col] = { {'T','P','P','A','P','T','P','I','P','T'},
                         {'O','P','A','T','A','P','O','Z','O','J'},
                         {'S','A','T','A','T','O','T','A','Z','I'},
                         {'A','T','O','P','A','P','A','T','O','S'},
                         {'P','A','T','A','N','O','P','O','T','N'},
                         {'T','A','O','P','A','T','I','P','A','P'},
                         {'R','R','N','A','D','O','T','A','P','O'},
                         {'E','D','N','T','A','P','O','T','A','T'},
                         {'N','I','I','A','T','I','T','A','P','A'},
                         {'P','S','S','N','T','T','T','P','A','P'} };
    */                    
    // /*
    char A[fil][col] = { {'T','P','P','A','P','T','D','P','P','T'},
                         {'O','P','A','T','A','P','O','Z','O','J'},
                         {'S','A','T','A','T','O','T','A','Z','I'},
                         {'A','T','A','P','A','D','A','T','O','S'},
                         {'P','A','T','A','N','O','D','O','T','N'},
                         {'T','A','A','P','A','T','I','P','A','P'},
                         {'R','R','N','A','D','O','T','A','P','O'},
                         {'E','D','N','T','A','P','O','T','A','T'},
                         {'N','I','I','A','T','I','T','A','P','A'},
                         {'P','S','S','N','T','T','T','P','A','P'} };
    // */                     
                         
                         
    //char palabra[] = "ATAP";
    char palabra_1[] = "PATAN";
    char palabra_2[] = "PATATA";
    char palabra_3[] = "PATO";
    char palabra_4[] = "TAPA";
    char palabra_5[] = "PATA";

    print(A);
    int n_1 = contar_palabras(A,palabra_1);
    cout<<endl<<"La palabra "<< palabra_1 <<" aparece "<<n_1<< " veces";
    
    int n_5 = contar_palabras(A,palabra_5);
    cout<<endl<<"La palabra "<< palabra_2 <<" aparece "<<n_5<< " veces";
    

    int n_2 = contar_palabras(A,palabra_2);
    cout<<endl<<"La palabra "<< palabra_2 <<" aparece "<<n_2<< " veces";
    
    int n_3 = contar_palabras(A,palabra_3);
    cout<<endl<<"La palabra "<< palabra_3 <<" aparece "<<n_3<< " veces";
    
    int n_4 = contar_palabras(A,palabra_4);
    cout<<endl<<"La palabra "<< palabra_4 <<" aparece "<<n_4<< " veces";
  
}

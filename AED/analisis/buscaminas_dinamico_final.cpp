#include <iostream>
#include <random>  // mt19937, uniform_int_distribution
using namespace std;

void print(int** A, int fil ){
    for(int** i = A ; i < A+fil  ; i++){
        for(  int* j = *i  ; j < *i+fil ; j++){
            if(*j==9){
               cout<<"* ";
            }
            else{
               cout<< *j <<" ";
            }           
        }
        cout<<endl;
    }
} 

void solucion(int** A, int fil ){                     //   100 101 102 103
    int cont=1;
    for(int** i = A ; i < A+fil  ; i++){              //   200 201 202 203
        cout<< i-A <<" < "<<fil <<" -- ";
        for(  int* j = *i  ; j < *i+fil ; j++){       //   300 301 302 303 //   400 401 402 403
            //cout<< *i <<" - "<<*j <<" -- ";
            if( *j != 9 ){
              //cout<<" ff ";
                if(  (i-1) >= A ){
                    if( *( *(i-1) + (j-*i-1) ) == 9   &&   ( *(i-1) + (j-*i-1) )   >= *(i-1) ) (*j)++;       //   o 
                    if( *( *(i-1) + (j-*i+0) ) == 9 )                                          (*j)++;       //      o 
                    if( *( *(i-1) + (j-*i+1) ) == 9   &&   ( *(i-1) + (j-*i+1) )   <  *(i) )   (*j)++;       //         o 
                }
                if( *( j-1 ) ==9   && ( j-1 ) >= *i )      (*j)++;                                           //   o
                if( *( j+1 ) ==9   && ( j+1 ) <  *(i+1) )  (*j)++;                                           //         o

                if(  (i+1) < A+fil ){   // se fixio el problema quitandole A+fil+1)
                    if( *( *(i+1) + (j-*i-1) ) == 9   &&   ( *(i+1) + (j-*i-1) )  >= *(i) ) (*j)++;          //   o 
                    if( *( *(i+1) + (j-*i+0) ) == 9)                                        (*j)++;          //      o 
                    if( *( *(i+1) + (j-*i+1) ) == 9   &&   ( *(i+1) + (j-*i+1))   < *(i+2)) (*j)++;          //         o 
                }   
            //cout<<endl;
           //cout<< *j <<" ";*
          }
        }//cout<<endl;
        cout<<"iteracion"<<cont++<<" "<<endl;;
    }
}

int main()
{
    cout<<"buscaminas\n";

    // Configuración del generador aleatorio
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 1); // devuelve 0 o 1  

    int fil,col;
    fil=10;
    col=10;

    int** p;
    p = new int*[fil];
    
    // creacion
    for(int i= 0; i < fil ; i++ ){
        p[i] = new int[col];
        for (int *j = *(p+i); j < *(p+i)+col; j++) {
            if (dist(gen) == 1) {
                *j = 9; // mina
            }
            else {
                *j = 0; // vacío
            }
        }
    }

    cout<<"solo minas"<<endl;
    print(p,fil);           cout<<endl;cout<<endl;
    solucion(p, 10 );       cout<<endl;cout<<endl;  
    cout<<"solucion"<<endl;
    print(p,10);
    return 0;

}

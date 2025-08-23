#include <iostream>
using namespace std;

void print(int(* A)[10], int fil ){
    for(int(* i)[10]=A    ; i < A+fil  ; i++){
        for(  int* j = *i  ; j < *(i+1) ; j++){
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

void solucion(int(* A)[10], int fil ){             //   100 101 102 103
    for(int(* i)[10]=A    ; i < A+fil  ; i++){        //   200 201 202 203
        for(  int* j = *i  ; j < *(i+1) ; j++){        //   300 301 302 303 //   400 401 402 403
          if( *j != 9 ){

            if( *( *(i-1) + (j-*i-1) ) == 9 ) (*j)++;;    //   o 
            if( *( *(i-1) + (j-*i+0) ) == 9 ) (*j)++;                       //      o 
            if( *( *(i-1) + (j-*i+1) ) == 9 ) (*j)++;                       //         o 

            if( *( j-1 ) ==9 ) (*j)++;                                      //   o
            if( *( j+1 ) ==9 ) (*j)++;                                      //         o

            if( *( *(i+1) + (j-*i-1) ) == 9 ) (*j)++;                       //   o 
            if( *( *(i+1) + (j-*i+0) ) == 9 ) (*j)++;                       //      o 
            if( *( *(i+1) + (j-*i+1) ) == 9 ) (*j)++;                       //         o 

           //cout<< *j <<" ";*
          }
        }
  
    }
}






int main()
{
    cout<<"buscaminas\n";
    int fil,col;
    int** p;
    
    fil=10;
    col=10;
    
    int A[10][10]=   {{0,9,9,0,0,0,0,0,0,0},  //1
                      {0,9,0,0,0,0,0,0,0,0},  //2
                      {0,0,0,0,9,9,0,0,0,0},  //3
                      {0,0,0,0,0,0,0,0,0,0},  //4
                      {0,9,0,0,0,0,0,0,0,0},  //5
                      {0,0,0,0,0,0,0,0,0,0},  //6
                      {0,0,0,0,0,0,0,0,0,0},  //7
                      {0,0,0,0,0,0,0,0,0,0},  //8
                      {0,0,0,0,0,0,0,0,0,0},  //9
                      {0,0,0,0,0,0,0,0,0,0},  //10
                     };
    // Dibujar matriz
    print(A,fil); cout<<endl;cout<<endl;

    
    // Dibujar matriz 

    cout<<"Solucion:"<<endl;
    solucion(A, 10 );     
    print(A,10);

    return 0;
}

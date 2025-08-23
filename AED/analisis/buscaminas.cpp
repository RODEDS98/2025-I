#include <iostream>
using namespace std;

template <class T> 
struct nodo{
    int a;
};


void print(int(* A)[10], int fil , int col ){
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


void solucion(int(* A)[10], int fil , int col ){             //   100 101 102 103
    for(int(* i)[10]=A    ; i < A+fil  ; i++){        //   200 201 202 203
        for(  int* j = *i  ; j < *(i+1) ; j++){        //   300 301 302 303 //   400 401 402 403
          if( *j != 9 ){
            cout<< "--" <<endl;
            cout<<  (j) <<endl;
            cout<<  (*i) <<endl;
            cout<<  (j-*i) <<endl;
            cout<<  (j-*i-1) <<endl;
            cout<< "--" <<endl;
            if( *( *(i-1) + (j-*i-1) ) == 9 ){cout<<"s"<<endl; (*j)++;};    //   o 
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
        cout<<endl;
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
    print(A,fil,col);
    
    cout<<endl;cout<<endl;
    
    // Dibujar matriz
    for(int(*i)[10] = A ; i <  A +fil  ; i++){
        for(int* j = *i  ; j < *i +col ; j++){
           if(*j==1){
               cout<<"* ";
           }
           else{
               cout<<" ";
           }
        }
        cout<<endl;
    }
    
    solucion(A, 10 , 10 );    
    print(A,10,10);

    return 0;
}

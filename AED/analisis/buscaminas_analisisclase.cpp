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
    cout<<endl;cout<<endl;
} 

void solucion(int(* A)[10], int fil ){             //   100 101 102 103
    for(int(* i)[10]=A    ; i < A+fil  ; i++){        //   200 201 202 203
        for(  int* j = *i  ; j < *(i+1) ; j++){        //   300 301 302 303 //   400 401 402 403 *( *(i-1) + (j-*i-1) )
          //cout<<j<<" ";
          if( *j != 9 ){
            cout<<" "<<j<<" "<<*j<<" ";
            if(  (i-1) >= A ){
                
                if( *( *(i-1) + (j-*i-1) ) == 9   &&   ( *(i-1) + (j-*i-1) )   >= *(i-1) ){ (*j)++;cout<<"1 ";}       //   o 
                if( *( *(i-1) + (j-*i+0) ) == 9 )                       {(*j)++;cout<<"2 ";}       //      o 
                if( *( *(i-1) + (j-*i+1) ) ==  9   &&   ( *(i-1) + (j-*i+1) ) <  *(i) ) {(*j)++;cout<<"3 ";}      //         o 
            }
            if( *( j-1 ) ==9   && ( j-1 ) >= *i )      {(*j)++;cout<<"4 ";}                         //   o
            if( *( j+1 ) ==9   && ( j+1 ) < *(i+1) )   {(*j)++; cout<<"6 ";}                        //         o

            if(  (i+1) < A+fil+1 ){
                if( *( *(i+1) + (j-*i-1) ) == 9   &&   ( *(i+1) + (j-*i-1) ) >= *(i) ) {(*j)++;cout<<"7 ";}       //   o 
                if( *( *(i+1) + (j-*i+0) ) == 9)  {(*j)++;cout<<"8 ";}        //      o 
                if( *( *(i+1) + (j-*i+1) ) == 9   &&   ( *(i+1) + (j-*i+1))  < *(i+2) ) {(*j)++;cout<<"9 ";cout<<"j: "<<j<<"  i+1: "<<i+1 <<"  *i: "<<*(i+2)<<"  *(i+1): " << ( *(i+1) + (j-*i+1) )<<endl;};       //         o 
            }

           //cout<< *j <<" ";*
          }
        }cout<<endl;
  
    }
}


void dir(int(* A)[10], int fil ){             //   100 101 102 103
    for(int(* i)[10]=A    ; i < A+fil  ; i++){        //   200 201 202 203
        for(  int* j = *i  ; j < *(i+1) ; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }cout<<endl;cout<<endl;
}



int main()
{
    cout<<"buscaminas\n";
    int fil,col;
    int** p;
    
    fil=10;
    col=10;
    
    int A[10][10]=   {{0,9,9,9,9,9,9,9,9,0},  //1
                      {0,0,0,0,0,0,0,0,0,0},  //2
                      {0,0,0,0,0,0,0,0,9,0},  //3
                      {0,9,0,0,9,0,0,0,9,0},  //4
                      {9,9,0,0,0,0,0,0,9,0},  //1
                      {9,9,0,0,0,0,0,0,9,0},  //2
                      {9,9,9,9,9,0,0,9,9,9},  //3
                      {9,9,9,9,9,9,0,9,9,9},  //8
                      {9,9,9,9,9,9,9,9,9,0},  //9
                      {9,9,9,9,9,9,9,9,9,0},  //10
                     };
    // Dibujar matriz
    print(A,fil); cout<<endl;cout<<endl;

    
    // Dibujar matriz 

    cout<<"Solucion:"<<endl;
    dir(A, 10 );
    solucion(A, 10 );     
    print(A,10);

    return 0;
}

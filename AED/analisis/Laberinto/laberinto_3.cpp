#include <iostream>
using namespace std;

void print(int(* A)[10], int fil ){
    for(int(* i)[10]=A    ; i < A+fil  ; i++){
        for(  int* j = *i  ; j < *(i+1) ; j++){
            if(*j==-1){
               cout<<"X";
            }
            else if(*j==100){
               cout<<"A";
            }
            else if(*j==200){
               cout<<"B";
            }
            
            else{
               cout<<" ";
            }
           
        }
        cout<<endl;
    }
    cout<<endl;
} 
void print2(int(* A)[10], int fil ){
    for(int(* i)[10]=A    ; i < A+fil  ; i++){
        for(  int* j = *i  ; j < *(i+1) ; j++){
            cout<< j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
} 
/*
void LAB(int(* A)[10], int fil, int* dir_A,int* dir_B ){
    //int(* i)[fil]= dir_A;
    
    if( *j != 10 ){
    if(  (i-1) >= A ){
        if( *( *(i-1) + (j-*i+0) ) == 0 )                      (*j)++;                       //      o  
        
        if( *( j-1 ) ==9   && ( j-1 ) >= *i )                      (*j)++;                                        
        if( *( j+1 ) ==9   && ( j+1 ) < *(i+1) )                   (*j)++;                                        // o         o
        if(  (i+1) < A+fil+1 ){
        if( *( *(i+1) + (j-*i+0) ) == 9)                       (*j)++;                                             //      o 
    }
}
*/

template<size_t fil,size_t col>
void encontrar(int (&ini)[fil][col], int* &p_A, int* &p_B, int (&fin)[fil][col]  ){
    int count=0;
    //cout<<sizeof(ini) /sizeof(**ini);
    const int dim = sizeof(ini) /sizeof(**ini);
    for(int* i = *ini ; i < *ini+dim  ; i++ ){
        if ( *i==100){
            count++;
            p_A = i;
        }
        else if ( *i==200){
            count++;
            p_B = i;
        }
        else if ( count==2){
            break;
        }
       
    }
}    

template<size_t fil,size_t col>
void solucion(int(& A)[fil][col], int* dir_A , int* dir_B ){             //   100 101 102 103
    //cout<<A <<endl;
    //cout<<i <<endl;
    int(* i)[col]= A + (dir_A - *A)/col;
    int* j = *i + (dir_A - *i);
    int* p = dir_A;
    int marca=1;
    //cout<<*A << " " <<(dir_A-*A) << " s " <<(dir_A-*A)/col <<endl;
    //cout<<i <<endl;
    //cout<<dir_A <<endl;
    //cout<<*i+3 <<endl;
    if (dir_A < dir_B){
        
        //cout<<A+1 <<" "<<*A+1 <<endl;
        //cout<<i+1 <<" "<<*i+1 <<endl;
        
        while( *i != dir_B ) {
            int contador=0;
            int direccion=0;
            int* tmp= j;
            if(  i-1 >= A && *(j-col) != -1 ){     //arriba
                contador++;
                direccion=1;
            }
            
            if( j-1 >= *i && *(j-1) != -1 ){
                contador++;
                direccion=2;
            }
            
            if( j+1  < *(i+1) && *(j+1) != -1 ){
                contador++;
                direccion=3;
            }         
            
            if(  (i+1) < A+fil+1 && j+col != -1 ){
                contador++;
                direccion=4;
            }
            if (contador == 0){
                *j=marca;
            }
            if (contador == 1){
                *j=marca;
            }
            if (contador > 1){
                marca++;
                *j=marca;
                marca--;
            }
            
            if (direccion==1){ i = i-1; j = j-col;}
            else if (direccion==4){ i = i+1; j = j+col;}
            else if (direccion==2){ j-- ;}
            else if (direccion==3){ j++ ;}
            
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
    
    int* dir_A = nullptr;
    int* dir_B = nullptr;
    
    
    int A[10][10]=  {{0,-1,0, 100, 0,0, 0, 0, 0,-1},  //1
                      {0,-1,0, 0, 0,0, -1,-1, 0,-1},  //2
                      {0,-1,0,-1,-1,0,-1, -1,-1,-1},  //3
                      {0,-1,0,-1, 0,0,-1,  0, 0, 0},  //4
                      {9, 0,0,-1,0,0,0,0,-1,-1},  //1
                      {9,-1,-1,-1,-1,-1,0,0,-1,0},  //2
                      {0,0,0,0,-1,0,0,0,0,0},  //3
                      {0,-1,-1,0,-1,0,0,-1,-1,-1},  //8
                      {-1,-1,0,0,-1,0,0,-1,0,0},  //9
                      {0,0,0,0,-1,0,0,0,0,200},  //10
                     };
    // Dibujar matriz
    print2(A,fil);
    print(A,fil); 

    
    // Dibujar matriz 

    
   
    encontrar(A ,dir_A ,dir_B , A  );
    //cout<<"direccion A:"<< dir_A<<endl<<"direccion B:"<< dir_B<<endl;
    cout<<"Solucion:"<<endl;
    solucion(A, dir_A, dir_B );  
    return 0;
}

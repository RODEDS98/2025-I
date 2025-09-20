#include <iostream>
using namespace std;

void print(int(* A)[10], int fil );

template<size_t fil,size_t col>
void reversa(int (&A)[fil][col],int(* &dir_i)[col] ,int* &dir_j,int marca ){
    cout<<"reversa "<<marca <<endl;
    int(* i)[col]= dir_i; 
    int* j = dir_j;
    while( true ) {    // marca == marca+1
            //cout<<"i_r" <<i<<"j_r" <<j<<endl;
            print(A,fil); 

            if( j+1  < *(i+1) && *(j+1) == marca ){ // derecha
                cout<<"reversa derecha"<<endl;
                *j = (*j)*(-1);
                j++;
                continue;
            }      
            else if(  (i+1) < A+fil && *(j+col) == marca ){  // abajo
                cout<<"reversa abajo"<<endl;
                *j = (*j)*(-1);
                i++;
                j = j+col;
                continue;
            }
            
            else if( j-1 >= *i && *(j-1) == marca ){ //izquierda
                cout<<"reversa izquierda"<<endl;
                *j = (*j)*(-1);
                j--;
                continue;
            }
            
            else if(  i-1 >= A && *(j-col) == marca ){     //arriba
                cout<<"reversa arriba"<<endl;
                *j = (*j)*(-1);
                i--;
                j = j-col;
                
                continue;
            }
            

            

            
            else{
                cout<<"reversa break"<<endl;
                *j = --marca;
                dir_i=i;
                dir_j=j;
                break;
            }
        }
}


void print(int(* A)[10], int fil ){
    for(int(* i)[10]=A    ; i < A+fil  ; i++){
        for(  int* j = *i  ; j < *(i+1) ; j++){
            if(*j==-1){
               cout<<" X";
            }
            else if(*j<-1){
               cout<<" ";
            }
            else if(*j==100){
               cout<<" A";
            }
            else if(*j==200){
               cout<<" B";
            }
            
            else{
                if(*j < 9){
                   cout<<"  "<<*j<<"  "; 
                }
                else{
                    cout<<*j;
                }
               
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

void print3(int(* A)[10], int fil ){
    for(int(* i)[10]=A    ; i < A+fil  ; i++){
        for(  int* j = *i  ; j < *(i+1) ; j++){
            if(*j==-1){
               cout<<" X";
            }
            else if(*j<-2 || *j==0){
               cout<<"  ";
            }
            else if(*j==100){
               cout<<" A";
            }
            else if(*j==200){
               cout<<" B";
            }
            
            else{
                if(*j > 0)
                   cout<<" *";
               
            }
           
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
    int marca=2;
    int iteraciones=0;
    //cout<<*A << " " <<(dir_A-*A) << " s " <<(dir_A-*A)/col <<endl;
    //cout<<i <<endl;
    //cout<<dir_A <<endl;
    //cout<<*i+3 <<endl;
    if (dir_A < dir_B){

        //cout<<A+1 <<" "<<*A+1 <<endl;
        //cout<<i+1 <<" "<<*i+1 <<endl;
        
        while( *i != dir_B ) {
            iteraciones++;
            //print(A, fil );
            cout<<endl;
            int contador=0;
            int direccion=0;
            int* tmp= j;
            cout<<"i " <<i<<"j " <<j<<endl;
            if( j+1  < *(i+1)   ){ cout<<"derecha " <<marca <<endl;    //derecha
                
                if(*(j+1) == 0){
                    contador++;
                    direccion=4;
                }
                else if(j+1 == dir_B){
                    cout <<"terminado"<<endl;
                    break;
                }

            }  
            //cout<<"ss " <<(i+0)<<"ss " <<(i+1)<<"---"<<A+fil-1<<"---"<<*(i+0)<<" ss "<<j+10<<" ss "<<*(j+10)<<" s"<<*(j+7)<<" s "<<endl;
            
            if(  (i+1) < A+fil  ){  cout<<"abajo " <<marca <<endl; //abajo
                //cout<<"ss " <<(j+0)<<"---"<<*(j+0)<<" ss "<<j+10<<" ss "<<*(j+10)<<" s"<<*(j+7)<<" s "<<endl;break;
                if( *(j+col) == 0){
                    contador++;
                    direccion=3;
                }
                else if(j+col == dir_B){
                    cout <<"terminado"<<endl;
                    break;
                }
            }
            
            if( j-1 >= *i  ){     cout<<"izquierda " <<marca <<endl;//izquierda

                
                if( *(j-1) == 0){
                    contador++;
                    direccion=2;
                }
                else if(j-1 ==  dir_B){
                    cout <<"terminado"<<endl;
                    break;
                }
                
            }
            
            if(  i-1 >= A && *(j-col) == 0 ){    cout<<"arriba " <<marca <<endl; //arriba
                contador++;
                direccion=1;
                
                if( *(j-col) == 0){
                    contador++;
                    direccion=1;
                }
                else if(j-col ==  dir_B){
                    cout <<"terminado"<<endl;
                    break;
                }
                
            }
            
            
            if (contador == 0){
                *j=marca;
                reversa(A,i,j,marca);
                cout<<"rcontador "<<endl;
                marca--;print(A, fil );
                continue;
            }
            if (contador == 1){
                *j=marca;print(A, fil );
            }
            if (contador > 1){
                marca++;
                *j=marca;print(A, fil );
            }
            if(iteraciones==60)break;
            if (direccion==1){ i--; j = j-col;}
            else if (direccion==2){ j-- ;}
            else if (direccion==3){ i++; j = j+col;}
            else if (direccion==4){ j++ ;}
            
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
    
    
    int A[10][10]=  {{100,-1,0, 0, 0,0, 0, 0, 0,-1},  //1
                      {0,-1,0, 0, 0,0, -1,-1, 0,-1},  //2
                      {0,-1,0,-1,-1,0,-1, -1,-1,-1},  //3
                      {0,-1,0,-1, 0,0,-1,  0, 0, 0},  //4
                      {0, 0,0,-1,0,0,0,0,-1,-1},  //1
                      {0,-1,-1,-1,-1,-1,0,0,-1,0},  //2
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
    cout<<"Solucion2:"<<endl;
    print3(A,fil); 
    return 0;
}

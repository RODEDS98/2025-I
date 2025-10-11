// //MERGE CON PUNTERO DOBLE

#include <iostream>
using namespace std;

struct nodo {

	int valor;
	nodo* next;

	nodo(int v,nodo* n=nullptr ) {          // ingresas el valor de cada v
		valor=v;                            // y un puntero del siguiente elemento
		next=n;
	};
};

//    {13,17,19,21,28};
void ArrayToLe(int *begin,int *end,nodo *&head) { //crea una serie de estructuras para cada elemento

	for(int* i=end ; i>=begin ; i--) {      // recorre de forma inversa la lista
		head=new nodo(*i,head);               // ingresa (*i):cada elemento y (head):
	}                                        // reemplaza/crea los valores con su mismo
}


void print2(nodo *head) {
	cout<< "HEAD ->" ;
	for(nodo* p=head; p; p=p->next) {
		cout<< p << "->";
	}
	cout<<"NULL"<<endl;
}



void print(nodo *head) {
	cout<< "HEAD ->" ;
	for(nodo* p=head; p; p=p->next) {
		cout<< p->valor<< "->";
	}
	cout<<"NULL"<<endl;
}

void merge(nodo* &A,nodo* &B) {
	nodo** p= &A;
	nodo** q= &B;
	nodo* r= nullptr;
	//   caso inicial:
	if((*p)->valor < (*q)->valor) {
	    
		r = (*p)->next; // cout<<"r: "<<r<<endl;
		p = &((*p)->next);
		*p = *q;
		*q = r;
		p = &((*p)->next); //terminamos apuntando a un campo
	}
	else {
	    
		r = (*q)->next;  
		q = &((*q)->next); 
		*q = *p;
		A=B;
		
        q = &((*q)->next); 
        p=q; 
        q= &B;
        *q=r;
        
	}

	while( *p ) {  //  p= 14  q = 13
	    
        if((*p)->valor < (*q)->valor) { // no es lo mismo que el anterior. aqui 
            p = &((*p)->next);                // esta apuntando a un campo, compara el siguiente nodo, el apuntando 
                                          // en cambio el anterior apuntaba al mismo nodo que analizabamos
        }
        else{
            r = *p;
            *p = *q;
            *q = r;
            p = &((*p)->next);
            
        }
	}
	*p=*q;
	B=nullptr;
}



int main() {

	nodo *head1=nullptr;
	nodo *head2=nullptr;

	int A[] = {13,15,19,21,28};
	int B[] = {11,14,17,18,20,22,24,27};

	//int A[] = {11,12,13,14,15,20,55,70};
	//int B[] = {1,2,3,4,5,6,7,8,100};

	int tamA=sizeof(A)/4;
	int tamB=sizeof(B)/4;

	ArrayToLe(A,A+tamA-1,head1);
	ArrayToLe(B,B+tamB-1,head2);

	cout<<"Lista original: "<<endl;
	print(head1);
	print(head2);

	
	cout<<endl;
	cout<<endl;

	merge(head1,head2);

	cout<<"Lista modificada: "<<endl;
	print(head1);


	cout<<endl;
	cout<<endl;

	return 0;
}

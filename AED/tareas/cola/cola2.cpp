#include <iostream>
using namespace std;

template<class T>
struct Cola{
	T A[10];
	T* Tail=nullptr;
	T* Head=nullptr;

	bool vacio();
	bool lleno();
	bool push(T a);
	bool pop(T &a);
	void print();
	
};

template<class T>
bool Cola<T>::vacio(){
	return(  Tail == nullptr ); //Tail!= nullptr &&  Head!= nullptr &&
}

template<class T>
bool Cola<T>::lleno(){
    int dim= sizeof(A)/sizeof(*A);
	if(!vacio()){
		if (Head<Tail)
		{
		 	return( Tail-Head == dim-1 );
		}
		else{
			return( !(Head-Tail-1));
		}
	}
	
	return false;

}

template<class T>
bool Cola<T>::push(T a){
    int dim= sizeof(A)/sizeof(*A);
	if(vacio()){
	    
		if(Head== nullptr){ // cambiar
			Head=A;
			*Head=a;
			Tail=Head;
		//	 cout<<"pushI Head"<<Head;cout<<" pushI Tail"<<Tail<<endl;
			return true;
		}
		else{
	        Tail=Head;
	        *Tail=a;
	        return true;
		}

	}
	else if(!lleno()){
		if(Head<=Tail){
			if(Tail!=A+dim-1){
				Tail++;	 //cout<<"push Head"<<Head;cout<<" push Tail"<<Tail<<endl;
				*Tail=a;
				return true;
			}
			else{
				Tail=A;
				*Tail=a;
			//	cout<<"push Head"<<Head;cout<<" push Tail"<<Tail<<endl;
				return true;
			}		
		}
		else if(Tail<Head && Head-Tail != 1){	
		    Tail++;
		    *Tail=a;
					//		    cout<<"push Head"<<Head;cout<< "push Tail"<<Tail<<endl;
			return true;
					
		}
	}
	
	cout<<"lleno"<<endl;
	return false;
	
}

template<class T>
bool Cola<T>::pop(T &a){
    cout<<"borrando"<<endl;
    int dim= sizeof(A)/sizeof(*A);
	if(vacio()){
		cout<<"vacio"<<endl;
		return false;
	}
	else if(Head==Tail){
		a=*Head;
		Head++;	
		Tail=nullptr;
		//			    cout<<"POP Head"<<Head;cout<<" POP Tail"<<Tail<<endl;
        return true;
	}
	else if(Head<Tail){
		a=*Head;
		Head++;		
		//			    cout<<"POP Head"<<Head;cout<<" POP Tail"<<Tail<<endl;

		return true;
	}
	else if(Tail<Head){		
		if(Head!= A+dim-1){
		    a=*Head;
			Head++;	 return true;
		}
		else{
			a=*Head;
			Head=A;	return true;	
		}
	}
    return false;
}

template<class T>
void Cola<T>::print(){
    int dim= sizeof(A)/sizeof(*A);cout<<"print"<<endl;
    //cout<<"Head"<<Head<<endl;cout<<"Tail"<<Tail<<endl;
    //cout<<sizeof(A)/sizeof(*A)<<endl;
    if(!vacio()){ //cout<<"Head"<<endl;
        T* i= Head;
        if(Head==Tail){
            cout<<*Head<<endl;
        }
        else if(Head<Tail){
            for(; i<=Tail ; i++)
                cout<<*i<<" ";
        }
        else{
            for(; i<A+dim ; i++)
                cout<<*i<<" ";
            i=A;
            for(; i<=Tail ; i++)
                cout<<*i<<" ";
        
        }
        cout<<endl;
    }
    else{
        cout<<"vacio"<<endl;
    }        
}


int main(){
    Cola<int> Pint;
    //cout<<Pint.vacio()<<endl;
    //cout<<Pint.lleno()<<endl;
    
    Pint.push(1);
    Pint.push(2);
    Pint.push(3);
    Pint.push(4);
    Pint.push(5);
    Pint.push(6);
    Pint.push(7);
    Pint.push(8);
    Pint.push(9);
    Pint.push(10);
    Pint.push(11);
    //Pint.push(10);
    Pint.print();
    int val;
    Pint.pop(val);
    cout <<endl<<"val "<< val<<endl;
    Pint.print();
    Pint.push(100);Pint.print();
    Pint.pop(val);Pint.print();
    Pint.pop(val);Pint.print();
    Pint.pop(val);Pint.print();
    Pint.push(101);Pint.print();
    Pint.push(102);Pint.print();
    Pint.push(103);Pint.print();
    Pint.push(100);Pint.print(); //lleno
    
    
    Pint.pop(val);Pint.pop(val);Pint.pop(val);Pint.pop(val);
    Pint.pop(val);Pint.pop(val);Pint.pop(val); //borra 7 elementos
    cout <<endl<<"val "<< val<<endl;
    Pint.print();
    Pint.pop(val);
    Pint.print();
    Pint.pop(val);
    Pint.print();
    Pint.pop(val);
    Pint.print();
    
    cout<<endl <<"p "<<endl;
    Pint.push(100);Pint.print();
    Pint.push(110);Pint.print();
    Pint.push(120);Pint.print();
    Pint.print();
	return 0;
}

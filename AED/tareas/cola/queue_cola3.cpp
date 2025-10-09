#include<iostream>
using namespace std;

template<class T>
class queue{
	
	public:
		queue();
		~queue();
		bool push(T a);
		bool pop(T &a);
		bool empty();
		bool full();
		void print();
		int size();

	private:
		T A[12];
		T* tail;
		T* head;
};

template<class T>
queue<T>::queue(){
	head=nullptr;
	tail=nullptr;
}

template<class T>
queue<T>::~queue(){

}

template<class T>
bool queue<T>::push(T a){
	if(full()) return false;
	if(empty()){
		if(!head){
    		head=A;
    		tail=head;
    		*head=a;
    		return true;    
	    }
	    tail=head;
	    *tail=a;
	    return true;
	    cout<<"iguala ";
		
	}

	else if(head<=tail){
	    cout<<"y tambien entra";
		if(tail == A+12-1){
			tail = A;;
			*tail = a;
			return true;
		}

		
	}
    *(++tail) = a;
	return true;
	
	return true;

}

template<class T>
bool queue<T>::pop(T &a){
	if(empty()) return false;
	if(head==tail){
		a = *head;
		tail=nullptr;
		return true;
	}
	//tail > head
	else if(head == A+12-1){
		a = *head;
		head=A;
		return true;
	}
	a = *head;
	head++;
	return true;
}

template<class T>
bool queue<T>::empty(){
	return !tail;
}

template<class T>    //
bool queue<T>::full(){
	if(!empty()){
		if(head<tail){
			return tail-head == 12-1; 
		}
		return(head-1==tail);
	}
	return false;
}


template<class T>
int queue<T>::size(){
	if(!empty()){
	if(head == tail) return 1;
	if(head<tail){
			return tail-head+1; 
		}
		return( (tail-A+1) + (A+12-1  -  head +1));
	}
	return 0;
}

template<class T>
void queue<T>::print(){
	int dim= sizeof(A)/sizeof(*A);cout<<"print: "<<endl;
    //cout<<"Head"<<Head<<endl;cout<<"Tail"<<Tail<<endl;
    //cout<<sizeof(A)/sizeof(*A)<<endl;
    if(!empty()){ //cout<<"Head"<<endl;
        T* i= head;
        if(head==tail){
            cout<<*head<<endl;
        }
        else if(head<tail){
            for(; i<=tail ; i++)
                cout<<*i<<" ";
        }
        else{
            for(; i<A+dim ; i++)
                cout<<*i<<" ";
            i=A;
            for(; i<=tail ; i++)
                cout<<*i<<" ";
        
        }
    }
    else{
        cout<<" vacio "<<endl;
    }        
}


int main(){
	queue<int> cola;
	cout<<cola.empty()<<endl;
	cout<<cola.full()<<endl;
	//cout<<queue.topp()<<endl;
	
	for (int i=1; i<=12 ; i++){
		cola.push(i);cola.print();cout<<" size "<<cola.size() <<endl;
		//cout<<cola.topp()<<endl;
	}
    
    cout<<cola.full()<<endl;
	//cout<<cola.topp()<<endl;
    
    int a;
	for (int i=1; i<=12 ; i++){
		cola.pop(a);
		
		cola.print();cout<<" size "<<cola.size() <<endl;
	}
	cout<<cola.empty();
	
	
	cout<<endl<<endl<<endl<<endl<<"prueba 2"<<endl<<endl<<endl;
	cola.print();
	cout<<"---"<<endl;
	for (int i=1; i<=12 ; i++){
		cola.push(i);cola.print();cout<<" size "<<cola.size() <<endl;
		//cout<<cola.topp()<<endl;
	}
    for (int i=1; i<=11 ; i++){
		cola.pop(a);
		
		cola.print();cout<<" size "<<cola.size() <<endl;
	}
	for (int i=1; i<=12 ; i++){
		cola.push(i);cola.print();cout<<" size "<<cola.size() <<endl;
		//cout<<cola.topp()<<endl;
	}
	
	

	return 0;
}

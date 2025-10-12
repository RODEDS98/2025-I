#include <iostream>
#include <queue>

class CSortedQueue
{
public:       //    front - pop->      push -> back
    void pushx(int x);
    void popx();
    int frontx();
    int backx();
    void remx(int x);
    void printx();
    std::queue<int> q;

};
/*
- frontx() debe retornar siempre el menor elemento de la fila
- popx() debe eliminar el menor elemento de la fila
- pushx(int x) debe insertar x, en orden
- remx(int x), debe eliminar todos los elementos iguales a x
- printx(), debe imprimir en una nueva línea todos los elementos de la fila
*/

//por conveniencia la lista sera de menor a mayor (por el pop)
void CSortedQueue::pushx(int x)
{
    std::cout<<"push"<<std::endl;
    //si es mayor...    2 4 6   462   624  6245 
    
    if(q.empty()) 
	{
		q.push(x); 
	}
    else if(!q.empty() &&  q.back() <= x){
        q.push(x);
    }
    
    else{  std::cout<<"push for"<<std::endl;
        int tmp;
        int size = q.size();
        bool inserted = 0;
        for( int i = 1 ; i <= size  ; i++ ){
            //std::cout<<"for "<< q.back() <<std::endl;
            tmp = q.front();  //4
            q.pop();
            if( x <= tmp && !inserted ){
                q.push(x);
                inserted=1;
            }
            q.push(tmp);
        }
    }        
}

    
    // si es menor...    



void CSortedQueue::popx()
{
    q.pop();
}

int CSortedQueue::frontx()
{   
    if(q.empty()) {std::cout<<" no hay elementos"; return 0;}
    return q.front();
}

int CSortedQueue::backx()
{   
    if(q.empty()) {std::cout<<" no hay elementos"; return 0;}
    return q.back();
}

void CSortedQueue::remx(int x)
{
	if ( x > q.back()  ) {
		std::cout<< " No existe el numero a remover" << std::endl;
		return ;
	}
	int size = q.size();
	int i=1;
    for(  ; i<=size ; i++ ){
 	
		if(q.front() == x ){
			for( true ; q.front()==x  ; q.pop() ){
				i++;	
			}
		}
    	std::cout<< " size: " << size << " ";
    	int temp= q.front();
    	q.pop();
		q.push(temp);

		
		
	} std::cout<<std::endl;
    
}

void CSortedQueue::printx(){
    for(std::queue<int> r=q ; !(r.empty()) ; r.pop() ){
        std::cout <<" "<< r.front();
    }
      std::cout<<"---"<<std::endl;
}



int main()
{
    CSortedQueue sq;
    std::cout<<sq.frontx()<<std::endl;
    sq.pushx(40); sq.printx();
    std::cout<<sq.frontx()<<std::endl;
    sq.pushx(23); sq.printx();
    sq.pushx(51); sq.printx();
    sq.pushx(12); sq.printx();
    sq.pushx(30); sq.printx();
    sq.pushx(5);  sq.printx();
    sq.pushx(40); sq.printx();
    sq.pushx(18); sq.printx();
    std::cout<<"front: "<< sq.frontx() <<std::endl;
    std::cout<<"back: "<< sq.backx() <<std::endl;
	std::cout<<"rem: "<<std::endl;
    //push 18 ? 5 12 18 23 30 40 40 51 ---
    sq.remx(40);  sq.printx();
    sq.remx(23);  sq.printx();
    sq.remx(12);  sq.printx();
    sq.remx(5);  sq.printx();

    std::cout<<"\nfront => "<<sq.frontx(); sq.popx();
    std::cout<<"\nfront => "<<sq.frontx(); sq.popx();
    sq.printx();
    
    std::queue<int> p;
    p.front();
    
    std::cout<<"\nfront"<< p.front()<<std::endl; 
    p.back();
    
    /* 
    p.pushx(1);
    p.pushx(2);
    p.pushx(3);
    p.pushx(4);
    q.printx();  
    std::cout<<"\nback"<< p.back()<<std::endl; 
    std::cout<<"\nfront"<< p.front()<<std::endl; 
    p.pop();
    //print(p);  
        p.popx();
    //print(p);   
        p.popx();
    //print(p);   
        p.popx();
    //print(p);   
    std::cout<<"\nfront"<< p.front()<<std::endl;
    */
}

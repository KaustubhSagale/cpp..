#include<iostream>
using namespace std;

class circular_queue{
    private:
    int front, rear, size ;
    int *arr ;

    public :
    circular_queue(int s){
        size = s ;
        front = -1 ;
        rear = -1 ;
        arr = new int[s] ;
    }

    bool Full(){
        if ((rear+1)%size == front)
        {
            return true ;
        }

        return false ;
    }

    bool Empty(){
        if(front==-1 && rear == -1){
            return true;
        }

        return false;
    }

    void enqueue(int element){
        if(Full()){
            cout<<"The Queue is full. Cannot Enter the element."<<endl ;
            return ;
        }

        if(front==-1 && rear == -1){
            front++ ;
            rear++ ;
        }
        else{
            rear = (rear+1)%size ;
        }

        arr[rear] = element ;
        cout<<"Element "<<element<<" is inserted in the queue."<<endl ;
    }

    void dequeue(){
        if(Empty()){
            cout<<"The Queue is empty."<<endl ;
            return ;
        }

        if(front==rear){
            front = -1 ;
            rear = -1 ;
            cout<<"Deleted Successfully."<<endl ;
        }
        else{
            front = (front+1)%size ;
            cout<<"Deleted Successfully."<<endl ;
        }


    }

    void Display(){
        if(Empty()){
            cout<<"The Queue is Empty."<<endl ;
        }
        else{
            cout<<"Elements in queue : " ;
            int i=front ;
            do{
                cout<<arr[i]<<" " ;
                i = (i+1)%size ;

            }while(i != (rear+1)%size);
            cout<<endl ;
        }
    }
};


int main(){
    int ch, size, element ;

    cout<<"Enter the size of circular queue : " ;
    cin>>size ;
    circular_queue que(size) ;
    do
    {  
        cout<<"\n1. Display the queue \n2. Insert an element in queue \n3. Delete an element from queue \n4. Exit \nEnter your choice : " ;
        cin>>ch ;
        switch(ch)
        {
            case 1:
                que.Display();
                break;
            case 2:
                cout<<"Enter the element you want to insert in the queue - \n";
                cin>>element;
                que.enqueue(element);
                break;
            case 3:
                que.dequeue();
                break;
            case 4:
                cout<<"Exit\n";
                break;
            default:
                cout<<"Invalid Choice\n";
                break;

        }
        
    } while (ch!=4);

    return 0;
}

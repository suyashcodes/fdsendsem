#include<iostream>
#include<vector>
using namespace std;

class Deque{
    private:
    int front,rear,max;
    vector<int> arr;
    public:
    Deque(int s){
        front=rear=-1;
        max=s;
        arr.resize(s);
    }

    bool isEmpty(){
        return front==-1 && rear==-1;
    }
    bool isFull(){
        return (front==0 && rear==max-1)||(front==rear+1);
    }
    void insertFront(int no){
        if(isFull()){
            cout<<"Dequeue is Full\n";return;
        }
        
            if(isEmpty()){
                front=rear=0;
            }
            else if(front==0){
                front = max-1;
            }
            else{
                front--;
            }
        
        arr[front] = no;
    }
    void insertRear(int no){
        if(isFull()){
            cout<<"Dequeue is Full\n";return;
        }
            if(isEmpty()){
                front=rear=0;
            }
            else if(rear==max-1){
                rear =0;
            }
            else{
                rear++;
            }
        
        arr[rear] = no;
    }

    void deleteFront(){
        if(isEmpty()){
            cout<<"Dequeue is Empty \n";return;
        }

        if(front==rear){
            front=rear=-1;
        }
        else if(front==max-1){
            front=0;
        }
        else{
            front++;
        }
    }

    void deleteRear(){
        if(isEmpty()){
            cout<<"Dequeue is Empty \n";return;
        }
        if(front==rear){
            front=rear=-1;
        }
        else if(rear==0){
            rear=max-1;
        }
        else{
            rear--;
        }
    }

    void display(){
        if(isEmpty()){
            cout<<"The DeQueue is empty.\n";
        }
        int i= front;
        do{
            cout<<arr[i]<<endl;
            i=(i+1)%max;
        }while(i!=(rear+1)%max);
    }

};

int main(){
    Deque q(5);
    q.insertFront(1);
    q.insertRear(7);
    q.insertRear(9);
    q.insertFront(4);
    q.insertRear(2);
    q.display();
    return 0;
}
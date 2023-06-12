#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAXLEN 10 
//IMPLEMENTATION USING CIRCULAR ARRAY

class Queue{
    public:
    int data[MAXLEN];
    int rear;
    int front;
    int no_el=0;
};

Queue initialize(){
    Queue q;
    q.rear=-1;
    q.front=-1;
    return q;
}

int isempty(Queue q){ return(q.no_el==0);}

int isfull(Queue q){ return(q.no_el==MAXLEN);}

void display(Queue q){
    if(q.no_el==0){
        cout<<"EMPTY Queue!"<<endl<<endl;
        return;
    }
    cout<<"out<- ";
    for(int i=q.front;i<q.front+q.no_el;i++){
        cout<<q.data[i%MAXLEN]<<" ";
    }
    cout<<"<-in"<<endl<<endl;
}

Queue push(Queue q,int val){
    if(isfull(q)){
        cout<<"OVERFLOW! failed to enqueue!"<<endl<<endl;
        return q;
    }
    if(isempty(q)){
        q.rear=q.front=0;
        q.data[q.rear]=val;
        q.no_el++;
        return q;
    }
    q.rear=(q.rear+1)%MAXLEN;
    q.data[q.rear]=val;
    q.no_el++;
    return q;
}

Queue pop(Queue q){
    if(isempty(q)){
        cout<<"UNDERFLOW! failed to dequeue!"<<endl<<endl;
        return q;
    }
    q.no_el--;
    q.front=(q.front+1)%MAXLEN;
    return q;
}

void peek(Queue q){
    if(isempty(q)){
        cout<<"Empty list! failed to peek!"<<endl<<endl;
    }
    else{
        cout<<"peeking at "<<q.data[q.front]<<endl<<endl;
    }
}

int main() {
    Queue q1;
    q1=initialize();

    for(int i=18;i<27;i++){
        q1=push(q1,i);
        display(q1);
    }
    q1=pop(q1);
    display(q1);
    q1=pop(q1);
    display(q1);
    q1=pop(q1);
    display(q1);
    q1=pop(q1);
    display(q1);

    for(int i=78;i<84;i++){
        q1=push(q1,i);
        display(q1);
    }
    for(int i=1;i<12;i++){
        q1=pop(q1);
        display(q1);
    }

return 0;
}

/*
OUTPUT:
out<- 18 <-in

out<- 18 19 <-in

out<- 18 19 20 <-in

out<- 18 19 20 21 <-in

out<- 18 19 20 21 22 <-in

out<- 18 19 20 21 22 23 <-in

out<- 18 19 20 21 22 23 24 <-in

out<- 18 19 20 21 22 23 24 25 <-in

out<- 18 19 20 21 22 23 24 25 26 <-in

out<- 19 20 21 22 23 24 25 26 <-in

out<- 20 21 22 23 24 25 26 <-in

out<- 21 22 23 24 25 26 <-in

out<- 22 23 24 25 26 <-in

out<- 22 23 24 25 26 78 <-in

out<- 22 23 24 25 26 78 79 <-in

out<- 22 23 24 25 26 78 79 80 <-in

out<- 22 23 24 25 26 78 79 80 81 <-in

out<- 22 23 24 25 26 78 79 80 81 82 <-in

OVERFLOW! failed to enqueue!

out<- 22 23 24 25 26 78 79 80 81 82 <-in

out<- 23 24 25 26 78 79 80 81 82 <-in

out<- 24 25 26 78 79 80 81 82 <-in

out<- 25 26 78 79 80 81 82 <-in

out<- 26 78 79 80 81 82 <-in

out<- 78 79 80 81 82 <-in

out<- 79 80 81 82 <-in

out<- 80 81 82 <-in

out<- 81 82 <-in

out<- 82 <-in

EMPTY Queue!

UNDERFLOW! failed to dequeue!

EMPTY Queue!


*/

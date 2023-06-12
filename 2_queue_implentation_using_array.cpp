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

int isfull(Queue q){ return(q.rear+1==MAXLEN);}

void display(Queue q){
    if(isempty(q)){
        cout<<"EMPTY Queue!"<<endl;
        return;
    }
    cout<<"out<- ";
    for(int i=q.front;i<=q.rear;i++){
        cout<<q.data[i]<<" ";
    }
    cout<<"<-in"<<endl;
}

Queue push(Queue q,int val){
    if(isfull(q)){
        cout<<"OVERFLOW! failed to enqueue!"<<endl;
        return q;
    }
    if(isempty(q)){
        q.rear=q.front=0;
        q.data[q.rear]=val;
        q.no_el++;
        return q;
    }
    q.rear++;
    q.data[q.rear]=val;
    q.no_el++;
    return q;
}

Queue pop(Queue q){
    if(isempty(q)){
        cout<<"UNDERFLOW! failed to dequeue!"<<endl;
        return q;
    }
    q.front=q.front+1;
    q.no_el--;
    return q;
}

void peek(Queue q){
    if(isempty(q)){
        cout<<"Empty list! failed to peek!"<<endl;
    }
    else{
        cout<<"peeking at "<<q.data[q.front]<<endl;
    }
}

int main() {
    Queue q1;
    q1=initialize();

    for(int i=3;i<10;i+=1){
        q1=push(q1,i*i+17);
        display(q1);
    }
    q1=pop(q1);
    display(q1);
    q1=pop(q1);
    display(q1);

    for(int i=78;i<83;i++){
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
out<- 26 <-in
out<- 26 33 <-in
out<- 26 33 42 <-in
out<- 26 33 42 53 <-in
out<- 26 33 42 53 66 <-in
out<- 26 33 42 53 66 81 <-in
out<- 26 33 42 53 66 81 98 <-in
out<- 33 42 53 66 81 98 <-in
out<- 42 53 66 81 98 <-in
out<- 42 53 66 81 98 78 <-in
out<- 42 53 66 81 98 78 79 <-in
out<- 42 53 66 81 98 78 79 80 <-in
OVERFLOW! failed to enqueue!
out<- 42 53 66 81 98 78 79 80 <-in
OVERFLOW! failed to enqueue!
out<- 42 53 66 81 98 78 79 80 <-in
out<- 53 66 81 98 78 79 80 <-in
out<- 66 81 98 78 79 80 <-in
out<- 81 98 78 79 80 <-in
out<- 98 78 79 80 <-in
out<- 78 79 80 <-in
out<- 79 80 <-in
out<- 80 <-in
EMPTY Queue!
UNDERFLOW! failed to dequeue!
EMPTY Queue!
UNDERFLOW! failed to dequeue!
EMPTY Queue!
UNDERFLOW! failed to dequeue!
EMPTY Queue!


*/
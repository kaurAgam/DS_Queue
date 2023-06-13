#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class item{
    public:
    int value;
    int priority;
};
item pq[6];
int size=-1;

void push(int val,int priority){
    size++;
    if(size>=sizeof(pq)/sizeof(item)){
        size--;
        cout<<"FULL QUEUE! failed to enqueue! ";
        return;
    }
    pq[size].value=val;
    pq[size].priority=priority;
    cout<<"enqueue successfull: ";
}
int peek(){
    int highest_priority=INT_MIN;
    int ind=-1;
    for(int i=0;i<=size;i++){
        if(pq[i].priority==highest_priority && ind>-1 && pq[ind].value<pq[i].value){
            highest_priority=pq[i].priority;
            ind=i;
        }
        if(pq[i].priority>highest_priority){
            highest_priority=pq[i].priority;
            ind=i;
        }
    }
    return ind;
}
void pop(){
    int ind=peek();
    int p=pq[ind].priority;
    int v=pq[ind].value;
    for(int i=ind;i<size;i++){
        pq[i]=pq[i+1];
    }
    size--;
    cout<<"dequeue (of {"<<v<<","<<p<<"} ) successfull: ";
}
void display(){
    if(size==-1){
        cout<<"EMPTY QUEUE"<<endl;
        return;
    }
    for(int i=0;i<=size;i++){
        cout<<"("<<pq[i].value<<","<<pq[i].priority<<")<-";
    }
    cout<<" in"<<endl;
}
int main() {
    push(20,34);
    display();
    push(22,7);
    display();
    push(12,23);
    display();
    push(89,34);
    display();
    push(34,45);
    display();
    push(56,1);
    display();
    push(78,8);
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    return 0;
}

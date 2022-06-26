#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next,*prev;

}*start=NULL,*last=NULL;
void Create()
{   int n,val;
    node *newnode=new node();
    cout<<"\nEnter How Many Nodes You Wanna Create : "; cin>>n;
    cout<<"\nEnter Values Into Node[1] : "; cin>>val;
    newnode->data=val;
    newnode->next=NULL; newnode->prev=start;
    start=newnode;  last=newnode;

    for(int i=1;i<n;i++)
    {   node *newnode=new node();
        cout<<"\nEnter Values Into Node["<<i+1<<"] : ";    cin>>val;
        newnode->data=val;
        newnode->next=NULL; newnode->prev=start;
        last->next=newnode; last=newnode;
    }
}
void Display()
{
    node *temp=start;
    cout<<"start-->";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|<==>";
        temp=temp->next;
    }   cout<<"|NULL|";
}
void Insert()
{   int pos,val;
    node *temp;
    node *newnode=new node();
    cout<<"\nEnter Position Where You Wanna Insert Node : ";    cin>>pos;
    cout<<"\nEnter Value Into Node : "; cin>>val;
    newnode->data=val;  newnode->next=NULL; newnode->prev=NULL;
    if(pos==1)
    {
        newnode->next=start;    start->prev=newnode;
        start=newnode;
    }
    else
    {   temp=start;
        for(int i=1;i<pos-1;i++)
            temp=temp->next;
        newnode->next=temp->next;   temp->next->prev=newnode;
        temp->next=newnode; newnode->prev=temp;
    }

}
void Search()
{
    int ele,flag=0;   
     node *temp=start;
    cout<<"\nEnter Element You Wanna Search : ";  cin>>ele;
    for(int i=1;temp!=NULL;temp=temp->next,i++)
    {
        if(temp->data==ele)
        {   flag=1;
            cout<<"Element ["<<ele<<"] Fount at : "<<i<<" position\n"; 
        }
    }
    if(flag==0)
        cout<<"Element ["<<ele<<"] not Present In The Doubly LInked List\n";
}
void Delete()
{
    int pos;
    node *temp,*pre;
    cout<<"\nEnter The Position Of NODE That You Wanna Delete : ";  cin>>pos;
    if(pos==1)
    {
        temp=start; 
        start=start->next;  start->prev=NULL;   temp->next=NULL;
        delete temp;
    }
    else
    {   pre=start;
        for(int i=1;i<pos-1;i++)
            pre=pre->next;
        temp=pre->next;
        pre->next=temp->next;   temp->next->prev=pre;
        temp->next=NULL;    temp->prev=NULL;
        
        delete temp;
    }
}
int main()
{   int ch;
while(1)
{
        cout<<"\n\n**** DOUBLY LINKED LIST ****\n";
        cout<<"1>Create\n2>Display\n3>Insert\n4>Search\n5>Delete\n6>ReverseLL\n7>Exit\n";
        cout<<"\nEnter Your Choice From Above :";
        cin>>ch;
        switch(ch)
        {
            case 1: Create(); break;
            case 2: Display(); break;
            case 3: Insert(); break;
            case 4: Search(); break;
            case 5: Delete(); break;
            /*case 6: ReverseSLL(); break;*/
            case 7: exit(0);

        }
}
    return 0;
}
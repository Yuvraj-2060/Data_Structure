//Author : Mr Singh
#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;

}*start=NULL,*last=NULL;

void Create()
{   int val,n;
    cout<<"Enter How Many Node You Wanna Create : ";
    cin>>n;
    node *newnode=new node();
    cout<<"Enter Value You Wanna Insert : ";
    cin>>val;
    newnode->data=val;
    newnode->next=NULL;
    start=newnode; last=newnode;
    for(int i=1;i<n;i++)
    {
        node *newnode=new node();
        cout<<"Enter Value You Wanna Insert : ";
        cin>>val;
        newnode->data=val;
        newnode->next=NULL;
        last->next=newnode;
        last=newnode;
    }
    
}
void Display()
{   node *temp=start;
    while(temp!=NULL)
    {
        cout<<temp->data<<"|";
        temp=temp->next;
    }

}
void Insert()
{   node *temp;
    node *newnode=new node();
    int val,pos;
    cout<<"\nEnter Data In Node That You Wanna Insert : "; cin>>val;
    newnode->data=val; newnode->next=NULL;
    cout<<"Enter The Position Where You Wanna Insert Node : "; cin>>pos;
    if(pos==1)
    {
        newnode->next=start;
        start=newnode;
    }
    else
    {      temp=start;
           for(int i=1;i<pos-1;i++)
            temp=temp->next;
           newnode->next=temp->next;
           temp->next=newnode;
    }
}
void Search()
{   int ele;
    cout<<"Enter Element You Wanna Search : ";
    cin>>ele;
    node *temp=start;
    for(int i=1;temp!=NULL;temp=temp->next,i++)
    {
        if(temp->data==ele)
        {   cout<<"Element ["<<ele<<"] Fount at : "<<i<<" position\n";
        }
    }
}
void Delete()
{   int pos;
    node *temp,*prev;
    cout<<"Enter The Position Of Node That You Wanna Delete : "; cin>>pos;
    if(pos==1)
    {   temp=start; start=start->next;
        temp->next=NULL; delete temp;}
    else
    {   prev=start;
        for(int i=1;i<pos-1;i++)
           prev=prev->next;
        temp=prev->next;
        prev->next=temp->next;
        temp->next=NULL; delete temp;
    }

}
void ReverseSLL()
{   node *prev=NULL,*next=NULL,*current=start;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current; current=next;
    }
    start=prev;
}
int main()
{   int ch;
while(1)
{
        cout<<"\n**** SINGLY LINKED LIST ****\n";
        cout<<"1>Create\n2>Display\n3>Insert\n4>Search\n5>Delete\n6>ReverseLL\n7>Exit\n";
        cout<<"Enter Your Choice From Above :";
        cin>>ch;
        switch(ch)
        {
            case 1: Create(); break;
            case 2: Display(); break;
            case 3: Insert(); break;
            case 4: Search(); break;
            case 5: Delete(); break;
            case 6: ReverseSLL(); break;
            case 7: exit(0);

        }
}
    return 0;
}
//Author : Mr Singh @+@
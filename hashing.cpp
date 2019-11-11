#include<bits/stdc++.h>

#define lli long long
using namespace std;

lli m;

lli hashf(lli x)
{
    return (x%m);
}

struct node{
    lli data;
    node *next;
};




// class LL{
//     public:
//     void insertend(lli x)
//     {
//         node *t=(node *)malloc(sizeof(node));
//         if(t==NULL)
//         {
//             cout<<"Failed"<<endl; return;
//         }
//         t->data=x;
//         t->next=NULL;
//         if(this->start==NULL)
//         {
//             this->end=t;
//             this->start=t;
//         }
//         else{
//         this->end->next=t;
//         this->end=t;
//         }
//         cout<<"Added "<<x<<endl;
//     }
//     void insertfront(lli x)
//     {
//         node *t=(node *)malloc(sizeof(node));
//         if(t==NULL)
//         {
//             cout<<"Failed"<<endl; return;
//         }
//         t->data=x;
//         t->next=NULL;
//         if(this->start==NULL)
//         {
//             this->end=t;
//             this->start=t;
//         }
//         else{
//         t->next=this->start;
//         this->start=t;
//         }
//         cout<<"Added "<<x<<endl;
//     }
//     void search(lli x)
//     {
//         node *t=this->start;
//         while(t!=NULL)
//         {
//             if(t->data==x)
//             {
//                 cout<<x<<" is present."<<endl;
//                 return;
//             }
//             t=t->next;
//         }    
//         cout<<x<<" is not in the list.";
//         cout<<endl;
//     }
//     void deletekey(lli x)
//     {
//         node *t=this->start,*prev=NULL;
//         while(t!=NULL)
//         {
//             if(t->data==x)
//             {
//                 if(prev==NULL)
//                 {
//                     this->start=t->next;
//                 }
//                 else
//                 {
//                     prev->next=t->next;
//                 }
//                 delete t;
//                 cout<<"Deleted."<<endl;
//                 return;
//             }
//             prev=t;
//             t=t->next;
//         }
//         cout<<"Not found"<<endl;  
//     }
//     void show()
//     {
//         node *t=this->start;
//         while(t!=NULL)
//         {
//             cout<<t->data<<'x';
//             t=t->next;
//         }    
//         cout<<endl;
//     }
//     LL()
//     {
//         this->end=NULL;
//         this->start=NULL;
//         //cout<<'x'<<endl;
//     }
//     private:
//     node *start,*end;
// };


class hasht{
    public:
    void insert(lli x)
    {
        this->a[hashf(x)].push_front(x);
        //cout<<hashf(x)<<'i';
        //this->a[hashf(x)].show();
    }
    void search(lli x)
    {
        int index = hashf(x); 
        list <int> :: iterator i; 
        for (i = a[index].begin(); i != a[index].end(); i++) { 
        if (*i == x) 
        {
            cout<<"Found "<<x<<endl;
            return;
        }
        }
        cout<<x<<" not found"<<endl;
    }
    void deletehash(lli x)
    {
        int index = hashf(x); 
        list <int> :: iterator i; 
        for (i = a[index].begin(); i != a[index].end(); i++) { 
        if (*i == x) 
        {
            a[index].erase(i);
            cout<<"Deleted "<<x<<endl;
            return;
        }
        }
        cout<<x<<" not found"<<endl;
    }
    // void show()
    // {
        
    //         this->a[0].show();
    //         cout<<endl;
        
    // }
    hasht(lli m)
    { 
        
        a = new list<int>[m];
    }
    
    private:
    //LL *a;
    list<int> *a;
};

int main()
{
    cout<<"Insert size of hash table(m)"<<endl;
    cin>>m;
    hasht H(m);
    start:
    cout<<"Enter choice : \n 1. Insert \n 2. Delete \n 3. Search \n 4. Exit \n";
    lli x;
    lli c;
    cin>>c;
    switch(c)
    {
        case 1: cin>>x;
                H.insert(x);
                break;
        case 2: cin>>x;
                H.deletehash(x);
                break;
        case 3: cin>>x;
                H.search(x);
                break;
        case 4: return 0;
        default: cout<<"Wrong choice!!"<<endl;
    }
    //H.show();
    goto start;

}
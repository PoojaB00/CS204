#include<bits/stdc++.h>

using namespace std;
struct Point{
	int x,y;
	struct Point* next;
};

struct Point *Start=NULL;
int S=sizeof(struct Point);

void AddFirst(int x,int y)
{
	struct Point *Node=(struct Point*)malloc(S);
	if(Node==NULL)
	{
		cout<<-1<<endl;
		return;
	}
	Node->x=x;
	Node->y=y;
	Node->next=Start;
	Start=Node;
	cout<<0<<endl;
}

void DelFirst()
{
	if(Start!=NULL)
	{
		struct Point *Node=Start;
		Start=Start->next;
		free(Node);
		cout<<0<<endl;
	}
	else 
		cout<<-1<<endl;
}

void Del(int x,int y)
{
	struct Point *Node=Start,*Prev=NULL;
	while(Node!=NULL)
	{
		if(Node->x==x&&Node->y==y)
		{
			//struct Point *t=Node;
			if(Prev==NULL)
				Start=Node->next;
			else Prev->next=Node->next;
			free(Node);
			cout<<0<<endl;
			return;
		}
		Prev=Node;
		Node=Node->next;
	}
	cout<<-1<<endl;
}

void Search(float d)
{
	//vector<pair<int,int>> v;
	struct Point *Node=Start;
	//cout<<d<<'D';
	int f=1;
	double D=d*d;
	while(Node!=NULL)
	{
		double t=Node->x*Node->x+Node->y*Node->y;
		if(t<=D)
			{ cout<<'('<<Node->x<<','<<Node->y<<')'<<' '; f=0;}
		Node=Node->next;
	}
	if(f)
		cout<<-1;
	cout<<endl;
}

bool Search(int x,int y)
{
	struct Point *Node=Start;
	while(Node!=NULL)
	{
		if(Node->x==x&&Node->y==y)
			return true;
		Node=Node->next;
	}
	return false;
}

void Length()
{
	struct Point *Node=Start;
	int c=0;
	while(Node!=NULL)
	{
		c++;
		Node=Node->next;
	}
	cout<<c<<endl;
}

void show()
{
	struct Point *Node=Start;
	//int c=0;
	while(Node!=NULL)
	{
		cout<<Node->x<<' '<<Node->y<<"    ";
		Node=Node->next;
	}
	cout<<endl;
}

void deallocate()
{
	Point *Node=Start;
	while(Node!=NULL)
	{
		Start=Node->next;
		free(Node);
		Node=Start;
	}
}
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		int x,y;
		float d;
		vector<pair<int,int>> v;
		switch(n)
		{
			case 1: //int x,y;
					cin>>x>>y;
					AddFirst(x,y);
					break;
			case 2:	DelFirst(); break;
			case 3:	//int x,y;
					cin>>x>>y;
					Del(x,y);
					break;
			case 4:	//int d;
					cin>>d;
					//vector<pair<int,int>> v1;
					Search(d);
					break;
			case 5:	//int x,y;
					cin>>x>>y;
					if(Search(x,y))
						cout<<"True";
					else cout<<"False";
					cout<<endl;
					break;
			case 6:	Length(); break;
			default: cout<<"Invalid input!!";
					break;

		}
		//show();
	}
	deallocate();
	cout<<endl;
	return 0;
}

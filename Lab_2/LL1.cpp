#include<bits/stdc++.h>

using namespace std;


class Point
{
private:
	int X;
	int Y;
public:
	double distance()
	{
		return double(X*X+Y*Y);
	}
	void show()
	{
		cout<<'('<<X<<','<<Y<<')'<<' ';
	}
	Point(int x,int y)
	{
		X=x;
		Y=y;
	}
	bool compare(int x,int y)
	{
		if(X==x&&Y==y)
			return true;
		else return false;
	}
};


struct N
{
	Point p;
	N *next;
};

N *Start=NULL;
int S=sizeof(struct N);

void AddFirst(int x,int y)
{
	N* Node=(struct N*)malloc(S);
	Point P(x,y);
	if(Node==NULL)
	{
		//cout<<-1<<endl;
		return;
	}
	Node->p=P;
	Node->next=Start;
	Start=Node;
	//cout<<0<<endl;
}

void DelFirst()
{
	if(Start!=NULL)
	{
		struct N *Node=Start;
		Start=Start->next;
		free(Node);
		//cout<<0<<endl;
	}	
	else	
	cout<<-1<<endl;
}

void Del(int x,int y)
{
	struct N *Node=Start,*Prev=NULL;
	while(Node!=NULL)
	{
		if(Node->p.compare(x,y))
		{
			//struct Point *t=Node;
			if(Prev==NULL)
				Start=Node->next;
			else Prev->next=Node->next;
			free(Node);
			//cout<<0<<endl;
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
	struct N *Node=Start;
	//cout<<d<<'D';
	int f=0;
	double D=d*d;
	while(Node!=NULL)
	{
		//double t=Node->x*Node->x+Node->y*Node->y;
		if(Node->p.distance()<=D)
			{f++;}
		Node=Node->next;
	}
	if(f)
		cout<<f;
	else cout<<f-1;
	cout<<endl;
}


bool Search(int x,int y)
{
	struct N *Node=Start;
	int c=0;
	while(Node!=NULL)
	{
		if(Node->p.compare(x,y))
			return true;
		Node=Node->next;
	}
	return false;
}

void Length()
{
	struct N *Node=Start;
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
	struct N *Node=Start;
	//int c=0;
	while(Node!=NULL)
	{
		Node->p.show();
		Node=Node->next;
	}
	cout<<endl;
}

void deallocate()
{
	N *Node=Start;
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
		//vector<pair<int,int>> v;
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

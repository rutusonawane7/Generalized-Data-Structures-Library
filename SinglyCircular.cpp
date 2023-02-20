#include<iostream>
using namespace std;

template<class T>
struct node
{
	T Data;
	struct node*next;
};

template<class T>
class SinglyCll
{
	private:
		struct node<T>*Head;
		struct node<T>*Tail;
		int Count;
		
	public:
		SinglyCll();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		void Display();
		int CountNode();
};
template<class T>
SinglyCll<T>::SinglyCll()
{
	Head=NULL;
	Tail=NULL;
	Count=0;
}

template<class T>
void SinglyCll<T>::InsertFirst(T iNo)
{
	struct node<T>*newn=NULL;
	newn=new node<T>;
	newn->Data=iNo;
	newn->next=NULL;
	
	
	if((Head==NULL)&&(Tail==NULL))
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		newn->next=Head;
		Head=newn;
	}
	Tail->next=Head;
	Count++;
}

template<class T>
void SinglyCll<T>::InsertLast(T iNo)
{
	
	struct node<T>*newn=NULL;
	newn=new node<T>;
	newn->Data=iNo;
	newn->next=NULL;
	
	if((Head==NULL)&&(Tail==NULL))
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		Tail->next=newn;
		Tail=newn;
	}
	Tail->next=Head;
	Count++;
}

template<class T>
void SinglyCll<T>::InsertAtPos(T iNo,int iPos)
{
	if((iPos<1)&&(iPos>Count+1))
	{
		return ;
	}
	
	if(iPos==1)
	{
		InsertFirst(iNo);
	}
	else if(iPos==Count+1)
	{
		InsertLast(iNo);
	}
	else
	{
		struct node<T>*newn=NULL;
		newn=new node<T>;
		newn->Data=iNo;
		newn->next=NULL;
		
		struct node<T>*temp=Head;
		for(int i=1;i<(iPos-1);i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
		Count++;
	}
}

template<class T>
void SinglyCll<T>::DeleteFirst()
{
	if((Head==NULL)&&(Tail==NULL))
	{
		return ;
	}
	else if(Head==Tail)
	{
		delete Head;
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		Head=Head->next;
		delete Tail->next;
	}
	Tail->next=Head;
	Count--;
}

template<class T>
void SinglyCll<T>::DeleteLast()
{
	
	if((Head==NULL)&&(Tail==NULL))
	{
		return ;
	}
	else if(Head==Tail)
	{
		delete Head;
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		struct node<T>*temp=Head;
		while(temp->next!=Tail)
		{
			temp=temp->next;
		}
		delete Tail;
		Tail=temp;
	}
	Tail->next=Head;
	Count--;
}

template<class T>
void SinglyCll<T>::DeleteAtPos(int iPos)
{
	if((iPos<1)&&(iPos>Count))
	{
		return ;
	}
	
	if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==Count)
	{
		DeleteLast();
	}
	else
	{
		struct node<T>*temp1=Head;
		struct node<T>*temp2=NULL;
		for(int i=1;i<(iPos-1);i++)
		{
			temp1=temp1->next;
		}
		temp2=temp1->next;
		temp1->next=temp2->next;
		delete temp2;
		//temp->next=temp->next->next;
		Count--;
	}
}

template<class T>
void SinglyCll<T>::Display()
{
	struct node<T>*temp=Head;
	if((Head==NULL)&&(Tail==NULL))
	{
		return;
	}
	
	do
	{
		cout<<"|"<<temp->Data<<"|->";
		temp=temp->next;
	}while(temp!=Head);
	cout<<endl;
	
}

template<class T>
int SinglyCll<T>::CountNode()
{
	return Count;
}

int main()
{
	SinglyCll <int> obj;
	
	obj.InsertFirst(111);
	obj.InsertFirst(101);
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.InsertLast(121);
	obj.InsertAtPos(55,4);
	
	obj.Display();
	int iRet=obj.CountNode();
	cout<<iRet<<endl;
	
	obj.DeleteFirst();
	obj.DeleteLast();
	obj.DeleteAtPos(4);
	obj.Display();
	iRet=obj.CountNode();
	cout<<iRet<<endl;
	
	
	return 0;
}
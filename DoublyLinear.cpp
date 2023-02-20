#include<iostream>
using namespace std;

template<class T>
struct node
{
	T Data;
	struct node* next;
	struct node *prev;
};

template<class T>
class DoublyLL
{
	private:
		struct node<T> *Head;
		int Count;
		
	public:
		DoublyLL();
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
DoublyLL<T>::DoublyLL()
{
	Head=NULL;
	Count=0;
}

template<class T>
void DoublyLL<T>::InsertFirst(T iNo)
{
	struct node<T>*newn=NULL;
	newn=new node<T>;
	
	newn->Data=iNo;
	newn->next=NULL;
	newn->prev=NULL;
	
	if(Head==NULL)
	{
		Head=newn;
	}
	else
	{
		Head->prev=newn;
		newn->next=Head;
		Head=newn;
	}
	Count++;
}

template<class T>
void DoublyLL<T>::InsertLast(T iNo)
{
	struct node<T>*newn=NULL;
	newn=new node<T>;
	
	newn->Data=iNo;
	newn->next=NULL;
	newn->prev=NULL;
	
	if(Head==NULL)
	{
		Head=newn;
	}
	else
	{
		struct node<T>*temp=Head;
		while(temp->next!=0)
		{
			temp=temp->next;
		}
		temp->next=newn;
		newn->prev=temp;
	}
	Count++;

}

template<class T>
void DoublyLL<T>::InsertAtPos(T iNo,int iPos)
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
		newn->prev=NULL;
		struct node<T>*temp=Head;
		
		for(int i=1;i<(iPos-1);i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		newn->prev=temp;
		temp->next->prev=newn;
		temp->next=newn;
		Count++;
	}
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
	if(Head==NULL)
	{
		delete Head;
		Head->next=NULL;
	    Head->prev=NULL;
	}
	else
	{
		Head=Head->next;
		delete Head->prev;
		Head->prev=NULL;
	}
	Count--;
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
	if(Head==NULL)
	{
		delete Head;
		Head->next=NULL;
		Head->prev=NULL;
	}
	else
	{
		struct node<T>*temp=Head;
		while(temp->next->next!=0)
		{
			temp=temp->next;
		}
		delete temp->next;
		temp->next=NULL;
		Count--;
	}
}

template<class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
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
		struct node<T>*temp=Head;
		
		for(int i=1;i<(iPos-1);i++)
		{
			temp=temp->next;
		}
		temp->next=temp->next->next;
		delete temp->next->prev;
		temp->next->prev=temp;
		Count--;
	}
}

template<class T>
void DoublyLL<T>::Display()
{
	struct node<T>*temp=Head;
	while(temp!=NULL)
	{
		cout<<"|"<<temp->Data<<"|->";
		temp=temp->next;
	}
	cout<<endl;
}

template<class T>
int DoublyLL<T>::CountNode()
{
	return Count;
}


int main()
{
	DoublyLL <int>Obj;
	
	Obj.InsertFirst(111);
	Obj.InsertFirst(101);
	Obj.InsertFirst(51);
	Obj.InsertFirst(21);
	Obj.InsertFirst(11);
	Obj.InsertLast(121);
	Obj.InsertAtPos(55,4);
	Obj.DeleteAtPos(4);
	
	Obj.Display();
	Obj.DeleteFirst();
	Obj.DeleteLast();
    Obj.Display();
   int iRet= Obj.CountNode();
	cout<<iRet<<endl;
	return 0;
}
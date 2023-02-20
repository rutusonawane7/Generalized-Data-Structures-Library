#include<iostream>

using namespace std;

template<class T>
struct node
{
	T Data;
	struct node*next;
	struct node*prev;
};

template<class T>
class DoublyCll
{
	private:
		struct node<T>*Head;
		struct node<T>*Tail;
		int Count;
	
	public:
		
		DoublyCll();
		void InsertFirst(T);
		void InserLast(T);
		void InsertAtPos(T,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int );
		void Display();
		int CountNode();	
};

template<class T>
DoublyCll<T>::DoublyCll()
{
	Head=NULL;
	Tail=NULL;
	Count=0;
}
//////////////////////////////////////////////////////////
//******************************************
// Function Name : InsertFirst
// Discription   : Insert the Node first in Doublys
//					Circular Linked list.
// input         : Genaric
// output        : Genaric
// Autor         : Manish Ghalme
// Date          : 12/06/2022
//*******************************************
////////////////////////////////////////////////////////////
template<class T>
void DoublyCll<T>::InsertFirst(T iNo)
{
	struct node<T>*newn=NULL;
	newn=new node<T>;
	newn->Data=iNo;
	newn->next=NULL;
	newn->prev=NULL;
	
	if((Head==NULL)&&(Tail==NULL))
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		newn->next=Head;
		newn->prev=Head;
		Head=newn;
	}
	Head->prev=Tail;
	Tail->next=Head;
	Count++;
}

//////////////////////////////////////////////////////////
//******************************************
// Function Name : InserLast
// Discription   : Insert the Node last node in Doubly 
//					Circular Linked list.
// input         : Genaric
// output        : Genaric
// Autor         : Manish Ghalme
// Date          : 12/06/2022
//*******************************************
////////////////////////////////////////////////////////////
template<class T>
void DoublyCll<T>::InserLast(T iNo)
{
	struct node<T>*newn=NULL;
	newn=new node<T>;
	newn->Data=iNo;
	newn->next=NULL;
	newn->prev=NULL;
	
	if((Head==NULL)&&(Tail==NULL))
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		Tail->next=newn;
		newn->prev=Tail;
		Tail=newn;
	}
	Head->prev=Tail;
	Tail->next=Head;
	Count++;

}

//////////////////////////////////////////////////////////
//******************************************
// Function Name : InsertAtPos
// Discription   : Insert the Node At Position in Doublys
//					Circular Linked list.
// input         : Genaric,intger
// output        : Genaric
// Autor         : Manish Ghalme
// Date          : 12/06/2022
//*******************************************
////////////////////////////////////////////////////////////

template<class T>
void DoublyCll<T>::InsertAtPos(T iNo,int iPos)
{
	if((iPos<1)&&(iPos>Count+1))
	{
		return;
	}
	
	if(iPos==1)
	{
		InsertFirst(iNo);
	}
	else if(iPos==Count+1)
	{
		InserLast(iNo);
	}
	else
	{
		struct node<T>*newn=NULL;
		newn=new node<T>;
		newn->Data=iNo;
		newn->next=NULL;
		newn->prev=NULL;
		
		struct node<T>* temp=Head;
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next->prev=newn;
		temp->next=newn;
		newn->prev=temp;
		Count++;
	}
}

//////////////////////////////////////////////////////////
//******************************************
// Function Name : DeleteFirst
// Discription   : Delete the Node last node in Doubly 
//					Circular Linked list.
// input         : Genaric
// output        : Genaric
// Autor         : Manish Ghalme
// Date          : 12/06/2022
//*******************************************
////////////////////////////////////////////////////////////

template<class T>
void DoublyCll<T>::DeleteFirst()
{	
	if((Head==NULL)&&(Tail==NULL))
	{
		return;
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
	Head->prev=Tail;
	Count--;

}
//////////////////////////////////////////////////////////
//******************************************
// Function Name : DeleteLast
// Discription   : Delete the Node last node in Doubly
//					Circular Linked list.
// input         : Genaric
// output        : Genaric
// Autor         : Manish Ghalme
// Date          : 12/06/2022
//*******************************************
////////////////////////////////////////////////////////////

template<class T>
void DoublyCll<T>::DeleteLast()
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
		Tail=Tail->prev;
		delete Tail->next;
	}
	Head->prev=Tail;
	Tail->next=Head;
	Count--;

}
//////////////////////////////////////////////////////////
//******************************************
// Function Name : DeleteAtPos
// Discription   : Delete the Node At Position in Doubly
//					Circular Linked list.
// input         : Genaric,intger
// output        : Genaric
// Autor         : Manish Ghalme
// Date          : 12/06/2022
//*******************************************
////////////////////////////////////////////////////////////

template<class T>
void DoublyCll<T>::DeleteAtPos(int iPos)
{
	if((iPos<1)&&(iPos>Count+1))
	{
		return ;
	}
	
	if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==Count+1)
	{
		DeleteLast();
	}
	else
	{
		struct node<T>*temp=Head;
		for(int i=1;i<iPos-1;i++)
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
void DoublyCll<T>::Display()
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
int DoublyCll<T>::CountNode()
{
	return Count;
}


int main()
{
	DoublyCll <int>dobj;
	
	dobj.InsertFirst(111);
	dobj.InsertFirst(101);
	dobj.InsertFirst(51);
	dobj.InsertFirst(21);
	dobj.InsertFirst(11);
	dobj.InserLast(121);
	dobj.InsertAtPos(55,4);
	
	dobj.Display();
	dobj.DeleteAtPos(4);
	dobj.DeleteFirst();
	dobj.DeleteLast();
	
	dobj.Display();
	int iRet=dobj.CountNode();
	cout<<iRet<<endl;
	
	return 0;
}

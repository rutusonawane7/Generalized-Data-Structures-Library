#include<iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	struct node *next;
};

template<class T>
class SinglyLL
{
	private:
	struct node <T> * Head;
	int Count;
	
	public:
		SinglyLL();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T ,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int );
		void Display();
		int CountNode();
};
template<class T>
SinglyLL<T>::SinglyLL()
{
	Head=NULL;
	Count=0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T iNo)
{
	struct node<T> *newn=NULL;
	newn=new node<T>;
	
	newn->data=iNo;
	newn->next=NULL;
	
	newn->next=Head;
	Head=newn;
	Count++;
}

template<class T>
void SinglyLL<T>::InsertLast(T iNo)
{
	struct node<T> *newn=NULL;
	newn=new node<T>;
	newn->data=iNo;
	newn->next=NULL;
		
		
	if(Head==NULL)
	{
		return;
	}
	
	if(Count==1)
	{
		Head->next=newn;
	}
	else
	{
		struct node<T> *temp=Head;
		while(temp->next!=0)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
	Count++;
}

template<class T>
void SinglyLL<T>::InsertAtPos(T iNo ,int iPos)
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
		struct node<T> *newn=NULL;
		newn=new node<T>;
		newn->data=iNo;
		newn->next=NULL;
		struct node<T>* temp=Head;
		
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
		Count++;
	}

}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
	if(Count==0)
	{
		return ;
	}
	
	if(Count==1)
	{
		delete Head;
		Head=NULL;
	}
	else
	{
		struct node<T>*temp=Head;
		
		Head=Head->next;
		delete temp;
	}
	Count--;
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
	
	if(Head==NULL)
	{
		return;
	}
	
	if(Count==1)
	{
		delete Head->next;
		Head->next=NULL;
	}
	else
	{
		struct node<T> *temp=Head;
		while(temp->next->next!=0)
		{
			temp=temp->next;
		}
		delete temp->next;
		temp->next=NULL;
	}
	Count--;
}

template<class T>
void SinglyLL<T>::DeleteAtPos(int iPos )
{
	
	if((iPos<1)&&(iPos>Count))
	{
		return ;
	}
	
	if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos=Count)
	{
		DeleteLast();
	}
	else 
	{
		struct node<T> *temp=Head;
		struct node<T> *temp2;
		
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}
		temp2=temp->next;
		temp->next=temp->next->next;
		delete temp2;
		Count++;
	}
}

template<class T>
void SinglyLL<T>::Display()
{
	struct node<T> *temp=Head;
	while(temp!=NULL)
	{
		cout<<"|"<<temp->data<<"|->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
	
}

template<class T>
int SinglyLL<T>::CountNode()
{
	return Count;
}


int main()
{
	SinglyLL <float>obj;
	
	obj.InsertFirst(111.11);
	obj.InsertFirst(101.11);
	obj.InsertFirst(51.11);
	obj.InsertFirst(21.11);
	obj.InsertFirst(11.11);

	obj.Display();
	
	obj.InsertLast(121.11);
	obj.InsertAtPos(155.11,3);
	obj.Display();
	cout<<endl;
	
	obj.DeleteAtPos(3);
	obj.DeleteFirst();
	obj.DeleteLast();
	obj.Display();
	int iRet=obj.CountNode();
	cout<<endl;
	cout<<iRet<<endl;
	
	return 0;
}
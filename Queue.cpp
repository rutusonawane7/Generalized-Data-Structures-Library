#include<iostream>
using namespace std;

template<class T>
struct node
{
	T data ;
	struct node *next;
	
};

template<class T>
class Queue
{
	public:
	struct node<T> *Head;
    int Count;
		
	Queue();
	void Display();
	int CountNode();
	void Enqueue(T);
	void Dequeue();
};

template<class T>
Queue<T>::Queue()
{
	Head=NULL;
	Count=0;
}

template<class T>
void Queue<T>::Display()
{
	cout<<"Element of Queue  are : "<<endl;
	struct node<T>*temp=Head;
	while(temp!=0)
	{
		cout<<"|"<<temp->data<<"|->";
		temp=temp->next;
	}
	cout<<endl;
}

template<class T>
int Queue<T>::CountNode()
{
	return Count;
}

template<class T>
void Queue<T>::Enqueue(T iNo)//insertLast
{
	struct node<T>*newn=NULL;
	newn=new node<T>;
	
	newn->data=iNo;
	newn->next=NULL;
	
	if(Head==NULL)
	{
		Head=newn;
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
void  Queue<T>::Dequeue()//delete first
{
	T temp;
	if(Count==0)
	{
		cout<<"Queue is empty"<<endl;
		return;
	}

	temp=Head->data;
	struct node<T> *temp1=Head;
	Head=Head->next;
	delete temp1;

	Count--;
	cout<<"Removed element is : "<<temp<<endl;
}

int main()
{
	Queue <int>obj1;
	obj1.Enqueue(11);
	obj1.Enqueue(21);
	obj1.Enqueue(51);
	obj1.Enqueue(101);
	
	obj1.Display();
	//cout<<endl;
	//cout<<"Number of elements inr Queue: "<<obj1.CountNode<<endl;
	
	obj1.Dequeue();
	obj1.Dequeue();
	obj1.Dequeue();
	
	obj1.Display();
	//cout<<"Number of elements inr Queue: "<<obj1.CountNode<<endl;
	obj1.Dequeue();
	obj1.Dequeue();
	
	
	return 0;
}
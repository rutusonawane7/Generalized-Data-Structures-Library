#include<iostream>
using namespace std;

template<class T>
struct node
{
	T data ;
	struct node *next;
	
};

template<class T>
class Stack
{
	public:
	struct node<T> *Head;
    int Count;
		
	Stack();
	void Display();
	int CountNode();
	void Push(T);
	void Pop();
};

template<class T>
Stack<T>::Stack()
{
	Head=NULL;
	Count=0;
}

template<class T>
void Stack<T>::Display()
{
	cout<<"Element of Stack  are : "<<endl;
	struct node<T>*temp=Head;
	while(temp!=0)
	{
		cout<<"|"<<temp->data<<"|->";
		temp=temp->next;
	}
	cout<<endl;
}

template<class T>
int Stack<T>::CountNode()
{
	return Count;
}

template<class T>
void Stack<T>::Push(T iNo)
{
	struct node<T>*newn=NULL;
	newn=new node<T>;
	
	newn->data=iNo;
	newn->next=NULL;
	
	newn->next=Head;
	Head=newn;
	Count++;
}

template<class T>
void  Stack<T>::Pop()//delete first
{
	T temp;
	if(Count==0)
	{
		cout<<"Stack is empty"<<endl;
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
	Stack<char>obj1;
	
	obj1.Push('A');
	obj1.Push('B');
	obj1.Push('C');
	obj1.Push('D');
	
	obj1.Display();
	
	obj1.Pop();
	obj1.Pop();
	
	obj1.Push('Z');
	obj1.Pop();
	
	return 0;
}
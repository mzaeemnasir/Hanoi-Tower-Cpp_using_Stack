// Task 1 
// Stack Implementation Using Stack 

#include<iostream>
#include<cmath>
using namespace std;

//creating Node
struct node
{
	int data;	// it can be of any type 
	node* next;	// this pointer store the adress of the node in it 
};





class Stack
{

private:
	//LinkList L;	 
public:

	node* head = NULL;
	node* tail = NULL;
	// Push the element in the Stack 
	void Push(int x)
	{
		// addng new entry at head 
		node* NODE = new node;
		NODE->data = x;
		NODE->next = head;
		if (head == NULL)
		{

			head = NODE;	  // now  the Adress & data of Node N is Stored in Head 
			tail = NODE;	 // now  the Adress & data of Node N is Stored in Tail 
		}
		else
		{
			head = NODE;
		}

	}
	// Pop the Element From the Stack 
	int Pop()
	{
		node* temp;
		temp = head;
		if (temp == NULL)
		{
			//cout << "THE STACK IS EMPTY PLEASE INSERT ELEMENTs FIST " << endl;
		}
		else
		{
			head = head->next;
			return temp->data;
			//	cout << "The Data " << temp->data << " has been poped " << endl;
		}
		

	}

	// return Stack Head Value
	int lastValue()
	{
		if (head == NULL)
		{
			return 0;
		}
		else
		{
			return head->data;
		}
		
	}

	//displaying data Of Stack 
	void Display()
	{
		node* temp;
		temp = head;
		if (temp == NULL)
		{
			//cout << "STACK IS EMPTY PLEASE PUSH Elements" << endl << endl;
		}
		while (temp != NULL)
		{

			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

	bool isSmall(Stack &A, Stack &B) // it will check the 1st disk is smaller then 2nd Disk 
	{
		if (A.head == NULL )
		{
			return false;
		}
		else if (B.lastValue() == 0)
		{
			return true;
		}
		else if (A.lastValue() < B.lastValue())
		{
			return true;
		}
		else { return false; }
	}

	void Display(Stack& A, Stack& B, Stack& C)
	{
		cout << "Source      =  ";
		A.Display();
		cout << "Auxaliary   =  ";
		B.Display();
		cout << "Destination =  ";
		C.Display();
		cout << endl << endl;
	}

// Return the middle Term of the Stack 
void moveDisk(Stack &A, Stack &B) // Move Disk From 1st Pole  To 2nd Pole
{
	if (isSmall(A, B))
	{
		B.Push(A.Pop());
	}
	else
	{
		A.Push(B.Pop());
	}
}

void hanoiTower(Stack& Src, Stack& Aux, Stack& Des, int& Disks, int& totalMoves)
{
	Display(Src, Aux, Des);
	if (Disks % 2 == 1) // if  Disks are odd 
	{
		for (int i = 1; i <= totalMoves; i++)
		{
			if (i % 3 == 1)
			{
				moveDisk(Src, Des);
			}
			else if (i % 3 == 2)
			{
				moveDisk(Src, Aux);
			}
			else if (i % 3 == 0)
			{
				moveDisk(Des, Aux);
			}
			Display(Src, Aux, Des);
		}
	}

	else if (Disks % 2 == 0) // if  Disks are odd 
	{
		for (int i = 1; i <= totalMoves; i++)
		{
			if (i % 3 == 1)
			{
				moveDisk(Src, Aux);
			}
			else if (i % 3 == 2)
			{
				moveDisk(Src, Des);
			}
			else if (i % 3 == 0)
			{
				moveDisk(Aux, Des);
			}
			Display(Src, Aux, Des);
		}
	}
}

int main()
{
	Stack Src, Aux, Des;   // There are three poles Source , Destination , Auxiliary 
	int Disks, totalMoves;
	cout << "Enter the Number of Disks = ";
	cin >> Disks;
	int temp = Disks;
	for (int i = Disks; i>0 ; i--)
	{
		Src.Push(i);
	}
	totalMoves = pow(2, Disks) - 1;
	hanoiTower(Src, Aux, Des, Disks, totalMoves);

	return 0;
	system("PAUSE");
}

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


// making Stack (For the Implementation of Hanoi Tower)
class Stack
{

private:
	//LinkList L;	 
public:
	
// making In Function Head And Tail 
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

	// I will REturn thr LAst Value means (Top Value of Stack ) 
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

// it will check the 1st disk is smaller then 2nd Disk

	bool isSmall(Stack &A, Stack &B)  
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

// it will display the all TowerS

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

// Move Disk From one Tower to Another Tower Also 
// it checks if 1st Disk is small then the Condition Reverses

void moveDisk(Stack &A, Stack &B) 
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


// Main Hanoi Tower Function 

void hanoiTower(Stack& Src, Stack& Aux, Stack& Des, int& Disks, int& totalMoves)
{
	Display(Src, Aux, Des); // Display the All Poles Initial Values Or Places of Disks 
	
	// For Odd No of Disks 
	
	if (Disks % 2 == 1) 
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

	
	// For EVEN Number of Disks 
	
	
	else if (Disks % 2 == 0) 
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

// MAin Function 

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
	
	totalMoves = pow(2, Disks) - 1;  // it will check the Totol No OF Moves that will make to Move From Source To DEstination 
	
	// calling main hanoi tower function
	
	hanoiTower(Src, Aux, Des, Disks, totalMoves); //passing the All Towers And Total Disks And Total Number OF Moves

	return 0;
	system("PAUSE");
}

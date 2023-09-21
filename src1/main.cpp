/*
 * main.cpp
 *
 *	Anggota:
 *	Billy Alexander (2110511086)
 *	Dimas Anggoro Sakti (2110511115)
 *	Kristo Josua Simangunsong (2110511111) 
 *  
 */
 
#include <iostream>

#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "CustomDeque.h"
#include "Prajurit.h"
using namespace std;

int fungsiProsesCustomDeque(int cdeq)
{

	// jika cdeq kurang dari 5 maka akan throws Exception

	if (cdeq < 5)
	{
		throw "Deque tidak boleh kurang dari 5\n";
		return 0;
	}

	return 100;
}

int main_deque_custom()
{
	// CustomDeque<Prajurit> deque = CustomDeque<Prajurit>(5);
	CustomDeque<string> deque = CustomDeque<string>(5);
	// Prajurit timpekerja = new Prajurit();

	// implement insertRear 5x atau insert rear 3 + front 2,
	try
	{
		deque.EnqueueFront("Billy");
		deque.PrintCustomDeque();
		deque.EnqueueBack("Dimas");
		deque.PrintCustomDeque();
		deque.EnqueueBack("Daniel");
		deque.PrintCustomDeque();
		deque.EnqueueBack("Mahesa");
		deque.PrintCustomDeque();	
		deque.EnqueueFront("Rangga");
		deque.PrintCustomDeque();
	}
	catch (const char *error_1)
	{
		cout << error_1 << endl;
	}

	try
	{
		cout << fungsiProsesCustomDeque(deque.m_count) << endl;
	}
	catch (const char *error_2)
	{
		cout << error_2 << endl;
	}

	return 0;
}

int main_deque()
{
	// NULL
	Deque<int> deque = Deque<int>();

	// Enqueue several numbers to the deque
	// 26
	deque.EnqueueFront(26);
	// 26 - 78
	deque.EnqueueBack(78);
	// 26 - 78 - 44
	deque.EnqueueBack(44);
	// 91 - 26 - 78 - 44
	deque.EnqueueFront(91);
	// 35 - 91 - 26 - 78 - 44
	deque.EnqueueFront(35);
	// 35 - 91 - 26 - 78 - 44 - 12
	deque.EnqueueBack(12);

	// list the element of queue
	while (!deque.IsEmpty())
	{
		// Get the front element
		cout << deque.Back() << " - ";

		// Remove the front element
		deque.DequeueBack();
	}
	cout << "END" << endl;

	return 0;
}

int main_queue()
{
	// NULL
	Queue<int> queueInt = Queue<int>();

	// Enqueue several numbers to the queue
	queueInt.Enqueue(35);
	queueInt.Enqueue(91);
	queueInt.Enqueue(26);
	queueInt.Enqueue(78);
	queueInt.Enqueue(44);
	queueInt.Enqueue(12);

	// list the element of queue
	while (!queueInt.IsEmpty())
	{
		// Get the front element
		cout << queueInt.Front() << " - ";

		// Remove the front element
		queueInt.Dequeue();
	}
	cout << "END" << endl;

	return 0;
}

int main_stack()
{
	// NULL
	Stack<int> stackInt = Stack<int>();

	// Store several numbers to the stack
	stackInt.Push(32);
	stackInt.Push(47);
	stackInt.Push(18);
	stackInt.Push(59);
	stackInt.Push(88);
	stackInt.Push(91);

	// list the element of stack
	while (!stackInt.IsEmpty())
	{
		// Get the top element
		cout << stackInt.Top() << " - ";

		// Remove the top element
		stackInt.Pop();
	}
	cout << "END" << endl;

	return 0;
}

int main()
{
	//	main_stack();
	main_deque_custom();
	return 0;
}

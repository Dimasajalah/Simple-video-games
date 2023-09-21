/*
 * CustomDeque.h
 *
 *	Anggota:
 *	Billy Alexander (2110511086)
 *	Dimas Anggoro Sakti (2110511115)
 *	Kristo Josua Simangunsong (2110511111) 
 */
 
#ifndef CUSTOMDEQUE_H_
#define CUSTOMDEQUE_H_
#include "DoublyNode.h"
#include "Deque.h"

template <typename T>
class CustomDeque : Deque<T>
{
private:
    DoublyNode<T> *m_front;
    DoublyNode<T> *m_back;

public:
    CustomDeque(int maxelement);
    virtual ~CustomDeque();
    int maxel;
    int m_count;
    bool IsEmpty();
    T Front();
    T Back();
    T temp;
    void EnqueueFront(T val);
    void EnqueueBack(T val);
    void DequeueFront();
    void DequeueBack();
    void PrintCustomDeque();
};

template <typename T>
CustomDeque<T>::CustomDeque(int maxelement) : m_count(0), m_front(NULL), m_back(NULL)
{
    maxel = maxelement;
}

template <typename T>
CustomDeque<T>::~CustomDeque()
{
    // TODO Auto-generated destructor stub
    // while (IsEmpty()) remove();
}

template <typename T>
bool CustomDeque<T>::IsEmpty()
{
    return m_count == 0;
}

template <typename T>
T CustomDeque<T>::Front()
{
    return m_front->Value;
}

template <typename T>
T CustomDeque<T>::Back()
{
    return m_back->Value;
}

template <typename T>
void CustomDeque<T>::EnqueueFront(T val)
{
	 // create a new node
    DoublyNode<T> *node = new DoublyNode<T>(val);
    
    // if m_count==5 then throws Exception
    if (m_count == maxel)
    {
        throw "Jumlah node sudah mencapai batas";
    }

    // the current m_front will no longer become a m_front
    // so the next pointer of the new node will
    // point to the current m_front
    node->Next = m_front;

    // if the current m_front is exist,
    // the previous pointer of the current m_front
    // should point to the node
    if (m_front != NULL)
        m_front->Previous = node;

    // the new node now become the m_front
    m_front = node;

    // if the deque is empty
    // the m_back is also the m_front
    if (m_count == 0)
        m_back = m_front;

    // one element is added
    m_count++;
}

template <typename T>
void CustomDeque<T>::EnqueueBack(T val)
{
	// create a new node
    DoublyNode<T> *node = new DoublyNode<T>(val);
    
    if (m_count == 0)
    {
        EnqueueFront(val);
        return;
    }

    // if m_count==5 then throws Exception
    if (m_count == maxel)
    {
        throw "Jumlah node sudah mencapai batas";
    }

    // the current m_back will no longer become a m_back
    // so the next pointer of the current m_back will
    // point to the new node
    m_back->Next = node;

    // also, the previous pointer of the new node
    // should point to the current m_back
    node->Previous = m_back;

    // the new node now become the m_back
    m_back = node;

    // one element is added
    m_count++;
}

template <typename T>
void CustomDeque<T>::DequeueFront()
{
    if (m_count == 0)
        return;

    // save the current m_front
    // to a new node
    DoublyNode<T> *node = m_front;

    // point the m_front pointer
    // to the element next to the current m_front
    m_front = m_front->Next;

    delete node;

    if (m_front != NULL)
        m_front->Previous = NULL;

    // one element is removed
    m_count--;
}

template <typename T>
void CustomDeque<T>::DequeueBack()
{
    if (m_count == 0)
        return;

    if (m_count == 1)
    {
        DequeueFront();
        return;
    }

    // save the current m_back
    // to a new node
    DoublyNode<T> *node = m_back;

    // point the m_back pointer
    // to the element before the current m_back
    m_back = m_back->Previous;

    // set the new next pointer of the new m_back
    // to NULL since we are going to delete
    // the last element
    m_back->Next = NULL;

    delete node;

    // one element is removed
    m_count--;
}

template <typename T>
void CustomDeque<T>::PrintCustomDeque()
{

    DoublyNode<T> *node = m_front;

    while (node != NULL)
    {
        std::cout << node->Value << ", ";
        node = node->Next;
    }
    std::cout << std::endl;
}
#endif

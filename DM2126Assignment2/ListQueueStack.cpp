#include "DetectMemoryLeak.h"
#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    Foo Jing Ting
 *  \date      2016
 *  \note      152856H
 */

//*******************************************************************//
// Linked list stuff
//*******************************************************************//
LinkedList::LinkedList() : head(0)
{
}

LinkedList::~LinkedList()
{
    for (Node* curr = head; curr != 0; curr = head) {
        head = head->next;
        delete curr;
    }
}

void LinkedList::push_front(int data)
{
    Node* curr = new Node(data);
    curr->next = head;
    head = curr;
}

void LinkedList::push_back(int data)
{
    Node* curr = 0, *prev = 0;
    for (curr = head; curr != 0; prev = curr, curr = curr->next) {}
    //now curr is at the very end of the list

    curr = new Node(data);
    //curr->next = 0 already
    if (head == 0) {		//list is empty; head is pointing to NULL also
        head = curr;
    }
    else {
        prev->next = curr;
    }
}

int LinkedList::pop_front()
{
    if (head == 0) {    //list is empty; hence head points to NULL
        return 0;
    }
    Node* curr = head;
    int temp = head->data;
    head = head->next;
    delete curr;

    return temp;
}

int LinkedList::pop_back()
{
    if (head == 0) {    //list is empty; hence head points to NULL
        return 0;
    }
    Node* curr = 0, *prev = 0;
    for (curr = head; curr->next != 0; prev = curr, curr = curr->next) {}
    //now curr is at the last node of the list (that will be popped)
    //prev is at the node that will be the last in the list after pop
    
    int temp = curr->data;
    if (head->next == 0) {  //popped item is the only node in list
        head = 0;
    }
    else {
        prev->next = 0;
    }
    delete curr;

    return temp;
}

void LinkedList::insert_at(int pos, int data)
{
    if (pos < 0) {  //negative positions should be treated as 0
        pos = 0;
    }

    Node* curr = 0, *prev = 0;
    int countPos = 0;
    for (curr = head; curr != 0 && countPos < pos; prev = curr, curr = curr->next) {
        ++countPos;
    }
    //now curr is at position pos of the list
    //prev should point to position (pos - 1)

    //prev->next = new Node(data);
    //prev->next->next = curr;

    curr = new Node(data);
    if (head == 0 || pos == 0) {    //list is empty or position is 0
        curr->next = head;
        head = curr;
    }
    else {
        curr->next = prev->next;
        prev->next = curr;
    }
}

int LinkedList::pop_at(int pos)
{
    if (head == 0) {    //list is empty
        return 0;
    }

    if (pos >= static_cast<int>(size())) {      //position is greater than list size, or list is empty
        return 0;
    }

    if (pos < 0) {  //negative positions should be treated as 0
        pos = 0;
    }

    Node* curr = 0, *prev = 0;
    int countPos = 0;
    for (curr = head; curr != 0 && countPos < pos; prev = curr, curr = curr->next) {
        ++countPos;
    }
    //now curr is at position pos of the list
    //to pop: curr

    int temp = curr->data;
    if (curr == head) {     //first object is being popped
        head = head->next;
    }
    else {
        prev->next = curr->next;
    }
    delete curr;

    return temp;
}

size_t LinkedList::size()
{
    size_t count = 0;
    for (Node* curr = head; curr != 0; curr = curr->next) {
        ++count;
    }
    return count;
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue() : front(0), back(0)
{
}

Queue::~Queue()
{
    for (Node* curr = front; curr != 0; curr = front) {
        front = front->next;
        delete curr;
    }
}

void Queue::enqueue(int data)
{
    Node* curr = new Node(data);
    if (front == 0) {   //queue is originally empty before enqueuing
        front = curr;
        back = front;
    }
    else {
        back->next = curr;
        back = back->next;
    }
}

int Queue::dequeue()
{
    if (front == 0) {   //queue is empty
        return 0;
    }

    Node* curr = front;
    int temp = front->data;
    if (front == back) {    //queue only has 1 node
        back = 0;
    }
    front = front->next;
    delete curr;

    return temp;
}

size_t Queue::size()
{
    if (front == 0) {   //queue is empty
        return 0;
    }

    size_t count = 1;
    for (Node* curr = front; curr != back; curr = curr->next) {
        ++count;
    }
    return count;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack() : top(0)
{
}

Stack::~Stack()
{
    for (Node* curr = top; curr != 0; curr = top) {
        top = top->next;
        delete curr;
    }
}

void Stack::push(int data)
{
    Node* curr = new Node(data);
    curr->next = top;
    top = curr;
}

int Stack::pop()
{
    if (top == 0) {     //stack is empty
        return 0;
    }

    Node* popped = top;
    top = top->next;
    int poppedData = popped->data;
    delete popped;

    return poppedData;
}

size_t Stack::size()
{
    size_t count = 0;
    for (Node* curr = top; curr != 0; curr = curr->next) {
        ++count;
    }
    return count;
}

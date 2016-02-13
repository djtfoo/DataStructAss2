#include "DetectMemoryLeak.h"
#include <string>
#include <vector>
#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::string;
using std::vector;


bool Brackets(const string& input);
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results);

double timeTaken(clock_t startTime);

// this ensures that _CrtDumpMemoryLeaks() is called after main() and right before program terminates
struct AtExit
{
    ~AtExit() { _CrtDumpMemoryLeaks(); }
} doAtExit;

int main()
{
    // This sets the boolean values to be represented in a textual format.
    cout << std::boolalpha;

    // Start the clock
    clock_t start = clock();

    // part 1
    cout << "Part 1" << endl;
    LinkedList ll;
    ll.push_front(1);
    ll.push_back(1);
    cout << ll.size() << endl;
    cout << ll.pop_back() << endl;
    cout << ll.pop_front() << endl;
    cout << ll.pop_back() << endl;
    ll.insert_at(2, 10);
    cout << ll.pop_at(0) << endl;
    cout << endl;

    // part 2
    cout << "Part 2" << endl;
    Queue q;
    q.enqueue(20);
    q.enqueue(42);
    cout << q.dequeue() << endl;
    cout << q.size() << endl;
    cout << endl;

    // part 3
    cout << "Part 3" << endl;
    Stack s;
    s.push(46);
    s.push(8);
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << endl;

    // part 4
    cout << "Part 4" << endl;
    const char* input = "((<>){<>";
    cout << Brackets(input) << endl;
    cout << endl;


    // part 5
    cout << "Part 5" << endl;
    int dataArray[] = { 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35 , 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35, 1, 2, 3, 4, 3, 2, 2, 6, 100, 25, 2156, 13, 1, 3, 123, 31, 13, 31, 31, 22, 25, 27, 86, 88, 34, 35, 35, 12, 22, 34, 36, 80, 77, 12304, 139, 35};
    int queryArray[] = {1, 2, 3, 5, 10, 12, 15, 1567, 2156, 100, 88, 31, 13, 80, 34, 35, 36, 123, 60, 77, 25, 6};

    vector<int> data(dataArray, dataArray + sizeof(dataArray) / sizeof(dataArray[0]));
    vector<int> queries(queryArray, queryArray + sizeof(queryArray) / sizeof(queryArray[0]));
    vector<unsigned int> results;
    QueryMachine(data, queries, results);
    for (size_t i = 0; i < results.size(); ++i)
    {
        cout << results[i] << " ";
    }
    cout << endl;

    cout << "Time taken to run the above code is " << timeTaken(start) << "ms" << endl;

    return 0;
}

// If you are curious, this calculates the time taken between the start time and the time that this function is called.
// The return value is in milliseconds (ms)
double timeTaken(clock_t startTime)
{
    return (clock() - startTime) / (double)(CLOCKS_PER_SEC/1000);
}


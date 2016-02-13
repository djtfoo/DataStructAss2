#include "DetectMemoryLeak.h"
#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>

using std::string;
using std::vector;
using std::list;
using std::map;
using std::stack;
using std::queue;

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    Foo Jing Ting
 *  \date      2016
 *  \note      152856H
 */


// Balanced parenthesis
 bool Brackets(const string& input)
{
     stack<char> openbrackets;

     for (size_t i = 0; i < input.size(); ++i) {
         if (input[i] == '(' || input[i] == '[' || input[i] == '<' || input[i] == '{') {
             openbrackets.push(input[i]);
         }
         else {
             if (!openbrackets.empty()) {
                 if (input[i] != openbrackets.top() + 1 && input[i] != openbrackets.top() + 2) {    //not the closing bracket
                     return false;
                 }
                 openbrackets.pop();
             }
             else {
                 return false;
             }
         }
     }
     if (!openbrackets.empty()) {   //some brackets in string are not closed -- string is "incomplete"
         return false;
     }

     return true;
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{
    
}
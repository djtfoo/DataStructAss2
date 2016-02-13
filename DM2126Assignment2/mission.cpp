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
    /*//vector method 1
    for (vector<int>::iterator it = queries.begin(); it != queries.end(); ++it) {
        results.push_back(0);
    }

    size_t size_queries = queries.size();

    for (vector<int>::iterator it = data.begin(); it != data.end(); ++it) {
        for (size_t i = 0; i < size_queries; ++i) {
            if (*it == queries[i]) {
                ++results[i];
            }
        }
    }*/

    /*//vector method 2
    for (vector<int>::iterator i = queries.begin(); i != queries.end(); ++i) {
        unsigned int count = 0;
        vector<int>::iterator it = data.begin();
        while (it != data.end()) {
            it = find(it, data.end(), *i);
            if (it != data.end()) {
                ++count;
                ++it;
            }
        }
        results.push_back(count);
    }*/

    /*//vector method 3
    for (vector<int>::iterator it = queries.begin(); it != queries.end(); ++it) {
        results.push_back(std::count(data.begin(), data.end(), *it));
    }*/

    map<int, unsigned int> storedata;
    map<int, unsigned int>::iterator itmap = storedata.begin();

    for (vector<int>::iterator it = data.begin(); it != data.end(); ++it) {
        itmap = storedata.find(*it);
        if (itmap != storedata.end()) {     //data exists already
            ++itmap->second;
        }
        else {      //create a new key
            storedata.insert(std::pair<int, int>(*it, 1));
        }
    }

    for (vector<int>::iterator it = queries.begin(); it != queries.end(); ++it) {
        itmap = storedata.find(*it);
        unsigned int count = storedata[*it];
        results.push_back(count);
    }
}
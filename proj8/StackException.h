/* StackException.h models exceptions in stack operations.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: Sungmin (David) Choi (sc94)
 * Date: 03/21/2022
 */

#ifndef STACK_EXCEPTION
#define STACK_EXCEPTION

#include <iostream>
using namespace std;

 
class StackException {
public:
   StackException(const string& whereThrown,
                  const string& message) { 
       myLocation = whereThrown; 
       myMessage = message; 
   }

   string asString() const {
       return "*** StackException in " +
               myLocation + ": " + myMessage; 
   }

private:
   string myLocation;
   string myMessage;
};  // StackException


/* Function to allow a StackException (or a subclass) to be showed
 * via an ostream.
 * Parameters: out, an ostream;
 *             se, a StackException.
 * Postcondition: the string representation of se has been inserted
 * into out
 *             && return-value == out.
 */
inline ostream& operator<<(ostream& out, const StackException& se) {
      out << se.asString();
      return out;
}

#endif


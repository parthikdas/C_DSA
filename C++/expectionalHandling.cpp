/* There is a special catch block called ‘catch all’ catch(…) that can be used to catch all types of exceptions. For example, in the following program, an int is thrown as an exception, but there is no catch block for int, so catch(…) block will be executed. 

CPP
#include <iostream>
using namespace std;
 
int main()
{
    try  {
       throw 10;
    }
    catch (char *excp)  {
        cout << "Caught " << excp;
    }
    catch (...)  {
        cout << "Default Exception\n";
    }
    return 0;
}
Output: 

Default Exception*/

---------------------------------------------------------------------------------------------------------
/* Implicit type conversion doesn’t happen for primitive types. For example, in the following program ‘a’ is not implicitly converted to int 

CPP
#include <iostream>
using namespace std;
 
int main()
{
    try  {
       throw 'a';
    }
    catch (int x)  {
        cout << "Caught " << x;
    }
    catch (...)  {
        cout << "Default Exception\n";
    }
    return 0;
}
Output: 

Default Exception*/

---------------------------------------------------------------------------------------------------------
/* If an exception is thrown and not caught anywhere, the program terminates abnormally. For example, in the following program, a char is thrown, but there is no catch block to catch a char.  

CPP
#include <iostream>
using namespace std;
 
int main()
{
    try  {
       throw 'a';
    }
    catch (int x)  {
        cout << "Caught ";
    }
    return 0;
}
Output: 

terminate called after throwing an instance of 'char'

This application has requested the Runtime to terminate it in an 
unusual way. Please contact the application's support team for more information.*/

---------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
 
// This function signature is fine by the compiler, but not recommended.
// Ideally, the function should specify all uncaught exceptions and function
// signature should be "void fun(int *ptr, int x) throw (int *, int)"
void fun(int *ptr, int x)
{
    if (ptr == NULL)
        throw ptr;
    if (x == 0)
        throw x;
    /* Some functionality */
}
 
int main()
{
    try {
       fun(NULL, 0);
    }
    catch(...) {
        cout << "Caught exception from fun()";
    }
    return 0;
}
Output: 

Caught exception from fun()
A better way to write above code 
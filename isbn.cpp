// Joe Welch, and Samba Diallo
// ISBN Check for 10 digit values
// Confirm correct values with: http://www.isbn-check.com/
// 2 Oct 2015
// Assignment to read code, modify as required and collaborate.

// CSS-1 HW due 8 Oct
// Correct functions for ISBN10 and ISBN13 are listed below
// Add two new tests each for ISBN10 and ISBN13 which pass
// Issue git commit
// Add two new tests each or ISBN10 and ISBN13 which fail
// Issue git commit
// Add your name to line 1, "Joe Welch, and xxxxxxx"
// Issue git commit
// Change the user.name and user.email to your name and email
// Issue git commit
// Issue git push to your GitHub account

#include <iostream>
#include <typeinfo>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <cmath>
using namespace std;

// must use these two functions
string sumISBN10Digits(string val);
string sumISBN13Digits(string val);


// you may use or discard these functions
int charToInt(char ch);
//bool isValidISBN10(int val);
//bool isValidISBN13(int val);

int main()
{

    string strA = "0385353308";      // test case for ISBN10
    string strB = "9780136091813";   // test case for ISBN13
    assert(sumISBN10Digits("123456789X") == "123456789X is a Valid ISBN10 number.");
    assert(sumISBN10Digits("0385353305") == "0385353305 is NOT a Valid ISBN10 number.");
    assert(sumISBN13Digits("9781566199094") == "9781566199094 is a Valid ISBN13 number.");
    assert(sumISBN13Digits("9780136091813") == "9780136091813 is a Valid ISBN13 number.");
    assert(sumISBN10Digits("12345678912345") == "12345678912345 is NOT a Valid ISBN10 number.");
    assert(sumISBN10Digits("038535330578X") == "038535330578X is NOT a Valid ISBN10 number.");
    assert(sumISBN13Digits("978156619956094") == "978156619956094 is NOT a Valid ISBN13 number.");
    assert(sumISBN13Digits("97B8156619899094") == "97B8156619899094 is NOT a Valid ISBN13 number.");

  
    
    return 0;
    
}// end main()

// ****************************
string sumISBN10Digits(string val)
{
    int sum = 0;
    int num;
    string right = val + " is a Valid ISBN10 number.";
    string wrong = val + " is NOT a Valid ISBN10 number.";
    // Sum : positional value x digit value, except rightmost digit (may be 'X')
    for(int ix = 0; ix < val.length() - 1 ; ix++)
    {
        num = charToInt(val.at(ix) ) * (10 - ix);
        sum += num;       
    }// end for
    
    // account for case if rightmost digit is an 'X'
    if( (val.at(9) == 'X'))
    {
        num = 10;
    }
    else
    {
        num = charToInt(val.at(val.length() - 1) );
    }
    sum += num;
    if ((sum % 11) == 0)
    {
        return right;
    }
    else
    {
        return wrong;
    }       
}// endl;

// ***************************

// ****************************
bool isValidISBN10(int val)
{
    if ((val % 11) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }       

}//end bool isValid(int val)

// ******************************
string sumISBN13Digits(string val)
{
    int sum = 0;
    int p;
    int num;
    string right = val + " is a Valid ISBN13 number.";
    string wrong = val + " is NOT a Valid ISBN13 number.";
    
    for(int ix = 0; ix < val.length() ; ix++)
    {
        p = charToInt(val.at(ix) ) ;
        
        if (( ix % 2) == 0)
        {
            num = p;
        }
        else
        {
            num = 3 * p;
         }
    
       sum += num;
       
    }//end for()
    if ((sum % 10) == 0)
    {
        return right;
    }
    else
    {
        return wrong;
    }

}// string sumISBN13Digits(string val)

// **********************************
bool isValidISBN13(int val)
{
    if ((val % 10) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}// end bool isValidISBN13(int val)
int charToInt(char ch)
{
    return (int(ch) - 48);

}// charToInt(char ch)


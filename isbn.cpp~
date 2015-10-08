// Joe Welch
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
using namespace std;

// must use these two functions
int sumISBN10Digits(string val);
int sumISBN13Digits(string val);

// you may use or discard these functions
int charToInt(char ch);
bool isValidISBN10(int val);
bool isValidISBN13(int val);

int main()
{

    string strA = "0385353308";      // test case for ISBN10  (PASS)
    string strA2 = "9780136091";     // 2nd  (FAIL)
    string strA3 = "123456789X";     // 3rd  (PASS)
    string strA4 = "1234567890";     // 4th (FAIL)
    
    string strB = "9780136091813";   // test case for ISBN13  (PASS)
    string strB2 = "0385353308978";  // 2nd (FAIL)
    string strB3 = "9780136091844";  // 3rd (PASS)
    string strB4 = "1234567890123";  // 4th (FAIL)
    
    
    assert(   isValidISBN10( sumISBN10Digits(strA)   )  == 1 ); //test 1 for ISB10
    assert(   isValidISBN10( sumISBN10Digits(strA2)  )  == 0 );// 2
    assert(   isValidISBN10( sumISBN10Digits(strA3)  )  == 1 );// 3
    assert(   isValidISBN10( sumISBN10Digits(strA4)  )  == 0 );// 4
    
    
    assert(   isValidISBN13( sumISBN13Digits(strB)   )  == 1 ); // test 1 ISBN13
    assert(   isValidISBN13( sumISBN13Digits(strB2)  )  == 0 ); // 2   
    assert(   isValidISBN13( sumISBN13Digits(strB3)  )  == 1 ); // 3   
    assert(   isValidISBN13( sumISBN13Digits(strB4)  )  == 0 ); // 4   
    
    
    
      
    return 0;
    
}// end main()

// ****************************
int sumISBN10Digits(string val)
{
    int sum = 0;
    int num;
    
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
    
    return sum;
}// endl;

// ***************************
int charToInt(char ch)
{
    return (int(ch) - 48);

}// charToInt(char ch)

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
int sumISBN13Digits(string val)
{
    int sum = 0;
    int p;
    int num;
    
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
    return sum;

}// int sumISBN13Digits(string val)

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

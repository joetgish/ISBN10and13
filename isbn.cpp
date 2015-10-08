// Joe Welch, and Daniel Calderon
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

    
   
    //************************ISBN10*********************************
    assert(sumISBN10Digits("0385353308") == 198);
    assert(isValidISBN10(198)==true);
   assert(sumISBN10Digits("9992158107") == 330);
    assert(isValidISBN10(330)==true);
    assert(sumISBN10Digits("9971502100") == 275);
    assert(isValidISBN10(275)==true);
    assert(sumISBN10Digits("0385353309") == 199);
    assert(isValidISBN10(199)==false);
    assert(sumISBN10Digits("9090878768") == 318);
    assert(isValidISBN10(318)==false);


   //****************************ISBN13********************************
    assert(sumISBN13Digits("9780136091813") == 80) ;
    assert(isValidISBN13(80)==true);
     assert(sumISBN13Digits("0000000000000") == 0) ;
    assert(isValidISBN13(0)==true);
    assert(sumISBN13Digits("9781234567897") == 140) ;
    assert(isValidISBN13(140)==true);
  assert(sumISBN13Digits("999999999999") == 216) ;
    assert(isValidISBN13(216)==false);
    assert(sumISBN13Digits("453675894628") == 145) ;
    assert(isValidISBN13(145)==false);
      
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

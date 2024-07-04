/*
 *  lab2exe_A.cpp
 *  ENSF 694 Lab 2 Exercise A
 */

int my_strlen(const char *s);
/*  Duplicates strlen from <cstring>, except return type is int.
 *  REQUIRES
 *     s points to the beginning of a string.
 *  PROMISES
 *     Returns the number of chars in the string, not including the
 *     terminating null.
 */

void my_strncat(char *dest, const char *source, int);
/*  Duplicates strncat from <cstring>, except return type is void.
 */

#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    char str1[7] = "banana";
    const char str2[] = "-tacit";
    const char* str3 = "-toe";
    
    /* point 1 */
    char str5[] = "ticket";
    char my_string[100]="";
    int bytes;
    int length;
    
    /* using strlen libarary function */
    length = (int) strlen(my_string);
    cout << "\nLine 1: my_string length is " << length;
  
    /* using sizeof operator */
    bytes = sizeof (my_string);
    cout << "\nLine 2: my_string size is " << bytes << " bytes.";
   
    /* using strcpy libarary function */
    strcpy(my_string, str1);
    cout << "\nLine 3: my_string contains: " << my_string;
   
    length = (int) strlen(my_string);
    cout << "\nLine 4: my_string length is " << length << ".";
   
    my_string[0] = '\0';
    cout << "\nLine 5: my_string contains:\"" << my_string << "\"";
  
    length = (int) strlen(my_string);
    cout << "\nLine 6: my_string length is " <<  length << ".";
   
    bytes = sizeof (my_string);
    cout << "\nLine 7: my_string size is still " << bytes << " bytes.";
 
    /* strncat append the first 3 characters of str5 to the end of my_string */
    strncat(my_string, str5, 3);
    cout << "\nLine 8: my_string contains:\"" << my_string << "\"";
  
    length = (int) strlen(my_string);
    cout << "\nLine 9: my_string length is " << length << ".";
   
    strncat(my_string, str2,  4);
    cout << "\nLine 10: my_string contains:\"" << my_string << "\"";
    
    /* strncat append ONLY up ot '\0' character from str3 -- not 6 characters */
    strncat(my_string, str3, 6);
    cout << "\nLine 11: my_string contains:\"" << my_string << "\"";
   
    length = (int) strlen(my_string);
    cout << "\nLine 12; my_string has " << length << " characters.";

    cout << "\n\nUsing strcmp - C library function: ";
    
    cout << "\n\"ABCD\" is less than \"ABCDE\" ... strcmp returns: " <<
    strcmp("ABCD", "ABCDE");

    cout << "\n\"ABCD\" is less than \"ABND\" ... strcmp returns: " <<
    strcmp("ABCD", "ABND");
    
    cout << "\n\"ABCD\" is equal than \"ABCD\" ... strcmp returns: " <<
    strcmp("ABCD", "ABCD");
 
    cout << "\n\"ABCD\" is less than \"ABCd\" ... strcmp returns: " <<
    strcmp("ABCD", "ABCd");

    cout << "\n\"Orange\" is greater than \"Apple\" ... strcmp returns: " <<
    strcmp("Orange", "Apple") << endl;
    return 0;
}

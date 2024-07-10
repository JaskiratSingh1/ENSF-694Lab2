//
//  compare_sorts.h
//  Compare Sort Methods
//
//  Created by Mahmood Moussavi on 2024-06-06.
//

#ifndef compare_sorts_h
#define compare_sorts_h
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <chrono>

const int MAX_WORD_SIZE = 20;
const int MAX_UNIQUE_WORDS = 10000;

void to_lower(char *str);
/* REQUIRES: str points to valid c-string terminated with a '\0'
 * PROMISES: changes any upper case character to a lowercase.
 */
void strip_punctuation(char *word);
/* REQUIRES: word points to valid c-string terminated with a '\0'
 * PROMISES: strips out any non-alphanumeric characters. Also keeps
 * hyphens.
 */
bool is_unique(char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int num_words, const char *word);
/* REQUIRES: words refer to a 2-D arry of character, and each row is a valid
 * c-string terminated with a '\0'
 * PROMISES: returns true if words in in the arra are unique. Otherwise, returns false
 */
void quicksort(int *indices, char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int left, int right);
/* REQUIRES: indices points to an arry of integer, holidng index numbers,
 * words refer to a 2-D arry of character, and each row is a valid c-string terminated with a '\0'
 * PROMISES: uses quick sort algorithm to sort the words in ascending order.
 */
void shellsort(int *indices, char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int size);
/* REQUIRES: indices points to an arry of integer, holidng index numbers,
 * words refer to a 2-D arry of character, and each row is a valid c-string terminated with a '\0'
 * PROMISES: uses shell sort algorithm to sort the words in ascending order.
 */
void bubblesort(int *indices, char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int size);
/* REQUIRES: indices points to an arry of integer, holidng index numbers,
 * words refer to a 2-D arry of character, and each row is a valid c-string terminated with a '\0'
 * PROMISES: uses bubble sort algorithm to sort the words in ascending order.
 */
void read_words(const char *input_file, char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int &num_words);
/* REQUIRES: words refer to a 2-D arry of character, and each row is a valid c-string
 * terminated with a '\0'
 * PROMISES: opens an input file, reads each word from the file, and saves the word with
 * no punctuations, all lowercase, into array of words, and updates numbers of words to
 * assure they are less than MAX_UNIQUE_WORDS
 */
void write_words(const char *output_file, char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int *indices, int num_words);
/* REQUIRES: words refer to a 2-D arry of character (number of rows: num_words),
 * and each row is a valid c-string terminated with a '\0'
 * PROMISES: opens an output file, writess the word referred by order of indecies into the
 * output file.
 */
void sort_and_measure_quicksort(char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int* indices, int num_words, void (*sort_func)(int *, char [MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int, int), const char *sort_name);
/* REQUIRES: words refer to a 2-D arry of character, and each row is a valid c-string
 * terminated with a '\0', num_words refers to number of words in the 2-D array, sort_func
 * points to a quicksort function.
 * PROMISES: uses std::chrono::high_resolution_clock::now, before and after call to the sort
 * function
 */
void sort_and_measure_shell_bubble(char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int* indices, int num_words, void (*sort_func)(int *, char [MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int), const char *sort_name);
/* REQUIRES: words refer to a 2-D arry of character, and each row is a valid c-string
 * terminated with a '\0', num_words refers to number of words in the 2-D array, sort_func
 * points to a shell or bubble sort function.
 * PROMISES: uses std::chrono::high_resolution_clock::now, before and after call to the sort
 * function
 */


#endif /* compare_sorts_h */

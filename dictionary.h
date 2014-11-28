/****************************************************************************
 * dictionary.h
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Declares a dictionary's functionality.
 ***************************************************************************/

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word);

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

/**
 * put correct letters in each bucket of table
 */
void key_hash_t(const char *file); 

/**
 * get word count of file
 */
int get_file_size(const char *file);

/**
 * convert word to all lowercase
 * to check in dict file
 */
void word_tolower(char *word);

/**
 * hash first letter of word
 * to get bucket number
 */
int hash(const char *str);

#endif // DICTIONARY_H

/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include "hashTable.h"
#include "dictionary.h"

table_node hash_table[TABLE_LENGTH];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
   //hash word
	int hash_val = hash(word); 

	//must reassign to make editable
	char *eword = strdup(word);

	//convert word to lower
	word_tolower(eword);

	node *cursor = NULL;
	
	//iterate table array to find bucket
	for (int i = 0; i  < TABLE_LENGTH; i ++)
	{
		cursor = hash_table[hash_val].next;

		//traverse list for bucket hash_val
		while (cursor != NULL)
		{
			if (strcmp(eword, cursor->word) == 0)
			{
				free(eword);
				return true;
			}
			else
			{
				cursor = cursor->next;
			}
		}
	}
	free(eword);
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    char word[WORD_LENGTH];
	char c;
	int index = 0, hash_val = 0, size = get_file_size(dictionary);
	FILE *file = fopen(dictionary, "r");
	
	if (file == NULL)
	{
		printf ("File not found...\n");
		return false;
	}

	for (int word_count = 0; word_count < size; word_count++) 
	{
		node *new_node = malloc( sizeof(*new_node) ); 

		// make sure malloc was successful
		if (new_node == NULL)
		{
			printf ("Failed to allocate memory...\n");
			return false;
		}

		new_node->next = NULL;
		
		//read word from file
		while ((c = fgetc(file)) != '\n')
		{
			word[index] = c;
			index++;
		}
		
		//terminate string
		word[index] ='\0';
		
		//hash word
		hash_val = hash(word);
	
		//copy string into node
		strcpy(new_node->word, word);
	
		//reset index
		index = 0;

		//add new node to list
		new_node->next = hash_table[hash_val].next;
		hash_table[hash_val].next = new_node; //<-- segfault here because a space '-65' is being passed as hash_val
	}
	fclose(file);
	return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
//TODO: Walk through this
unsigned int size(void)
{
	bool loaded =  false;
	
	for (int i = 0; i < TABLE_LENGTH; i++) //<----- Debugg this
	{
		if (hash_table[i].next != NULL)
		{
			loaded = true;
			break;
		}
	}
	
    if (!loaded)
	{
		printf("Dictionary not loaded..\n");
		return 0;
	}
	node *cursor = NULL;
	int node_count = 0;
		
	for (int i = 0; i < TABLE_LENGTH; i++)
	{
		cursor = hash_table[i].next;
		while (cursor != NULL)
		{
			node_count++;
			cursor = cursor->next;
		}
	}
	return node_count;
}

//TODO: RETURN
/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    /**
	 * loop through array
	 * traverse each list and
	 * delete each node
	 **/
	for (int i = 0; i < TABLE_LENGTH; i++)
	{
		node *cursor = hash_table[i].next;

		while (cursor != NULL)
		{
			node *temp = cursor;
			cursor = cursor->next;
			free(temp);
		}
	}
	return true;
}

void key_hash_t( ) 
{
	char key = 'a';
	for ( int i = 0; i < TABLE_LENGTH; i++ )
		hash_table[i].letter = (key + i);
}

int get_file_size(const char *file_name)
{
	char c;
	int line_count = 0;
	FILE *file = fopen(file_name, "r");
	
	if (file == NULL)
	{
		printf("File not found..\n");
		exit(EXIT_FAILURE);
	}

	while ((c = fgetc(file)) != EOF)
	{
		if (c == '\n')
		{
			line_count++;
		}
	}
	fclose(file);

	return line_count;
}

//TODO: make sure str[0] is a letter
int hash(const char *str)
{
	if (str == NULL)
	{
		printf("NULL pointer..\n");
		exit(EXIT_FAILURE);
	}
	if (!isalpha(str[0]))
	{
		printf("Cannot hash not a valid value..\n");
		exit(EXIT_FAILURE);
	}
	
	return (tolower(str[0]) - 97);
}

void word_tolower(char* word)
{
	if (word == NULL)
	{
		printf("NULL pointer ...\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0, length = strlen(word); i  < length; i ++)
		word[i] = tolower(word[i]);
}
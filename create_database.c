#include "inverted_search.h"

char *fname;
void create_database(Flist *f_head, Wlist *head[])
{
    //Traverse through file linked list
    while(f_head)
    {
	read_datafile(f_head, head, f_head->file_name);
	f_head = f_head->link;
    }
}

/* Function to read data file for Flist */
Wlist *read_datafile(Flist *file, Wlist *head[], char *filename)
{
    //Open file in read mode

    fname = filename;
    FILE *fptr = fopen(filename, "r");
    char word[WORD_SIZE];

    int flag=1;
    
    if(fptr == NULL)
    {
	printf("Error in opening %s file\n", filename);
    }
    while(fscanf(fptr, "%s", word) != EOF)
    {
	//INDEX
	int index = tolower(word[0]) % 97;

	//Other than alphabets
	if(!(index >= 0 && index <= 25))
	    index = 26;
	
	//insert_at_last(&head[index], word);
    	if(head[index] != NULL)
    	{
    	    Wlist *temp = head[index];

    	    //Compare the words at each node with new word
    	    while(temp)
    	    {
    		if(!strcmp(temp->word, word))
    		{
    		    update_word_count(&temp, filename);
    		    flag = 0;
    		    break;
    		}
    		temp = temp->link;
    	    }
    	}  
    	if(flag == 1)
    	{
    	    //Function() is called when words are not repeated
    	    insert_at_last(&head[index], word);
    	}
    }
    printf("Successfully created database for %s file\n", filename);
}

//Function to update the word count
int update_word_count(Wlist **head, char *file_name)
{
    Ltable* l_temp = (*head)->Tlink, *prev = NULL;
    while(l_temp)
    {
	//Check whether filenames same or not
	if(!strcmp(l_temp->file_name, file_name))
	{
	    //Update word count
	    l_temp->word_count++;
	    return SUCCESS;
	}
	prev = l_temp;
	l_temp = l_temp->table_link;
    }
    
    //Increment and update the file count
    (*head)->file_count++;

    //Adding new node in link table
    Ltable* new_link_table_node = malloc(sizeof(Ltable));

    //Error check
    if(new_link_table_node == NULL)
    {
    	return FAILURE;
    }

    //Upadating link table value
    strcpy(new_link_table_node->file_name, file_name);
    new_link_table_node->word_count = 1;
    new_link_table_node->table_link = NULL;

    //Establishing the link between prev and new
    prev->table_link = new_link_table_node;
    return SUCCESS;
}

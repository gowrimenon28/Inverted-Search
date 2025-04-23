#include "inverted_search.h"

void search_database( Wlist *head, char *word)
{
    //check empty or not

    if(head == NULL)
    {
	    printf("Search word is not available in the list as list is empty\n");
	    return;
    }
    // Check empty or not and traverse the list
    while(head)
    {
    	//Compare the search word with available words	
        if(!(strcmp(head->word, word)))
	    {
	        printf("Word %s is present in %d file\n " , head->word , head->file_count);

	        Ltable *Thead = head->Tlink;

	        while(Thead)
	        {
	    	    printf("In File : %s\t%d times \n", Thead->file_name , Thead->word_count);
		        Thead = Thead->table_link;
	        }
	        return;
	    }
	    head = head->link;
    }
    printf("Error: Search word is not found in list \n");
}




#include "inverted_search.h"

void display_database (Wlist *head[])
{
    //Printing the database
    printf("[index] [word] filecount file/s : file_name word_count\n");
    printf("\n--------------------------------------------------\n");
    
    for (int i = 0 ; i < 27; i++)
    {
	Wlist* temp = head[i];
       
	//Traversing through the list till last node of Wlist
        while (temp != NULL)
        {
            printf("[%d] [%s] %d files:\t", i, temp->word, temp->file_count);
            Ltable* Thead = temp->Tlink;

	    //Traverse through link table
            while (Thead != NULL)
            {
                printf("%s %d\t",Thead->file_name, Thead->word_count);
                Thead = Thead->table_link;
            }
            printf("\n");           
	        //Moving temp to next node
            temp = temp->link;
        }
    }
    printf("\n--------------------------------------------------\n");
}




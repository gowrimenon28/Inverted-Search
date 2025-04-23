#include "inverted_search.h"

void update_database(Wlist* head[], Flist** f_head)
{
    int empty;
    char file_name[FNAME_SIZE];
    //input
    printf("Enter the filename do you want to add in Database: ");
    scanf("%s", file_name);
        
    //Validate the file its empty or not
    empty = isFileEmpty(file_name);
    if (empty == FILE_NOTAVAILABLE)
    {
	    printf("The file %s is not available\n", file_name);
	    printf("Hence we are not adding this into File Linked List\n");
	    return;
    }
    else if (empty == FILE_EMPTY)
    {
	    printf("The file %s is Empty\n", file_name);
	    printf("Hence we are not adding %s into File Linked List\n", file_name);
	    return;
    }
    else
    {
	    //File is valid then add it to the linked list
       	int result = to_create_list_of_files (f_head, file_name);	        
        if (result == SUCCESS)
	    {
	        printf("Successful in Inserting file %s into the File Linked List\n",file_name);
	    }
	    else if (result == REPEATATION)
	    {
	        printf("This file %s is Repeated\n", file_name);
	        printf("Hence we are not adding %s into file Linked List\n", file_name);
	        return;
	    }
	    else
	    {
	        printf("Failed to add the file into the File Linked List");
	        return;
	    }   
    }
    //After successful insertion of file into the file linked list
    Flist* f_temp = *f_head;
    while (f_temp)
    {	
        //Compare the files of Flist
    	if (!strcmp(f_temp->file_name, file_name))
	    {
	        create_database(f_temp, head);
	        return;
	    }
	    f_temp = f_temp->link;
    }
    printf("Database updated successfully!!\n");
}





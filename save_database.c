#include "inverted_search.h"

void save_database( Wlist *head[])
{
    //prompt the user
    char file_name[FNAME_SIZE];
    printf("Enter the filename you want save in database\n");
    scanf("%s" , file_name);

    //open the file

    FILE *fptr = fopen(file_name , "w");
    
    if (fptr == NULL)
    {
	printf("Error: File not available\n");
        return;
    }
    fprintf(fptr,"[index] [word] filecount file/s : file_name word_count\n");
    fprintf(fptr,"\n--------------------------------------------------\n");
    for (int index = 0; index < 27; index++)
    {
        Wlist* temp = head[index];
	
	//Checking the Wlist empty or not
        while (temp != NULL)
        {
            fprintf(fptr,"[%d] [%s] %d files:\t", index, temp->word, temp->file_count);
            printf("hell\n");
            Ltable* l_temp = temp->Tlink;
            while (l_temp != NULL)
            {
                fprintf(fptr,"%s %d\t",l_temp->file_name, l_temp->word_count);
                l_temp = l_temp->table_link;
            }
            fprintf(fptr,"\n");
            
	        //Moving temp to next node
            temp = temp->link;
        }
    }
    fprintf(fptr,"\n--------------------------------------------------\n");
    printf("Database saved successfully in %s\n", file_name);
    fclose(fptr);
}


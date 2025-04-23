/*-----------------------------------------------
Name : Gowri menon
Date : 1-09-24
Project Title : Inverted Search
Sample Input : ./output.exe file1.txt file2.txt
Sample Output :
Successful in Inserting file file1.txt into the File Linked List
Successful in Inserting file file2.txt into the File Linked List
Successful in Inserting file file3.txt into the File Linked List
1. Create Database
2. Display Database
3. Update Database
4. Search
5. Save Database
Enter your Choice: 1
Successfully created database for file1.txt file
Successfully created database for file2.txt file
Successfully created database for file3.txt file
Do you want to continue (y/n): y
1. Create Database
2. Display Database
3. Update Database
4. Search
5. Save Database
Enter your Choice: 2
[index] [word] filecount file/s : file_name word_count

--------------------------------------------------
[1] [bye] 1 files:	file1.txt 1	
[7] [hi] 3 files:	file1.txt 1	file2.txt 1	file3.txt 1	
[7] [hello] 3 files:	file1.txt 1	file2.txt 1	file3.txt 1	
[7] [how] 1 files:	file1.txt 1	
[7] [hey] 2 files:	file1.txt 1	file2.txt 1	
[14] [oi] 2 files:	file1.txt 1	file2.txt 1	

--------------------------------------------------
Do you want to continue (y/n): y
1. Create Database
2. Display Database
3. Update Database
4. Search
5. Save Database
Enter your Choice: 3
Enter the filename you want to add in Database: file2.txt
This file file2.txt is Repeated
Hence we are not adding file2.txt into file Linked List
Do you want to continue (y/n): y
1. Create Database
2. Display Database
3. Update Database
4. Search
5. Save Database
Enter your Choice: 4
Enter the word you want to search: hi
Word hi is present in 3 file
 In File : file1.txt	1 times 
In File : file2.txt	1 times 
In File : file3.txt	1 times 
Do you want to continue (y/n): y
1. Create Database
2. Display Database
3. Update Database
4. Search
5. Save Database
Enter your Choice: 5
Enter the filename you want save in database
save1.txt
Database saved successfully in save1.txt
Do you want to continue (y/n): n
------------------------------------------------*/

#include "inverted_search.h"

int main(int argc, char *argv[])
{
    system("clear");
    
    //Validate CLA
    //If only one CLA is passed then throw an error
    if(argc == 1)
    {
	printf("Enter the valid number of arguments \n");
	printf("./SList.exe file1.txt file2.txt ..........\n");
	return 0;
    }
    //Create file list
    //Declare the file head 
    Flist *f_head = NULL;
  
    //validate the files
    file_validation_n_file_list(&f_head, argv);
    
    if(f_head == NULL)
    {
	printf("NO files are available in the file linked list\n");
	printf("Hence the process terminated\n");
	return 1;
    }

    //Prompt the user choice 

    int choice;
    char option;
    char word[WORD_SIZE];
    Wlist *head[27] = {NULL};

    do
    {
        printf("Select your choice among following options:\n1. Create Database\n2. Display Database\n3. Update Database\n4. Search\n5. Save Database\nEnter your Choice: ");
        scanf("%d", &choice);
	
        switch (choice)
        {
        
            //create    
            case 1:
 	            create_database(f_head, head); 	             
                break;        
            //display            
            case 2:
	            display_database(head);
	            break;
            //update        
	        case 3:
	            update_database(head, &f_head);
	            break;
            //search        
             case 4:
 	            //clearing input buffer
	            printf("Enter the word you want to search: ");
	            scanf("%s",word);
	            search_database(head[tolower(word[0])%97],word);
	            break;
    	    //save database
    	    case 5:   
	            save_database(head);
	            break;        
	        default:
	            break;
	}
    printf("Do you want to continue (y/n): ");
	getchar();        
    scanf("%c",&option);
    } while (option == 'Y'|| option == 'y');
    
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fu.h"
#define True 1


void main () {


//______________________

User* head = (User*)malloc(sizeof(User));
head->name = "Admin" ;
head->pass = "Admin" ;
head->next = NULL ;


Post* first = (Post*)malloc(sizeof(Post)) ;
first->name = "Admin" ;
first->content = "Nothing" ;
first->like = 0 ;
first->id = 0 ;
first->next = NULL ;


//______________________

    system("cls") ;
    printf("Welcome to UT TOTI") ;
    getchar() ;

    int POST_ID = 0 ;

    while (True)
    {
        system("cls") ;
        printf("Use Correct Command in Terminal\n") ;
        printf("You Can Also use Help to see Commands :\n") ;

        char * command_line = (char*)malloc(40*sizeof(char)) ;
        
        gets(command_line) ;
        int order = -1 ;
        order = check_order(command_line) ;
        printf("%d" , order) ;
        if (order == 4)
        {
            break;
        }
        Call_functions(order , head  , first , &POST_ID) ;    
        getchar() ;
        free(command_line) ;
    }
    


    printf("hope you Enjoyed UT TOTI\n") ;

    getchar() ;



}
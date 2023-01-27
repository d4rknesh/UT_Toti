#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define True 1


struct User
{
    char* name ;
    char* pass ;
    int* post_id_Array ;
    struct User* next ;
} ;

typedef struct User User ;

struct Post
{
    char* name ;
    char* content ;
    int like ;
    int id ;
    struct Post *next ;
};

typedef struct Post Post ;
//________________________________


void AddNew_user(char *name , char* pass  ,  User* head) {


    int count = 0 ;
    for (User* check = head ; check != NULL ; check = check->next)      
        if (strcmp(check->name , name) == 0)
            count ++ ;
    if (count == 0){        
        User* new = (User*)malloc(sizeof(User));
        new->name = name ;
        new->pass = pass ;
        new->post_id_Array = (int*)calloc(20,sizeof(int)) ;
        new->next = NULL ;
        printf("user name :%s\n" , name) ;
        printf("password :%s\n" , pass) ;
        
        User* current ;
        for (current= head ; current->next != NULL ; current = current->next) ;
        current->next = new ;
        printf("\nyour account created successfully!\n") ;
    }
    else
    {
        printf("Error !\nUser with this name found !\n") ;
        getchar() ;
    }
    

}


void AddNew_post(char* name , char* content , int* POST_ID , Post* first){
    Post* post = (Post*)malloc(sizeof(Post)) ;
    post->content = content ;
    post->name = name ;
    post->id = *(POST_ID) ;
    post->next = NULL ;
    printf("writer :%s\n" , name) ;
    printf("content :%s\n" , content) ;
    printf("content :%s\n" , post->content) ;
    printf("id = %d\n\n" , *(POST_ID)) ;

    Post* current ;
    for (current = first ; current->next != NULL ; current = current->next) ;
    current->next = post ;    

}

//_________________________________

int check_order(char* Command_line){

    if (strcmp(Command_line , "signup") == 0)
        return 1 ;
    else if (strcmp(Command_line , "login") == 0)
        return 2 ;
    else if (strcmp(Command_line , "help") == 0) 
        return 3 ;
    else if (strcmp(Command_line , "exit") == 0)
        return 4 ;
    else
        return 0;
}












void Call_functions (int order , User* head , Post* first , int* POST_ID) {

    if (order == 1)
        signup (head) ;
    else if (order == 2) 
        login (head , first , POST_ID) ;
    else if (order == 3)
        help() ;
    else if (order == 0)
        printf("Error !\n") ;
        getchar() ;
}




void signup (User* head) {

    system("cls") ;
    
    printf("Enter Username (less than 15 char) :\n") ;
    char* name = (char*)malloc(15*sizeof(char)) ;
    gets(name) ;

    printf("\nSet the password (less than 15) :\n") ;
    char* pass = (char*)malloc(15*sizeof(char)) ;
    gets(pass) ;

    AddNew_user(name , pass , head) ;


}










void help() {

    printf("\tU T TO TI Help:\n\n\tUse login to Login\n\tUse signup for Signing Up\n") ;
    printf("\tUse delete to delete post when you loggedin\n\tUse like to like a post\n") ;
    printf("\tUse Logout to logout from your account\n") ;
}











void Clear_Command_line (char* Command_line) {
    for (int i = 0; i < 100 ; i++)
        Command_line[i] = '\0' ;
      
}






//_____________________________________________________________________





int check_order_login(char* command_line_login){

    
    if (strcmp(command_line_login , "signup") == 0 || strcmp(command_line_login , "login") == 0 || strcmp(command_line_login , "exit") == 0 )
        return 1 ; // 1 : logout first ; error
    else if (strcmp(command_line_login , "help") == 0) 
        return 3 ; // 3 : help
    else if (strcmp(command_line_login , "logout") == 0)
        return 4 ; // 4 : logout
    else if (strcmp(command_line_login , "post") == 0)
        return 5 ; // 5 : posting
    else if (strcmp(command_line_login , "logout") == 0)
        return 6 ; // 6 : logout
    else if (strcmp(command_line_login , "info") == 0)
        return 7 ;
    else if (strcmp(command_line_login , "delete") == 0)
        return 8 ;
    else
        return 0;
    
}



void Call_function_login (int order_login , User* head , Post* first , User* loggedin , int* POST_ID) {


    // switch (order_login)
    // {
    // case 1:

    //     printf("at first you should log out from your account\n") ;
    //     getchar();
    //     break;
    
    // case 3 :
    //     help() ;
    //     getchar() ;
    //     break;
    // case 5 :
    //     post(loggedin , POST_ID , first) ;
    //     getchar() ;
    //     break; 
    // case 7 :
    //     info(loggedin , first) ;
    //     getchar() ;
    //     break;
    // case 8 :
    //     delete(loggedin , first) ;
    //     getchar() ;
    //     break;

    // case 0 :
    //     printf("Error !\n") ;
    //     getchar() ;
    // default:
    //     printf("Error !\n") ;
    //     getchar() ;
    //     break;
    // }

    if (order_login == 1){
        printf("at first you should log out from your account\n") ;
        getchar();
    }
    else if (order_login == 3){
        help() ;
        getchar() ;
    }
    else if (order_login == 5) {   
        post(loggedin , POST_ID , first) ;
        getchar() ;
    }
    else if (order_login == 7)
    {
        info(loggedin , first) ;
        getchar() ;
    }

    else if (order_login == 8)
    {
        delete(loggedin , first) ;
        getchar() ;
    }

    else if (order_login == 0)
        printf("Error !\n") ;
        getchar() ;    

}













void login(User* head , Post* first , int* POST_ID) {

    system("cls") ;
    
    printf("Enter Username :\n") ;
    char* Enter_name = (char*)malloc(15*sizeof(char)) ;
    gets(Enter_name) ;


    printf("\nEnter Password :\n") ;
    char* Enter_pass = (char*)malloc(15*sizeof(char)) ;
    gets(Enter_pass) ;


    getchar() ;

    User* current ;
    for (current = head ; current != NULL ; current = current->next) {
        if ( strcmp(Enter_name , current->name) == 0 && strcmp(Enter_pass , current->pass) == 0){
            
            printf("Correct!\n") ;
            free(Enter_name); 
            free(Enter_pass);             
            getchar() ;
            User* loggedin = current ;
            while (True)
            {
                system("cls") ;
                printf("you logged in to your account successfully\n") ;

                char* Command_line_login = (char*)malloc(100*sizeof(char)) ;
                gets(Command_line_login) ;
                int order_login = -1 ;
                order_login = check_order_login(Command_line_login) ;
                free(Command_line_login) ;
                if (order_login == 4)
                    break ;
                Call_function_login(order_login , head , first , loggedin , POST_ID ) ;

                getchar() ;
            }   
        }
    }


    printf("\nError") ;
    
    


}





void post (User* loggedin , int* POST_ID , Post* first) {
    system("cls") ;
    printf("Type what you want to post : \n") ;

    char* content = (char*)malloc(50*sizeof(char)) ;
    gets(content) ;
    printf("%s" , content) ;
    *(POST_ID) = *(POST_ID) + 1 ;
    for (int i = 0 ; i < 20 ; i++)
    {
        if (*(loggedin->post_id_Array + i ) == 0 )
        {
            *(loggedin->post_id_Array + i) = *(POST_ID) ;
            // printf("\nYou Posted this :\n%s\n" , content) ;
            // printf("with this ID :%d\n" , *POST_ID) ;
            // printf("creator :%s\n" , loggedin->name) ;
            AddNew_post(loggedin->name , content , POST_ID , first) ;
            getchar();
            break ;
        }   
    }
    
}



void info (User*loggedin  , Post* first) {

    printf("User Name :%s\n" , loggedin->name) ;

    // printf("id from array\n");
    // printf("--%d--\n" , *(loggedin->post_id_Array + 0)) ;
    // printf("--%d--\n" , *(loggedin->post_id_Array + 1)) ;
    // printf("--%d--\n" , loggedin->post_id_Array[2]) ;

    for (int i = 0 ; i < 20 && loggedin->post_id_Array[i] != 0 ; i++)
    {
        Post* post ;
        for (post = first ; post != NULL ; post = post->next)
        {
            if (post->id == *(loggedin->post_id_Array + i))
            {
                printf("Post id : %d\n" , post->id) ;
                printf("Content : %s\n" , post->content) ;
                printf("____________________________\n") ;
            }
            
        }
        
    }



}



void delete (User* loggedin , Post* first) {

    printf("which post do you want to delete ?\n") ;
    printf("Type the id :\n") ;

    int entered_id ;

    if (scanf("%d" , entered_id))
    {
        
        int counter = 0 ;
        for (int i = 0; i < 20 && loggedin->post_id_Array[i] != 0; i++)
            if (loggedin->post_id_Array[i] == entered_id)
                counter++ ;
        
        if (counter == 1)
        {
            delete_post(first , loggedin , entered_id) ;
            printf("You deleted post sucsessfully!\n") ;
        }
        
        else
        {
            printf("You Dont have access to this id !\n") ;
        }


        
    }
    else {

        printf("Enter Id not trying to find bug :) !\n") ;
    }





}






void delete_post(Post* first , User* loggedin , int id ) {


    Post* befor ;
    Post* delete ;
    Post* after ;

    int count = 0 ;
    for ( befor = first ; befor != NULL ; befor = befor->next ) 
        if (befor->id == id)  
            count ++ ;
        
    if (count == 1)
    {

    

    for ( befor = first ; befor->id != id  && befor != NULL ; befor = befor->next ) ;
    delete = befor->next ; 
    after = delete->next ;
    // befor->delete->after 
    befor->next = after ;
    // befor->after  , delete->after
    free (delete) ;

    }
    else{

        printf("No Id found !\n") ;
    }

    for (int i = 0; i < 20 ; i++)
        if (*(loggedin->post_id_Array + i) == id)
            *(loggedin->post_id_Array + i) = 0 ;
        
    

}
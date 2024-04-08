#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define ENTER 13
#define TAB 9
#define BACKSPACE 8

// construct structure for user
struct user{
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
};

void handleInput(char ch[50]){
    fgets(ch,50,stdin);
    ch[strlen(ch) - 1] = 0;
}

void generateUsername(char email[50], char username[50]){
    for(int charIndex = 0; charIndex < strlen(email); charIndex++){
        if(email[charIndex] == '@'){
            break;
        }
        else
        {
            username[charIndex] = email[charIndex];
        }
    }
}

void handlePassword(char password[50]){
    int characterIndex; 
    char character = password[0];
    while(1){
        character = getch();
        if(character == ENTER || character == TAB ){
            password[characterIndex] = '\0';
            break;
        }
        else if(character == BACKSPACE){
            if(characterIndex > 0){
                characterIndex--;
                printf("\b \b");
            }
        }else{
            password[characterIndex++] = character;
            printf("* \b");
        }
    }
}

int main(){

    int opt;
    struct user user;
    char confirmPassword[50];

    printf("\n\t\t---------Welcome to the Authentication System-----------");
    printf("\nPlease choose your operation");
    printf("\n1.Sign Up");
    printf("\n2.Login");
    printf("\n3.Exit");

    printf("\n\nYour choice:\t");
    scanf("%d",&opt);
    fgetc(stdin);

    switch(opt){
        case 1:
            printf("Enter your full name:\t");
            handleInput(user.fullName);
            printf("Enter your email:\t");
            handleInput(user.email);
            printf("Enter your contact no:\t");
            handleInput(user.phone);
            printf("Enter your password:\t");
            handlePassword(user.password);
            // printf("%s",user.password); // check password being input
            printf("\nConfirm your password:\t");
            handlePassword(confirmPassword);

            if(!strcmp(user.password, confirmPassword)){
                printf("\nYour passwords match.");
            }
            else
            {
                printf("\nYour passwords do not match.");
            }
    }

    return 0;
}
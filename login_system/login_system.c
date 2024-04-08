#include<stdio.h>
#include<conio.h>
#include<windows.h>

// construct structure for user
struct user{
    char fullname[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
};

void takeInput(char ch[50]){
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

int main(){

    int opt;
    
    printf("\n\t\t\t\t---------Welcome to the Authentication System-----------");
    printf("\nPlease choose your operation");
    printf("\n1.Sign Up");
    printf("\n2.Login");
    printf("\n3.Exit");

    printf("\n\nYour choice:\t");
    scanf("%d",&opt);
    fgetc(stdin);

    return 0;
}
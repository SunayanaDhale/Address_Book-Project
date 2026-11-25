#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"


Contact contacts[100];
int count=0;

void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the chosen criteria
    if(count==0){
        printf("No contacts available\n");
        return;
    }
    for(int i=0; i<count; i++){
        for(int j=i+1; j<count; j++){
            int result=0;
            if(sortCriteria==0)
                result=strcmp(contacts[i].name, contacts[j].name);
            else if(sortCriteria==1)
                result=strcmp(contacts[i].phone, contacts[j].phone);
            else if(sortCriteria==2)
                result=strcmp(contacts[i].email, contacts[j].email);
            else if(sortCriteria==3){
                if(contacts[i].id > contacts[j].id)
                    result = 1;
                else if(contacts[i].id < contacts[j].id)
                    result = -1;
            }

            if(result>0){
                Contact temp=contacts[i];
                contacts[i]=contacts[j];
                contacts[j]=temp;
            }
        }
    }
    printf("\n");
    printf("********** Contact List **********\n");
    for(int i=0; i<count; i++){
        printf("\n");
        printf("Contact %d\n",i+1);
        printf("\n");
        printf("Contact ID : %d\n",contacts[i].id);
        printf("Name : %s\n",contacts[i].name);
        printf("Phone : %s\n",contacts[i].phone);
        printf("Email ID : %s\n",contacts[i].email);
        printf("Address : %s\n",contacts[i].address);
        printf("Date of Birth : %s\n", contacts[i].birthday);
        printf("Relationship : %s\n",contacts[i].relationship);
    }
    printf("\n");
    printf("***********************************\n");
}

void initialize(AddressBook *addressBook) {
    count=0;
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    if(count>=100){
        printf("Contact list is full\n");
        return;
    }
    char name[50];
    char phone[12];
    char email[50];
    char address[100];
    char birthday[11];
    char relationship[30];
    int maxid=100;
    printf("Enter name : ");
    scanf(" %49[^\n]",name);
    printf("Enter phone number : ");
    scanf("%11s",phone);
    printf("Enter email id : ");
    scanf("%49s",email);
    printf("Enter address : ");
    scanf(" %99[^\n]",address);
    printf("Enter date of birth (DD-MM-YYYY) : ");
    scanf("%10s",birthday);
    printf("Enter relationship : ");
    scanf(" %29[^\n]",relationship);
    printf("\n");
    printf("****************************\n");
    int flagDot=0, flagAt=0;
    for(int i=0; email[i]!='\0';i++){
        if(email[i]=='@'){
            flagAt=1;
        }
        if(email[i]=='.'){
            flagDot=1;
        }
    }
    printf("\n");
    
    if(flagDot==1 && flagAt==1){
        strcpy(contacts[count].name,name);
        strcpy(contacts[count].phone,phone);
        strcpy(contacts[count].email,email);
        strcpy(contacts[count].address, address);
        strcpy(contacts[count].birthday, birthday);
        strcpy(contacts[count].relationship, relationship);
                
        for(int i=0; i<count; i++){
            if(contacts[i].id>maxid){
                maxid=contacts[i].id;
            }
        }
        contacts[count].id=maxid+1;
        printf("\n");
        printf("********** Contact Created **********\n");
    
        printf("Contact ID : %d\n", contacts[count].id);
        printf("Name : %s\n", contacts[count].name);
        printf("Phone number : %s\n", contacts[count].phone);
        printf("Email ID : %s\n", contacts[count].email);
        printf("Address : %s\n", contacts[count].address);
        printf("Date of Birth : %s\n", contacts[count].birthday);
        printf("Relationship : %s\n", contacts[count].relationship);
    
        printf("*************************************\n");
        count++;

    }else{
        printf("\nInvalid email\n");
    }
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    char search[50];
    int found=0;
    printf("Enter what you want to search : ");
    scanf(" %49[^\n]",search);
    for(int i=0; i<count; i++)
    if(strcmp(search,contacts[i].name)==0 || 
       strcmp(search,contacts[i].phone)==0 || 
       strcmp(search,contacts[i].email)==0){
        printf("Contact found\n");
        printf("Contact ID : %d\n",contacts[i].id);
        printf("Name : %s\n",contacts[i].name);
        printf("Phone : %s\n",contacts[i].phone);
        printf("Email ID : %s\n",contacts[i].email);
        printf("Address : %s\n",contacts[i].address);
        printf("Date of Birth : %s\n",contacts[i].birthday);
        printf("Relationship : %s\n",contacts[i].relationship);
        printf("\n");
        printf("*********************************\n");
        found=1;
        break;
    }
    if(found==0){
        printf("Contact not found\n");
    }
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    char search[50];
    int found=0;
    printf("Enter name to edit : ");
    scanf(" %[^\n]",search);
    for(int i=0; i<count; i++){
        if(strcmp(search,contacts[i].name)==0){
            printf("contact found\n");
            printf("Enter new name : ");
            scanf(" %49[^\n]",contacts[i].name);

            printf("Enter new phone number : ");
            scanf("%11s",contacts[i].phone);

            printf("Enter new email ID : ");
            scanf("%49s",contacts[i].email);

            printf("Enter new address : ");
            scanf(" %99[^\n]",contacts[i].address);

            printf("Enter new date of birth : ");
            scanf("%10s",contacts[i].birthday);

            printf("Enter new relationship : ");
            scanf(" %29[^\n]",contacts[i].relationship);

            printf("\n");
            printf("**********Contact edited successfully**********\n");
            found=1;
            break;
        }
    }
    if(found==0){
        printf("Contact not Found\n");
    }
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    char search[50];
    int found=0;
    printf("Enter name to delete : ");
    scanf(" %[^\n]",search);
    for(int i=0; i<count; i++){
        if(strcmp(search, contacts[i].name)==0){
            for(int j=i; j<count-1; j++){
                contacts[j]=contacts[j+1];
            }
            count--;
            printf("\n");
            printf("**********contact deleted successfully**********\n");

            found=1;
            break;
        }
    }               
    if(found==0){
        printf("\n contact not found\n");
    }
   
}

#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fp=fopen("Contact.txt","w");
    if(fp==NULL){
        printf("file connot br opened\n");
        return ;
    }
    for(int i=0; i< count; i++){
        fprintf(fp,"ID : %d\nName : %s\nPhone : %s\nEmail ID : %s\nAddress : %s\nDate of Birth : %s\nRelationship : %s\n",
            contacts[i].id,contacts[i].name,contacts[i].phone,contacts[i].email,contacts[i].address,contacts[i].birthday,contacts[i].relationship);
        fprintf(fp,"\n");
    }
    fclose(fp);
    printf("Contact saved Successfully\n");
    printf("\n*****************************\n");
  
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fp=fopen("Contact.txt","r");
    if(fp==NULL){
        printf("File not found\n");
        return;
    }
    while(fscanf(fp," %d,%49[^,],%11[^,],%49[^\n],%99[^\n],%10s,%29[^\n]",
        &contacts[count].id,contacts[count].name,contacts[count].phone,contacts[count].email,contacts[count].address,contacts[count].birthday,contacts[count].relationship)==3){
        count++;
    }
    fclose(fp);
    printf("Contact load successfully\n");
    printf("\n******************************\n");
}

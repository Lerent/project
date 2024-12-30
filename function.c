// Noi di trien khai cac ham
#include <stdio.h>
#include <string.h>
#include "function.h"

void Menu() {
	printf("\n***Bank Account Management***\n");
	printf("\n-----------Menu------------\n");
	printf("=============================\n");
	printf("[1]. Add a new user.\n");
	printf("[2]. Show all user.\n");
	printf("[3]. Show detail user.\n");
	printf("[4]. Search user.\n");
	printf("[5]. Lock (UnLock) an user.\n");
	printf("[6]. User guideline\n");
	printf("[7]. About us\n");
	printf("[8]. Exit the program\n");
	printf("==============================\n");
	printf("Enter the choice: ");
}

void newUser() {
	FILE *ptr = fopen("adduser.bin", "wb");
	if (ptr == NULL) {
		printf("Error opening file\n");
		return;
	}
	
	int numberUsers;
    printf("Enter the number of user you want to add: ");
    scanf("%d", &numberUsers);
    getchar();

    for (int i = 0; i < numberUsers; i++) {
        adduser newUser;
        printf("\nUser %d:\n", i + 1);
		printf("Enter user ID: ");
	    scanf("%d", &newUser.id);
	    getchar();
	    printf("Enter name: ");
	    fgets(newUser.name, sizeof(newUser.name), stdin);
	    newUser.name[strcspn(newUser.name, "\n")] = "\0";
	    printf("Enter age: ");
	    scanf("%d", &newUser.age);
	    getchar();
	    printf("Enter gender: ");
	    fgets(newUser.gender, sizeof(newUser.gender), stdin);
	    newUser.gender[strcspn(newUser.gender, "\n")] = "\0";
	    printf("Enter phone number: ");
	    scanf("%d", &newUser.phoneNumber);
	    getchar();
	    printf("Enter email: ");
	    fgets(newUser.email, sizeof(newUser.email), stdin);
	    newUser.email[strcspn(newUser.email, "\n")] = "\0";
	}	
    fwrite(&newUser, sizeof(adduser), 1, ptr);
    fclose(ptr);
    printf("\n*User added successfully*\n");
}

void show() {
	FILE *ptr= fopen("adduser.bin", "rb");
	if(ptr == NULL) {
		printf("Error opening file\n");
        return;
	}
	
	adduser newUser;
	printf("-------------------------------------\n");
    printf("| ID   | Name                 | Age  |\n");
    printf("-------------------------------------\n");
    
    while (fread(&newUser, sizeof(adduser), 1, ptr)) {
        printf("| %-4d | %-20s | %-3d |\n", newUser.id, newUser.name, newUser.age);
    }
    printf("--------------------------------------\n");
    fclose(ptr);
}

void showUser() {
    FILE *ptr = fopen("adduser.bin", "rb");
    if (ptr == NULL) {
        printf("Error opening file\n");
        return;
    }

    adduser newUser;
    printf("----------------------------------------------------------------------------------------------\n");
    printf("| ID   | Name                  | Age   | Gender   | Email                     | Phone        |\n");
    printf("----------------------------------------------------------------------------------------------\n");

    while (fread(&newUser, sizeof(adduser), 1, ptr)) {
        printf("| %-4d | %-20s | %-3d | %-8s | %-20s | %-10s |\n",
               newUser.id, newUser.name, newUser.age, newUser.gender, newUser.email, newUser.phoneNumber);
    }
    printf("----------------------------------------------------------------------------------------------\n");
    fclose(ptr);
}

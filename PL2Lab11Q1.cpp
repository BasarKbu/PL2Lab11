#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

// Linked List example.
/*
A) Program will have a main menu with options below:
1-Add new record
2-List records
3-Update record
4-Calculate class average 
5-Show best student record according to average
B) Listing will be according to the student number.
C) Updating records will be carried out according to student number
*/

struct student {
    int stdNo;
    char name[20];
    float midterm;
    float final;
    struct student* next;
};

typedef struct student Student;
Student* head = NULL;

void AddRecord(char x[], float y, float z, int q) {
    Student* temp = head;
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, x);
    newStudent->midterm = y;
    newStudent->final = z;
    newStudent->stdNo = q;
    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newStudent;
    }
}

void Print() {
    printf("\n\n");
    Student* temp = head;
    if (temp == NULL) {
        printf("Your list is empty... \n");
    } else {
        while (temp != NULL) {
            printf("Name: %s\n", temp->name);
            printf("Midterm Grade: %f\n", temp->midterm);
            printf("Final Grade: %f\n", temp->final);
            printf("Student number: %d\n", temp->stdNo);
            temp = temp->next;
        }
    }
}

void Average() {
    Student* temp = head;
    int cnt = 0;
    float sum = 0.0;
    if (temp == NULL) {
        printf("Your list is empty.. \n");
    } else {
        while (temp != NULL) {
            cnt++;
            sum += temp->midterm * 0.4 + temp->final * 0.6;
            temp = temp->next;
        }
        printf("The average of the class is: %f\n", sum / cnt);
    }
}

void Success() {
    if (head == NULL) {
        printf("The list is empty..\n");
        return;
    }

    Student* temp = head;
    Student* bestStudent = head;
    float bestAverage = head->midterm * 0.4 + head->final * 0.6;

    while (temp != NULL) {
        float average = temp->midterm * 0.4 + temp->final * 0.6;
        if (average > bestAverage) {
            bestAverage = average;
            bestStudent = temp;
        }
        temp = temp->next;
    }

    printf("The most successful student's name is: %s\n", bestStudent->name);
    printf("The most successful student's midterm grade is: %f\n", bestStudent->midterm);
    printf("The most successful student's final grade is: %f\n", bestStudent->final);
    printf("The most successful student's student number is: %d\n", bestStudent->stdNo);
    printf("The most successful student's average is: %f\n", bestAverage);
}

void Update(int q) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->stdNo == q) {
            printf("Enter the new name: ");
            scanf("%s", temp->name);
            printf("Enter the new Midterm grade: ");
            scanf("%f", &temp->midterm);
            printf("Enter the new Final grade: ");
            scanf("%f", &temp->final);
            printf("Record updated successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Student with student number %d not found.\n", q);
}

int main() {
    char Name[20];
    float Midterm, Final;
    int option;
    int No;

    while (1) {
        printf("\nMenu:\n");
        printf("1 -> Adds a new record.\n");
        printf("2 -> Lists all the records you have.\n");
        printf("3 -> Updates the List.\n");
        printf("4 -> Calculates the average of the class.\n");
        printf("5 -> Show the most successful student according to the List.\n");
        printf("6 -> You exit from the program.\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("You are adding a new record...\n");
                printf("Enter your name: ");
                scanf("%s", Name);
                printf("Enter your Midterm grade: ");
                scanf("%f", &Midterm);
                printf("Enter your Final grade: ");
                scanf("%f", &Final);
                printf("Enter your student number: ");
                scanf("%d", &No);
                AddRecord(Name, Midterm, Final, No);
                break;
            case 2:
                printf("You are listing all the records you have.\n");
                Print();
                break;
            case 3:
                printf("You are updating a record...\n");
                printf("Enter the student number: ");
                scanf("%d", &No);
                Update(No);
                break;
            case 4:
                printf("You are calculating the average of the class.\n");
                Average();
                break;
            case 5:
                printf("Showing the most successful student..\n");
                Success();
                break;
            case 6:
                printf("You are exiting the program.\n");
                exit(0);
                break;
            default:
                printf("There isn't an option such as you have entered.\n");
        }
    }

    getch();
    return 0;
}


/*
 * TASK 3: High - Student Management System
 * Menu-driven C program to manage student records.
 * Features: Add, Delete, Update, Search, Display records.
 * Uses structures + file handling to store data permanently.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILENAME "students.dat"

typedef struct {
    int rollNo;
    char name[50];
    char course[30];
    float marks;
} Student;

/* Add a new student record by appending to the file */
void addStudent() {
    FILE *fp = fopen(FILENAME, "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Course: ");
    scanf(" %[^\n]", s.course);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Student record added successfully!\n");
}

/* Display all student records */
void displayStudents() {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    Student s;
    int found = 0;
    printf("\n%-10s %-20s %-15s %-10s\n", "Roll No", "Name", "Course", "Marks");
    printf("--------------------------------------------------------\n");
    while (fread(&s, sizeof(Student), 1, fp)) {
        printf("%-10d %-20s %-15s %-10.2f\n", s.rollNo, s.name, s.course, s.marks);
        found = 1;
    }
    if (!found) {
        printf("No records found!\n");
    }
    fclose(fp);
}

/* Search for a student by roll number */
void searchStudent() {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    int rollNo, found = 0;
    printf("Enter Roll Number to search: ");
    scanf("%d", &rollNo);

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.rollNo == rollNo) {
            printf("\nRecord Found:\n");
            printf("Roll No: %d\nName: %s\nCourse: %s\nMarks: %.2f\n",
                   s.rollNo, s.name, s.course, s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll No %d not found!\n", rollNo);
    }
    fclose(fp);
}

/* Update an existing student's record */
void updateStudent() {
    FILE *fp = fopen(FILENAME, "rb+");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    int rollNo, found = 0;
    printf("Enter Roll Number to update: ");
    scanf("%d", &rollNo);

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.rollNo == rollNo) {
            printf("Enter new Name: ");
            scanf(" %[^\n]", s.name);
            printf("Enter new Course: ");
            scanf(" %[^\n]", s.course);
            printf("Enter new Marks: ");
            scanf("%f", &s.marks);

            /* Move file pointer back to the start of this record */
            fseek(fp, -(long)sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);

            found = 1;
            printf("Record updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Student with Roll No %d not found!\n", rollNo);
    }
    fclose(fp);
}

/* Delete a student record by roll number */
void deleteStudent() {
    FILE *fp = fopen(FILENAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (fp == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int rollNo, found = 0;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &rollNo);

    Student s;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.rollNo != rollNo) {
            fwrite(&s, sizeof(Student), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILENAME);
    rename("temp.dat", FILENAME);

    if (found) {
        printf("Record deleted successfully!\n");
    } else {
        printf("Student with Roll No %d not found!\n", rollNo);
    }
}

int main() {
    int choice;

    do {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Student\n");
        printf("4. Search Student\n");
        printf("5. Display All Students\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: updateStudent(); break;
            case 4: searchStudent(); break;
            case 5: displayStudents(); break;
            case 6: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

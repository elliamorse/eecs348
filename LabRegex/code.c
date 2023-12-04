#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

void addStudent(struct Student students[], int *count) {
    printf("Enter student name: ");
    scanf("%s", students[*count].name);

    printf("Enter roll number: ");
    scanf("%d", &students[*count].rollNumber);

    printf("Enter marks: ");
    scanf("%f", &students[*count].marks);

    (*count)++;
}

void displayStudents(const struct Student students[], int count) {
    printf("\nStudent Records:\n");
    printf("%-20s %-15s %-10s\n", "Name", "Roll Number", "Marks");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-15d %-10.2f\n", students[i].name, students[i].rollNumber, students[i].marks);
    }
}

void searchStudent(const struct Student students[], int count) {
    int rollNumber;
    printf("Enter roll number to search: ");
    scanf("%d", &rollNumber);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Student Found:\n");
            printf("%-20s %-15d %-10.2f\n", students[i].name, students[i].rollNumber, students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }
}

int main() {
    struct Student students[50];  // Assume a maximum of 50 students
    int count = 0;
    int choice;

    // Hard code details for 10 students
    for (int i = 0; i < 10; i++) {
        strcpy(students[count].name, "StudentName");
        students[count].rollNumber = 1000 + i;
        students[count].marks = 75.5 + i;

        count++;
    }

    do {
        printf("\nStudent Database System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

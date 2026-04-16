#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define SUBJECTS 5

// Function to calculate average of 5 marks
float AvgM(int marks[]) {
    int sum = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        sum += marks[i];
    }
    return (float)sum / SUBJECTS;
}

// Function to display student info
void displayS(char name[], int marks[]) {
    float avg = AvgM(marks);
    char grade;

    if (avg >= 90) grade = 'A';
    else if (avg >= 75) grade = 'B';
    else if (avg >= 60) grade = 'C';
    else if (avg >= 40) grade = 'D';
    else grade = 'F';

    printf("\nName: %s\n", name);
    printf("Average Marks: %.2f\n", avg);
    printf("Grade: %c\n", grade);
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    char names[MAX_STUDENTS][50];
    int marks[MAX_STUDENTS][SUBJECTS];

    for (int i = 0; i < n; i++) {
        printf("\nEnter name of student %d: ", i + 1);
        scanf(" %[^\n]",&names[i]); // Read full name with spaces

        printf("Enter 5 marks for %s:\n", names[i]);
        for (int j = 0; j < SUBJECTS; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    printf("\n--- Student Report ---\n");
    for (int i = 0; i < n; i++) {
        displayS(names[i], marks[i]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[100];
    int roll;
    char grade;
};

// Read student details
void read(int n, struct student s[]) {
    printf("Enter student name, roll no. and grade obtained\n");
    for (int i = 0; i < n; i++) {
        printf("Enter details of student %d:\n",i+1);
        printf("Name: ");
        scanf("%s",s[i].name);
        printf("ROll. No.: ");
        scanf("%d", &s[i].roll);
        printf("Grade: ");
        scanf(" %c", &s[i].grade);
    }
}
// Sort student details by roll number
void sort(int n, struct student s[]) {
    struct student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].roll > s[j + 1].roll) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

// Display student details
void display(int n, struct student s[]) {
    printf("\nStudent details as follows:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\t", s[i].name);
        printf("Roll No: %d\t", s[i].roll);
        printf("Grade: %c\n", s[i].grade);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter no. of students, whose details need to be added:\n");
    scanf("%d", &n);
    struct student s[n];
    read(n, s);
    sort(n, s);
    display(n, s);
}
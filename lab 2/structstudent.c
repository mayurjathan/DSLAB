/*Write a C program to define a structure student with the data members to store name,
roll no and grade of the student. Also write the member functions to read, display, and
sort student information according to the roll number of the student. All the member
functions will have array of objects as arguments.*/
#include <stdio.h>
struct student{
    char name[50];
    int roll;
    char grade;
};
void read(struct student a[], int n);
void display(struct student a[], int n);
void sort(struct student a[], int n);
int main() {
    struct student s[MAX];
    int num;
    printf("Enter the number of students: ");
    scanf("%d", &num);
    read(s, num);
    sort(s, num);
    printf("Student information sorted by roll number:\n");
    display(s, num);
    return 0;
}
void read(struct student a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: \n");
        scanf("%s", a[i].name);
        printf("Roll No: \n");
        scanf("%d", &a[i].roll);
        printf("Grade : \n");
        scanf("%c", &a[i].grade);
    }
}
void display(struct student a[], int n) {
    printf("Name\tRoll No\tGrade \n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%c\n", a[i].name, a[i].roll,a[i].grade);
    }
}
void sort(struct student a[], int n) {
    struct student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].roll > a[j + 1].roll) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
#include <stdio.h>
#include <string.h>

// Structure to store student information
struct student 
{
    int roll_no;
    char name[50];
    int age;
    float per;  // Percentage should be a float
};

int main() 
{
    struct student s[15]; // Array to store up to 15 students
    int count = 0;         // Counter for the number of students
    int index, roll_no, choice;

    while (1)
    {
        // Display menu options
        printf("\n=== Student Information System ===\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        while(getchar()!='\n'); // Consume newline character

        switch (choice) 
        {
            case 1: // Add a new student
                if (count < 15)
                {
                    printf("Enter Roll Number: ");
                    scanf("%d", &s[count].roll_no);
                    while(getchar()!='\n');
                    printf("Enter Name: ");
                    scanf("%[^\n]",s[count].name);
                    printf("Enter Age: ");
                    scanf("%d", &s[count].age);
                    printf("Enter Percentage: ");
                    scanf("%f", &s[count].per);
                    
                    count++;
                } 
                else
                {
                    printf("Maximum Student Limit reached...\n");
                }
                break;

            case 2: // Display all students
                if (count == 0) 
                {
                    printf("No Student Record Available\n");
                } 
                else
                {
                    for (int i = 0; i < count; i++) 
                    {
                        printf("\n-----------------------------------------------\n");
                        printf("Student %d Info:\n", i + 1);
                        printf("Roll Number: %d\n", s[i].roll_no);
                        printf("Name: %s\n", s[i].name);
                        printf("Age: %d\n", s[i].age);
                        printf("Percentage: %.2f%%\n", s[i].per);
                    }
                }
                break;

            case 3: // Search for a student by roll number
                printf("Enter Roll Number to search: ");
                scanf("%d", &roll_no);
                index = -1;
                for (int i = 0; i < count; i++)
                {
                    if (s[i].roll_no == roll_no)
                    {
                        index = i;
                        break;
                    }
                }
                if (index != -1) 
                {
                    printf("\nStudent Info:\n");
                    printf("Roll Number: %d\n", s[index].roll_no);
                    printf("Name: %s\n", s[index].name);
                    printf("Age: %d\n", s[index].age);
                    printf("Percentage: %.2f%%\n", s[index].per);
                }
                else 
                {
                    printf("Student with Roll Number %d not found.\n", roll_no);
                }
                break;

            case 4: // Update student details
                printf("Enter Roll Number to update: ");
                scanf("%d", &roll_no);
                index = -1;
                for (int i = 0; i < count; i++)
                {
                    if (s[i].roll_no == roll_no)
                    {
                        index = i;
                        break;
                    }
                }
                if (index != -1) 
                {
                    printf("Enter updated details:\n");
                    printf("Enter Name: ");
                    while(getchar()!='\n');  // Consume any leftover newline character
                    scanf("%[^\n]", s[index].name); // Use s[index].name to update the correct student's name
                    printf("Enter Age: ");
                    scanf("%d", &s[index].age);
                    printf("Enter Percentage: ");
                    scanf("%f", &s[index].per);
                    printf("Student data updated successfully.\n");
                } 
                else
                {
                    printf("Student with Roll Number %d not found.\n", roll_no);
                }
                break;

            case 5: // Delete a student record
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll_no);
    index = -1;

    // Find the student index with the given roll number
    for (int i = 0; i < count; i++)
    {
        if (s[i].roll_no == roll_no)
        {
            index = i;
            break;
        }
    }

    if (index != -1) 
    {
        // Shift all students after the deleted student to the left
        for (int i = index; i < count - 1; i++) 
        {
            s[i] = s[i + 1];
            s[i].roll_no = i + 1;  // Reassign roll number sequentially
        }

        count--; // Decrease student count
        printf("Student with Roll Number %d deleted successfully.\n", roll_no);
        
        // If the last student's roll number was deleted, update it
        if (index == count) {
            s[count].roll_no = count + 1;
        }
    } 
    else 
    {
        printf("Student with Roll Number %d not found.\n", roll_no);
    }
    break;


            case 6: // Exit the program
                printf("Exiting the system. Goodbye!\n");
                return 0;

            default: // Handle invalid menu choices
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
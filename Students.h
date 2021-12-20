#include <stdio.h>
#include <stdlib.h>

//Student personal information structure//
struct info_s
    {
        //Initialization for structure
        char first_name[30];
        char surname[30];
        int age;
        char date_of_birth[15];
        int number_of_subjects;
        char subjects[6][30];
        char password[30];

    };

//Function to get new student's personal information//
struct info_s New_student()
{
    //Initialization for function
    struct info_s student_info;
    char subject_holder[30] = "\0";

    printf("___________STUDENT___________\n");
    printf("Enter First name : ");
    scanf("%s", &student_info.first_name);
    printf("Enter Surname  : ");
    scanf("%s", &student_info.surname);
    printf("***Password can be no more than 30 chracters****\n");
    printf("Enter password :");
    scanf("%s",&student_info.password);
    printf("Enter Age : ");
    scanf("%d", &student_info.age);
    printf("***DD/MM/YYYY***\n");
    printf("Enter Date Of Birth : ");
    scanf("%s", &student_info.date_of_birth);
    printf("Enter number of subjects : ");
    scanf("%d", &student_info.number_of_subjects);


    //code for opening the subject list file
    FILE *subject_list_file;
    subject_list_file = fopen ("TimeTable\\Subjects\\Subject_list.txt", "r");
    if (subject_list_file == NULL)
    {
        printf("subject_list_file did not want to open.");
        exit(1);
    }

    do
    {
        printf("%s\n",subject_holder);
    }
    while (fscanf(subject_list_file,"%[^\n ] ", subject_holder) != EOF);

    fclose(subject_list_file);

    // Flush Console
    int c;
    while ( (c = getchar()) != '\n' && c != EOF );

    //Filling subjects
    for (int i = 1;i < student_info.number_of_subjects+1; i++)
    {
        printf("Enter subject %d :",i);
        fgets(student_info.subjects[i], 30, stdin);

    }

    return(student_info);
}







//Function to print students information into a text file//
void print_new_student_file(struct info_s student_info)
{
    //Filling student's file

    //Initialization for function
    char name_of_file[100];

    //code for opening the student's file
    snprintf(name_of_file,100,"TimeTable\\Students\\%s_%s.txt",student_info.first_name,student_info.surname);
    FILE *student_file;
    student_file = fopen (name_of_file, "w");

    //check whether file was able to open
    if (student_file == NULL)
    {
        printf("File did not want to open.");
        exit(1);
    }


    //printing info in student file
    fprintf(student_file, "Name: %s\n",student_info.first_name);
    fprintf(student_file, "Surname: %s\n",student_info.surname);
    fprintf(student_file, "Password: %s\n",student_info.password);
    fprintf(student_file, "Age: %d\n",student_info.age);
    fprintf(student_file, "Date of birth: %s\n",student_info.date_of_birth);
    fprintf(student_file, "Number of subject: %d\n",student_info.number_of_subjects);

    for (int i = 1;i <= student_info.number_of_subjects+1;i++)
    {
        fprintf(student_file, "%s",student_info.subjects[i]);
    }
    fclose(student_file);
}






//Function to read students information from student's file//
struct info_s read_student_file()
{
    //Initialization for function
    char first_name[20];
    char surname[20];
    struct info_s student_info;
    char name_of_file[100];
    char terminate[10] = "exit";
    char password[10];

    printf("___________STUDENT___________\n");
    printf("Enter your first name : ");
    scanf("%s",first_name);
    printf("Enter your surname : ");
    scanf("%s",surname);
    system("cls");

    //code for opening the student's file
    snprintf(name_of_file,100,"TimeTable\\Students\\%s_%s.txt",first_name,surname);
    FILE *student_file;
    student_file = fopen (name_of_file, "r");

    //check whether file was able to open
    if (student_file == NULL)
    {
        printf("File did not want to open.");
        exit(1);
    }

    //code to scan teacher info from student's file
    fscanf(student_file, "%*s %s",&student_info.first_name);
    fscanf(student_file, "%*s %s",&student_info.surname);
    fscanf(student_file, "%*s %s\n",student_info.password);
    fscanf(student_file, "%*s %d",&student_info.age);
    fscanf(student_file, "%*s %*s %*s %s",&student_info.date_of_birth);
    fscanf(student_file, "%*s %*s %*s %d",&student_info.number_of_subjects);

    for (int i = 0;i <= student_info.number_of_subjects; i++)
    {
        fgets(student_info.subjects[i], 30, student_file);
    }

    //code to check whether the teacher password is correct
    do
    {
        printf("___________STUDENT___________\n");
        printf("To return to menu enter: exit\n");
        printf("Username: %s %s\n",first_name,surname);
        printf("Password: ");
        scanf("%s",&password);
        system("cls");

        if (strcmp(password,student_info.password) == 0)
        {
            break;
        }
        else if (strcmp(password,terminate) == 0)
        {
            student_info.number_of_subjects = 888;
            break;
        }
        else if (strcmp(password,student_info.password) != 0)
        {

             printf("***Wrong password***\n");
        }
        getchar();
        system("cls");
    }
    while (strcmp(password,student_info.password)!= 0 || strcmp(password,terminate) != 0);

    fclose(student_file);

    return(student_info);
}

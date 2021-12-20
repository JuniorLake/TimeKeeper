#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function for creating time table format//
void default_room_table(int room_number)
{
    //Initialization for function
    char *table[13][6];
    char name_of_file[100];

    //code for opening the room table file
    snprintf(name_of_file,100,"TimeTable\\Rooms\\Room%d.txt",room_number);
    FILE *room_table_file;
    room_table_file = fopen (name_of_file, "w");

    //check whether file was able to open
    if (room_table_file == NULL)
    {
        printf("Room table file did not want to open.");
        exit(1);
    }

    for (int i = 0;i < 13;i++)
    {
        for (int j = 0;j < 6;j++)
        {
            table[i][j] = "Free";
        }
    }

    table[0][0] = "Time     ";
    table[0][1] = "Mon";
    table[0][2] = "Tues";
    table[0][3] = "Wed";
    table[0][4] = "Thur";
    table[0][5] = "Fri";

    table[1][0] = "07:15AM ";
    table[2][0] = "07:55AM ";
    table[3][0] = "08:50AM ";
    table[4][0] = "09:30AM ";
    table[5][0] = "10:10AM ";
    table[6][0] = "10:50AM ";
    table[7][0] = "12:30PM ";
    table[8][0] = "01:15PM ";
    table[9][0] = "02:10PM ";
    table[10][0] = "02:55PM ";
    table[11][0] = "03:40PM ";
    table[12][0] = "04:25PM ";

     for (int i = 0;i < 13;i++)
    {
        for (int j = 0;j < 6;j++)
        {
            fprintf(room_table_file,"%s\n",table[i][j]);
        }
    }
    fclose(room_table_file);
}

//function to print room table//
void print_room_table(int room_number)
{
    //Initialization for function
    char *table[13][6];
    char name_of_file[100];

    //code for opening the room table file
    snprintf(name_of_file,100,"TimeTable\\Rooms\\Room%d.txt",room_number);
    FILE *room_table_file;
    room_table_file = fopen (name_of_file, "r");

    //check whether file was able to open
    if (room_table_file == NULL)
    {
        printf("room table File did not want to open.");
        exit(1);
    }

    //code to scan table
    for (int i = 0;i < 13;i++)
    {
        for (int j = 0;j < 6;j++)
        {
            table[i][j] = malloc(30);
            fscanf(room_table_file,"%s",table[i][j]);
        }
    }

    //code to print table
    for (int i = 0;i < 13;i++)
    {
        for (int j = 0;j < 6;j++)
        {
            if (j == 5)
            {
                printf("%s\n", table[i][j]);
            }
            else if (strlen(table[i][j]) <= 9)
            {
                printf("%s\t  \t  \t", table[i][j]);
            }
            else if (strlen(table[i][j]) >= 17)
            {
                printf("%s\t", table[i][j]);
            }
            else
            {
                printf("%s\t  \t", table[i][j]);
            }

        }
    }
}

//check if a table slot is already occupied//
int checking_table(int room_number,int day,int start_time,int end_time)
{
    //Initialization for function
    char *table[13][6];
    char name_of_file[100];
    int ans;
    char free[] = "Free";

    //code for opening the table file
    snprintf(name_of_file,100,"TimeTable\\Rooms\\Room%d.txt",room_number);
    FILE *room_table_file;
    room_table_file = fopen (name_of_file, "r");

    //check whether file was able to open
    if (room_table_file == NULL)
    {
        printf("File did not want to open.");
        exit(1);
    }

    //code to scan table
    for (int i = 0;i < 13;i++)
    {
        for (int j = 0;j < 6;j++)
        {
            table[i][j] = malloc(30);
            fscanf(room_table_file,"%s",table[i][j]);
        }
    }

    if (strcmp(table[start_time][day],free) != 0)
    {
        printf("***Your starting time slot is occupied***\n");
        ans = 2;
        getchar();

    }
     else if (strcmp(table[start_time][day],free) == 0)
    {
        ans = 1;

    }
    if (strcmp(table[end_time][day],free) != 0)
    {
        printf("***Your ending time slot is occupied***\n");
        ans = 2;
        getchar();

    }





    else if (strcmp(table[end_time][day],free) == 0)
    {
        ans = 1;

    }

    return(ans);
}

//function to add to room table//
void add_to_room_table(char subjects[20],int start_time,int end_time,int day,int room_number,char first_name[20],char surname[20])
{
    //Initialization for function
    char *table[13][6];
    char name_of_file[100];
    char table_info[30];

    //code for opening the table file
    snprintf(name_of_file,100,"TimeTable\\Rooms\\Room%d.txt",room_number);
    FILE *room_table_file;
    room_table_file = fopen (name_of_file, "r");

    //check whether file was able to open
    if (room_table_file == NULL)
    {
        printf("Table file for reading did not want to open.");
        exit(1);
    }

    //code to scan from table
    for (int i = 0;i < 13;i++)
    {
        for (int j = 0;j < 6;j++)
        {
            table[i][j] = malloc(30);
            fscanf(room_table_file,"%s",table[i][j]);
        }
    }
    fclose(room_table_file);


    //code to add to the table
    subjects[strcspn(subjects, "\n")] = 0;
    snprintf(table_info,100,"%sRoom:%dTr:%c%c",subjects,room_number,first_name[0],surname[0]);
    for (int i = start_time; i <= end_time; i++)
    {
        table[start_time][day] = table_info;
        start_time++;
    }

    //code for opening the table file
    room_table_file = fopen (name_of_file, "w");

    if (room_table_file == NULL)
    {
        printf("Table file for writing did not want to open.");
        exit(1);
    }

    for (int i = 0;i < 13;i++)
    {
        for (int j = 0;j < 6;j++)
        {
            fprintf(room_table_file,"%s\n",table[i][j]);
        }
    }
    fclose(room_table_file);

}

//Function for printing student's table//
void student_table(struct info_s student_info)
{
    //Initialization for function
    int appears;
    int max_num = 0;
    int ans = 1;
    char name_of_file[100];
    struct info_t teacher_info;

    for (int i = 1;i <= student_info.number_of_subjects;i++)
    {
        student_info.subjects[i][strcspn(student_info.subjects[i], "\n")] = 0;
        //code for opening the subject list file
        snprintf(name_of_file,100,"TimeTable\\Subjects\\%s.txt",student_info.subjects[i]);
        FILE *subject_file;
        subject_file = fopen (name_of_file, "r");

        //check whether file was able to open
        if (subject_file == NULL)
        {
            printf("subject_file did not want to open.");
            exit(1);
        }
        //code to scan from subject file
        fscanf(subject_file, "%*s %s\n",&teacher_info.first_name);
        fscanf(subject_file, "%*s %s\n",&teacher_info.surname);
        fscanf(subject_file, "%*s %s\n",&teacher_info.password);
        fscanf(subject_file, "%*s %s\n",&teacher_info.subjects[i]);
        fscanf(subject_file, "%*s %*s %d\n",&teacher_info.start_time[i]);
        fscanf(subject_file, "%*s %*s %d\n",&teacher_info.end_time[i]);
        fscanf(subject_file, "%*s %d\n",&teacher_info.day[i]);
        fscanf(subject_file, "%*s %*s %*s %d\n",&teacher_info.number_of_sessions[i]);
        for (int j = 1; j <= teacher_info.number_of_sessions[i]; j++)
        {
            fscanf(subject_file, "%*s %*s %d\n",&teacher_info.room_number[i][j]);
        }

        fclose(subject_file);
    }

    //code to list rooms and put them in order
    while (ans != 2)
    {
        //code for getting the maximum number
        for (int i = 1;i <= student_info.number_of_subjects;i++)
        {
            for (int l =1; l <= teacher_info.number_of_sessions[i]; l++)
            {
                if (teacher_info.room_number[i][l] > max_num)
                {
                    max_num = teacher_info.room_number[i][l];
                }
            }
        }


        //code to put room in order
        printf("___________STUDENT___________\n");
        for (int a =1; a <= max_num; a++)
        {
            appears = 2;
            for (int i = 1;i <= student_info.number_of_subjects;i++)
            {
                for (int j =1; j <= teacher_info.number_of_sessions[i]; j++)
                {
                    if (teacher_info.room_number[i][j] == a)
                    {
                        appears = 1;
                        break;

                    }
                }
            }

            if (appears == 1)
            {
                printf("____________Room%d____________\n",a);
            }
            else if (appears == 2)
            {

            }
        }

        //code to let user choose the rooms displayed
        printf("To go back to menu :888\n");
        printf("Enter room number : ");
        scanf("%d",&ans);
        system("cls");
        if (ans == 888)
        {
            ans = 2;
            break;
        }








        else if (ans != 888)
        {

            student_table_info(student_info);
            printf("\t\t\t\t\t\t_________ROOM%d_________\n",ans);
            print_room_table(ans);
            ans = 1;
            getchar();
            getchar();
        }

        system("cls");
    }
}

//Function for printing teacher's table//
void teacher_table(struct info_t teacher_info)
{
    int appears;
    int max_num = 0;
    int ans = 1;

    //code to list rooms and put them in order
    while (ans != 2)
    {
        //code for getting the maximum number
        for (int i = 1;i <= teacher_info.number_of_subjects;i++)
        {
            for (int l =1; l <= teacher_info.number_of_sessions[i]; l++)
            {
                if (teacher_info.room_number[i][l] > max_num)
                {
                    max_num = teacher_info.room_number[i][l];
                }
            }
        }





        //code to put room in order
        printf("___________TEACHER___________\n");
        for (int a =1; a <= max_num; a++)
        {
            appears = 2;
            for (int i = 1;i <= teacher_info.number_of_subjects;i++)
            {
                for (int j =1; j <= teacher_info.number_of_sessions[i]; j++)
                {
                    if (teacher_info.room_number[i][j] == a)
                    {
                        appears = 1;
                        break;

                    }
                }
            }
            if (appears == 1)
            {
                printf("____________Room%d____________\n",a);
            }
            else if (appears == 2)
            {

            }
        }

        //code to let user choose the rooms displayed
        printf("To go back to menu :888\n");
        printf("Enter room number : ");
        scanf("%d",&ans);
        system("cls");
        if (ans == 888)
        {
            ans = 2;
            break;
        }









        else if (ans != 888)
        {
            teacher_table_info(teacher_info);
            printf("\t\t\t\t\t\t_________ROOM%d_________\n",ans);
            print_room_table(ans);
            ans = 1;
            getchar();
            getchar();
        }

        system("cls");
    }

}

//Function for student's info//
void student_table_info(struct info_s student_info)
{
    printf("___________STUDENT___________\n");
    printf("Name    : %s\n",student_info.first_name);
    printf("Surname : %s\n",student_info.surname);
    printf("Age     : %d\n",student_info.age);
    printf("DOB     : %s\n",student_info.date_of_birth);
    printf("Number of Subjects : %d\n\n",student_info.number_of_subjects);

}

//Function for teacher's info//
void teacher_table_info(struct info_t teacher_info)
{
    printf("___________TEACHER___________\n");
    printf("Name    : %s\n",teacher_info.first_name);
    printf("Surname : %s\n",teacher_info.surname);
    printf("Password: %s\n",teacher_info.password);
    printf("Number of subject: %d\n",teacher_info.number_of_subjects);
    for (int i = 1;i < teacher_info.number_of_subjects+1;i++)
    {
        printf("%s\n", teacher_info.subjects[i]);
    }
    printf("\n");
}

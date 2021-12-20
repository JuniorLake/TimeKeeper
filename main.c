#include <stdio.h>
#include <stdlib.h>
#include "Students.h"
#include "Teachers.h"
#include "Table.h"
#include "Subjects_and_rooms.h"
#include <dir.h>
#include <string.h>

int main()
{
    //Initialization for main
    int sign_as;
    int ans;
    struct info_s student_info2;
    struct info_t teacher_info2;
    char string1[] = "Time";
    char string2[10];
    int valid;
    char *table2[13][6];
    char name_of_file[100];
    int room_num;
    char dirname[5][50] = {"TimeTable\\Rooms","TimeTable\\Students",
    "TimeTable\\Teachers","TimeTable\\Subjects"};
    char room_holder[30];
    int counter;
    char teacher_password[] = "Teacher";
    char password[30];
    int max_num;
    int room_check[10];
    char terminate[10] = "exit";

    mkdir("TimeTable");
    //code to create folders
    for(int i = 0; i <= 3; i++)
    {
        mkdir(dirname[i]);
    }


    //Welcome Message
    printf("___________________WELCOME TO TIME KEEPER_________________\n");
    printf("This program let's teachers organize their school schedule\n");
    printf("so that students have a easier time knowing what class, room\n");
    printf("__________________and day they have class.________________\n");
    getchar();
    system("cls");

    //Menu
    do
    {
        //main menu
        printf("_______________MENU_______________\n");
        printf("____________Teacher : 1___________\n");
        printf("____________Student : 2___________\n");
        printf("_____Show a Specific Room: 5______\n");
        printf("_______Close Program: 999_________\n\n");
        printf("What would you like to do: ");
        scanf("%d", &sign_as);
        system("cls");

        if (sign_as == 1)
        {
            //teacher menu
            do
            {
                printf("__________TEACHER MENU___________\n");
	    printf("To return to menu enter: exit\n");
                printf("Enter teacher password: ");
                scanf("%s",&password);
                system("cls");

                if (strcmp(password,teacher_password) == 0)
                {
                    printf("__________TEACHER MENU___________\n");
                    printf("_______Sign-up a student: 1______\n");
                    printf("_____Sign-up a new teacher: 2____\n");
                    printf("______login as a Teacher: 4______\n");
                    printf("______Back to main menu: 888_______\n");
                    printf("_______Close Program: 999________\n\n");
                    printf("What would you like to do: ");
                    scanf("%d", &sign_as);
                    system("cls");


	        if (sign_as == 1||sign_as == 2||sign_as == 4||sign_as == 888||sign_as == 999)
                    {

                    }
                    else
                    {
                        sign_as = 100;
                    }
                    break;

                }
    else if (strcmp(password,terminate) == 0)
    {
        sign_as = 888;
        break;
                }
                else if (strcmp(password,teacher_password) != 0)
                {
                    printf("__________TEACHER MENU___________\n");
                    printf("*******Password incorrect********\n");
                }
                getchar();
                getchar();
                system("cls");
            }
            while (strcmp(password,teacher_password) != 0);
        }
        else if (sign_as == 2)
        {
            //student menu
            printf("__________STUDENT MENU___________\n");
            printf("______login as a Student: 3______\n");
            printf("______Back to main menu: 888_______\n");
            printf("_______Close Program: 999________\n\n");
            printf("What would you like to do: ");
            scanf("%d", &sign_as);
            system("cls");
	
if (sign_as == 3||sign_as == 888||sign_as == 999)
            {

            }
            else
            {
                sign_as = 100;
            }

        }

        else if (sign_as == 5||sign_as == 999)
        {

        }
        else
        {
            sign_as = 100;
        }

        switch (sign_as)
        {
            case 1:
                //code for new students to sign up
                student_info2 = New_student();
                getchar();
                system("cls");
                print_new_student_file(student_info2);
                getchar();
                system("cls");
                break;
            case 2:
                //code for new teacher to sign up
                teacher_info2 = New_teacher();
                system("cls");
                print_subjects(teacher_info2);
                print_new_teacher_file(teacher_info2);
                subject_list(teacher_info2);
                system("cls");
                break;
            case 3:
                //code for students to log in
                student_info2 = read_student_file();
                if (student_info2.number_of_subjects == 888 )
                {
                    system("cls");
                    break;
                }
                system("cls");
                student_table(student_info2);
                getchar();
                system("cls");
                break;
            case 4:
                //code for teacher to log in
                teacher_info2 = read_teacher_file();
                if (teacher_info2.number_of_subjects == 888 )
                {
                    break;
                }
                system("cls");
                teacher_info2 = read_subjects_teachers(teacher_info2);
                teacher_table(teacher_info2);
                getchar();
                system("cls");
                break;
            case 5: ;
                //code for showing different room tables
                ans = 0;
                while (ans != 888)
                {
                    printf("___________ROOM___________\n");
                    FILE *room_list_file;
                    room_list_file = fopen ("TimeTable\\Rooms\\Room_list.txt", "a+");
                    if (room_list_file == NULL)
                    {
                        printf("subject_list_file did not want to open.");
                        exit(1);
                    }

                    counter = 0;
                    do
                    {
                        counter++;
                        if (counter > 1)
                        {
                            printf("___________%s____________\n",room_holder);

                        }

                    }
                    while (fscanf(room_list_file,"%[^\n ] ", room_holder) != EOF);

                    printf("Back to main menu: 888\n");
                    printf("What room would like to see : ");
                    scanf("%d",&ans);
                    system("cls");



                    if (ans != 888)
                    {
                        printf("\t\t\t\t\t\t_________ROOM%d_________\n",ans);
                        print_room_table(ans);
                        getchar();
                        getchar();
                        system("cls");
                    }
                }

                break;
            case 999:
                //code when program is ended
                printf("_________THANK YOU FOR USING TIME KEEPER________\n");
                printf("________________HAVE A GREAT DAY!!_______________\n");
                getchar();
                getchar();
                break;
            case 888:
                //back to main menu
                break;
            default:
                //code when unregistered input is entered
                printf("***out of range***\n");
                getchar();
                getchar();
                getchar();
                system("cls");
                break;

        }
    }while (sign_as != 999);

    return 0;
}

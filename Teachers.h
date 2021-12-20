#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//teacher personal information structure//
struct info_t
    {
        //Initialization for structure
        char first_name[30];
        char surname[30];
        char subjects[6][30];
        int start_time[6];
        int end_time[6];
        char password[30];
        int day[6];
        int room_number[6][6];
        char rooms[6];
        int number_of_subjects;
        int number_of_sessions[6];

    };

//function for login system//
int login_system(struct info_t teacher_info)
{
    //Initialization for function
    int valid;
    char terminate[10] = "exit";
    char password[10];

    //code to check whether the teacher password is correct
    do
    {
        printf("___________TEACHER___________\n");
        printf("To return to menu enter: exit\n");
        printf("Username: %s %s\n",teacher_info.first_name,teacher_info.surname);
        printf("Password: ");
        scanf("%s",&password);

        if (strcmp(password,teacher_info.password) == 0)
        {
            valid = 1;
            break;
        }
        else if (strcmp(password,terminate) == 0)
        {
            valid = 2;
            break;
        }
        else if (strcmp(password,teacher_info.password) != 0)
        {

             printf("***Wrong password***\n");
        }
        getchar();
        getchar();
        system("cls");
    }
    while (password,teacher_info.password != 0);
    return(valid);
}


//Function to get new Teacher's personal information//
struct info_t New_teacher()
{
    //Initialization for function
    struct info_t teacher_info;
    char room_holder[30][20];
    char name_of_file[100];
    int ans;
    int counter;
    int counter2;
    int max_num;
    char room_check[10];

    printf("___________TEACHER___________\n");
    printf("Enter First name : ");
    scanf("%s", &teacher_info.first_name);
    printf("Enter Surname  : ");
    scanf("%s", &teacher_info.surname);
    printf("Enter password : ");
    scanf("%s", &teacher_info.password);
    printf("How much subjects do you teach : ");
    scanf("%d", &teacher_info.number_of_subjects);

    // Flush Console
    int c;
    while ( (c = getchar()) != '\n' && c != EOF );

    //code to scan and get new teacher's information
    for(int i = 1; i <= teacher_info.number_of_subjects; i++)
    {

        printf("***Do not enter Subject with a space in between***\n");
        printf("***No more than ten(10) characters***\n");
        printf("Enter subject %d: ",i);
        fgets(teacher_info.subjects[i], 30, stdin);
        printf("Enter number of sessions: ");
        scanf("%d",&teacher_info.number_of_sessions[i]);
        system("cls");

        //loop for number of sessions the teacher will have
         for (int l = 1; l <= teacher_info.number_of_sessions[i]; l++)
        {
            ans = 0;
            while (ans != 1)
            {
	    //code to scan the existing rooms in the room file
                FILE *room_list_file;
                room_list_file = fopen ("TimeTable\\Rooms\\Room_list.txt", "a+");
                if (room_list_file == NULL)
                {
                    printf("subject_list_file did not want to open.");
                    exit(1);
                }

                counter = 0;
                max_num = 0;
                do
                {
                    if (room_holder[counter] > max_num)
                    {
                        max_num = room_holder[counter];
                    }
                    counter++;

                }
	    //code to display rooms
                while (fscanf(room_list_file,"%[^\n ] ",room_holder[counter]) != EOF);
                fclose(room_list_file);

                printf("___________TEACHER___________\n");
                printf("Please wait a while.....\n");
                for (int a = 1; a <= max_num; a++)
                {
                    snprintf(room_check,10,"Room%d",a);
                    for (int k = 1; k < counter; k++)
                    {
                         if (strcmp(room_holder[k],room_check) == 0)
                        {
                            printf("____________%s_____________\n",room_holder[k]);

                        }
                    }

                }
                printf("________Add room = 999_______\n");
                printf("Enter room number: ");
                scanf("%d", &teacher_info.room_number[i][l]);
                system("cls");

	    //code to add a new room and check if the new room already exist
                if (teacher_info.room_number[i][l] == 999)
                {
                    printf("___________TEACHER___________\n");
                    printf("Enter new room number : ");
                    scanf("%d", &teacher_info.room_number[i][l]);
                    system("cls");
                    snprintf(name_of_file,30,"Room%d",teacher_info.room_number[i][l]);

                    for (int j = 0; j < counter2; j++)
                    {
                        if (strcmp(name_of_file,room_holder[j]) == 0)
                        {
                            printf("***This room already exists***\n");
                            ans = 3;
                            getchar();
                            getchar();
                            system("cls");
                        }
                    }

	        //code to confirm that the room the user chose for new rooms
                    if (ans != 3)
                    {
                        default_room_table(teacher_info.room_number[i][l]);
                        room_list(teacher_info.room_number[i][l]);
                        printf("\t\t\t\t\t\t________ROOM%d_______\n",teacher_info.room_number[i][l]);
                        print_room_table(teacher_info.room_number[i][l]);
                        printf("Do you confirm the room number : \n");
                        printf("Yes : 1\n");
                        printf("No  : 2\n");
                        scanf("%d", &ans);
                        system("cls");
                    }

                }

	    //code to confirm that the room the user chose for existing rooms
                else if (teacher_info.room_number[i][l] != 999)
                {
                    printf("___________TEACHER___________\n");
                    printf("\t\t\t\t\t\t_________ROOM%d________\n",teacher_info.room_number[i][l]);
                    print_room_table(teacher_info.room_number[i][l]);
                    printf("Do you comfirm the room number : \n");
                    printf("Yes : 1\n");
                    printf("No  : 2\n");
                    scanf("%d", &ans);
                    system("cls");
                }

	    //code to enter info into the room time table
                if (ans == 1)
                {
                    ans = 0;
                    printf("___________TEACHER___________\n");
                    printf("\t\t\t\t\t\t_________ROOM%d________\n",teacher_info.room_number[i][l]);
                    print_room_table(teacher_info.room_number[i][l]);
                    snprintf(teacher_info.rooms[i],30,"Room%d",teacher_info.room_number[i][l]);
                    printf("_______Monday    = 1_______\n");
                    printf("_______Tuesday   = 2_______\n");
                    printf("_______Wednesday = 3_______\n");
                    printf("_______Thursday  = 4_______\n");
                    printf("_______Friday    = 5_______\n");
                    printf("Enter day : ");
                    scanf("%d", &teacher_info.day[i]);
                    printf("_______07:15AM = 1_______\n");
                    printf("_______07:55AM = 2_______\n");
                    printf("_______08:50AM = 3_______\n");
                    printf("_______09:30AM = 4_______\n");
                    printf("_______10:10AM = 5_______\n");
                    printf("_______10:50AM = 6_______\n");
                    printf("_______12:30PM = 7_______\n");
                    printf("_______01:15PM = 8_______\n");
                    printf("_______02:10PM = 9_______\n");
                    printf("_______02:55PM = 10______\n");
                    printf("_______03:40PM = 11______\n");
                    printf("_______04:25PM = 12______\n");
                    printf("Enter start time : ");
                    scanf("%d", &teacher_info.start_time[i]);
                    printf("Enter end time : ");
                    scanf("%d", &teacher_info.end_time[i]);

	        //code for checking if the time and day select is occupied
                    ans = checking_table(teacher_info.room_number[i][l],teacher_info.day[i],
        teacher_info.start_time[i],teacher_info.end_time[i]);
                    if (ans == 1)
                    {
                        add_to_room_table(teacher_info.subjects[i],teacher_info.start_time[i],teacher_info.end_time[i],teacher_info.day[i],teacher_info.room_number[i][l],teacher_info.first_name,teacher_info.surname);
                    }
                    getchar();
                    system("cls");
                }
            }
            // Flush Console
            while ( (c = getchar()) != '\n' && c != EOF );
        }
    }

    // Flush Console
    while ( (c = getchar()) != '\n' && c != EOF );
    printf("_____Successfully Sign in______ ");
    getchar();
    getchar();

    return(teacher_info);
}


//Function to print teacher information into a text file//
void print_new_teacher_file(struct info_t teacher_info)
{
    //Initialization for function
    char name_of_file[100];

    //code for opening the teacher's file
    snprintf(name_of_file,100,"TimeTable\\Teachers\\%s_%s.txt",teacher_info.first_name,teacher_info.surname);
    FILE *teacher_file;
    teacher_file = fopen (name_of_file, "w");

    //check whether file was able to open
    if (teacher_file == NULL)
    {
        printf("teacher_file did not want to open.");
        exit(1);
    }

    //code to print teacher info to teacher's file
    fprintf(teacher_file, "Name: %s\n",teacher_info.first_name);
    fprintf(teacher_file, "Surname: %s\n",teacher_info.surname);
    fprintf(teacher_file, "Password: %s\n",teacher_info.password);
    fprintf(teacher_file, "Number of subjects: %d\n",teacher_info.number_of_subjects);

    for (int i = 1;i <= teacher_info.number_of_subjects;i++)
    {
        fprintf(teacher_file, "%s\n", teacher_info.subjects[i]);
    }

    fclose(teacher_file);
}







//Function to read teacher information from a text file//
struct info_t read_teacher_file()
{
    //Initialization for function
    char first_name[20];
    char surname[20];
    struct info_t teacher_info;
    char name_of_file[100];
    char terminate[10] = "exit";
    char password[10];

    printf("___________TEACHER___________\n");
    printf("Enter your first name : ");
    scanf("%s",first_name);
    printf("Enter your surname : ");
    scanf("%s",surname);
    system("cls");

    //code for opening the teacher's file
    snprintf(name_of_file,100,"TimeTable\\Teachers\\%s_%s.txt",first_name,surname);
    FILE *teacher_file;
    teacher_file = fopen (name_of_file, "r");

    //check whether file was able to open
    if (teacher_file == NULL)
    {
        printf("teacher_file did not want to open.");
        exit(1);
    }

    //code to scan teacher info from teacher's file
    fscanf(teacher_file, "%*s %s",&teacher_info.first_name);
    fscanf(teacher_file, "%*s %s",&teacher_info.surname);
    fscanf(teacher_file, "%*s %s",&teacher_info.password);
    fscanf(teacher_file, "%*s %*s %*s %d",&teacher_info.number_of_subjects);

    for (int i = 1;i < teacher_info.number_of_subjects+1;i++)
    {
        fscanf(teacher_file,"%s",teacher_info.subjects[i]);
    }

    fclose(teacher_file);

    //code to check whether the teacher’s passwrod is correct
    do
    {
        printf("___________TEACHER___________\n");
        printf("To return to menu enter: exit\n");
        printf("Username: %s %s\n",first_name,surname);
        printf("Password: ");
        scanf("%s",&password);
        system("cls");

        if (strcmp(password,teacher_info.password) == 0)
        {
            break;
        }
        else if (strcmp(password,terminate) == 0)
        {
            teacher_info.number_of_subjects = 888;
            break;
        }
        else if (strcmp(password,teacher_info.password) != 0)
        {

             printf("***Wrong password***\n");
        }
        getchar();
        system("cls");
    }
    while (strcmp(password,teacher_info.password)!= 0 || strcmp(password,terminate) != 0);

    fclose(teacher_file);

    return(teacher_info);
}

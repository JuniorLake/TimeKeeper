#include <stdio.h>
#include <stdlib.h>

//function to print in room list//
void room_list(int room_num)
{

    //code for opening the room list file
    FILE *room_file;
    room_file = fopen ("TimeTable\\Rooms\\Room_list.txt", "a");

    //check whether file was able to open
    if (room_file == NULL)
    {
        printf("Room list file did not want to open.");
        exit(1);
    }

    //printing to room list
    fprintf(room_file, "Room%d\n",room_num);


    fclose(room_file);
}

//function to print to subject list file//
void subject_list(struct info_t teacher_info)
{

    //code for opening the subject list file
    FILE *subject_list_file;
    subject_list_file = fopen ("TimeTable\\Subjects\\Subject_list.txt", "a");

    //check whether file was able to open
    if (subject_list_file == NULL)
    {
        printf("subject_list_file did not want to open.");
        exit(1);
    }

    //code to print in subject list
    for (int i = 1;i <= teacher_info.number_of_subjects;i++)
    {
        fprintf(subject_list_file, "%s\n",teacher_info.subjects[i]);
    }

    fclose(subject_list_file);
}

//function to print to subject file//
void print_subjects(struct info_t teacher_info)
{
    //Initialization for function
    char name_of_file[100];

    for (int i = 1;i <= teacher_info.number_of_subjects;i++)
    {
        teacher_info.subjects[i][strcspn(teacher_info.subjects[i], "\n")] = 0;

        //code for opening the subject list file
        snprintf(name_of_file,100,"TimeTable\\Subjects\\%s.txt",teacher_info.subjects[i]);
        FILE *subject_file;
        subject_file = fopen (name_of_file, "w");

        //check whether file was able to open
        if (subject_file == NULL)
        {
            printf("subject_file did not want to open.");
            exit(1);
        }

        //code to print to subject file
        fprintf(subject_file, "Name: %s\n",teacher_info.first_name);
        fprintf(subject_file, "Surname: %s\n",teacher_info.surname);
        fprintf(subject_file, "Password: %s\n",teacher_info.password);
        fprintf(subject_file, "Subject: %s\n",teacher_info.subjects[i]);
        fprintf(subject_file, "Start Time: %d\n",teacher_info.start_time[i]);
        fprintf(subject_file, "End Time: %d\n",teacher_info.end_time[i]);
        fprintf(subject_file, "Day: %d\n",teacher_info.day[i]);
        fprintf(subject_file, "Number of Sessions: %d\n",teacher_info.number_of_sessions[i]);
        for (int j = 1; j <= teacher_info.number_of_sessions[i]; j++)
        {
            fprintf(subject_file, "Room Number: %d\n",teacher_info.room_number[i][j]);
        }
        fclose(subject_file);
    }

}

//function to read to subject file//
struct info_t read_subjects_teachers(struct info_t teacher_info)
{
    //Initialization for function
    char name_of_file[100];

    for (int i = 1;i <= teacher_info.number_of_subjects;i++)
    {
        //code for opening the subject list file
        snprintf(name_of_file,100,"TimeTable\\Subjects\\%s.txt",teacher_info.subjects[i]);
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
    return(teacher_info);
}


///functions used on structs in


#include "student_struct.h"  // must be here also and in main

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RIGHT 1
#define WRONG -1

#define FOUND 1
#define NOT_FOUND -1

#define FIRST_LARGER 1
#define SECOND_LARGER 2
#define EQUAL 0
#define NOT_EQUAL -1



/***************1*******************/


void student_print(struct student  s)
{
    printf("==================\n");

    printf("name: %s\nage: %d\ngrade: %c\nphone : %s\n",s.name,s.age,s.grade,s.phone);
    printf("==================\n");

}

/***************2*******************/

void student_print_ByRef(struct student* ps)
{

    printf("name: %s\nage: %d\ngrade: %c\nphone : %s\n",ps->name,ps->age,(*ps).grade,ps->phone);  // all ways the same

}

/***************3*******************/

void student_Print_ArrayOfStructs(std_t *arr,int size)   //std_t == struct student -- and means student type
{
    printf("****************\n");
    printf("================\n");

    for (int i =0 ; i<size ; i++)
    {
        printf("name: %s\nage: %d\ngrade: %c\nphone : %s\n================\n",(*(arr+i)).name,(arr+i)->age,arr[i].grade,arr[i].phone); // all same
//student_print(arr[i]);
//student_printByRef(arr+i);   //many ways

    }

    printf("****************\n");

}

/**************4********************/

std_t student_scan (void)
{
    std_t  s;   // define a local struct called "s"

    fflush(stdin);  // needs to include c libraries to work here

    printf("Enter your name : ");
    str_scan(s.name);   //s.name is the name of the string (its address)

    printf("Enter your age : ");
    scanf("%d",&(s.age));

    printf("Enter your grade : ");
    scanf(" %c",&(s.grade));

    printf("Enter your phone number: ");
    str_scan(s.phone);   //s.name is the name of the string (its address)

    return s;

}


/**************5********************/

void student_scan_byRef (std_t* ps)
{

    fflush(stdin);

    printf("Enter your name : ");
    str_scan(ps->name);   //s.name is the name of the string (its address)

    printf("Enter your age : ");
    scanf("%d",&(ps->age));

grade_again :

    printf("Enter your grade : ");
    scanf(" %c",&(ps->grade));

    if (ps->grade>='a' && ps->grade<='z')
    {
        ps->grade = ps->grade - ('a'-'A');
    }
    if (ps->grade<'A' || ps->grade>'F' || ps->grade=='E')
    {
        printf("Wrong Grade!\n");
        goto grade_again;
    }


    printf("Enter your phone number: ");
    str_scan(ps->phone);

}


/***************6*******************/

std_t* student_scan_dynamic (void)  // returns pointer to struct
{
    std_t* ps = (std_t*)malloc(10*sizeof(std_t));   // define a local struct called "s"

    fflush(stdin);  // needs to include c libraries to work here

    printf("Enter your name : ");
    str_scan(ps->name);   //s.name is the name of the string (its address)

    printf("Enter your age : ");
    scanf("%d",&(ps->age));

    printf("Enter your grade : ");
    scanf(" %c",&(ps->grade));

    printf("Enter your phone number: ");
    str_scan(ps->phone);

    return ps;

}


/**************7********************/

void student_swap(std_t* ps1, std_t* ps2)
{

    std_t temp;

    temp=*ps1;
    *ps1=*ps2;
    *ps2 = temp;

}

/**************8********************/

int student_search_maxAge (std_t* arr, int size)  // returns "index" of struct of the oldest student ,, takes array of structs of type student & size
{
    int i, max=arr[0].age, index=0;  // if assigning max as 1st element - index too must be 0 , as he may be the oldest

    for(i=0 ; i<size ; i++)
    {
        if (arr[i].age>max)
        {
            max=arr[i].age;   // only age our concern here
            index = i;       // as we return index not only the age - age is not enough to know the student
        }
    }

    return index;

}

/**************9********************/

int student_search_maxGrade (std_t* arr, int size)
{
    int i, index=0;
    char max=arr[0].grade;
    int last_valid_index = student_array_search_1st_empty_place(arr,size)-1;

    for(i=0 ; i<last_valid_index ; i++)
    {
        if (arr[i].grade<max) // grades are inversed - A is max & D is min - unlike C compiling
        {
            max=arr[i].grade;   // only age our concern here
            index = i;       // as we return index not only the age - age is not enough to know the student
        }
    }

    return index;
}

/**************9********************/

int student_search_name (std_t* arr, int size, char* name)
// returns "index" of struct of the oldest student ,, takes array of structs of type student & size & a name

{
    for (int i =0 ; i<size ; i++)
    {
        if(str_compare_not_case_sensitive(arr[i].name, name)==EQUAL)
        {
            return i;
        }
    }
    return NOT_FOUND;
}

/**********************************/
//Project
/**********************************/

int student_array_search_1st_empty_place (std_t* arr, int size)   // returns index of 1st empty place in array of students
{
    for (int i=0 ; i<size ; i++)
    {
        if (arr[i].age==0)       // the age will be zero if it's an empty place
        {
            return i;
        }
    }

    return -1; // no places left in school

}

/**********************************/

int student_add_new (std_t* arr, int size)   // add at the end (1st empty place)
{
    int first_empty_index = student_array_search_1st_empty_place (arr,size);

    if (first_empty_index!=-1)
    {
        student_scan_byRef (&arr[first_empty_index]);

        return first_empty_index; // the index of new student

    }

    else
    {
        printf("No places left in school for newcomers\n");
    }


}

/******************************************/


void student_sorting_by_name (std_t* arr,int size)  // ascending selective sorting of structs in an array
{
    int max_index, i;
    int first_empty_place = student_array_search_1st_empty_place (arr,size);  // we sort the students without empty places

    for (int j=0 ; j<first_empty_place ; j++)
    {

        max_index = 0;
        for (i =0 ; i<first_empty_place-j ; i++)                   // excluding last element every loop
        {
            if (str_compare_larger_not_case_sensitive (arr[max_index].name, arr[i].name)==SECOND_LARGER) // excluding empty structs
            {
                max_index = i;
            }

        }                                               // (i) will be at last element (size-j)

        student_swap(&arr[i-1],&arr[max_index]);           //(i-1) because (i) will exit the array - byt7a22a2 el shrt eli y5arragak mn el loop
        // swap whole structs - not only names
    }

}

/******************************************/


void student_sorting_by_age (std_t* arr,int size)  // ascending selective sorting of structs in an array
{
    int  max_index, i;
    int first_empty_place = student_array_search_1st_empty_place (arr,size);  // we sort the students without empty places

    for (int j=0 ; j<first_empty_place ; j++)
    {

        max_index = 0;
        for (i =0 ; i<first_empty_place-j ; i++)                   // excluding last element every loop
        {
            if (arr[i].age>arr[max_index].age) // excluding empty structs
            {
                max_index = i;
            }

        }                                               // (i) will be at last element (size-j)

        student_swap(&arr[i-1],&arr[max_index]);           //(i-1) because (i) will exit the array - byt7a22a2 el shrt eli y5arragak mn el loop
        // swap whole structs - not only names
    }

}


/******************************************/

void student_sorting_by_grade_descending (std_t* arr,int size)  // DESCENDING selective sorting of structs in an array

{
    int i,min_i,last_i,j;
    int first_empty_place = student_array_search_1st_empty_place (arr,size);
    last_i=first_empty_place-1;

    for(j=0; j<first_empty_place; j++)
    {
        min_i=0;

        for(i=0; i<first_empty_place-j; i++)
        {
            if(arr[min_i].grade<arr[i].grade)   //descending and ascending are reversed in grades as (A>B>C>D) - but in c - (A<B<C<D)
            {
                min_i=i;
            }

        }
        student_swap(&arr[min_i],&arr[last_i]);
        last_i--;

    }

}


/******************************************/

void student_sorting_by_grade_ascending (std_t* arr,int size)  // ascending selective sorting of structs in an array
{
    int  max_index, i;
    int first_empty_place = student_array_search_1st_empty_place (arr,size);  // we sort the students without empty places

    for (int j=0 ; j<first_empty_place ; j++)
    {

        max_index = 0;
        for (i =0 ; i<first_empty_place-j ; i++)                   // excluding last element every loop
        {
            if (arr[i].grade<arr[max_index].grade)
            {
                max_index = i;
            }

        }                                               // (i) will be at last element (size-j)

        student_swap(&arr[i-1],&arr[max_index]);           //(i-1) because (i) will exit the array - byt7a22a2 el shrt eli y5arragak mn el loop
        // swap whole structs - not only names
    }

}

/******************************************/

int student_insert_new (std_t* arr, int size)   // add the student in the right place according to ascending names sorting
{
    int max_index,i, ID;

    if (student_array_search_1st_empty_place(arr,size)!=-1)  // no places left
    {
        int last_index = student_add_new(arr,size); // last index = index of added student
        char name[30];
        str_copy(arr[last_index].name,name);

        // selective sorting part

        for (int j=0 ; j<=last_index ; j++)
        {

            max_index = 0;
            for (i =0 ; i<=(last_index-j) ; i++)                   // excluding last element every loop
            {
                if (str_compare_larger_not_case_sensitive (arr[max_index].name, arr[i].name)==SECOND_LARGER) // excluding empty structs
                {
                    max_index = i;
                }

            }                                               // (i) will be at last element (size-j)

            student_swap(&arr[i-1],&arr[max_index]);           //(i-1) because (i) will exit the array - byt7a22a2 el shrt eli y5arragak mn el loop
            // swap whole structs - not only names
        }

        ID=student_search_name(arr,size,name);
        return ID;
    }

    else
    {
        printf("No places left in school for newcomers\n");
    }

}

/******************************************/

void student_delete_and_sort (std_t* arr, int size,int index)  // takes the ID of the student to be deleted
{
    int length = str_length(arr[index].name);
    int last_index = (student_array_search_1st_empty_place (arr,size) -1 );
    student_swap(&arr[index],&arr[last_index]); //swapping element to be deleted and last element

    arr[last_index].age = 0;   //last index now is with the desired to be deleted struct
    arr[last_index].grade = 0;

    for (int i =0 ; i<length ; i++)
    {
        arr[last_index].name[i] = 0;
    }

    student_swap(&arr[index],&arr[last_index-1]); //reswapping the last struct to the new last place again as it's the biggest name


}

/******************************************/

void student_edit_data (std_t* arr, int size, int index)
{
    int ID_range = student_array_search_1st_empty_place(arr,size)-1;

    if (index>ID_range)
    {
        printf("Wrong ID!\n");
        return;
    }


    int choice;

    char name[30];
    char phone[20];
    char grade;
    int age;



    printf("Choose the number of operation you want : \n(1) Edit name \n(2) Edit age \n(3) Edit grade \n(4) Edit phone number \n(5) Edit All data\n");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1 :
        printf("Name : ");
        str_scan(name);
        str_copy(name,arr[index].name);
        break;

    case 2 :
        printf("Age : ");
        scanf("%d",&age);
        arr[index].age = age;
        break;

    case 3 :
        fflush(stdin);
        printf("Grade : ");
        scanf(" %c",&grade);
        arr[index].grade = grade;
        break;

    case 4 :
        printf("Phone number : ");
        str_scan(phone);
        str_copy(phone,arr[index].phone);
        break;


    case 5 :

        fflush(stdin);

        printf("Name : ");
        str_scan(name);
        printf("Age : ");
        scanf("%d",&age);
        printf("Grade : ");
        scanf(" %c",&grade);
        printf("Phone number : ");
        str_scan(phone);

        str_copy(name,arr[index].name);
        arr[index].age = age;
        arr[index].grade = grade;
        str_copy(phone,arr[index].phone);

        break;


    default :
        printf("Wrong Choice!\n");


    }

    student_print(arr[index]);
    printf("Edited Successfully!\n\n");

}

/******************************************/

void student_phone_calling_by_ID (std_t* arr, int index)  // index = ID
{
    printf("Student Name : ");
    printstr(arr[index].name);

    for (int seconds =0 ; seconds<4 ; seconds++)
    {
        printf("Calling.   ");


        sleep(1);

        printf("\b\b\b");

        printf(".  ");


        sleep(1);

        printf("\b\b");
        printf(". ");

        sleep(1);
        printf("\b");
        printf(".");
        printf("\b\b\b\b\b\b\b\b\b\b\b\b\b");

        sleep(1);

    }

    printf("No Answer! \n");

}

/******************************************/


void student_phone_calling_by_name (std_t* arr, int size, char* name)
{
    int i, found, index;

    for (i=0 ; i<size ; i++)
    {
        if(str_compare_not_case_sensitive(arr[i].name,name)==EQUAL)
        {
            found=1;
            index = i;
            break;

        }
    }


    if(found==1)
    {
        printf("Student Name : ");
        printstr(arr[index].name);

        for (int seconds =0 ; seconds<4 ; seconds++)
        {
            printf("Calling.   ");


            sleep(1);

            printf("\b\b\b");

            printf(".  ");


            sleep(1);

            printf("\b\b");
            printf(". ");

            sleep(1);
            printf("\b");
            printf(".");
            printf("\b\b\b\b\b\b\b\b\b\b\b\b\b");

            sleep(1);

        }

        printf("No Answer! \n");

    }

    else
    {
        printf("No matching names!\n");
    }
}

/******************************************/

void student_print_byID (std_t* arr, int index)
{
    student_print(arr[index]);
}
/******************************************/

void admin_password_change (char* password)
{
    printf("New password : ");
    str_scan(password);
}

/******************************************/
int admin_password_check (char* password, char* input_password)
{
    if (str_compare (password,input_password)== EQUAL)
    {
        return RIGHT;
    }

    return WRONG;
}

/******************************************/
/***************result_t*******************/

result_t add_mult (int n1,int n2)

{

    result_t r;

    r.sum=n1+n2;
    r.mult=n1*n2;

    return r;

}

/**********************************/



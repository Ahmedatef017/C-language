
///String functions

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define FIRST_LARGER 1
#define SECOND_LARGER 2
#define EQUAL 0
#define NOT_EQUAL -1

/*********************************************/

void printstr (char* str)
{
    for (int i = 0 ; str[i] ; i++)
    {

        printf("%c",str[i]);
    }

    printf("\n");

}

/*********************************************/

int str_length (char* str)
{
    int i; // must be outside to return it after the for loop

    for(i = 0 ; str[i] ; i++) {}

    return i;
}

/*********************************************/

void str_reverse (char* str)   //also works as mirror if str has odd length
{

    int i,j;
    char temp;
    int length;
    length = str_length(str);
    j=length-1;     // if not length -1 --> it will swap null .. always will be true // also j will be used as index starts from 0

    for (i = 0 ; i<(length/2) ; i++)
    {

        temp = str[i];
        str[i]=str[j];
        str[j]=temp;
        j--;
    }

}

/*********************************************/


void str_upper2lower_case (char* str) // turns only any capital letter to small
{
    for (int i = 0 ; str[i] ; i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            str[i]=str[i]+('a'-'A');
        }
    }

}

/*********************************************/


void str_lower2upper_case (char* str) // turns only any small letters to capital
{
    for (int i = 0 ; str[i] ; i++)
    {
        if(str[i]>='a'&&str[i]<='z')
        {
            str[i]=str[i]-('a'-'A');
        }
    }

}

/*********************************************/

int str_compare (char* str1, char* str2)         //strings are the same or not -- if same return 1  -- CASE SENSITIVE
{

    for (int i =0 ; str1[i] || str2[i] ; i++)   //or not && -- if sizes not equal - it will compare null with a charecter and return 0 --
        //also due to place of return
    {
        // if && the loop will be completed (useless)
        if (str1[i]!=str2[i])
        {
            return NOT_EQUAL;  // different
        }
    }

    return EQUAL;   // same

}

/*********************************************/

int str_compare_not_case_sensitive (char* str1, char* str2)
{
    signed int temp;

    for (int i =0 ; str1[i] || str2[i] ; i++)   // || or not && -- if sizes not equal - it will compare null with a charecter and return 0
    {
        temp = str1[i]-str2[i];

        if (temp!='A'-'a'&& temp!='a'-'A' && str1[i]!=str2[i])  // && not or || ---> the three must happen at same time ,,if or -- if one is not true only
            // it will return zero
        {
            return NOT_EQUAL;  //different
        }

    }

    return EQUAL;  // same

}


/*********************************************/

void str_copy (char* source, char* copy)
{
    int i ;
    int L2 = str_length(source);


    for (i = 0 ; source[i] ; i++)
    {
        copy[i]=source[i];  // el trtib mohem
    }
    copy[i]=0;

}

/*********************************************/

void str_concatenate (char* str1, char* str2, char* result)

{
    int L1 = str_length(str1);
    int L2 = str_length(str2);
    int i=0, j=0 ;

    for(i = 0 ; i<L1 ; i++) //1st word
    {
        result [i] = str1[i];
    }

    result[i]=1; // anything..it will be replaced kda kda.. if not put it will read zero - idk why -- str_length will get L of 1st word only

    for(j = 0 ; j<L2 ; j++) //2nd word
    {
        result [i] = str2[j];
        i++;
    }

    result[i]=0;

}

/*********************************************/

int str_search_letter (char* str, char letter)  // search for a certain letter and return its order -- if not found return
{

    for (int i =0 ; str[i] ; i++)
    {

        if (str[i]==letter || str[i]==letter-('a'-'A') || str[i]==letter+('a'-'A') ) // solving capital & small
        {
            return i+1;
        }

    }

    return 0 ;

}


/*********************************************/

void str_max_min (char* str)
{
    char max = 'a',min = 'z';

    str_upper2lower_case (str);

    for (int i= 0 ; str[i]; i++)
    {

        if (str[i]>max )
        {
            max = str[i];
        }

        if (str[i]<min )
        {
            min = str[i];
        }

    }

    printf ("Max = %c    Min = %c   \n",max,min);
}



/*********************************************/

void str_swap(char* str1, char* str2)
{

    int i, temp;


    for (i = 0 ; str1[i]&&str2[i]; i++) // will swap according to smaller length and يسيب باقي الطويل زي ما هو من نفسه
    {
        temp = str1[i];
        str1[i]=str2[i];
        str2[i]=temp;
    }

}

//*********************************///

int str_compare_larger_not_case_sensitive (char* str1, char* str2)
{
    int L1=str_length(str1) , L2=str_length(str2);
    char str1_copy[L1-1];
    char str2_copy[L2-1];

    str_copy(str1,str1_copy);
    str_copy(str2,str2_copy);  // take copies and edit them without editing originals

    str_upper2lower_case(str1_copy);
    str_upper2lower_case(str2_copy);  // now all copies are in lower case


    for (int i =0 ; str1_copy[i] || str2_copy[i] ; i++)   // (|| or) not && -- if sizes not equal - it will compare null with a charecter and return 0
    {

        if (str1_copy[i]>str2_copy[i])

        {
            return FIRST_LARGER;  //1st is larger
        }

        else if ((str2_copy[i]>str1_copy[i]))

        {
            return SECOND_LARGER;  //2nd is larger
        }

    }

    return EQUAL;  // same

}


//*********************************///


int str_compare_larger (char* str1, char* str2)
{

    for (int i =0 ; str1[i] || str2[i] ; i++)
    {

        if (str1[i]>str2[i] )

        {
            return 1;  //1st is larger
        }

        else if (str2[i]>str1[i])

        {
            return 2;  //2nd is larger
        }

    }

    return 0;  // same

}


/*********************************************/

void str_bet2letters (char letter1, char letter2 ) //printing higher case - ascending or descending
{


    if (letter1 >= 'a' && letter1 <= 'z')
    {
        letter1 = letter1 - ('a'-'A');
    }

    if (letter2 >= 'a' && letter2 <= 'z')
    {
        letter2 = letter2 - ('a'-'A');
    }



    if (letter2>letter1)  // ascending
    {
        for (char i= letter1+1; i<letter2 ; i++)
        {
            printf("%c ",i);
        }
        printf("\n");
    }


    else if (letter1>letter2) //descending
    {
        for (char i= letter1-1; i>letter2 ; i--)
        {

            printf("%c ",i);

        }
        printf("\n");
    }



    else
    {
        printf(" \n");
    }
}

/*********************************************/

void str_scan (char* str)   //write the str as a normal sentence
{
    int i =0;

    fflush(stdin);

    //printf("Enter the sentence you want to write : \n");

    scanf("%c",&str[i]);      // once here 1st -- we don't want the check of the for loop on the garbage (may be \n) .. but we want the check on the input

    for (; str[i]!='\n';)      // check now will be on the input
    {
        i++;                  // increment 1st to 1st write in str[1] .. if put in for condition .. user will rewrite on str[0]
        scanf("%c",&str[i]);   // last input will be enter '\n'
    }

    str[i]=0;    // null replacing enter '\n' as we don't want it to be part of the length

}

/*********************************************/

int str_merge (char* str1,char* str2, char* merged_str)
{
    int i=0,new_length,j=0,k=0, merge_length,L1,L2;
    L1 = str_length(str1);
    L2 = str_length(str2);

    new_length = L1+L2;
    // merge_length = L1<L2?(2*L1):(2*L2);
    //printf("%d\n\n",merge_size);

    for (i = 0 ; str1[j] && str2[j] ; i=i+2)  //loop to merge
    {
        merged_str[i] = str1[j];    // for even elements starts from 0
        merged_str[i+1] = str2[j];  // for odd elements starts from 1
        j++;                         // increment for elements of both strings by 1
    }


    //completing from 1st str1 if it's larger

    while (str1[j])
    {
        merged_str[i] = str1[j];
        j++;
        i++;
    }

    //completing from 2nd str2 if it's larger

    while (str2[j])
    {
        merged_str[i] = str2[j];
        j++;
        i++;
    }


    merged_str[i]=0;

    return new_length;
}

/*********************************************/

int str_most_repeated (char* str, char* P_letter)   // returns the most repeated letter in by pointer (input is addr) & the number of its repetitions
{
    str_lower2upper_case(str);   //unifying the letters' case

    int repetition = 0, count =0;

    for (int i = 0 ; str[i] ; i++)
    {
        count = 0;      // to count for the next element

        for (int j = i ; str[j] ; j++)
        {
            if(str[i]==str[j])
            {
                count++;
            }

        }

        if(count>repetition)
        {
            repetition = count ;
            *P_letter = str[i]  ; // to return the most repeated letter
        }

    }

    return repetition; // to return number of repetitions
}

/*********************************************/

int str_remove_most_repeated_incopy (char* str,char* new_str)
{
    str_upper2lower_case(str);   //unifying the letters' case

    int repetition = 0, count =0,k=0;
    char letter;                    // not Pointer as all will  happen in this func

    for (int i = 0 ; str[i] ; i++)
    {
        count = 0;      // to count for the next element

        for (int j = i ; str[j] ; j++)
        {
            if(str[i]==str[j])
            {
                count++;
            }

        }

        if(count>repetition)
        {
            repetition = count ;
            letter = str[i]  ; // to return the most repeated letter
        }

    }

    for (int i = 0 ; str[i] ; i++)
    {

        if(str[i]!=letter)
        {
            new_str[k]=str[i];
            k++;
        }

    }

    new_str[k]=0;

    return str_length(new_str); // to return length of new str
}

/*********************************************/

int str_remove_repeated_incopy (char* str,char* new_str) // take 1 copy of a repeated letter - delete other copies
{
    str_upper2lower_case(str);   //unifying the letters' case

    int i,j,k=0,flag;

    for (i = 0 ; str[i] ; i++)
    {
        flag=0;
        for(j=0; j<i; j++)   //loop from beginning to the element to see if arr[i] is repeated-- if found before don't take it -- remove the copies only
        {
            if(str[i]==str[j] && str[i]!=' ')  // we don't need to remove spaces here
            {
                flag=1;
            }
        }
        if (flag==0)            // if not found repeated
        {
            new_str[k]=str[i];
            k++;
        }
    }

    new_str[k]=0;

    return str_length(new_str) ;  // length of new array

}
/*********************************************/

int str_longest_word (char* str, char* longest_word )    // returns the no. of letters of the longest word + str containing longest word
{
    int max =0, count = 0, i, j, word_index ;


    for (i=0 ; str[i] ; i++)  // loop to find length of longest word
    {
        count++;


        if (str[i]==' ')
        {
            count = 0;
        }

        else if (count > max)
        {
            max = count;
            word_index = i; // index of 'last' letter in longest word
        }


    }

    word_index = (word_index - max) +1; // now word index is at 1st letter of the longest word

    for (j=0 ; j<max ; j++)         // or condition may be (str[word_index] !=' ' && str[word_index] != 0)
    {
        longest_word[j]=str[word_index];     // loop to assign the longest word into a string
        word_index++;
    }

    longest_word[j]=0;   // assigning null after the word to set the length of the string right -- VIP step -- j=max here

    return max ;
}


/************************************************/

void int2string (int n, char* str)    // useful in dealing with screens
{

    int i = 0, flag=0;

    if (n==0)
    {
        str[i]='0'; // to print 0
        str[i+1]=0; // to assign null
        return ;    // to exit the VOID func
    }

    if (n<0)
    {
        flag=1;
        n = -1*n ;  // to be +ve >0
    }

    while(n>0) // positive or negative
    {

        str[i]= n%10 + '0'; // turn it to ascii  -- number will be reversed -- deal with later
        n=n/10;
        i++;  // assign from i =0 then increment

    }

    if (flag==1)
    {
        str[i]='-'; // it will be at last of str but the str will be reversed
        i++;
    }

    str[i]=0; // null for last element (after -ve if existed)

    str_reverse(str); // 3shan a3del el rqm tani

}

/*********************************************/

int str2int (char* str)   //useful in performing mathematical operations on numbers on screens   // returns the integer
{
    int n=0,i=0,j=1,flag=0;

    if (str[i]==' ')  // if it starts with space
    {
        i++;
    }


    if (str[i]=='-')
    {
        flag=1;
        i++;      // if -ve i will be 1  .. if +ve i remains zero
    }


    while (str[i] && str[i]!=' ')  // solving the issue of ' ' at end of string -- SECURE
    {
        n=n*10 + (str[i]-'0');
        i++;
    }

    if (flag==1)
    {
        n=n*-1;
    }

    return n;
}

/*********************************************/

/*********************************************/

/*********************************************/

void str_no_corner_cases (char* str, char* edited_str) //split all words by 1 space for sure -- sure no space at the beginning or at end after using
                                                       // only takes letters and numbers with one space between each two words
                                                       // original string kept as it is
{

    int i,flag=22, flag2=1,j=0;       //flag not equal zero but any number else
    int L = str_length(str);


    for (i = 0 ; str[i] ; i++)
    {
        if (flag!=0 && ((str[i]>='A' && str[i]<= 'Z') || (str[i]>='a' && str[i]<= 'z') || (str[i]>= '0' && str[i]<= '9')))
                                                                                            // add any range you want to except here
                                                                                           // it will neglect each of these spaces at beginning or end
        {
            edited_str[j]=str[i];
            j++;
            if (str[i+1]==' ' || str[i+1]=='&' || str[i+1]==',' || str[i+1]=='.')
            {
                flag=0;     // to enter else if again but only after entering here - won't take these shapes at the beginning
            }

            flag2++;    // if last assigned is letter we will know
        }

        else if (flag==0)   // anything else + flag=0
                          //only 1 space for whatever no. of these shapes
        {

                edited_str[j]=' ';
                j++;
                flag++;
                flag2=0; // to know if we have space at last

        }

    }

    if (flag2==0)
    {
     edited_str[j-1]=0;   // null instead of useless space at end
    }

    else
    {

    edited_str[j]=0; // null after last word
    }
}

/************************************************/

int str_search_word (char* str, char* word)  // search for a certain "word" string and returns its index in original if found -- if not returns -1
{
    int L1 = str_length(str);
    int L2 = str_length(word);
    int i=0,j=0, index;

    if (L2 > L1)   // can't be
    {
        return -1;
    }

    while( word[j] && str[i])
    {



        if (str[i]==word[j] || str[i]==word[j]-('a'-'A') || str[i]==word[j]+('a'-'A') ) // solving capital & small  // when find 1st letter to reduce time
        {
            i++;
            j++;
        }

        else
        {
            i++; // el i kda kda mashi L oddaam
            j=0; // el word mn el awl tani 3shan adwr tani mn awl 7rf

        }

        if (j==L2-1)  // wselt L a5er index fel word yb2a la2et-ha kollaha
        {
            //printf("index1=%d\n",i);
            index = i-L2+1;
            return index;
        }


    }


    return -1; // not found
}


/*********************************************/
/*****************Sheet (4)*******************/
/*********************************************/
/*******************(2)***********************/

int str_mirror_or_not (char* str)   // if yes return 1 - no return 0
{
    int L = str_length(str);

    if ((L%2) == 0 ) // to be mirror - L must be odd
    {
        return 0;
    }

    for (int i = 0 ; i < L/2 ; i++) //excluding the mid letter
    {
        if (str[i]!=str[(L-i)-1])
        {
            return 0;
        }
    }

    return 1;

}

/*******************(3)MODIFIED***********************/

void str_reverse_words_original (char* str)  // no any copies or external strings
{

    int L=str_length(str);
    str_reverse(str); // 1st- reversing whole string


    int i=0, space_index, j=0, k=0,l=0, word_length, space_end_flag ;
    char temp;

repeat_till_last_word :

    space_end_flag =0;

    while(str[i])
    {
        if (str[i]==' ')
        {
            space_end_flag++;
            space_index = i;
            i++;
            break;
        }
        else
        {
            i++;
        }


    }

    if (space_end_flag==1)
    {
        k=space_index-1;
        word_length = space_index-j;
        i++;          // to return to the upper loop with the 1st letter of next word
    }

    else // last word only
    {
        word_length = L-j;
        k= L-1;
    }

    for (l=0 ; l<(word_length/2); l++) //re-reversing one word
    {
        temp=str[j];
        str[j]=str[k];
        str[k]=temp;
        j++;
        k--;
    }

    j=space_index+1; //to skip copying the space which is already there

    if (space_end_flag==1)
    {
        goto repeat_till_last_word;
    }


}


/*******************(4)***********************/

void str_triangle_type (char* str, char* tri_type)

{
    int i;
    int L1=0, L2=0, L3=0, L4=0 ;     // dimensions // L4 for check - if not zero - not triangle
    int L_str = str_length(str);
    int flag=0 ;


    for (i=0 ; str[i]; i++)           // loop to convert each dimension in the string to a separate integer length
    {

        if (str[i] == ' ' && i != 0 && i!= (L_str-1) ) // solving space issue at the beginning or end
        {
            flag++;   // flag =1 , 2
        }

        else
        {

            if (flag==0)
            {
                L1=L1*10 + (str[i]-'0');
            }

            else if (flag==1)
            {
                L2=L2*10 + (str[i]-'0');
            }
            else if (flag==2)
            {
                L3=L3*10 + (str[i]-'0');
            }
            else if (flag==3)  // for check only
            {
                L4=L4*10 + (str[i]-'0');
            }
        }
    }


    if ( L1 !=0 && L2 !=0 && L3 !=0 && L4 == 0 && (L1<(L2+L3)&& L2<(L1+L3)&& L3<(L1+L2)) )

        // triangle -- if L4=0 && any side is less than the sum of the other 2 sides
    {
        if (L1 == L2 && L1 == L3 )  // equilateral
        {
            str_copy("Equilateral triangle ",tri_type);
        }
        else if (L1 == L2 || L1==L3 || L2 == L3)  // isosceles
        {
            str_copy("Isosceles triangle ",tri_type);
        }
        else if (L1!=L2 && L1 != L3 && L3 != L2)        //scalene
        {
            str_copy("Scalene triangle",tri_type);
        }
    }


    else    // not triangle
    {
        str_copy("Not triangle",tri_type);
    }

}

/*******************(5)***********************/

void flt2str (float n,char* str)
{
    char str1[30]= {0};
    char str2 [30]= {0};
    int n1,n2,n3,i=0,j=0,k=0;
    int zeroes_before_fraction=0,flag=0,flag2=0;
    int L1, L2;

    if (n<0)
    {
        n=n*-1;
        flag2++;
    }

    n1 = n;   //part before point
    n= n-n1;
    n2 = n *1000000000; // part after point enlarged to be int *10^9

    int2string(n1,str1);
    int2string(n2,str2);

    L1 = str_length(str1);
    L2 = str_length(str2);

    zeroes_before_fraction = 9 - L2;  // counting zeros right after point (before the no. after point)


    for (j=(L2-1) ; j>=0 ; j--) // to count if there's zeros before the no. after the point      // loop to edit str2
    {
        n3 = n2 %10;
        n2=n2/10;

        if (n3!=0)
        {
            flag++;
        }

        if (flag==0)
        {
            str2[j]=0;     //removing useless zeros from the string2 from the end
        }
    }


    L2 = str_length(str2); // new length after removing useless zeros

//concatenation both in str

    if (flag2!=0)
    {
        str[i]='-';
        i++;
    }

    for(k = 0 ; k<L1 ; k++)
    {
        str [i] = str1[k];
        i++;
    }

    str[i]='.';
    i++;

    for (j=0 ; j<zeroes_before_fraction ; j++) // if no zeros before - won't enter the loop
    {
        str[i]='0';
        i++;
    }

    for(j = 0 ; j<L2 ; j++)
    {
        str [i] = str2[j];
        i++;
    }

    str[i]=0; // null at end


}


/*******************(6)***********************/

void str_find_and_replace (char* main, char* find, char* replace, char* returned)
{

    int found_index = str_search_word (main,find); //index of the found word in main str


    if (found_index!=-1)
    {

        for (int i=0 ; replace[i]; i++)
        {
            main[found_index]=replace[i];
            found_index++;

        }

    }

    str_copy(main,returned);

}


/*******************(7)***********************/

void str_words_print_number (char* str)
{

    //static char str[] = {0};
    //str_no_corner_cases(str1,str); // edited string to have spaces only
    //print_str(str);

    char str_1st_num[10]= {0};
    char str_2nd_num[10]= {0};
    char str_1st_word[50]= {0};
    char str_2nd_word[50]= {0};
    int i,j=0,k=0,l=0,m=0;     //indexes
    int n1, n2, index1, index2;
    int length_1st_word, length_2nd_word;
    int spaces_count=0;



    for (i =0 ; str[i] ; i++)   // dividing the string into 4 strings
    {
        if (str[i]==' ' || str[i]==',' )
        {
            spaces_count++;

        }

        if(spaces_count=0 && str[i]!=' ' && str[i]!=',')   // 1st word assigned to string_word 1
        {
            str_1st_word[l]=str[i];
            l++;
        }

        if (spaces_count ==1 && str[i]!=' ' && str[i]!=',')  //assigning 1st number to string_num 1
        {
            index1 = i;
            str_1st_num[j]=str[i];
            j++;
        }

        if(spaces_count=2 || str[i]!=',')   // 2nd word assigned to string_word 2 -- 2nd word here may be sentence
        {
            str_2nd_word[m]=str[i];
            m++;
        }


        if (spaces_count ==3 && str[i]!=' ' && str[i]!=',')  //assigning 2nd number to string_num 2
        {
            index2 = i;
            str_2nd_num[k]=str[i];
            k++;
        }
    }

    str_1st_word[l]=0;
    str_2nd_word[m]=0;
    str_1st_num[j]=0;
    str_2nd_num[k]=0;




    if (spaces_count==3)
    {

        if (str_1st_num[0]=='-' && str_2nd_num[0]=='-')
        {
            printf("Numbers must be positive\n");
        }



        else
        {
            n1=str2int (str_1st_num);   // now both numbers are in integers
            n2 = str2int (str_2nd_num);

            length_1st_word = (index1 -2) +1;  // (index1 -2) = (index of last charecter in 1st word)    +1 = length of 1st word
            length_2nd_word = (index2 -2) +1;


            if (n1>0)
            {
                for (i= 0 ; i< n1 ; i++)
                {
                    printstr(str_1st_word);
                }
            }

            if (n2>0)
            {
                for (i= 0 ; i< n2 ; i++)
                {
                    printstr(str_2nd_word);
                }

            }

        }
    }




    else
    {
        printf("Wrong input!\n ");
    }

}


/*********************return string************************/

long str_return (void)
{
    static char str[]="khaled";

    return str;
}

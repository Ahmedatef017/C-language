
// this file contains array & string funcs same as before but optimized

/*********************************************/

int array_binary_search (int* arr , int size , int n)   // returns index of the number you search for -- o(logn) // array must be sorted to work
                                                        // if not found returns -1
{
 int first =0, middle, last=size-1;      //indexes of binary search

    while(first<=last)
    {
        middle = (first+last)/2;

        if(arr[middle]==n)
        {
            return middle;

        }

        else if (arr[middle]>n)    // so n in the 1st half
         {

            last = middle-1;   // middle itself not needed

        }

        else
        {
            first = middle+1; // 2nd half

        }

    }

   return -1;
}

/*********************************************/

int array_most_repeated_op (int* arr, int size,int* pelement)  // returns no. of repetitions & the most repeated element by a pointer
{
    int flag=0;
    int max = arr[0], min=arr[0];
    int count_size, element;
    int* freq_arr;

    for (int i=0 ; i<size ; i++)
    {

        if (arr[i]>max)
        {
            max = arr[i];
        }

        if (arr[i]<min)
        {
            min = arr[i];
        }
    }

    count_size = max - min + 1 ;
    freq_arr = (int*)calloc(count_size,sizeof(int)); // calloc sets all zeroes (always with freq array ) - don't forget casting calloc
    // malloc may have garbage ---> so you must write after it freq_arr={0}

    if (freq_arr!=0)
    {

        for (int i=0 ; i<size ; i++)
        {
            freq_arr[arr[i]-min]++;   //-min as min may not = 0 .. so our start is not 0 but 3 // so min is offset

        }

        for (int i =0 ; i< count_size ; i++)
        {
            if (flag==0)
            {
                max=freq_arr[i];
                flag++;
            }

            if (freq_arr[i]>max)
            {
                max = freq_arr[i];
                *pelement = i + min; //reset the index with the "min" offset to return the value right
            }

        }

    }


    else
    {
        printf("No Memory! \n");
        return;
    }

    free(freq_arr); // i have both data needed - so freq_arr not needed anymore

    return max;  // max count


}


/*********************************************/

int str_most_repeated_char (char* str,char* pelement)   // returns no. of repetitions -- returns the charecter by a pointer
{
    char freq_str[256]= {0};
    int i, repetitions =0;

    for (i=0 ; str[i] ; i++)
    {
        freq_str[str[i]]++;

        if (freq_str[str[i]]>repetitions)
        {
            repetitions = freq_str[str[i]];
            *pelement = str[i];
        }
    }


    return repetitions;

}

/*********************************************/





/*********************************************/

/*******************Sheet(5)*******************/

/*********************1************************/


int arr_find_missing_1_100 (int* arr, int size)
{
    int n;

    for (int i = 0 ; i<99 ; i++)
    {
        if ((arr[i]+1) != arr[i+1])
        {
            n= arr[i]+1;
            return n;
        }

    }

}

/********************2*************************/

int arr_find_repeated_1_100 (int* arr, int size)
{

    int n ;

    for (int i = 0 ; i<101 ; i++)
    {
        if ((arr[i] == arr[i+1]))
        {
            n= arr[i];
            return n;
        }

    }

}

/*******************3*************************/


int arr_int_repeated1_all_repeated2 (int* arr, int size)

{
    int xor=0;  // starting - any number x-ored with zero = the number
    int* freq_arr;

    for (int i =0 ; i<size ; i++)
    {
        xor = arr[i] ^ xor; //any number repeated (x-ored with itself) will be zero..last result will be the not repeated
    }

    return xor;

}


/*******************4-MODIFIED**************************/


int arr_int_repeated1_all_repeated2_sorted (int* arr, int size) // O(logn)
{
    int first =0, middle, last=size-1;   //indexes of binary search

    while(first<=last)
    {
        middle = (first+last)/2;

        if((arr[middle]!=arr[middle+1]) && (arr[middle]!=arr[middle-1]))
        {
            return arr[middle];

        }


        else if ((middle%2 == 0 && arr[middle]==arr[middle+1]) || (middle%2 == 1 && arr[middle]==arr[middle-1]) ) // explanation in notebook - session 20

        {
            first = middle+1;                   // el impostor ba3di - 2nd half

        }

        else if ((middle%2 == 0 && arr[middle]==arr[middle-1]) || (middle%2 == 1 && arr[middle]==arr[middle+1]))
        {
            last = middle+1;      // el impostor abli - 1st half

        }

    }

    return -1;

}


/*********************5************************/

int arr_most_repeated_mono (int* arr, int size, int* pelement)     //numbers from 0 to 9 only // o(n)
{
    int freq_arr[10]= {0};
    int freq_size = sizeof(freq_arr)/sizeof(freq_arr[0]);
    int i, repetitions=0;

    for (i=0 ; i<size ; i++)
    {
        freq_arr[arr[i]]++;
    }

    for (i=0 ; i<freq_size ; i++)
    {
        if (freq_arr[i]>repetitions)
        {
            repetitions = freq_arr[i];
            *pelement = i;
        }
    }

    return repetitions;


}



/********************6*************************/

char str_first_repeated_char (char* str)   // returns no. of repetitions -- returns the charecter by a pointer
{
    char freq_str[256]= {0};

    for (int i=0 ; str[i] ; i++)
    {
        freq_str[str[i]]++;

        if (freq_str[str[i]]==2)
        {
            return str[i];
        }
    }



}

/***********************7**********************/


void str_remove_repeated_copy_optimized (char* str,char* str_copy)   // returns no. of repetitions -- returns the charecter by a pointer
{
    char freq_str[256]= {0};
    int i, j;

    for (i=0 ; str[i] ; i++)
    {
        freq_str[str[i]]++;       // if you want to keep spaces add :- if(freq_str[str[i]] != ' ')

        if (freq_str[str[i]]<2)  // because we want only 1 copy from repeated
        {
            str_copy[j]=str[i];
            j++;
        }

    }
    str[j]=0; // null at end
}



/*********************8************************/

int arr_copy_before_given_number (int* arr, int size, int* new_arr, int n)  // returns new size & the new arr in int* pointer
{

    int i,j=0, new_size=0;


    for (i=0 ; i<size ; i++) // loop to calculate size of new array
    {
        if (arr[i]!= n)
        {
            new_size++;
        }
        else
        {
            break;
        }
    }




    //new_arr = (int*) malloc(new_size*sizeof(int));


    if (new_arr!=0)   // loop to copy
    {

        for (i=0 ; i<new_size ; i++)
        {
            new_arr[i]=arr[j];
            j++;

        }

        return new_size;
    }

    else
    {
        return 0;
    }
}


/********************(9-a)MODIFIED*************************/


void swap_bytes_of_short_temp (unsigned short * n)  // sending addr of a short
{

unsigned char* p = n;	// assigning addr of short to a char pointer
unsigned char temp= *p; // or temp=p[0]; (1st byte)

*p = p[1];              // so now 2nd byte in the 1st byte of n
p[1]=temp;             // swapped.


}

/********************(9-b)MODIFIED*************************/


void swap_bytes_of_short_bitwise (unsigned short * n)  // sending addr of a short
{

unsigned short* p = n;	// assigning addr of short to a SHORT pointer

*p = ((*p)>>8 | (*p)<<8);   // 0x0055 | 0xff00 = 0xff55 // swapped in n itself.

}
/*********************8************************/









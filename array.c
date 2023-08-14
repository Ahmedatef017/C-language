
// This file contains array functions

/*****************1*************************/

int array_search(int* array, int size, int n)    //return its place if found & -1 if not found
{
    for (int i = 0 ; i<size ; i++)
    {
        if (array[i]==n)
        {
            return i;
        }
    }
    return -1;

}

/*****************2*************************/

void printarr (int* arr, int size)   //------>Void
{
    unsigned char flag=0;
    printf("{ ");
    for(int i =0 ; i<size ; i++)
    {
        if (flag==0)
        {
            printf("%d",arr[i]);
        }
        else
        {

            printf(" , %d",arr[i]);
        }
        flag++;
    }
    printf(" }\n");

}

/*****************3*************************/


int array_remove_prime (int *array, int size)    // make prime elements = 0
{
    int count = 0, i;

    for (int i = 0 ; i<size ; i++)
    {
        if (IsPrime(array[i])==1)
        {
            array[i] = 0;
            count++;
        }
    }

    return count;

}

/******************4************************/

int array_scan (int* arr, int max_size)  // making and returning an array for main --- بتيديلها مصفوفة فاضية وهي بتملاها وترجعها --- returns the size
{
    // EDITED TO BE SECURED - to not overwrite unknown data of ram [maxsize] - secured

    int i, size ;    // i is index .. (max i = size-1)

    printf("Enter size of array : \n");
    scanf ("%d",&size);

    if(size>max_size)
    {
        size = max_size;    // SECURED.
    }
    printf("Enter the elements of the array : ");
    for (i=0 ; i<size ; i++)
    {
        scanf("%d",&arr[i]);     //or scanf(arr+i); ---> ass arr+i is already address , no need for "&"
    }

    return size; // to print only the size filled in the function
}


// must save the return size in variable x - then print_array(arr,x) -- or :-
//print_array (arr2 , array_scan(arr2)); in one direct line


/******************5************************/

int array_longest_series (int* arr, int size)
{
    unsigned int count = 0, max = 0;

    for (int i=0 ; i<size ; i++)
    {

        if ((arr[i+1]-arr[i])==1)
        {
            count++;
            if (max<count)
            {
                max = count;

            }
        }
        else
            count = 0;
    }
    return max+1;  //because the last number in the sequence won't be counted and it will go to "else" not "if" .. so we count it manually

}



/******************6************************/


int array_copy (int* source, int source_size, int* copy, int max_size)  // copies an array to another array // max_size = copy array size - SECURED Function
//  to prevent writing in places outside array
{
    int i,size;     // the actual size i will work with

    if(source_size>max_size)

    {
        size = max_size;     // can't exceed the max copy size whatever the source size is
    }

    else  // we take the smaller size to edit the only needed data only - مش لازم أملاه كله عادي

    {
        size = source_size ;     // can't exceed the max copy size whatever the source size is   // secured .
    }

    for (int i = 0 ; i<size ; i++)
    {
        copy[i]=source[i];  // el trtib mohem
    }

    return size;
}

/*****************7*************************/

int array_most_repeated (int* arr, int size, int* Pelement)   // returns the most repeated number in an array by pointer & the number of its repetitions
{
    int repetition = 0, count =0;

    for (int i = 0 ; i<size ; i++)
    {
        count = 0; // to count for the next element
        for (int j = i ; j<size ; j++)   // J may not start from zero but from i - مش لازم ارجع للي عديته
        {
            if(arr[i]==arr[j])
            {
                count++;
            }

        }

        if(count>repetition)
        {
            repetition = count ;
            *Pelement = arr[i]  ; // to return the most repeated element
        }

    }

    return repetition; // to return number of repetitions
}


/*****************8*************************/

//AGAIN - WITHOUT NESTED FOR - sorted elements

int array_most_repeated_sorted (int* arr, int size, int* Pelement)   // returns the most repeated number in an array by pointer & the number of its repetitions
{
    int repetition = 0, count =0;

    for (int i = 0 ; i<size ; i++)
    {
        if(arr[i]==arr[i+1])
        {
            count++;
            if(count>repetition)
            {
                repetition = count;
                *Pelement = arr[i];
            }
        }
        else
        {
            count = 0;
        }

    }


    return repetition+1; // to return number of repetitions
}


/******************************************/
/******************************************/
//Sheet 3
/******************************************/
/*******************9***********************/

int array_last_occurence(int* array, int size, int n)    //return its place if found & -1 if not found
{
    for (int i = size-1 ; i>=0 ; i--)
    {
        if (array[i]==n)
        {
            return i;
        }
    }
    return -1;

}

/*******************10***********************/

int array_max_min (int* arr, int size, int* Pmin, int* Imax, int* Imin)     // Returns maximum element in array + min elem + imax + imin
{
    int max=arr[0],min=arr[0];

    for (int i = 0 ; i<size ; i++)
    {
        if (arr[i]>=max)  // "<=" to take the index of the 1st element if it's the largest
        {
            max=arr[i];
            *Imax = i;
        }
        if (arr[i]<=min) // "<=" to take the index of the 1st element if it's the smallest
        {
            min=arr[i];
            *Imin = i;
        }

    }
    *Pmin = min;

    return max;
}

/*****************11*************************/


int array_bet2numbers (int*arr, int n1, int n2)
{

    int i, size, max=0, min=0 ;      // i is index .. (max i = size-1)

    if(n1!=n2)
    {


        max = n1>n2?n1:n2;
        min = n1<n2?n1:n2;

        size = (max-min)-1;

        for (i= 0 ; i< size ; i++)
        {
            min++;
            arr[i] = min ;

        }

        return size;
    }
    else
        return 0 ;
}

/****************12**************************/


int array_reverse_copy (int* source, int size, int* reverse)
{
    int i,r;

    r=size-1; // reverse index

    for (int i = 0 ; i<size ; i++)
    {
        reverse[(size-i)-1]=source[i];  //input reversed

    }

    return size;
}

/*****************13*************************/

void array_reverse_original (int* arr, int size)  // reverse on itself using swapping
{
    int i,temp;

    for (i = 0 ; i<size/2 ; i++)   // (size/2) because if whole size it will return to original..we walk half the distance - notebook session 10 last
    {
        temp = arr[i];
        arr[i]=arr[(size-i)-1];
        arr[(size-i)-1]=temp;
    }

}

/*****************14*************************/

int array_swap(int * arr1, int size1, int* arr2,int size2 )     //take the bigger size
{
    int i,size,temp;     // the actual size i will work with

    size=size1>=size2?size1:size2;

    for (i = 0 ; i<size ; i++)
    {
        temp = arr1[i];
        arr1[i]=arr2[i];
        arr2[i]=temp;
    }

    return size;
}

/*****************15*************************/

int array_longest_occurence_givenN (int* arr, int size, int n)   //series متصلة from a given number in array
{
    unsigned int count = 0, max = 0;

    for (int i=0 ; i<size ; i++)
    {

        if (n==arr[i])
        {
            count++;
            if (max<count)
            {
                max = count;
            }
        }
        else
            count = 0;
    }
    return max;

}

/*****************16*************************/

int array_longest_occurence_returned (int* arr, int size, int* pelement)   // most repeated number in a series
{
    unsigned int count = 0, max = 0;

    for (int i=0 ; i<size ; i++)
    {

        if (arr[i]==arr[i+1])
        {
            count++;
            if (max<count)
            {
                max = count;
                *pelement = arr[i];
            }
        }
        else
            count = 0;
    }
    return max+1;

}


/*****************17*************************/

int array_merge (int* arr1, int size1, int* arr2,int size2, int* merged_array) // modified to merge and complete elements from larger array
{
    int i,new_size,j=0,k=0, merge_size;
    new_size = size1+size2;                         // the whole size (merged + completed from the larger array if there's any)
    merge_size = size1<size2?(2*size1):(2*size2);  // double the smaller size
    //printf("%d\n\n",merge_size);

    for (i = 0 ; i<new_size ; i=i+2)              // increment by 2 as it takes 2 values at a time
    {
        if(i<merge_size)                         //merging process condition
        {
            // merged array will take from both at only one loop execution

            merged_array[i] = arr1[j];    // for even elements starts from 0
            merged_array[i+1] = arr2[j];  // for odd elements starts from 1
            j++;                          // increment for elements of both arrays
        }

        else                              //we exceeded the merge size
        {
            if (size1>size2)              //completing from 1st array if it's larger
            {
                merged_array[i] = arr1[j];
                merged_array[i+1] = arr1[j]; // both from arr1 - 2 steps because i is incremented by +2 not 1
                j=j+2;                       // not j++ here , increment of j must be same as i
            }

            else                             //completing from 2nd array if it's larger
            {
                merged_array[i] = arr2[j];
                merged_array[i+1] = arr2[j];   // both from arr2 - 2 steps because i is incremented by +2 not 1
                j=j+2;                       // not j++ here , increment of j must be same as i
            }
        }


    }
    return new_size;
}

/*****************18-MODIFIED*************************/

// this function means if there's repeated no. .. take it only one time and remove the repititions ,, not remove (all repetitions + original)

int array_remove_repeated_incopy (int* arr, int size, int* new_arr) // sorted or not - remove them not make them 0 // returns size of new array
{
    int i,j,k=0,flag;

    for (i = 0 ; i<size ; i++)
    {
        flag=0;
        for(j=0; j<i; j++)   //loop from beginning to the element to see if arr[i] is repeated-- if found before don't take it
        {
            if(arr[i]==arr[j])
            {
                flag=1;
            }
        }
        if (flag==0)            // if not found arr[i] repeated
        {
            new_arr[k]=arr[i];
            k++;
        }
    }
    return k ; // size of new array as it differs from original size -- size != k+1 -- see notebook session 12 last page if not understandable

}


/*****************18-a*************************/


void array_remove_repeated_sorted (int* arr, int size, int* new_arr) // sorted only - make them zero  //void as the size & new array are know by user
{
    int i=0 ;

    new_arr[i]=arr[i]; // initialization

    for (i = 0 ; i<size ; i++)
    {
        if(arr[i]==arr[i+1])
        {
            new_arr[i]=0;
            new_arr[i+1]=0;       //to solve the problem of the last repeated number in a sequence
        }
        else
        {
            new_arr[i+1]=arr[i+1];   // if not repeated - step 2 of solving last repeated number in a sequence
        }
    }

}


/*****************19*************************/

void array_swap_after2zeros (int* arr)  // swap on itself using  --- unkown size = don't take size
{
    unsigned char flag=0;
    int i,j,temp,first_zero,second_zero;

    for (i = 0 ; flag < 2 ; i++) // not necessiraly the middle condition is in terms of (i) also
    {
        if (arr[i]==0 && flag ==0)
        {
            first_zero =i;  //saving index of 1st zero
            flag++;
        }
        else if (arr[i]==0 && flag==1)    // must be else if to not assign the same zero -- if "if" it will enter it في نفس اللفة
        {
            second_zero =i; // saving index of 2nd zero

            if((second_zero - first_zero)>3) // making sure that there's 3 elements or more between them
            {
                flag++;
            }
        }

    }

    if(flag==2)
    {


        swap (&arr[first_zero+1],&arr[second_zero+1]);  // "&" as it takes addresses
        swap (arr+first_zero+2,arr+second_zero+2);      // another solution for sending address instead of "&"
        swap (&arr[first_zero+3],&arr[second_zero+3]);
    }

}


/*****************20*************************/

int array_largest_difference_small_1st (int* arr, int size)  // returns max difference bet 2 numbers in 1 array - small must come 1st or return 0
{
    int i,k=0;
    int max_diff=0, diff ;

    for (k=0 ; k<size-1 ; k++)   //not needed to size , to decrease time consumption -- as i starts from last element also

    {
        for (i = size-1 ; i>k ; i--)  //from last to k only - so max will be ahead of min - ensured
        {
            diff=arr[i]-arr[k];

            if(diff>max_diff)
            {
                // printf("max = %d    min= %d    \n",arr[i],arr[k]);
                max_diff=diff;
            }
        }

    }


    return max_diff;

}

/*****************21*************************/

void swap_pointers(int** px, int** py)   //swap any 2 pointers  ------VOID -     // must takes addresses of pointers as inputs (&p1,&p2)
{
    int* temp = *px;  // temp is as same type of the variables - here the variables are pointers
    *px = *py;        // 1st pointer contains the 2nd address now
    *py = temp;       // not = *temp as *temp=x not px ,, نفس الرتبة temp & px ,, // swapped.
}

/*****************22*************************/

void array_fibonacci (int* arr, int n)
{
    int i;
    arr[0]=0;
    arr[1]=1;    // initializing fibonacci series



    for (i = 2 ; i<n ; i++ )
    {
        arr[i]=arr[i-1]+arr[i-2];

    }
    //return arr[i]; // i = n-1 --> i starts from zero , input n starts from 1
}


/*****************23*************************/

/*****************16*************************/

/*****************16*************************/



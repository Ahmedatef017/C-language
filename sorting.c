

// SORTING ALGORITHMS

/*********************************************/


void array_bubbleSort_ascending (int*arr,int size)
{
    int i,j,sorted_flag;

    for(j=0;j<size;j++)   // rotate b 3adadd el elements (worst case)
    {
        sorted_flag=1;
        for(i=0;i<size-1-j;i++)   // i<size-1 3shan maqarensh a5er element b garbage barra
		                          // i<size-1-j 3shan kda kda a5er element mzboot
        {
            if(arr[i]>arr[i+1])   // only difference between ascending (>) - descending (<)
            {
                swap(&arr[i],arr+i+1);
                sorted_flag=0;
            }

        }

        if(sorted_flag==1) // mada5alsh el condition ? so mtrtbin 5las - twfir w2t
        {
            break;         // or return
        }

    }
}


/*********************************************/

void array_bubbleSort_descending (int*arr,int size)
{
    int i,j,sorted_flag;

    for(j=0;j<size;j++)   // rotate b 3adadd el elements (worst case)
    {
        sorted_flag=1;
        for(i=0;i<size-1-j;i++)   // i<size-1 3shan maqarensh a5er element b garbage barra
		                          // i<size-1-j 3shan kda kda a5er element mzboot
        {
            if(arr[i]<arr[i+1])   // only difference between ascending (>) - descending (<)
            {
                swap(&arr[i],arr+i+1);
                sorted_flag=0;
            }

        }
        if(sorted_flag==1) // mada5alsh el condition ? so mtrtbin 5las - twfir w2t
        {
            break;         // or return
        }

    }
}


/*********************************************/

void sort_selection_ascending (int*arr,int size)
{
 int max, max_index , i;

 for (int j=0 ; j<size ; j++)
 {
   //max = arr[0];                                 // lazem kol mrra 3shan maye7tafez-sh b akbr rkm dymn (not needed)
   max_index = 0;                                // lazem el index bta3 awl element t-assigno hna 3shan lw mala2ash akbr mn awl element y3rf el index

   for (i =0 ; i<size-j ; i++)                   // excluding last element every loop
   {
    if (arr[max_index]<arr[i])
    {
     //max = arr[i];                           (not needed)
     max_index = i;
    }

   }                                               // (i) will be at last element (size-j)

    swap(&arr[i-1],&arr[max_index]);               //(i-1) because (i) will exit the array - byt7a22a2 el shrt eli y5arragak mn el loop
                                                  // privilege :- swap only n times..faster if the elements of arr have big bytes of memory
                                                 // swapping was n^2 in bubble
}

}

/*********************************************/


void sort_selection_descending (int*arr,int size)
{
    int i,min_i,last_i,j;
    last_i=size-1;

    for(i=0;i<size;i++)
    {
        min_i=0;

        for(j=0;j<size-i;j++)
        {
            if(arr[min_i]>arr[j])
            {
                min_i=j;
            }

        }
        swap(&arr[min_i],&arr[last_i]);
        last_i--;

    }

}

/*********************************************/

void sort_counting_ascending (int*arr,int size)
{
    int max=arr[0],min=arr[0],count_size,i,j;
    for(i=0;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        if(arr[i]<min)
        {
            min=arr[i];
        }

    }
    count_size=max-min+1;

    int*count=(int*)calloc(count_size,sizeof(int));

    if(count==0)  // no memory
    {
        return;
    }

    for(i=0;i<size;i++)   // to fill up the freq arr use original arr size not count size
    {
        count[arr[i]-min]++;

    }

    i=0;     // from beginning again to sort  (ascending)

    for(j=0;j<count_size;j++)   // to perform sorting -- use count size not original arr size - // also both nested loop are o(n)
                                // 3adadd el e7tmalat (n) * tekrar kol e7tmal (3 msln) --> o(3n) = o(n)
    {
        while(count[j])        // only enter if there's no. .. if zero won't enter (the element is not in the arr)
			                   // so it will enter n times (n=original size of the arr at worst case (each no. exists 1 time))
        {
            arr[i]=j+min;     // the index is the element + offset
            count[j]--;       // to enter less time at the same element and exist when count[j] =0
            i++;
        }

    }
    free(count);        // not needed anymore ? free then

}


/*********************************************/

void sort_counting_descending (int*arr,int size)
{
    int max=arr[0],min=arr[0],count_size,i,j;
    for(i=0;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        if(arr[i]<min)
        {
            min=arr[i];
        }

    }
    count_size=max-min+1;

    int*count=(int*)calloc(count_size,sizeof(int));

    if(count==0)  // no memory
    {
        return;
    }

    for(i=0;i<size;i++)   // to fill up the freq arr use original arr size not count size
    {
        count[arr[i]-min]++;

    }

    i=size-1;     // from last element ( descending )

    for(j=0;j<count_size;j++)   // to perform sorting -- use count size not original arr size
    {
        while(count[j])        // only enter if there's no. .. if zero won't enter (the element is not in the arr)
			                   // so it will enter n times (n=original size of the arr at worst case (each no. exists 1 time))
        {
            arr[i]=j+min;     // the index is the element + offset
            count[j]--;       // to enter less time at the same element and exist when count[j] =0
            i--;              // (descending 2nd difference)
        }

    }
    free(count);        // not needed anymore ? free then

}

/*********************************************/

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void sort_quick_ascending (int arr[], int low, int high)  // takes size as (0,size-1)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        sort_quick_ascending(arr, low, pi - 1);
        sort_quick_ascending(arr, pi + 1, high);
    }
}


/*********************************************/
/*********************************************/

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
/*********************************************
int partition (int* arr, int size)
{
    int low = 0;
    int high = size-1;
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */

/*********************************************
void sort_quick_ascending (int* arr, int size)
{
    int low = 0;
    int high = size-1;

    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        //int pi = partition(arr,size);
/*********************************************
        // Separately sort elements before
        // partition and after partition
        sort_quick_ascending(arr, size-pi+1);
        sort_quick_ascending(arr+pi+1,size-pi-1);
    }
}
*********************************************/
/*********************************************/




/*********************************************/


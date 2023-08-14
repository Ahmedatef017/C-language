

//#include <string.h>

//void flt2str (float n,char* str);
//long long pow(long n, int a);

# define NULLPTR  (void*)0
# define SQR(x)  ((x)*(x))
# define CUBE(x)  ((x)*(x)*(x))
# define MAX(x,y)  (((x)>(y))?((x):(y)))
# define MIN(x,y)  (((x)<(y))?((x):(y)))



///2D arrays & arrays of strings funcs

/*********************************/
///1) arrays of strings
/*********************************/

void printarrayofstrings (char** arr, int size )    // arguments in main like before (arr,size)

{
    int i, j;

    for (i=0 ; i<size ; i++)
    {

        /*for (j=0 ; arr[i][j];j++)
        {
            printf("%c",arr[i][j]);
        }

        printf("\n");*/


        printstr(arr[i]);  // alternative solution - kda kda hytb3 str str l7d el null w ysib str
    }


}

/*********************************/

int arrayofstrings_search_word (char** arr, int size, char* word)    //returns index of 1st letter
{

    for (int i=0; i<size ; i++)
    {
        if (str_compare_not_case_sensitive (arr[i],word) ==1) // arr[i] is a pointer (already address)
        {
            return i;
        }
    }

    return -1 ; //not found


}




/*********************************/

void arrayofstrings_bubble_sort_ascending (char** arr,int size)
{
    int i,j,sorted_flag;

    for(j=0; j<size; j++) // rotate b 3adadd el elements (worst case)
    {
        sorted_flag=1;

        for(i=0; i<size-1-j; i++) // i<size-1 3shan maqarensh a5er element b garbage barra
            // i<size-1-j 3shan kda kda a5er element mzboot
        {
            if(str_compare_larger(arr[i],arr[i+1])==1)   // only difference between ascending (>) - descending (<)
            {
                swap_pointers(&arr[i],&arr[i+1]);     // swap pointers not ordinary swap
                sorted_flag=0;
            }

        }

        if(sorted_flag==1) // mada5alsh el condition ? so mtrtbin 5las - twfir w2t
        {
            break;         // or return
        }

    }

}


/*********************************/

void arrayofstrings_bubble_sort_descending (char** arr,int size)
{
    int i,j,sorted_flag;

    for(j=0; j<size; j++) // rotate b 3adadd el elements (worst case)
    {
        sorted_flag=1;

        for(i=0; i<size-1-j; i++) // i<size-1 3shan maqarensh a5er element b garbage barra
            // i<size-1-j 3shan kda kda a5er element mzboot
        {
            if(str_compare_larger(arr[i],arr[i+1])==2)   // only difference -- strcompare ==2 - 2nd is larger
            {
                swap_pointers(&arr[i],&arr[i+1]);
                sorted_flag=0;
            }

        }

        if(sorted_flag==1) // mada5alsh el condition ? so mtrtbin 5las - twfir w2t
        {
            break;         // or return
        }

    }

}


/*********************************/

int arrayofstrings_binary_search_word (char** arr,int size, char* word)  // must be sorted - returns index of 1st letter in the word

{
//arrayofstrings_bubble_sort_ascending (arr,size);

    int first =0, middle, last=size-1;      //indexes of binary search

    while(first<=last)
    {
        middle = (first+last)/2;

        if(str_compare_larger (arr[middle],word) ==0)   // who is largest from A (smallest) --> Z (largest)
        {
            return middle;
        }

        else if (str_compare_larger (arr[middle],word) ==1)    // middle larger - so the "word" before it
        {

            last = middle-1;   // middle itself not needed

        }

        else if (str_compare_larger (arr[middle],word) ==2) // word is larger
        {
            first = middle+1; // 2nd half

        }

    }

    return -1;  // not found
}


/*********************************/
/// 2D arrays - arrays of arrays --- mostly arrays of strings without pointers
/*********************************/

void printarr2D (char arr[][10],int size)  // you may change this 10 at any step you want // same as printarrayofstrings func mostly
{
    int i, j;

    for (i=0 ; i<size ; i++)
    {

        /*for (j=0 ; arr[i][j];j++)
        {
            printf("%c",arr[i][j]);
        }

        printf("\n");*/


        printstr(arr[i]);  // alternative solution - kda kda hytb3 str str l7d el null w ysib str
    }

}


/*********************************/

int arr2D_search_charecter (char arr[][10],int size, char letter,  int* first_index )  // returns both i on pointer and j directly
// size here is the no. of lines
// each line contains 10 charecters
{

    int i, j;

    for (i=0 ; i<size ; i++)
    {

        for (j=0 ; arr[i][j]; j++)
        {
            if(arr[i][j]==letter)
            {
                *first_index = i;
                return j;

            }
        }

        return -1;  // not found

    }

}

/*********************************/

void printmatrix (int matrix[][5],int rows, int columns)  // columns can be more than 5 3ady

{

    for ( int i=0 ; i<rows ; i++)
    {
        for (int j =0 ; j<columns ; j++)
        {
            printf("%2d  ",matrix[i][j]);  // %2d make any number fits in 2 places or more
        }
        printf("\n");
    }

}

/*********************************/

void printmatrix_zigzag (int matrix[][5],int rows, int columns)

{
    int i, j;

    for (i=0 ; i<rows ; i++)
    {
        if (!(i&1))   // if i is even -- i&1 == 0 ,, so !(i&1) == !(0) = 1 [true]
        {
            for (j =0 ; j<columns ; j++)
            {

                printf("%2d  ",matrix[i][j]);  // %2d make any number fits in 2 places or more
            }
        }

        else
        {
            for (j =columns-1 ; j>=0 ; j--)
            {

                printf("%2d  ",matrix[i][j]);  // %2d make any number fits in 2 places or more
            }
        }

        printf("\n");
    }

}

/*********************************/

int matrix_sum_diagonals_equal (int matrix[][5],int rows, int columns) // returns 1 if equal - 0 if not
{
    if (rows != columns)  // must be square matrix
    {
        return 0;
    }

    int i, j, sum_left_diagonal=0, sum_right_diagonal = 0;

    for(i=0 ; i<rows ; i++)
    {

        for (j=0 ; j<columns ; j++)
        {
            if (i==j)
            {
                sum_left_diagonal = sum_left_diagonal + matrix[i][j];
            }

            if (j== (columns-1)-i) // not else if because they will meet at a point
            {
                sum_right_diagonal = sum_right_diagonal + matrix[i][j];
            }

        }

    }

    if (sum_left_diagonal == sum_right_diagonal)
    {
        return 1;
    }

    else
    {
        return 0;
    }

}

/*********************************/

void star_set(char arr[][30],int row,int col,int star_i,int star_j)   // char shapes and set in original arr in main
{
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(i==star_i&&j==star_j)
            {
                arr[i][j]='*';
            }
            else if(j==star_j&&i<star_i)    // above it
            {
                arr[i][j]='V';
            }
            else if(j==star_j&&i>star_i)   // below it
            {
                arr[i][j]='^';
            }
            else if(j<star_j&&i==star_i)  // on its left
            {
                arr[i][j]='>';       // points right to it
            }
            else if(j>star_j&&i==star_i)  // on its right
            {
                arr[i][j]='<';      // points left to it
            }


            ///LEFT :- (A,B)

            else if(j<star_j&&i<star_i)  // above left (A)
            {
                arr[i][j]='A';
            }
            else if(j<star_j&&i>star_i)  // below left (B)
            {
                arr[i][j]='B';
            }


            ///RIGHT :- (C,D)

            else if(j>star_j&&i<star_i) // above right (C)
            {
                arr[i][j]='C';
            }
            else if(j>star_j&&i>star_i)  // below right (D)
            {
                arr[i][j]='D';
            }

        }
    }
}


/*********************************/

void star_print(char arr[][30],int row,int col)  // poitner to arr of charecters as arguement
{
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%c ",arr[i][j]);  // leave space to be obvious // %c

        }
        printf("\n");
    }
}

/*********************************/

void star_search (char arr[][30],int row,int col,int* pstar_i,int* pstar_j)  // returns both indexes of '*'- i,j - on pointers
{
    int i,j;
    //int c;

    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(arr[i][j]=='*')
            {
               // printf("ordinary search = %d\n",c);

                *pstar_i=i;
                *pstar_j=j;
                return;    // found? save time then
            }
            //c++;
        }

    }
}


/*************BINARY-TASK********************/

void star_binary_search (char arr[][30],int rows,int col,int* pstar_i,int* pstar_j)

{
    int first_r =0, middle_r, last_r=rows-1;      //indexes of rows
    int first_c =0, middle_c, last_c=col-1;      //indexes of columns


    while(first_r<=last_r && first_c<=last_c )
    {
        middle_r = (first_r+last_r)/2;
        middle_c = (first_c+last_c)/2;


        if(arr[middle_r][middle_c]=='*')
        {
            //printf("binary count = %d\n",c);

            *pstar_i=middle_r;
            *pstar_j=middle_c;
            return;
        }


        else if (arr[middle_r][middle_c]=='V')  // same col
        {

            first_r = middle_r+1;

        }

        else if (arr[middle_r][middle_c]=='^')  // same col
        {

            last_r = middle_r-1;

        }

        else if (arr[middle_r][middle_c]=='>')  // same row
        {

            first_c = middle_c+1;

        }

        else if (arr[middle_r][middle_c]=='<')  // same row
        {

            last_c = middle_c-1;

        }




        else if (arr[middle_r][middle_c]=='A')  //above left
        {

            first_r = middle_r+1;
            first_c = middle_c+1;

        }

        else if (arr[middle_r][middle_c]=='B')  // below left
        {
            last_r = middle_r-1;
            first_c = middle_c+1;

        }

        else if (arr[middle_r][middle_c]=='C')    // above right
        {

            first_r = middle_r+1;
            last_c = middle_c-1;

        }

        else if (arr[middle_r][middle_c]=='D')    // below right
        {

            last_r = middle_r-1;
            last_c = middle_c-1;

        }


    }

    return;
}


/*********************************/

int arr2D_search_word (unsigned char arr[][5],int size, unsigned char* s)
{
    int i;
    for(i=0; i<size; i++)
    {
        if(str_compare(arr[i],s))
        {

            return i;  // i tehemmeni bs msh j -- 3shan a3rf order el array nfso
        }
    }
    return -1 ;
}

/*********************************/

void printarr2D_serial_number_hexa(unsigned char SerialArray[][5],unsigned int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        for(j=0; j<5; j++)
        {
            printf("%.2x  ",SerialArray[i][j]);  // hexa prints 2 digits (8-->printed : 08 )
        }
        printf("\n==============================\n");
    }

}


/*********************************/















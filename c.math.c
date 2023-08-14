
// This file contains math functions

/******************************************/

int fact (int n) // Factorial
{

    signed int  factorial =1, i ;

    factorial = 1;

    if (n>=0)
    {
        for(i=n; i>1; i--)
        {
            factorial = factorial * i;
        }
        return factorial;
    }

    else
        return 0;
}

/******************************************/

long long pow(long n, int a)  // find number power number
{
    int   i;
    long long result = 1 ; //not zero due to multiplication   + inside while to reset result to 1


    for (i =0 ; i < a ; i++)
    {
        result = result * n; // multiplication not summation
    }


    return result ;
}


/******************************************/


int CheckBase2 (int n)  // check if this number is a base of 2 or not
{
    signed int i, flag = 0;
    signed int result =1 ;


    flag = 0;
    result =1 ;


        for (i=1 ; i<n && flag==0 ; i++)
        {

            result = 2 * result ;

            if(result == n)
                flag = 1;
        }

        if (flag==1 || n==1)
           {
            return 1;
           }

        return 0;

}

/******************************************/

int IntSqrt (int n) // square root of an integer number - returns integer - if has no root - returns 0
{
    for (int i=1 ; i<n ; i++)
    {
        if (i*i==n)
        {
            return i;
        }

    }
    return 0;

}

/******************************************/

void swap (int * px, int * py)   //swap any 2 numbers - takes there adresses as an arguments  ------VOID
{
    int temp;
    temp = *px ; //assigned in original variable itself
    *px = *py;
    *py = temp;
}



/********************************************/


int IsPrime (int n)  //Check if number is prime or not
{
    if (n==0 || n==1)
        return 0;

    for (int i=2 ; i<n ; i++)
    {

        if(n%i==0)
        {
            return 0;
        }
        else
            return 1;
    }

    return 1; // for no. (2)
}

/******************************************/

int holes (int n) // count holes in a number shape

{


    int  sum, holes, total_holes =0, result;



    while (n !=0)
    {
        holes = 0;

        result = n %10;
        n = n/10 ;

        if(result==0 || result==4 || result==6 || result==9 )
            holes = 1;

        else if(result==8)   // The rest will be zero alone
            holes = 2;

        total_holes = total_holes + holes;

    }
    return total_holes;

}

/******************************************/

void print_PrimeBet2n(int n1, int n2)  //find prime numbers between 2 numbers - without them
{
    int max, min, flag = 0, i, n;

    if (n1 != n2)
    {

        if (n1>n2)
        {
            max = n1;
            min = n2;
        }

        else
        {
            max = n2;
            min = n1;
        }

        for (i = max -1 ; i > min ; i--)
        {
            flag=0;

            for (n = 2 ; n < i && flag ==0 ; n++)
            {
                if (i%n == 0)
                {
                    flag = 1;
                }
            }

            if (i == max-1)
                printf("Prime numbers in between are :  ");

            if (flag==0)
                printf(" %d ", i );

        }

    }

    else
        printf("no numbers in between - both numbers are the same !\n");
}

/******************************************/

int EvenOrOdd (int n) //returns 1 for even ,, 0 for odd
{

    int x ;
    x=0;

    x=n&1;

    if (x==0)
        return 1;


    else
        return 0;
}

/******************************************/


int approx(float n)    //Approximate fractional numbers to integers

{

    int x;

    x=n+0.5;

    return x;

}

/******************************************/

void print_binary (int n)   // Convert from decimal to binary  ------VOID
{
    unsigned char flag;
    int binary;
    signed int i ;

    for(i=31 ; i>=0 ; i--)
    {
        binary = (n>>i) &1;

        if(binary==1)
            flag = 1 ;

        if (flag==1)
            printf("%d",binary);
    }

    printf("\n");


}

/******************************************/

void print_primes (int n)  //generating n numbers of prime numbers starting from 2   -----VOID
{
    unsigned int  x, i2 = 0 ; // or i2= 2 ;

    while (n>0)
    {
        x = IsPrime(i2);
        if (x==1)
        {
            printf("%d  ",i2);
            n--; // inside the condition to count the prime only
        }
        i2++; //  outside the condition to increase +1 on the number whatever it's prime or not
    }
    printf("\n");
}

/******************************************/

int count_max_zeroes (int n) //count max successive zeros in a binary representation of a number
{
 int flag = 0 , max = 0 , binary =0 , count = 0;
 signed int i;

 if(n==0)
 {
  return 0;
 }

  for (i=31 ; i>=0 ; i--)
  {


  if ((n>>i) &1) // bit check zeroes or ones
  {
     if (count > max) // put here not at else to assign the count to max only if there's 1 at the end - to prevent left corner case of zeroes
	  {
       max = count;
	   }
      count = 0 ; // start over as there's bit = 1
	  flag = 1;   // count won't count except after the 1st 1 it sees - to avoid right corner case of zeros
  }

  else if (flag ==1) // and ضمنيا [ (n>>i) &1 = 0 ] due to "else" // only count after flag
  {
	count = count+1; // count when zeroes only // also left corner zeroes will be counted but no assigned to max
  }

  }
  return max ;
}

/******************************************/

int CheckBase3 (int n)  // check if this number is a base of 3 or not   (3^n)
{
    signed int i, flag = 0;
    signed int result =1 ;


    flag = 0;
    result =1 ;

        for (i=1 ; i<n && flag==0 ; i++)
        {

            result = 3 * result ;

            if(result == n)
                flag = 1;
        }

        if (flag==1 || n==1)
            {return 0;}

        return 1;

}


/******************************************/
int reverse_decimal (int n)
{
int reverse;
while(n!=0)
  {
  reverse = n%10;
  n = n/10;
  }
  return reverse;
}

/******************************************/














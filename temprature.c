
//(temp = temprature) functions

/**********************************************/

static int max_temp=5; // global variables
static int min_temp;

/**********************************************/


void temp_take(int n)
{

    static int flag=0;

    if (flag==0)
    {
        min_temp = n;
        max_temp = n;
        flag++;
    }

    if (n< min_temp )
    {
        min_temp=n;
    }

    if (n> max_temp)
    {
        max_temp = n;
    }

}

/**********************************************/


int temp_max (void)
{

    return max_temp;
}

/**********************************************/

int temp_min (void)
{


    return min_temp;
}


/**********************************************/
/**********************************************/


/**********************************************/

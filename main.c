#include <stdio.h>
#include <math.h>
/*a. Compute the approximated value of square root of a positive real number. The precision is provided by the user.
b. Given a vector of numbers, find the longest contiguous subsequence such that the difference of any two consecutive elements is a prime number.
 */

void read_the_vector(int the_vector[200],int length)
{

    for(int index = 0; index < length;index++)
        scanf("%d",&the_vector[index]);

}

void print_the_vector(int the_vector[200],int length)
{
    for(int index = 0; index < length; index++)
        printf("%d ", the_vector[index]);
    printf("\n");
}

void calculate_sqrt(int the_vector[200],int length)
{
    int precision;
    printf("Insert the precision:");
    scanf("%d", &precision);

    int sum = 0;
    for(int index = 0; index < length; index++)
        if(the_vector[index] > 0)
            sum += the_vector[index];

        double sqrt_result;
        sqrt_result = sqrt((double)sum);
        printf("%.*f\n",precision,sqrt_result);

}

int prime(int first_number, int second_number)
{

    if(first_number < second_number)
    {
        int aux = first_number;
        first_number = second_number;
        second_number = aux;
    }
    first_number = first_number - second_number;
    if(first_number == 1 || first_number == 2)
        return 1;
    int index;

    for(index = 2; index <= first_number/2; index++)
        if(first_number % index == 0)
            return 0;

        return 1;

}

void calculate_sequence(int the_vector[200],int length)
{
    int start_sequance = 0;
    int finish_sequence = 0;
    int in_sequence = 0;
    if(length < 2)
        printf("There are not enough elements in the vector.\n");
    else
    {
        int curent_start = 0;
        int curent_finish = 0;

        int index;
        for(index = 0; index < length - 1; index++)
        {
            printf("Prime result if %d is %d \n",index,prime(the_vector[index],the_vector[index + 1]));
            if(prime(the_vector[index],the_vector[index + 1]) == 1)
            {
                if(in_sequence == 0)
                {
                    curent_start = index;
                    in_sequence = 1;
                    curent_finish = index + 1;

                }
                else if(in_sequence == 1)
                {
                    curent_finish++;
                }
            }
            else
            {
                printf("The start: %d, the finish %d\n",start_sequance,finish_sequence);
                printf("Curect start: %d, curent finish %d\n",curent_start,curent_finish);
                if(curent_finish-curent_start > finish_sequence - start_sequance)
                {
                    finish_sequence = curent_finish;
                    start_sequance = curent_start;
                }
                in_sequence = 0;
            }
        }

    }
    //printf("%d %d",start_sequance, finish_sequence);
    for(int index = start_sequance; index <= finish_sequence; index++)
    {
        printf("%d ",the_vector[index]);
    }
}

int main() {

    int opt;
    int length;
    int the_vector[200] = {1,2,3,4,5,11,10,2,1,2,1,2,1,2,1,10};
    calculate_sequence(the_vector,16);

    do {
        printf("\n\n1.Read the vector.\n2.Print the vector.\n3.The SQRT of sum.\n4.The sequence\n");
        printf("Your option is:");
        scanf("%d", &opt);

        if(opt == 1)
        {
            printf("Enter the length of the vector:");
            scanf("%d", &length);
            read_the_vector(the_vector,length);
        }
        if(opt == 2)
        {
            print_the_vector(the_vector,length);
        }
        if(opt == 3)
        {
            calculate_sqrt(the_vector,length);
        }
        if(opt == 4)
        {
            calculate_sequence(the_vector,length);
        }


    }while(opt != 0);



    return 0;
}

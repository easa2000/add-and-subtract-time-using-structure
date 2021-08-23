// program to read, display, add, and subtract two times variable, using hours minutes and time

#include<stdio.h>
#include<conio.h>
typedef struct
{
    int hr;
    int min;
    int sec;
}TIME;

TIME t1, t2, t3, t4;
TIME add_time(TIME,TIME);
TIME subtract_time(TIME,TIME);
int main()
{
    int choice;
    system("cls");
    do{
        printf("\n ***** MAIN MENU *****");
        printf("\n 1. Read time");
        printf("\n 2. Display time");
        printf("\n 3. Add");
        printf("\n 4. Subtract");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\n Enter the first time in hours, minutes and seconds: ");
                scanf("%d %d %d", &t1.hr, &t1.min, &t1.sec);
                printf("\n Enter the second time in hours, minutes and seconds: ");
                scanf("%d %d %d",&t2.hr, &t2.min, &t2.sec);
            break;

            case 2:
                printf("\n The first time is : %d hr %d min %d sec",t1.hr, t1.min, t1.sec);
                printf("\n The second time is : %d hr %d min %d sec",t2.hr, t2.min, t2.sec);
            break;

            case 3:
                t3 = add_time(t1,t2);
                printf("\n the sum of two time values is: %d hr %d min %d sec",t3.hr , t3.min, t3.sec);
            break;

            case 4:
                t4 = subtract_time(t1,t2);
                printf("\n the differenece in time is : %d hr %d min %d sec",t4.hr, t4.min, t4.sec);
            break;
        }
    }while(choice != 5);
    getch();
    return 0;
}

TIME add_time(TIME t1, TIME t2)
{
    TIME sum;
    sum.sec = t1.sec + t2.sec;
    while(sum.sec >= 60)
    {
        sum.sec -= 60;
        sum.min++;
    }

    sum.min = t1.min + t2.min;
    while (sum.min >= 60)
    {
        sum.min -= 60;
        sum.hr++;
    }
    sum.hr = t1.hr + t2.hr;
    return sum;
    
}

TIME subtract_time(TIME t1, TIME t2)
{
    TIME sub;
    if(t1.hr > t2.hr)
    {
        if(t1.sec < t2.sec)
        {
            t1.sec += 60;
            t1.min--;
        }
        sub.sec = t1.sec = t2.sec;
        if(t1.min < t2.min)
        {
            t1.min += 60;
            t1.hr--;
        }
        sub.min = t1.min - t2.min;
        sub.hr = t1.hr - t2.hr;
    }
    else
    {
        if(t2.sec < t1.sec)
        {
            t2.sec += 60;
            t2.min--;
        }
        sub.sec = t2.sec =-t1.sec;
        if(t2.min < t1.min)
        {
            t2.min += 60;
            t2.hr--;
        }
        sub.min = t2.min - t1.min;
        sub.hr = t2.hr - t1.hr;
    }
    return sub;
}

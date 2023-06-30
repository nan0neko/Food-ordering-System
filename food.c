#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
typedef struct node
{
	float data;
	char foodname[50];
	int quantity;
	float price;
    struct node *next;
}node;
typedef struct head
{
    node *start;
}head;
void hotel();
void food();
void mainmenu(){
    int ch;
 printf("\t\t Enter choice:\n\t\t 1.Search by HOTEL\n\t\t 2.Search by FOOD\n\t\t 3.Log Out\n");
                scanf("%d", &ch);
                switch(ch){
            case 1:
                hotel();
                break;
            case 2:
                food();
                break;
            default:
                exit(0);
                }
                }
void insertend(head *t, float data, char foodname[25], int quantity, float price)
{
    node *p, *q;
    p=(node *)malloc(sizeof(node));
    p->data=data;
    p->quantity=quantity;
    p->price=price;
    strcpy(p->foodname, foodname);
    p->next=NULL;
    if(t->start==NULL)
    {
        t->start=p;
    }
    else
    {
        q=t->start;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=p;
    }
}
void foodlist(head *t)
{
	printf("\n\t");
	printf("___________________");
	printf("\n\t");
	printf("  Food Code          Name                Price         ");
	printf("\n\t");
	printf("-------------------------------------------------------");
	node *p;
    p=t->start;
    while(p!= NULL)
    {
        printf("\n\t");
        printf("  %0.1f   |  %-25s     |    %0.2f   ",p->data,p->foodname,p->price);

		printf("\n\t");
        printf("-------------------------------------------------------");
        p=p->next;
    }
}
void foodlist1(head *t)
{
	printf("\n\t");
	printf("_______________________");
	printf("\n\t");
	printf("  Food Code       Name                       Quantity      Price   ");
	printf("\n\t");
	printf("-------------------------------------------------------------------");
	node *p;
    p=t->start;
    while(p!= NULL)
    {
		printf("\n\t");
        printf("  %0.1f   |  %-25s      |    %2d      |  %0.2f   ",p->data,p->foodname, p->quantity, p->price);
		printf("\n\t");
		printf("------------------------------------------------------------------");
        p=p->next;
    }
}
float getbill(head *t)
{
    node *p;
    float b=0;
    p=t->start;
    while(p!=NULL)
    {
        b=b+p->price;
        p=p->next;
    }
    return b;
}
void order(head *t, head *l, float fc, int qty)
{
    node *p;
    p=t->start;
    while(p->data!=fc)
    {
        p=p->next;
    }
    insertend(l, fc, p->foodname, qty, (p->price*qty));
    return;
}
void cls()
{
    system("cls");
}
int main()
{
    head x, s, m, d, o;
    x.start=s.start=m.start=d.start=o.start=NULL;
    char uid[20], pwd[20], uid1[20], pwd1[20], c=' ', k=' ';
    int i=0, ch;
    while(1)
    {
        cls();
mainscr: printf("\n\t\t\tWELCOME TO HUNGRY PANDA\n\t\t\t\tEnter Choice:\n\t\t\t\t1. Login\n\t\t\t\t2.New User\n\t\t\t\t3.Exit\n");
        scanf("%d", &ch);
        if(ch==3)
            break;
        if(ch==2)
        {
            printf(" \n\n                  ENTER USERNAME:-");
            scanf("%s", &uid1);
            printf(" \n\n                  ENTER PASSWORD:-");
            while(i<20)
            {
                pwd1[i]=getch();
                c=pwd1[i];
                if(c=='\r') break;
                else printf("*");
                i++;
            }
            pwd1[i]='\0';
            printf("\n\n            Registered Successfully!\n");
            Sleep(2000);
        }
        else
        {
            printf("\n  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  ");
            printf(" \n\n                  ENTER USERNAME:-");
            scanf("%s", &uid);
            printf(" \n\n                  ENTER PASSWORD:-");
            c=' '; i=0;
            while(i<20)
            {
                pwd[i]=getch();
                c=pwd[i];
                if(c=='\r') break;
                else printf("*");
                i++;
            }
            pwd[i]='\0';
            if(strcmp(uid,uid1)==0&&strcmp(pwd,pwd1)==0)
            {
                printf("\n\n            LOGIN SUCCESFULL!");
                Sleep(2000);
                cls();
                int i, ch;
                mainmenu();
}
    }
    }
    return 0;
        }
void food(){
    int ch,ch3,ch4;
     head x, s, m, d, o;
    x.start=s.start=m.start=d.start=o.start=NULL;
    float fcode;
    int qty, lo;
    insertend(&s, 1.1, "Samosa", 1, 50);
    insertend(&s, 1.2, "Paneer Cutlet Sandwich", 1, 100);
    insertend(&s, 1.3, "Nachos", 1, 150);
    insertend(&s, 1.4, "Chicken Burger", 1, 150);
    insertend(&s, 1.5, "Chicken Roll", 1, 150);
    insertend(&m, 2.1, "Pav Bhaji", 1, 100);
    insertend(&m, 2.2, "Punjabi Thali", 1, 150);
    insertend(&m, 2.3, "Paneer Parotha", 1, 90);
    insertend(&m, 2.4, "Peri Peri Chicken Pizza", 1, 250);
    insertend(&m, 2.5, "Margherita Pizza", 1, 200);
    insertend(&m, 2.6, "Veg Pulao", 1, 250);
    insertend(&m, 2.7, "Chicken Hyderabadi Biryani", 1, 350);
    insertend(&d, 3.1, "Chocolate Overload Waffle", 1, 150);
    insertend(&d, 3.2, "Icecream with Nuts", 1, 150);
    insertend(&d, 3.3, "Chocolate Cake", 1, 250);
    insertend(&d, 3.4, "Cold Coffee", 1, 350);
    insertend(&d, 3.5, "Sizzling Brownie", 1, 100);
    insertend(&d, 3.6, "Orea Freakshake", 1, 150);
    insertend(&d, 3.7, "Fruit Milkshake", 1, 80);
    order: printf("\t\tEnter Choice:\n");
                    printf("\t\t 1.Snacks\n\t\t 2.Main Course\n\t\t 3.Dessert\n");
                    scanf("%d", &ch);
                    while(1){
                    switch(ch)
                    {
                        case 1: foodlist(&s);
                                printf("\n");
                                printf("Enter Food Code:\n");
                                scanf("%f", &fcode);
                                printf("Enter Quantity of Food:\n");
                                scanf("%d", &qty);
                                order(&s, &o, fcode, qty);
                                foodlist1(&o);
                                break;
                        case 2: foodlist(&m);
                                printf("\n");
                                printf("Enter Food Code:\n");
                                scanf("%f", &fcode);
                                printf("Enter Quantity of Food:\n");
                                scanf("%d", &qty);
                                order(&m, &o, fcode, qty);
                                foodlist1(&o);
                                break;
                        case 3: foodlist(&d);
                                printf("\n");
                                printf("Enter Food Code:\n");
                                scanf("%f", &fcode);
                                printf("Enter Quantity of Food:\n");
                                scanf("%d", &qty);
                                order(&d, &o, fcode, qty);
                                foodlist1(&o);
                                break;
                        default: printf("Invalid Choice.\n");
                        exit(0);
                    }
afterorder:printf("\n\n");
printf("\n\t\tEnter Choice: \n\t\t1.Hungry For More? \n\t\t2.View Order \n\t\t3.Confirm Order?\n");
scanf("%d", &ch3);
if(ch3==1)
{
cls();
goto order;
}
else if(ch3==2)
{
 cls();
 printf("Current Order:\n");
 foodlist1(&o);
 goto afterorder;
}
else if(ch3==3)
{
cls();
foodlist1(&o);
printf("\n\t\t\tTotal amount to pay: %0.2f\n", getbill(&o));
printf("\n\t\t\t   Enjoy Your Meal!\n");
printf("\nPress 0 to continue.\n");
scanf("%d", &ch4);
if(ch4==0)
{
cls();
mainmenu();
}
}}}
void hotel(){
int ch1;
printf("\t\t 1. RATNA FOREVER\n\t\t 2. CAFE STONEWAY\n\t\t 3. KITCHEN BELLS\n");
printf("\t\tEnter your Choice\n");
scanf("%d",&ch1);
switch(ch1){
case 1:
    food();
    break;
case 2:
    food();
    break;
case 3:
    food();
    break;
default:
    exit(0);}
}

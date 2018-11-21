#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct head
{
    struct node *front;
    struct node *rear;
    int count, timer, lightCount, TTL, COC;
} head;

void metaupdate(struct head *, int, int);
void enqueue(struct head*);
void startup();
int dequeue(struct head *header);
void chance2(struct head *, struct head *);
void chance3(struct head *, struct head *, struct head *);
void movecar(struct head *, struct head *, struct head *, struct head *);
void display (int, int, struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *);
void regularTraffic(struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *);
void specialEvent(struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *);
void menu(struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *,struct head *);

int main()
{
    struct head pineA;
    metaupdate(&pineA, 4, 2);

    struct head pineB;
    metaupdate(&pineB, 2, 0);

    struct head richmond;
    metaupdate(&richmond, 2, 1);

    struct head weyA;
    metaupdate(&weyA, 1, 2);

    struct head weyB;
    metaupdate(&weyB, 2, 2);

    struct head weyC;
    metaupdate(&weyC, 3, 2);

    struct head westA;
    metaupdate(&westA, 3, 2);

    struct head westB;
    metaupdate(&westB, 3, 1);

    struct head washA;
    metaupdate(&washA, 3, 0);

    struct head washB;
    metaupdate(&washB, 3, 1);

    struct head dorA;
    metaupdate(&dorA, 2, 3);

    struct head dorB;
    metaupdate(&dorB, 2, 3);

    struct head dorC;
    metaupdate(&dorC, 2, 0);

    struct head empireA;
    metaupdate(&empireA, 2, 1);

    struct head empireB;
    metaupdate(&empireB, 2, 1);

    struct head empireC;
    metaupdate(&empireC, 2, 0);

    struct head eddy;
    metaupdate(&eddy, 2, 1);

    struct head mat;
    metaupdate(&mat, 2, 1);
    startup();
    menu(&pineA, &pineB, &richmond, &weyA, &weyB, &weyC, &eddy, &mat, &westA, &westB, &washA, &washB, &dorA, &dorB, &dorC, &empireA, &empireB, &empireC);
    return 0;
}
void startup()
{
    printf ("\t\tPROVIDENCE TRAFFIC MODELING SYSTEM \n");
    printf("\t\t\t\t(PTMS)\n\n\n\n");
    printf("\t\t\tDevelopers:\n\n");
    printf("\t\t\t\tBianca Ebanks\n\t\t\t\tJonathan Winter\n\t\t\t\tRomanov Andre\n\n\n\n\n\n");
    system("pause");
}
void menu(struct head *pineA,struct head *pineB,struct head *richmond, struct head *weyA, struct head *weyB, struct head *weyC, struct head *eddy, struct head *mat, struct head *westA,struct head *westB, struct head *washA, struct head *washB, struct head *dorA, struct head *dorB, struct head *dorC, struct head *empireA, struct head *empireB, struct head *empireC)
{
    int select;

    system("cls");
    printf("Select from the following options: \n\n");
    printf("\t\t1 - Regular Traffic\n");
    printf("\t\t2 - Special Event\n");
    printf("\t\t3 - Exit\n");
    scanf("%i",&select);

    if (select==1)
    {
        regularTraffic(pineA, pineB, richmond, weyA, weyB, weyC, eddy, mat, westA, westB, washA, washB, dorA, dorB, dorC, empireA, empireB, empireC);
        menu(pineA, pineB, richmond, weyA, weyB, weyC, eddy, mat, westA, westB, washA, washB, dorA, dorB, dorC, empireA, empireB, empireC);
    }
    if (select==2)
    {
        specialEvent(pineA, pineB, richmond, weyA, weyB, weyC, eddy, mat, westA, westB, washA, washB, dorA, dorB, dorC, empireA, empireB, empireC);
        menu(pineA, pineB, richmond, weyA, weyB, weyC, eddy, mat, westA, westB, washA, washB, dorA, dorB, dorC, empireA, empireB, empireC);
    }
    if (select==3)
    {
        exit(0);
    }

}

void metaupdate(struct head *header, int leave, int chance)
{
    header->front = NULL;
    header->count = 0;
    header->timer = 0;
    header->TTL = leave;
    header->COC = chance;
}

void enqueue(struct head *header)
{
    struct node *newptr;
    struct node *temp;
    newptr = (struct node *)malloc(sizeof(struct node));


    if (header->front == NULL)
    {
        newptr->data = 5;
        newptr->next = NULL;
        header->front = newptr;
        header->rear = newptr;
        header->count++;

    }
    else
    {
        newptr->data = 6;
        newptr->next = NULL;
        temp = header->rear;
        header->rear = newptr;
        temp->next = newptr;
        header->count++;
    }
}

int dequeue(struct head *header)
{
    struct node *temp;

// Empty Queue
    if (header->front == NULL)
    {
        printf("Cannot Dequeue from an empty list\n");
        return(1);
    }
// One Structure in the Queue
    else if (header->front == header->rear)
    {
//printf("Dequeueing from a queue with only one item...\n\n");
        temp = header->front;
        header->front = NULL;
        header->rear = NULL;
// Save the address of tempPtr
        header->count--;
        return(temp);
    }
    else
    {
//printf("Dequeueing from a queue that has more than one item...\n\n");
        temp = header->front;
// = temp->forward
        header->front = header->front->next; //might replace below code
//header.front = head.front->forward;
        header->count--;
    }
}


void chance2(struct head *e, struct head *e2)
{
    int r;

    r = rand() % 2;
    if (r == 0)
    {
        enqueue(e);
    }
    else
    {
        enqueue(e2);
    }
}

void chance3(struct head *e, struct head *e2, struct head *e3)
{
    int r;

    r = rand() % 3;
    if (r == 0)
    {
        enqueue(e);
    }
    else if (r == 1)
    {
        enqueue(e2);
    }
    else
    {
        enqueue(e3);
    }
}

void movecar(struct head *header, struct head *e, struct head *e2, struct head *e3)
{
    if (header->count>0)
    {
        if (header->timer == header->TTL)
        {
            dequeue(header);

            if (header->COC == 1)
            {
//only other way to go
                enqueue(e);
            }
            else if (header->COC == 2)
            {
                if (e2 == NULL)
                {
                }
                else
                {
                    chance2(e, e2);
//enqueue(e);
//enqueue(e2);
                }
            }
            else if (header->COC == 3)
            {
                if (e2 == NULL || e3 == NULL)
                {
                }
                else
                {
                    chance3(e, e2, e3);
                }
            }

            header->timer = 0;
        }
        else
        {
            header->timer++;
        }
    }
}

void specialEvent(struct head *pineA,struct head *pineB,struct head *richmond, struct head *weyA, struct head *weyB, struct head *weyC, struct head *eddy, struct head *mat, struct head *westA,struct head *westB, struct head *washA, struct head *washB, struct head *dorA, struct head *dorB, struct head *dorC, struct head *empireA, struct head *empireB, struct head *empireC)
{
    int totalCars=0, x, pineAp, pineBp, weyAp, weyCp, richmondp, weyBp, westAp, westBp, matp, eddyp, empireAp, empireBp, empireCp, dorAp, dorBp, dorCp, washAp, washBp, whilecnt, totalBefore=0, carleft=0;


// Add cars to Pine A
    for (x = 0; x < MAX; x++)
    {
        enqueue(pineA);
    }

// Add cars to Dor A
    for (x = 0; x < MAX; x++)
    {
        enqueue(dorA);
    }

// Add cars to Empire A
    for (x = 0; x < MAX; x++)
    {
        enqueue(empireA);
    }

// Add cars to Wash B
    for (x = 0; x < MAX; x++)
    {
        enqueue(washB);
    }

// VARIABLES
    totalCars = pineA->count + pineB->count + weyA->count + weyC->count + richmond->count + weyB->count + westA->count + westB->count + mat->count + eddy->count + empireA->count + empireB->count + empireC->count + dorA->count + dorB->count + dorC->count + washA->count + washB->count;
    printf("Simulation Start Total Cars: %i\n\n", totalCars);



// SIMULATION ENGINE
    while (totalCars != 0)
    {
// USED LATER TO PRINT BEFORE AND AFTER
        system("cls");
        pineAp = pineA->count;
        pineBp = pineB->count;
        weyAp = weyA->count;
        weyCp = weyC->count;
        richmondp = richmond->count;
        weyBp = weyB->count;
        westAp = westA->count;
        westBp = westB->count;
        matp = mat->count;
        eddyp = eddy->count;
        empireAp = empireA->count;
        empireBp = empireB->count;
        empireCp = empireC->count;
        dorAp = dorA->count;
        dorBp = dorB->count;
        dorCp = dorC->count;
        washAp = washA->count;
        washBp = washB->count;
// LIGHT HERE
        movecar(pineA, pineB, richmond, NULL);
        movecar(pineB, NULL, NULL, NULL);

        movecar(richmond, weyC, NULL, NULL);
        movecar(weyA, weyB, dorA, NULL);
// LIGHT HERE
        movecar(weyB, weyA, NULL, NULL);
        movecar(weyC, empireC, NULL, NULL);
// LIGHT HERE
        movecar(westA, westB, eddy, NULL);
        movecar(westB, empireA, NULL, NULL);
        movecar(washA, NULL, NULL, NULL);
        movecar(washB, washA, NULL, NULL);
        movecar(empireA, empireB, NULL, NULL);
// LIGHT HERE
        movecar(empireB, empireC, weyC, NULL);
        movecar(empireC, NULL, NULL, NULL);
// LIGHT HERE
        movecar(dorA, weyA, dorB, NULL);
        movecar(dorB, dorC, westA, NULL);
        movecar(dorC, NULL, NULL, NULL);
        movecar(eddy, weyA, NULL, NULL);
        movecar(mat, westB, NULL, NULL);


// UPDATE CAR COUNT
        totalBefore = totalCars;

        totalCars = pineA->count + pineB->count + weyA->count + weyC->count + richmond->count + weyB->count + westA->count + westB->count + mat->count + eddy->count + empireA->count + empireB->count + empireC->count + dorA->count + dorB->count + dorC->count + washA->count + washB->count;
        if (totalCars != totalBefore)
        {
            carleft++;
        }
        else
        {
            carleft = carleft;
        }
        display(totalCars, carleft, pineA, pineB, richmond, weyA, weyB, weyC, eddy, mat, westA, westB, washA, washB, dorA, dorB, dorC, empireA, empireB, empireC);
        system("pause");
        whilecnt++;
    }
}

void regularTraffic(struct head *pineA,struct head *pineB,struct head *richmond, struct head *weyA, struct head *weyB, struct head *weyC, struct head *eddy, struct head *mat, struct head *westA,struct head *westB, struct head *washA, struct head *washB, struct head *dorA, struct head *dorB, struct head *dorC, struct head *empireA, struct head *empireB, struct head *empireC)
{
    int r,i, time, totalCars=0, totalBefore=0, carleft=0;
   // r = rand()%4;
   // if (r==0)
    {
        r = rand()%4;
        for (i=0;i<r;i++)
        {
            enqueue(pineA);
        }
    }
  //  if (r==1)
    {
        r = rand()%4;
        for (i=0;i<r;i++)
        {
            enqueue(dorA);
        }
    }
  //  if (r==2)
    {
        r = rand()%4;
        for (i=0;i<r;i++)
        {
            enqueue(empireA);
        }
    }
  //  if (r==3)
    {
        r = rand()%4;
        for (i=0;i<r;i++)
        {
            enqueue(washB);
        }
    }

    printf("System Run Time:    _____ minutes\n\n");
    scanf("%i",&time);

    totalCars = pineA->count + pineB->count + weyA->count + weyC->count + richmond->count + weyB->count + westA->count + westB->count + mat->count + eddy->count + empireA->count + empireB->count + empireC->count + dorA->count + dorB->count + dorC->count + washA->count + washB->count;
    printf("Simulation Start Total Cars: %i\n\n", totalCars);

    for (i=0;i<time*3;i++)
    {
        r=rand()*18;

        if (r==0)
            {movecar(pineA, pineB, richmond, NULL);}
        if (r==1)
            {movecar(pineB, NULL, NULL, NULL);}
        if (r==2)
            {movecar(richmond, weyC, NULL, NULL);}
        if (r==3)
            {movecar(weyA, weyB, dorA, NULL);}
        if (r==4)
            {movecar(weyB, weyA, NULL, NULL);}
        if (r==5)
            {movecar(weyC, empireC, NULL, NULL);}
        if (r==6)
            {movecar(westA, westB, eddy, NULL);}
        if (r==7)
            {movecar(westB, empireA, NULL, NULL);}
        if (r==8)
            {movecar(washA, NULL, NULL, NULL);}
        if (r==9)
            {movecar(washB, washA, NULL, NULL);}
        if (r==10)
            {movecar(empireA, empireB, NULL, NULL);}
        if (r==11)
            {movecar(empireB, empireC, weyC, NULL);}
        if (r==12)
            {movecar(empireC, NULL, NULL, NULL);}
        if (r==13)
            {movecar(dorA, weyA, dorB, NULL);}
        if (r==14)
            {movecar(dorB, dorC, westA, NULL);}
        if (r==15)
            {movecar(dorC, NULL, NULL, NULL);}
        if (r==16)
            {movecar(eddy, weyA, NULL, NULL);}
        if (r==17)
            {movecar(mat, westB, NULL, NULL);}

        totalBefore = totalCars;

        totalCars = pineA->count + pineB->count + weyA->count + weyC->count + richmond->count + weyB->count + westA->count + westB->count + mat->count + eddy->count + empireA->count + empireB->count + empireC->count + dorA->count + dorB->count + dorC->count + washA->count + washB->count;
        if (totalCars != totalBefore)
        {
            carleft++;
        }
        else
        {
            carleft = carleft;
        }
        display(totalCars, carleft, pineA, pineB, richmond, weyA, weyB, weyC, eddy, mat, westA, westB, washA, washB, dorA, dorB, dorC, empireA, empireB, empireC);
        system("cls");

    }
    system("pause");
}

void display(int tot, int left, struct head *pineA,struct head *pineB,struct head *richmond, struct head *weyA, struct head *weyB, struct head *weyC, struct head *eddy, struct head *mat, struct head *westA,struct head *westB, struct head *washA, struct head *washB, struct head *dorA, struct head *dorB, struct head *dorC, struct head *empireA, struct head *empireB, struct head *empireC)
{
    int ti, i;
    char box = 219;

    printf("______________________________________________________________\n");
    printf("_____    __________%i____________     ______%i_______    _____\n", pineA->count,pineB->count);
    printf("     |  |                        |   |               |  |     \n");
    printf("     |  |                        |   |               |  |     \n");
    printf("     |  |                        |   |               |  |     \n");
    printf("     |  |                        |   |               |  |     \n");
    printf("     %i                          %i                %i         \n",dorA->count,richmond->count,empireC->count);
    printf("     |  |                        |   |               |  |     \n");
    printf("     |  |                        |   |               |  |     \n");
    printf("     |  |                        |   |               |  |     \n");
    printf("     |  |________________________|   |_______________|  |     \n");
    printf("            %i          %i                %i                  \n",weyA->count,weyB->count,weyC->count);
    printf("     |   ________    ________     ___________________   |     \n");
    printf("     |  |        |  |        |   |                   |  |     \n");
    printf("     |  |        |  |        |   |                   |  |     \n");
    printf("     |  |        |  |        |   |                   |  |     \n");
    printf("      %i          %i                                  %i      \n",dorB->count,eddy->count,empireB->count);
    printf("     |  |        |  |        |   |                   |  |     \n");
    printf("     |  |        |  |        |   |                   |  |     \n");
    printf("     |  |________|  |________|   |___________________|  |     \n");
    printf("                   %i                     %i                  \n",westA->count,westB->count);
    printf("     |   ________    ________     ___________________   |     \n");
    printf("     |  |        |  |        |   |                   |  |     \n");
    printf("     |  |        |  |        |   |                   |  |     \n");
    printf("     |  |        |  |        |   |                   |  |     \n");
    printf("      %i                      %i                      %i      \n",dorC->count,mat->count, empireA->count);
    printf("     |  |        |  |        |   |                   |  |     \n");
    printf("     |  |        |  |        |   |                   |  |     \n");
    printf("_____|  |________|  |________|   |___________________|  |_____\n");
    printf("                 %i                       %i                  \n",washA->count,washB->count);
    printf("_______________________________________________________________\n\n\n");
    printf("Service Rate \t\t ");
    for(i = 0; i < tot; i++) putchar(box);
    printf("\n");
    printf("Inter-arrival Time \t ");
    for(i = 0; i < left; i++) putchar(box);
    printf("\n");
    if (left != 0)
    {
        ti = tot/left;
    }
    else
    {
        ti=0;
    }
    printf("Traffic Intensity \t ");
    for(i = 0; i < ti; i++) putchar(box);
    printf("\n");
}

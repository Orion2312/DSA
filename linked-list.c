#include<stdio.h>
#include<stdlib.h>
void append();
void display();
int length();
void insert();
void add_begin();
void delete();
void mid_length();

struct node 
{
    int data;
    struct node *link;
};
struct node *Root=NULL;

int main()
{
    printf("WELCOME TO LINKED LIST\n");
    int i,n;    
    while(1)
    {
        int ch;
        printf("Enter 1 for append\n");
        printf("Enter 2 for display\n");
        printf("Enter 3 for finding length of the linked list\n");
        printf("Enter 4 for inserting at begining\n");
        printf("Enter 5 for inserting at a specific position\n");
        printf("Enter 6 for deleting a node\n");
        printf("Enter 7 for finding the middle length of the linked list\n");
        printf("Enter 8 for exiting the linked list\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the number of times you want to append: ");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                append();
            }
            break;

            case 2:
            display();
            break;

            case 3:
            length();
            break;

            case 4:
            add_begin();
            break;

            case 5:
            insert();
            break;

            case 6:
            delete();
            break;

            case 7:
            mid_length();
            break;

            case 8:
            exit(1);
            break;

            default:
            printf("Invalid Input\n");
        }
    }
}

void append()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the node values to append(): ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(Root == NULL)
    {
        Root=temp;
    }
    else{
        struct node *p;
        p=Root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
}

void display()
{
    struct node *p;
    p=Root;
    while(p!=NULL)
    {
        printf("%d->->",p->data);
        p=p->link;
    }
    printf("\n");
}

int length()
{
    int count=0;
    struct node *p;
    p=Root;
    while(p!=NULL)
    {
        p=p->link;
        count++;
    }
    printf("The length of the linked list is %d\n",count);
    return(count);
}

void add_begin()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the node values to add in begining: ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(Root == NULL)
    {
        Root=temp;
    }
    else{
        temp->link=Root;
        Root=temp;
    }    
}

void insert()
{
    int i=1,loc;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the node values: ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    printf("Enter the location to insert: ");
    scanf("%d",&loc);
    if(loc<1 && loc>length())
    {
        printf("Out of range");
    }    
    else if(Root == NULL)
    {
        Root=temp;
    }
    else
    {
        struct node *p;
        p=Root;
        while(i<loc-1)
        {
            p=p->link;
            i++;
        }
        temp->link=p->link;
        p->link=temp;
    }
}

void delete()
{
    struct node *p;
    int i=1,loc;
    printf("Enter the location to delete: ");
    scanf("%d",&loc);
    if(loc<=length())
    {
        if(loc == 1)
        {
            p=Root;
            Root=Root->link;
            p->link=NULL;
            free(p);
        }
        else{
            struct node *p,*q;
            p=Root;
            while(i<loc-1)
            {
                i++;
                p=p->link;
            }
            q=p->link;
            p->link=q->link;
            q->link=NULL;
            free(q);
        }
    }
}

void mid_length()
{
    if(length()%2 == 0)
    {
        printf("The middle nodes are on %d and %d positions\n",(length()/2),(length()+2)/2);
    }
    else{
        printf("The middle node is on %d postion\n",(length()+1)/2);
    }
}


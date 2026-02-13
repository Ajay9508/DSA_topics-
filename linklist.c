#include<stdio.h>
#include<stdlib.h>

struct node
{
        int a;
        struct node *link, *backlink;
};
struct node *start = NULL, *curr = NULL;

/*void initialize(int val)
{
        start = (struct node *) malloc(sizeof(struct node));
        curr = start;
        curr->a = val;
        curr->link = NULL;
}*/

void insert(int val)
{
        if(start == NULL)
        {
                start = (struct node *) malloc(sizeof(struct node));
                curr = start;
                curr->a = val;
                curr->link = NULL;
                curr->backlink = NULL;
                return;
                             return;
        }
        curr->link = (struct node *) malloc(sizeof(struct node));
        struct node *temp = curr;
        curr = curr->link;
        curr->link = NULL;
        curr->backlink = temp;
        curr->a = val;
}

void insertNew()
{

}
void deleteNew()
{

}

void delete()
{
        struct node *temp=start;

        if(start==NULL) //underflow
                printf("Item not present!!");

        else if(start->link == NULL)
                start = NULL;
                 else
        {
                temp = curr->backlink;
                temp->link = NULL;
                curr = temp;
        }
}

void display()
{
        struct node *temp = start;

        while(temp!=NULL)
        {
                printf("%d\t",temp->a);
                temp = temp->link;
        }
}

void push(int val)
{
        insert(val);
}

int pop()
{
        if(start == NULL)
        {
                printf("nothing to pop");
                return -1;
        }
        int t = curr->a;
        delete();
        return t;
}

int main()
{
        //initialize the linked list

        /*struct node *start, *curr;
        start = (struct node *) malloc(sizeof(struct node));

        curr = start;
        curr->a = 10;
        curr->link = NULL;*/

        //Add more elements in the list

        //initialize(10);

        /*curr->link = (struct node *) malloc(sizeof(struct node));
        curr = curr->link;
        curr->link = NULL;
        curr->a = 20;

        
        curr->link = (struct node *) malloc(sizeof(struct node));
        curr = curr->link;
        curr->link = NULL;
        curr->a = 30;

        curr->link = (struct node *) malloc(sizeof(struct node));
        curr = curr->link;
        curr->link = NULL;
        curr->a = 40;

        curr->link = (struct node *) malloc(sizeof(struct node));
        curr = curr->link;
        curr->link = NULL;
        curr->a = 50;*/
        /*insert(20);
        insert(30);
        insert(40);
        insert(50);
        delete(10);
        delete(50);
        delete(30);
        */
        push(10);
        push(20);
        push(30);
        push(40);
        printf("\n%d\n",pop());
          printf("\n%d\n",pop());
        display();
        //Delete an element from the linked list
        /*int item;
        printf("enter the item to be deleted:");
        scanf("%d",&item);

        struct node *temp=start, *prev = NULL;
        while(temp->a!=item && temp!=NULL)
        {
                prev = temp;
                temp = temp->link;
        }

        if(temp==NULL)
                printf("Item not present!!");

        if(temp == start)
        {
                start=start->link;
        }

        else
        {
                prev->link = temp->link;
        }*/
        
        //traverse the list
        /*temp = start;

        while(temp!=NULL)
        {
                printf("%d\t",temp->a);
                temp = temp->link;
        }
        */

        return 0;
}s
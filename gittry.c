#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum type{
    PREMIUM , REGULAR , SAVINGS
}type;

typedef struct map{
    int id;
}map;

map mp[100];
int idx = 0;

typedef struct Node{
    int cust_id;
    char *name;
    type account;
    struct Node* next;
}node;

type string_to_enum(char *ac_type){
    if(strcmp(ac_type,"PREMIUM") == 0) return PREMIUM;
    else if(strcmp(ac_type,"REGULAR") == 0) return REGULAR;
    else if(strcmp(ac_type,"SAVINGS") == 0) return SAVINGS;
    else return -1;
}

char *ac_type[] = {"PREMIUM","REGULAR","SAVINGS"};

node* insert(node *head,node **temp){
    node * newNode = (node *)malloc(sizeof(newNode));
    char *name = (char *)malloc(100 * sizeof(char));
    char *ac_type = (char *)malloc(100 * sizeof(char));
    int id;

    while(1){
        scanf("%d",&id);
        node *temp = head;
        while(temp != NULL){
            if(temp->cust_id == id){
                printf("Id already exists\n");
            }

        }
    }
    
    // scanf("%d",&id);
    // int is_duplicate = 0;
    // for(int i=0;i<idx;i++){
    //     if(mp[i].id == id){
    //         is_duplicate =1;
    //         break;
    //     }
    //     if(is_duplicate == 1){
    //         printf("Duplicate id\n");
    //     }
    //     else{
    //         mp[idx++].id = id;
    //     }
    // }


    getchar();
    fgets(name,100,stdin);
    name[strcspn(name,"\n")] = '\0';
    fgets(ac_type,100,stdin);
    ac_type[strcspn(ac_type,"\n")] = '\0';

    newNode->cust_id = id;
    newNode->name = (char *)malloc(100 * sizeof(char));
    strcpy(newNode->name,name);
    newNode->account = string_to_enum(ac_type);
    newNode->next = NULL;
    
    if(head == NULL){
        head = newNode;
        *temp = newNode;
    }
    else{
        (*temp)->next = newNode;
        *temp = newNode;
    }  
    return head; 
}

node *sort(node *head){
    node *ptr;
    node *lastptr = NULL;
    int swapped = 0;

    do{
        swapped = 0;
        ptr = head;
        while(ptr->next != lastptr){
            node *ptr1 = ptr->next;

            if((ptr->account) > (ptr1->account) || ((ptr->account) == (ptr1->account) && (ptr->cust_id) > (ptr1->cust_id))){
                int temp_id = ptr->cust_id;
                ptr->cust_id = ptr1->cust_id;
                ptr1->cust_id = temp_id;

                int temp_account = ptr->account;
                ptr->account = ptr1->account;
                ptr1->account = temp_account;

                char *temp_name =(char*)malloc(100*sizeof(char));
                strcpy(temp_name, ptr->name);
                strcpy(ptr->name , ptr1->name);
                strcpy(ptr1->name , temp_name);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        lastptr = ptr;
    }while(swapped);
    return head;
}

void display(node *head){
    node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->cust_id);
        printf("%s ",temp->name);
        int idx = temp->account;
        printf("%s ",ac_type[idx]);
        temp=temp->next;    
        printf("\n");
    }
}

node* delelte(node *head){
    if(head == NULL) return NULL;
    node *temp = head;
    head = head->next;
    temp->next = NULL;
    int idx = temp->account;
    printf("Customer Id : %d  Name : %s  Account Type : %s\n",temp->account,temp->name,ac_type[idx]);
    return head; 
}

int main(){
    int choice,no_of_operations;
    scanf("%d",&no_of_operations);
    getchar();
    node *head = NULL;
    node *temp = head;

    for(int i =0;i<no_of_operations;i++){
        printf("Enter choice");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            head = insert(head,&temp);
            break;
        case 2 :    
            head = sort(head);
            display(head);
            break;
        case 3 : 
            head = sort(head);
            delelte(head);
            break;      
        default:
            break;
        }
    }
    return 0;
}
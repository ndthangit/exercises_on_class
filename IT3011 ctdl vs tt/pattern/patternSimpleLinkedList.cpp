
//#############  SINGLY LINKED LIST with ALL Operations  ###############

#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct Node{
    int info;
    struct Node *next;
} Node;

/** 
 * Purpose: Traverse through linked list. 
 * Complexity: O(N)
 * @return: void
 */
void printList(struct Node *head){

    if(head != NULL){
        while(head->next !=NULL){
            cout<<head->info<<" -> ";
            head = head->next;
        }
        cout<<head->info;//for last node
    }
    else{
        cout<<"Empty List..!"<<endl;
    }
}

/** 
 * Purpose: Insert Node at front. 
 * Complexity: O(1)
 * @return: Head pointer
 */
struct Node* insertBegin(struct Node *head){

        struct Node* newN= NULL;
        newN = (struct Node*)malloc(sizeof(struct Node));

        cout<<"Enter the Node inserted at Begin\n";
        cin>>newN->info;

        newN->next = head;
        head = newN;

        // Freeing the newN Node
       	// free(newN);

        //return the head as the Head Node
        return head;

}
/** 
 * Purpose: Insert Node at end. 
 * Complexity: O(N)
 * @return: void
 */
void insertEnd( struct Node* head){

    while(head->next!=NULL){
        head = head->next;
    }
    struct Node* newN= NULL;
    newN = (struct Node*)malloc(sizeof(struct Node));
    cout<<"Enter the node need to inserted at END..!\n";
    cin>>newN->info;

    newN->next = head->next; //now it becomes end Node
    head->next = newN;  // finally head->points to newN

}

/** 
 * Purpose: Insert node after specific Node. 
 * Complexity: O(N)
 * @return: Head pointer
 */
void insertAfter(struct Node* head){
    cout<<"Enter the Node the after which you want to insert\n";
    int nodeAt; cin>>nodeAt;

    while( head->info != nodeAt){
        head = head->next;
    }//loops ends when head becomes the

    struct Node *newN= NULL;
    newN = (struct Node*)malloc(sizeof(struct Node));  //dynamic mem allocation
    cout<<"Enter the Node needs to be inserted\n";
    cin>>newN->info;

    newN->next = head->next;
    head->next = newN;
}

/** 
 * Purpose: Deletes from Node. 
 * Complexity: O(1)
 * @return: Head pointer
 */
struct Node* deleteFront(struct Node *head){
    struct Node*newN;
    newN = head;
    head=head->next; //head is pointing to next node
    free(newN);
    return head;

}

/** 
 * Purpose: Deletes Node at the End. 
 * Complexity: O(N)
 * @return: Head pointer
 */
struct Node* deleteEnd(struct Node *head){


    struct Node *endPrev=head;
    struct Node *startConst = head; //it always points to head Node
    //if only one element is there
    if(head->next == NULL){
        head=deleteFront(head);
        return head;
    }

    else{
        while(head->next!=NULL){
            endPrev = head;  //keep track of second last node
            head = head->next;
        }
        endPrev->next= NULL; //tail(head) becomes null referenced
        free(head);
        return startConst;
    }
}

/** 
 * Purpose: Deletes Node after a specific Node. 
 * Complexity: O(N)
 * @return: Head pointer
 */
void deleteAfter(struct Node*head){
    cout<<"Enter the Node the after which you want to Delete\n";
    int nodeAt; cin>>nodeAt;

    while(head->info!=nodeAt){
        head= head->next;
    }
    struct Node*oldNptr=NULL;
    oldNptr = head->next;//pointer refers to Node need to be deleted
    head->next = oldNptr->next;  //heads points the Node after the DeleteNode(oldNptr)
    oldNptr=NULL; //deleted node is null referenced
    free(oldNptr);  //deallocates the memory

}

/** 
 * Purpose: Deletes specific Node. 
 * Complexity: O(N)
 * @return: Head pointer
 */
struct Node* deleteNode( struct Node*head){
    cout<<"Enter the Node which you want to Delete\n";
    int nodeAt; cin>>nodeAt;

    struct Node *ptrN= head; //node to keep track of prev of deleted node
    struct Node *newHead = head;  //always points to head Node

    //if the node is head Node itself
    if(head->info == nodeAt){
        head = deleteFront(head);
        return head;
    }
    else{//if it is not the start Node
        while(head->info!=nodeAt){
            ptrN = head; //points to Node prev to deleted node
            head=head->next;
        }//stops when head becomes deleted node

        ptrN->next = head->next;  //ptrN points to Node which need to be deleted
        head = NULL;   //node need to deleted becomes Null Referenced
        free(head);
    }
    return newHead;

}


int main(){

    struct Node *head;
    head=NULL;

    int choice;

    while(choice!=8){
        cout<<"\nEnter Your Choice\n1: Insert Begin\n2: Insert End\n3: Insert After\n4: Delete Front\n5: Delete End\n6: Delete After\n7: Delete Particular Node\n8: EXIT"<<endl;
        cin>>choice;
        switch(choice){
            case 1: head = insertBegin(head);
                    break;
            case 2: insertEnd(head);
                    break;
            case 3: insertAfter(head);
                    break;
            case 4: head=deleteFront(head);
                    break;
            case 5: head = deleteEnd(head);
                    break;
            case 6: deleteAfter(head);
                    break;
            case 7: head=deleteNode(head);
                    break;
            case 8: break;  //EXIT
            default: break;
        }
        printList(head);
    }
}
/*


    Given two nos represented by two lists, create a linked list that returns sum list.
    the sum list is list reprsentation of addition of two input numbers


*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
    
    #define let struct List *
    
    struct List {
		
		int data;
		struct List *next;
	};

    int getInt(char c) {

            switch(c) {
                case '0': return 0;
                case '1': return 1;
                case '2': return 2;
                case '3': return 3;
                case '4': return 4;
                case '5': return 5;
                case '6': return 6;
                case '7': return 7;
                case '8': return 8;
                case '9': return 9;

            }

    }

    let create(let head , char *num) {

        let temp;
        let node;

        for(int i = 0 ; i <  strlen(num) ; i++) {
        
            node = (let)malloc(sizeof(struct List));
            node->data = getInt(num[i]);
            node->next = NULL;
            if(head == NULL) {

                head = node;
                temp = head;
            }
            else {

                temp->next = node;
                temp = node;
            }

        }

        return head;
    }

    void print(let head) {

        while(head) {

            printf("%d->",head->data);
            head = head->next;

        }
    }


    let reverse(let head) {

        let curr = head;
        let next;
        let prev = NULL;

        while(curr) {

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
        }

        return prev;
    }

    int size(let head) {

        int size = 0;
        while(head) {

            size += 1;
            head = head->next;
        }
        return size;
    } 

    let match(let head , int size) {

        let temp = head;
        int i = 0;
        let node;

        while(temp->next!= NULL) {

            i += 1;
            temp = temp->next;
        }
        while(i < size - 1) {

            node = (let)malloc(sizeof(struct List));
            node->data = 0;
            node->next = NULL;
            temp->next = node;
            temp = node;
            i += 1;
        }

        return head;
    }

    let add(let list1 , let list2) {

        let list3 = NULL;
        let node = NULL;
        let temp;
        int res , carry = 0;
        while(list1) {
            
            res = list1->data + list2->data + carry;

            if(res >= 10) {

                res %= 10;
                carry = 1;
            }
            else
                carry = 0;

            node = (let)malloc(sizeof(struct List));
            node->next = NULL;
            node->data = res;
            list1 = list1->next;
            list2 = list2->next;

            if(list3 == NULL) {

                list3 = node;
                temp = list3;
            }
            else {

                temp->next = node;
                temp = node;
            }
        }
        if(carry) {

            node = (let)malloc(sizeof(struct List));
            node->next = NULL;
            node->data = 1;
            temp->next = node;
        }

        return reverse(list3);
    }
    int main() {

        let list1 = NULL;
        let list2 = NULL;
        let list3 = NULL;
        char num1[100];
        char num2[100];
        printf("\nEnter First No:\t");
        gets(num1);
        printf("\nEnter Second No:\t");
        gets(num2);

        list1 = create(list1 , num1);
        list2 = create(list2 , num2);
        
        list1 = reverse(list1);
        list2 = reverse(list2);
        
        if(size(list1) > size(list2)) {
            
            list2 = match(list2 , size(list1));
        }
        else {
            list1 = match(list1 , size(list2));
        }

        list3 = add(list1 , list2);

        print(list3);
    }
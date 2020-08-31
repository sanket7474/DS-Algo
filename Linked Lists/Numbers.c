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

    let addOne(let head ) {

        
        int carry = 1;
        let node;
        head = reverse(head);
        let temp = head;
        let temp2;
        while(temp) {

            temp->data += carry;

            if(temp->data >= 10) {
                
                temp->data %= 10;
                carry = 1;
            }
            else
            {
                    carry = 0;
            }
            temp2 = temp;
            temp = temp->next;
        }
        if(carry == 1) {
            
            node = (let)malloc(sizeof(struct List));
            node->data = 1;
            node->next = NULL;
            temp2->next = node;
        }
        return reverse(head);
    }
    int main() {

        let head = NULL;
        char num[100];

        gets(num);
        head = create(head,num);

        printf("\n");
        head = addOne(head);
        print(head);
        printf("\n");
        head = addOne(head);
        print(head);
        printf("\n");
        
        return 0;
    }
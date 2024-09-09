//this file of mine will contain general functions of lin lists
#include<iostream>
using namespace std;



class Node{
    int data;
    Node* next;
    Node* prev;

    public:
        Node(){
            data = -1;
            next = nullptr;
            prev = nullptr;
        }

        Node(int val){
            data = val;
            next = nullptr;
            prev = nullptr;
        }
    
    friend class linkedlist;
};

class linkedlist{
    Node* head = nullptr;
    Node* tail= nullptr;
    int len =0;

    public:
        int get(int pos){                               //gets the data at given positon
            Node* temp = head;
            for(int i = 0; i<=pos && temp!= nullptr; i++){
                temp = temp->next;
            }

            return temp == nullptr ? -1 : temp->data;
        }

        void add_begin(int val){
            Node* newnode = new Node(val);
            Node* temp = head;
            newnode->next = head;
            newnode->prev = nullptr;
            if (head != NULL) {
                temp->prev = newnode;
            }
            if(head == NULL){
                tail = newnode;
            }
            head = newnode;
            len++;
        }

        void add_end(int val){                          //add at end
            if(head==nullptr){add_begin(val);}
            Node* new_node = new Node(val);
            Node* temp = tail;
            temp->next = new_node;
            new_node->prev = temp;
            tail = new_node;
            len++;
        }

        void add_atpos(int val, int pos){               //add an element to after a given position
            if(pos == -1){
                add_begin(val);
            }
            else if(pos>=len){
                add_end(val);
            }
            else{
                Node* new_node = new Node(val);
                Node* temp2 = head;
                for (int i = 0; i < pos ; i++){
                    temp2 = temp2->next;
                }
                new_node->next = temp2->next;
                new_node->prev = temp2;
                temp2->next = new_node;
                temp2 = temp2->next;
                temp2->prev = new_node;
                if(pos == len){
                    tail = new_node;
                }
                len++;
            }
        }

        void delete_begin(){                            //deletes the first element
            Node* temp = head;
            head = temp->next;
            head->prev = nullptr;
            delete temp;
            len--;
        }

        void delete_end(){                              //deletes last element
            Node* temp = tail;
            tail = temp->prev;
            tail->next = nullptr;
            delete temp;
            len--;
        }

        void delete_pos(int pos){
            ;
        }

        void display(){                                 //display the entire list
            Node* temp = head;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

        void length(){                                     //display length of list
            cout<<len;
        }


        
}; 



int main(){
    linkedlist l1;
    l1.add_begin(1);
    l1.add_begin(5);
    l1.add_begin(10);
    l1.add_end(15);
    l1.add_atpos(12, 0);

    l1.display();

    return 0;
}


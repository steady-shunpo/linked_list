//this file of mine will contain all types of lin lists


//starting with singly lin list

class Node{
    int data;
    Node* next;

    public:
        Node(){
            data = -1;
            next = nullptr;
        }

        Node(int val){
            data = val;
            next = nullptr;
        }
    
    friend class single_ll;
};

class single_ll{
    Node* head;
    int len =0;

    public:
        int get(int pos){
            Node* temp = head;
            for(int i = 0; i<=pos && temp!= nullptr; i++){
                temp = temp->next;
            }

            return temp == nullptr ? -1 : temp->data;
        }

        void add_begin(int val){                        //add at beginning
            Node* new_node = new Node(val);
            new_node->next = head;
            head = new_node;
            len++;
        }

        void add_end(int val){                          //add at end
            if(head==nullptr){add_begin(val);}
            Node* new_node = new Node(val);
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp = new_node;
            len++;
        }

        void add_atpos(int val, int pos){               //add at given position
            if(pos == 0){
                add_begin(val);
            }
            else if(pos>len){
                return;
            }
            else{
                Node* new_node = new Node(val);
                Node* temp2 = head;
                for (int i = 0; i < pos ; i++){
                    temp2 = temp2->next;
                }
                new_node->next = temp2->next;
                temp2->next = new_node;
                len++;
            }
        }
};      


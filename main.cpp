#include <iostream>
#include <stdio.h>
class Node{
	public:
		int num;
		Node *next;
};
class Link_list{
	private:
		Node *current,*root,*newNode,*ptr;
	public:
		Link_list(){
			root=NULL;
			current=NULL;
		}
		void insert(int input_num){
            newNode=new Node;
            newNode->next=NULL;
			if(root==NULL){
                root=newNode;
				newNode->num=input_num;
				current=newNode;
			}else{
				newNode->num=input_num;
				current->next=newNode;
				current=newNode;
			}
		}
        void remove(int index){
            Node *x;
            ptr=root;
            while (index-1){
                ptr=ptr->next;
            }
            x=ptr->next;
            ptr->next=x->next;

        }
		void display(){
            ptr=root;
			while(true){
				printf("%d->",ptr->num);
				if(ptr->next==NULL){
					break;
				}else{
					ptr=ptr->next;
                }
			}
            printf("\n");
		}
};

class Node_save{
    public:
        Node *list_save;
        Node_save  *next;
        char *name;
};
class list_save{
    private:
		Node_save *current,*root,*newNode,*ptr;
	public:
		list_save(){
			root=NULL;
			current=NULL;
		}
		void insert(Node *input_link,char *link_name){
            newNode=new Node_save;
            newNode->next=NULL;
			if(root==NULL){
                root=newNode;
				newNode->name=link_name;
                newNode->list_save=input_link;
				current=newNode;
			}else{
				newNode->name=link_name;
                newNode->list_save=input_link;
				current->next=newNode;
				current=newNode;
			}
		}
		void display(){
            ptr=root;
			while(true){
                printf("list name : %s\n",ptr->name);
				printf("%d->",ptr->list_save->num);
				if(ptr->next==NULL){
					break;
				}else{
					ptr=ptr->next;
                }
			}
            printf("\n");
		}
};


Node *add_two_num(Node *l1,Node *l2){
    Node *newNode=new Node;
    Node *root,*current;
    root=current;
    while(true){
        if(l1->next!=NULL&&l2->next!=NULL){
            newNode->num=l1->num+l2->num;
            current=newNode;
        }else if(l1->next==NULL&&l2->next!=NULL){
            newNode->num=l2->num;
            current=newNode;
        }else if(l1->next!=NULL&&l2->next==NULL){
            newNode->num=l1->num;
            current=newNode;
        }else{
            break;
        }
        current=current->next;
    }
    return root;
}

int main(){
	Link_list link_list;
    
    bool turn=true;
    while(turn){
        char react;
        printf("pleace input the keword:");
        scanf("%c",&react);
        switch (react){
            case 'q':
                turn=false;
                break;
            case 'i':
                int num;
                printf("enter,what figure you want to input :");
                scanf("%d",&num);
                link_list.insert(num);
                break;
            case 'd':
                link_list.display();
                break;
            case 'r':
                int index;
                printf("whitch index node do you want remove:");
                scanf("%d",&index);
                link_list.remove(index);
            // case 'at': 
            //     break;
            
        }
    }
	return 0;
}
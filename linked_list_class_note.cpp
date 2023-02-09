#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data ;
        node *link ;
};

void creation(node **head , int data){
    node *ptr = new node();
    ptr->data = data ;
    ptr->link = NULL ;
    if(*head == NULL) *head = ptr ;
    else{
        node *temp = *head;
        while(temp->link != NULL) temp = temp->link ;
        temp->link = ptr ; 
    }
}

int last_ins(node **head , int data , int n){
    creation(head , data) ;
    return n+1 ;
}

int first_ins(node **head , int data , int n){
    node *ptr = new node();
    ptr->data = data ;
    ptr->link = *head;
    *head = ptr ;
    return n+1 ;
}

int b4_ins(node **head , int data , int search , int n){
    node *ptr = new node() ;
    ptr->data = data ;
    ptr->link = NULL ;

    node *temp = *head , *src;
    while(temp != NULL){
        if(temp->data == search){
            if(temp == *head) return first_ins(head , data , n) ;
            else{
                ptr->link = temp ;
                src->link = ptr ;
                return n+1 ;
            }
        }
        else{
            src = temp ;
            temp = temp->link ;
        }
    }

    cout << "\nTomar data to pailam na \n\n" ;
    return n ;
}

int after_ins(node **head , int data , int search , int n){
    node *ptr = new node();
    ptr->data = data ;
    ptr->link = NULL ;
    
    node *temp = *head ;
    while(temp != NULL){
        if(temp->data == search){
            if(temp->link == NULL) return last_ins(head , data , n);
            else{
                ptr->link = temp->link ;
                temp->link = ptr ;
                return n+1 ;
            }
        }
        else temp = temp->link ;
    }

    cout << "\nTomar data to pailam na \n\n";
    return n ;
}

int dell_first(node **head , int n){
    *head = (*head)->link ;
    return n-1 ;
}

int dell_last(node **head , int n){
    node *temp = *head ;
    while(temp->link->link != NULL) temp = temp->link ;
    temp->link = NULL ;
    return n-1 ;
}

int dell(node **head , int del , int n){
    node *temp = *head ;
    if(temp->data == del) return dell_first(head , n) ;
    else{
        while(temp->link != NULL){
            if(temp->link->data == del) {
                temp->link = temp->link->link ; 
                return n-1 ;
            }
            else temp = temp->link ;
        }
    }

    cout << "\nTomar data to pailam na \n\n";
    return n ;

}

void display(node **head){
    node *temp = *head;
    cout << "\n---------------------------\n" ;
    while(temp != NULL) {
        cout << temp->data ;
        if(temp->link != NULL) cout << " -> ";
        temp = temp->link ;
    }
    cout << "\n---------------------------\n" ;
}

int main(){
    cout << "Initializing List\n";
    cout << "kotogula dhukaite chao : " ;
    
    // 0. Creation & initialization 
    int n , data; cin >> n ; 
    cout << n << " ta data *dao : " ;
    node *head = NULL ;
    for(int i = 0 ; i < n ; i++){
        cin >> data ;
        creation(&head , data) ;
    }
    display(&head) ;

    int choice ;

    do{
        cout << "\n======Menu=======\n";
        cout << "1. First e dhukao \n2. Last e dhukao \n3. konotar age dhukao\n4. konotar pore dhukao\n5. Delete";
        cout<<"\nPress any other key to exit\nChoice : " ;
        cin >> choice ;
        
        // 1. Inserting at first
        if(choice == 1){
            
            cout << "\nFirst data *dao : " ;
            cin >> data ;
            n = first_ins(&head , data , n) ;
            display(&head) ;
        }

        // 2. Inserting at last
        else if(choice == 2){
            cout << "\nlast data *dao : " ;
            cin >> data ;
            n = last_ins(&head , data , n) ;
            display(&head) ;
        }
        
        // 3. Inserting b4 search_data
        else if(choice == 3){
            cout << "\nkontar age : " ;
            int search ; cin >> search ;
            cout << search << " er age dhukanor jonno data *dao : " ;
            cin >> data ;
            n = b4_ins(&head , data , search , n) ;
            display(&head) ;
        }

        // 4. Inserting after search_data
        else if(choice == 4){
            cout << "\nkontar pore : " ;
            int search ; cin >> search ;
            cout << search << " er pore dhukanor jonno data *dao : " ;
            cin >> data ;
            n = after_ins(&head , data , search , n) ;
            display(&head) ;
        }

        // 5. Deleting
        else if(choice == 5){
            cout << "\n======Delete======" ;
            cout << "\n1. First Del\n2.Last Del\n3.Any del\nChoice : ";
            int choice2 ; cin >> choice2 ;
            if(choice2 == 1) dell_first(&head , n) ;
            else if(choice2 == 2)dell_last(&head , n) ;
            else{
                cout << "\nKonta delete : " ;
                int del ; cin >> del ;
                n =  dell(&head , del , n) ;

            }
            display(&head) ;
        }




        else break;

    }while(1) ;

    
}
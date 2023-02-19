#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data ;
        node *link ;
};

/* Creation */
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

/* Last Insert */
int last_ins(node **head , int data , int n){
    creation(head , data) ;
    return n+1 ;
}

/* First Insert */
int first_ins(node **head , int data , int n){
    node *ptr = new node();
    ptr->data = data ;
    ptr->link = *head;
    *head = ptr ;
    return n+1 ;
}

/* Insert Before element */
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

/* Insert After Element */
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

/* First Element Delete */
int dell_first(node **head , int n){
    *head = (*head)->link ;
    return n-1 ;
}

/* Last Element Delete */
int dell_last(node **head , int n){
    node *temp = *head ;
    while(temp->link->link != NULL) temp = temp->link ;
    temp->link = NULL ;
    return n-1 ;
}

/* Any element Delete */
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

/* Merge one list after another's last */
int last_merge(node **head1 , int n , node **head2 , int m){
    node *temp = *head1 ;
    while(temp->link != NULL) temp = temp->link ;
    temp->link = *head2 ;
    return m+n ;
}

/* Merge 2 list elements alternatively */
int shuffle_merge(node **h1, node **h2 , int n) { 
    node *temp1 = *h1, *temp2 = *h2; 
    node *temp1_n, *temp2_n; 
  
    while (temp1 != NULL && temp2 != NULL){  
        temp1_n = temp1->link; 
        temp2_n = temp2->link; 
  
        temp2->link = temp1_n;
        temp1->link = temp2;

        temp1 = temp1_n; 
        temp2 = temp2_n; 
    }
    return n*2 ;
}

/* Display List*/
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
    int choice , chh;
    cout << "1. Ekta list banabo , oitare modify korbo \n2. 2ta list lagabo\nChoice bolo : " ;
    cin >> chh ;
    

    // Single List banano & modify
    if(chh == 1){
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

    else if(chh == 2){
        cout << "\n====2 List Merge====\n" ;
        int cm ; 
        cout << "1. Ektar sesh e arekta\n2. Ekta element er pore arektar element(alternate)\n" ;
        cout << "Choice : " ;
        cin >> cm ; 

        // 6. Merging 2 list, ektar sesh e arekta
        if(cm == 1){
            node *h1 = NULL ;
            node *h2 = NULL ;
            int item ;
            cout << "List 1 te koyta : " ;
            int n ; cin >> n ;
            cout << "First list er "<<n<<" ta *dao : " ;
            for(int i = 0 ; i < n ; i++){
                cin >> item ;
                creation(&h1 , item) ;
            }

            cout << "List 2 te koyta : " ;
            int m ; cin >> m ;
            cout << "Porer list er "<<m<<" ta *dao : " ;
            for(int i = 0 ; i < m ; i++){
                cin >> item ;
                creation(&h2 , item) ;
            }

            cout << "\nList 1" ;
            display(&h1) ;
            cout << "\nList 2" ;
            display(&h2) ;
            n = last_merge(&h1 , n , &h2 , m) ;
            
            cout << "\nMerged one after another" ;
            display(&h1) ;
        }

        // 7. Merging 2 list items one after another (alternatively)
        else if(cm == 2){
            cout << "Koyta dhukaite chao : " ;
            int nm ; cin >> nm ;
            node *h1 = NULL;
            cout << "First list er "<<nm<<" ta *dao : " ;
            for(int i = 0 ; i < nm ; i++){
                int d ; cin >> d ;
                creation(&h1 , d) ;
            }
            node *h2 = NULL;
            cout << "Porer list er "<<nm<<" ta  *dao : " ;
            for(int i = 0 ; i < nm ; i++){
                int d ; cin >> d ;
                creation(&h2 , d) ;
            }
            cout << "\nList 1" ;
            display(&h1) ;
            cout << "\nList 2" ;
            display(&h2) ;
            nm = shuffle_merge(&h1 , &h2 , nm) ;
            
            cout << "\nMerged alternatively" ;
            display(&h1) ;
        }
    }
    
}
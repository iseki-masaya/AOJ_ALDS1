#include <iostream>
 
using namespace std;
 
class node{
public:
    node* next;
    node* prev;
    int data;
     
    node(){next=prev=0;};
    node(node *n,node *p,int d){next=n;prev=p;data=d;};
     
    friend class list;
};
 
class list{
    node *first;
    node *last;
     
public:
    list();
    ~list();
     
    void list_insert(int key);
    void list_delete(int key);
    void list_deleteFirst(void);
    void list_deleteLast(void);
    void printAll(void);
};
 
list::list(){
    first=0;
    last=0;
}
 
list::~list(){
    node *nf;
    node *nl;
     
    nf=first;
    while(nf!=0){
        nl = nf->next;
        delete nf;
        nf = nl;
    }
}
 
void list::list_insert(int key){
    if(last==0){
        first = new node(0,0,key);
        last = first;
    }
    else{
        first->prev = new node(first,0,key);
        first = first->prev;
    }
}
 
void list::list_delete(int key){
    node *nf;
    nf = first;
    while(nf!=0){
        if(nf->data==key){
            if(nf==first){
                list_deleteFirst();
                return;
            }
            else if(nf==last){
                list_deleteLast();
                return;
            }
            else{
                nf->next->prev = nf->prev;
                nf->prev->next = nf->next;
                return;
            }
        }
        nf = nf->next;
    }
}
 
void list::list_deleteFirst(){
    if(first==last){
        first=last=0;
    }
    else{
        first->next->prev = 0;
        first = first->next;
    }
}
 
void list::list_deleteLast(){
    if(first==last){
        first=last=0;
    }
    else{
        last->prev->next=0;
        last = last->prev;
    }
}
 
void list::printAll(){
    cout << first->data;
    while(first!=last){
        first = first->next;
        cout << " " << first->data;
    }
    cout << endl;
}
 
int main(int argc, const char * argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
     
    int i;
    int num;
    cin >> num;
     
    list intList;
     
    string input;
    int arg;
    for(i=0;i<num;++i){
        cin >> input;
        if(input[0]=='i'){
            cin >> arg;
            intList.list_insert(arg);
        }
        else if(input[0]=='d'){
            if (input.size()>6) {
                if(input[6]=='F')
                    intList.list_deleteFirst();
                else if(input[6]=='L')
                    intList.list_deleteLast();
            }
            else{
                cin >> arg;
                intList.list_delete(arg);
            }
        }
    }
     
    intList.printAll();
     
    return 0;
}
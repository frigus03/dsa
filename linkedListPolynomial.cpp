#include<iostream>
using namespace std;
struct Node{
    int coeff,exp;Node*next;
    Node(int c,int e){coeff=c;exp=e;next=NULL;}
};
void append(Node*&head,Node*&tail,int c,int e){
    if(c==0)return;
    Node*temp=new Node(c,e);
    if(!head){head=tail=temp;}
    else{tail->next=temp;tail=temp;}
}
Node*add(Node*a,Node*b){
    Node*res=NULL,*tail=NULL;
    while(a&&b){
        if(a->exp==b->exp){
            append(res,tail,a->coeff+b->coeff,a->exp);
            a=a->next;b=b->next;
        }else if(a->exp>b->exp){
            append(res,tail,a->coeff,a->exp);a=a->next;
        }else{append(res,tail,b->coeff,b->exp);b=b->next;}
    }
    while(a){append(res,tail,a->coeff,a->exp);a=a->next;}
    while(b){append(res,tail,b->coeff,b->exp);b=b->next;}
    return res;
}
Node*sub(Node*a,Node*b){
    Node*res=NULL,*tail=NULL;
    while(a&&b){
        if(a->exp==b->exp){
            append(res,tail,a->coeff-b->coeff,a->exp);
            a=a->next;b=b->next;
        }else if(a->exp>b->exp){
            append(res,tail,a->coeff,a->exp);a=a->next;
        }else{append(res,tail,-b->coeff,b->exp);b=b->next;}
    }
    while(a){append(res,tail,a->coeff,a->exp);a=a->next;}
    while(b){append(res,tail,-b->coeff,b->exp);b=b->next;}
    return res;
}
Node*mul(Node*a,Node*b){
    Node*res=NULL;
    for(Node*p=a;p;p=p->next){
        for(Node*q=b;q;q=q->next){
            int c=p->coeff*q->coeff,e=p->exp+q->exp;
            Node*temp=res,*prev=NULL;
            while(temp&&temp->exp>e){prev=temp;temp=temp->next;}
            if(temp&&temp->exp==e)temp->coeff+=c;
            else{
                Node*n=new Node(c,e);
                if(!prev){n->next=res;res=n;}
                else{n->next=prev->next;prev->next=n;}
            }
        }
    }
    return res;
}
void print(Node*head){
    if(!head){cout<<"0\n";return;}
    while(head){
        cout<<head->coeff<<"x^"<<head->exp;
        head=head->next;
        if(head)cout<<" + ";
    }
    cout<<endl;
}
Node*create(){
    int n,c,e;Node*head=NULL,*tail=NULL;
    cout<<"Enter no. of terms:";cin>>n;
    cout<<"Enter coeff and exp in descending order:\n";
    for(int i=0;i<n;i++){cin>>c>>e;append(head,tail,c,e);}
    return head;
}
int main(){
    Node*a=NULL,*b=NULL,*res=NULL;
    int ch;
    do{
        cout<<"\nMenu\n1.Enter Polynomials\n2.Add\n3.Subtract\n4.Multiply\n5.Display A,B\n6.Exit\nChoice: ";
        cin>>ch;
        switch(ch){
            case 1:a=create();b=create();break;
            case 2:res=add(a,b);cout<<"Result(Add): ";print(res);break;
            case 3:res=sub(a,b);cout<<"Result(Sub): ";print(res);break;
            case 4:res=mul(a,b);cout<<"Result(Mul): ";print(res);break;
            case 5:cout<<"A: ";print(a);cout<<"B: ";print(b);break;
            case 6:cout<<"Exiting...\n";break;
            default:cout<<"Invalid choice\n";
        }
    }while(ch!=6);
}

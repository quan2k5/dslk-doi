#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
}Node;
//tao node moi
Node* createNode(int n){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=n;
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;
}
//them node vao cuoi mang
void insertToTail(Node** head,int n){
	Node* newNode=createNode(n);
	if(*head==NULL){
		*head=newNode;
		return;
	}
	Node* tmp=*head;
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	newNode->prev=tmp;
	tmp->next=newNode;
}
//duyet node theo chieu xuoi
void printList(Node** head){
	Node* tmp=*head;
	while(tmp!=NULL){
		printf("%d<->",tmp->data);
		tmp=tmp->next;
	}
	printf("NULL");
}
//chen danh sach vao danh sach
void insertLink(Node** a,Node** b,int n){
	Node* x=*a;
	Node* z=*b;
	Node* y=*b;
	while(y->next!=NULL){
	y=y->next;
   }
	if(n==0){
	   y->next=x;
	   x->prev=y;
	   	*a=z;
	   return;
	}
    for(int i=0;i<n-1&&x->next!=NULL;i++){
    	x=x->next;
	}
	if(x==NULL){
		printf("Vi tri khong phu hop");
		return;
	}
	y->next=x->next;
	x->next->prev=y;
	x->next=z;
	z->prev=x;
}
int main(){
	int n,x;
	scanf("%d",&n);
	Node* a=NULL;
	printf("Nhap phan tu cua danh sach lien ket 1\n");
	for(int i=0;i<n;i++ ){
		scanf("%d",&x);
		insertToTail(&a,x);
	}
	Node* b=NULL;
	scanf("%d",&n);
	printf("Nhap phan tu cua danh sach lien ket 2\n");
	for(int i=0;i<n;i++ ){
		scanf("%d",&x);
		insertToTail(&b,x);
	}
	printf("Nhap vi tri chen\n");
	scanf("%d",&n);
	printf("Chen danh sach 2 vao danh sach 1 tai vi tri: %d\n",n);
	insertLink(&a,&b,n);
    printList(&a);
}

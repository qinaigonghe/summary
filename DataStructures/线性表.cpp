#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define InitSize 100
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList; 		//*代表什么意思？	//头指针指向 


typedef struct{
	int data[50];
	int length;
}SqList;
typedef struct{
	int *data;
	int MaxSize,length;
}SeqList;

bool ListInsert(SeqList &L,int i,int e){
	//printf("%d%d",L.length,L.MaxSize);
	if(i<1||i>L.length+1)return false;
	if(L.length>=L.MaxSize) return false;
	for(int j=L.length;j>=i;j--) L.data[j]=L.data[j-1];
	L.data[i-1]=e;

	//printf("%d",e);
	L.length++;
	return true;
}
int main(){
	SeqList L;
	L.data=(int*)malloc(sizeof(int)*InitSize);//这个int*与 定义的int * 
	int a=20;
	ListInsert(L,1,a);				//关于这个实参与形参，地址的分析 
	ListInsert(L,1,a);
	printf("%d",L.data[1]); 
	//printf("hello"); 
	return 0;
} 

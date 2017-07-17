#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash{
	int key;
	int val;
	struct hash *next;
};

typedef struct hash* table;
typedef struct hash* List;

List InsertHead(List L,int key,int value){
	List head,p;
	head  = L;
	p = (List)malloc(sizeof(struct hash));
	p->next = head->next;
	p->key = key;
	p->val = value;
	head->next = p;
	return head;
}

List Find(List L, int value){
	List p;
	p = L->next;
	while(p!=NULL && p->val!=value){
		p = p->next;
	}
	return p;
}

int* twoSum(int* nums, int numsSize, int target) {
	int *a = (int*)malloc(2*sizeof(int));
	int expect;
	List L,head;
	int value =0;
	L = (List)malloc(sizeof(struct hash));
	for(int i=0;i<numsSize;i++){
		value = nums[i];
		if(!Find(L,value)){
			head = InsertHead(L,i,value);
		}
		expect = target - value;
		head = Find(L,expect);
		if(head){
			int n = head->key;
			if(n < i){
				a[0] = n;
				a[1] = i;
				return a;
			}
		}
	}
	return a;
}

int main(){
	int nums[] = {150,24,79,50,88,345,3,200};
	
	int *a;
	a = twoSum(nums,8,200);
	for(int i=0;i<2;i++){
		printf("%d\t",a[i]);
	}
//    List L,head,p;
//	head = L = (List)malloc(sizeof(struct hash));
//	head = InsertHead(L,0,2);
//	head = InsertHead(L,1,7);
////	head = NULL;
////	head = Find(L,2);
//    p = L->next;
//	while(p!=NULL){
//		printf("%d\t",p->val);
//		p = p->next;
//	}
	return 0;
}

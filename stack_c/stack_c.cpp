#include <iostream>
using namespace std;
extern "C" {

#define true 1
#define false 0

struct node{
	int v;
	struct node * pre;
};

struct node * NewNode(struct node * pre, int v){
	struct node nd;
	nd.v = v;
	nd.pre = pre;
	return &nd;	
}

struct Stack
{
	struct node * top;
	int size;
	int length;
};

/*
* 展示栈内容
*/
extern void Display(struct Stack stk);

/*
* 判断栈顶元素距离栈底高度，Go不能做指针运算，需要提供该函数
*/
int before(int * a,int* b){
	return a - b;
}


// 初始化
void Init(struct Stack * stk,int size){
	stk->top = NewNode(0,NULL);
	stk->size = size;
	stk->length = 0;
}

// 栈容量
int Capacity(Stack stk){
	return stk.size;
}

// 栈大小
int Length(struct Stack stk){
	return stk.length;
}

// 是否为空
bool IsEmpty(struct Stack stk){
	return Length(stk)<=0;
}

// 是否满栈
bool IsFull(struct Stack stk){
	if (Length(stk) >= Capacity(stk))
	{
		return true;
	}
	return false;
}

// 压栈
bool Push(struct Stack * stk,int v){
	if (IsFull(*stk))
	{
		return false;
	}
	struct node * nd = NewNode(stk->top, v);
	stk->top = nd;
	stk->length++;
	return true;
}

// 弹栈
int Pop(struct Stack * stk,bool * ok){
	if (IsEmpty(*stk))
	{
		*ok = false;
		return -1;
	}
	*ok = true;
	stk->length--;
	int v = stk->top->v;
	stk->top = stk->top->pre;
	return v;
}

// 查看栈顶元素
int Seek(struct Stack stk,bool * ok){
	if (IsEmpty(stk))
	{
		*ok = false;
		return -1;
	}
	*ok = true;
	struct node* nd = stk.top;
	if(NULL == nd){
		*ok = false;
		return 0;
	}	
	return nd->v;
}

}

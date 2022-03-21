//双向链表
#include<iostream>
#include<string>
using namespace std;

struct node			//创建结构体
{
	int date;
	node* last;
	node* next;
};

struct node* creat ()			//创建一个双向链表
{
	cout << "输入数据（输入0时结束）" << endl;
	node* head, * p1, * p2;
	p1 = new node;
	p2=p1;
	cin >> p1->date;
	head = NULL;				//创建头节点

	int i = 0;
	
	while (p1->date != 0)
	{
		i += 1;
		if (i == 1)
		{
			head = p1;
		}
		else
		{
			p2->next = p1;
			p1->last = p2;
		}						//将两个节点双向连接
		p2 = p1;				
		p1 = new node;			//p1开辟新的节点后连接上一个节点
		cin >> p1->date;
	}
	p2->next = NULL;
	return head;
}


void print(struct node* p)//打印链表
{
	cout << "输出的数据为：" << endl;
	do
	{
		cout << p->date << " ";
		p = p->next;
	} while (p != NULL);
}


int main()
{
	struct node* p;
	p = creat();
	
	print(p);

	free(p);
}



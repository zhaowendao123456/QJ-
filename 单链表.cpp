//单向动态链表

#include <iostream>
using namespace std;

struct node		//创建一个结构体
{
	int date;
	struct node* next;
};

struct node* creat()//创建一个单向链表
{
	cout << "请输入数据，每输入一个数后点击enter输入下一个，输入0表示结束！！" << endl;

	node* head, * p1, * p2;
	p1 = p2 = new node;
	cin >> p1->date;
	head = NULL;//将链表初始化

	int i = 0;

	while (p1->date != 0)//输入数据，直到0结束
	{
		i += 1;
		if (i == 1)
			head = p1;
		else
			p2->next = p1;//连接上一节点
		p2 = p1;
		p1 = new node;//p1开辟新的节点,p2用于连接新的节点
		cin >> p1->date;
	}
	p2->next = NULL;
	return head;//返回头节点
}

void print(struct node* p)//打印链表
{
	cout << "输出的数据为：" << endl;
	do
	{
		cout << p->date << " ";
		p = p->next;
	} while (p != NULL);
	cout << endl;
}

void swap (struct node* p)//调换奇偶的函数
{
	node* head = p;
	int temp;
	while(1)
	{
		if(p->next!=NULL && p->next->next != NULL)
		{
			if ((p->date % 2) == (p->next->date % 2))//判断是否一奇一偶
			{

			}
			else                                   //如果是则调换，否则不做改动
			{
				temp = p->date;
				p->date = p->next->date;
				p->next->date = temp;
			}
			p = p->next->next;
		}
		else//直到结束退出循环
		{
			break;
		}
	} 
	cout << "已调换奇偶数" << endl;
	print(head);
}

void find_mid(struct node* p)
{
	cout << "中间节点的数据为：";
	node* p1, * p2;
	p1 = p2 = p;
	while (1)
	{
		//当走到到达链表最后的时候跳出循环
		//分情况输出中间节点的数据
		if (p1->next!=NULL&&p1->next->next == NULL)			
		{
			cout << p2->date << "和" << p2->next->date << endl << endl;
			break;
		}
		if (p1->next == NULL)
		{
			cout << p2->date << endl << endl;
			break;
		}
		p1 = p1->next->next;
		p2 = p2->next;
	}
}

void judge_circle(struct node* p)//判断链表是否成环
{
	//使用快慢指针法
	node* fast, * low;
	fast = low = p;
		for (int i = 0;i < 100;i++)
		{
			if (fast->next->next == NULL)
				fast = fast->next->next;
			else
			{
				cout << "该链表不成环！" << endl;
				break;
			}
			low = low->next;
			if (fast == low)
			{
				cout << "该链表成环！" << endl;
				break;
			}
		}
	
}

void reversal(struct node* p)//反转单链表
{
	node* p1, * p2, * p3;
	p1 = p->next->next;
	p2 = p->next;
	p3 = p;
	p->next = NULL;//将头节点改为尾节点
	while (p1->next != NULL)//将每一个节点中*next改为指向上一个节点
	{
		p2->next = p3;
		p3 = p2;
		p2 = p1;
		p1 = p1->next;
	}
	p1->next = p2;
	p2->next = p3;
	//尾节点改为头节点
	print(p1);
}

int main()
{
	struct node* p;
	p = creat();
	system("cls");

start:

	system("cls");
	
	cout << "1、将单链表奇偶调换" << endl << "2、输出单链表的中点"
		<< endl << "3、判断链表是否成环" << endl << "4、将链表反转" << endl
		<< "请选择想要实现的功能（输入对应的序号）" << endl;
	int a;
	cin >> a;

	system("cls");

	if (a == 1)
	{
		swap(p);
	}
	if (a == 2)
	{
		find_mid(p);
	}
	if (a == 3)
	{
		judge_circle(p);
	}
	if (a == 4)
	{
		reversal(p);
	}

	system("pause");
	system("cls");
	goto start;

	free(p);
}  

	

	
	
	
//˫������
#include<iostream>
#include<string>
using namespace std;

struct node			//�����ṹ��
{
	int date;
	node* last;
	node* next;
};

struct node* creat ()			//����һ��˫������
{
	cout << "�������ݣ�����0ʱ������" << endl;
	node* head, * p1, * p2;
	p1 = new node;
	p2=p1;
	cin >> p1->date;
	head = NULL;				//����ͷ�ڵ�

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
		}						//�������ڵ�˫������
		p2 = p1;				
		p1 = new node;			//p1�����µĽڵ��������һ���ڵ�
		cin >> p1->date;
	}
	p2->next = NULL;
	return head;
}


void print(struct node* p)//��ӡ����
{
	cout << "���������Ϊ��" << endl;
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



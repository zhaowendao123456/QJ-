//����̬����

#include <iostream>
using namespace std;

struct node		//����һ���ṹ��
{
	int date;
	struct node* next;
};

struct node* creat()//����һ����������
{
	cout << "���������ݣ�ÿ����һ��������enter������һ��������0��ʾ��������" << endl;

	node* head, * p1, * p2;
	p1 = p2 = new node;
	cin >> p1->date;
	head = NULL;//�������ʼ��

	int i = 0;

	while (p1->date != 0)//�������ݣ�ֱ��0����
	{
		i += 1;
		if (i == 1)
			head = p1;
		else
			p2->next = p1;//������һ�ڵ�
		p2 = p1;
		p1 = new node;//p1�����µĽڵ�,p2���������µĽڵ�
		cin >> p1->date;
	}
	p2->next = NULL;
	return head;//����ͷ�ڵ�
}

void print(struct node* p)//��ӡ����
{
	cout << "���������Ϊ��" << endl;
	do
	{
		cout << p->date << " ";
		p = p->next;
	} while (p != NULL);
	cout << endl;
}

void swap (struct node* p)//������ż�ĺ���
{
	node* head = p;
	int temp;
	while(1)
	{
		if(p->next!=NULL && p->next->next != NULL)
		{
			if ((p->date % 2) == (p->next->date % 2))//�ж��Ƿ�һ��һż
			{

			}
			else                                   //�������������������Ķ�
			{
				temp = p->date;
				p->date = p->next->date;
				p->next->date = temp;
			}
			p = p->next->next;
		}
		else//ֱ�������˳�ѭ��
		{
			break;
		}
	} 
	cout << "�ѵ�����ż��" << endl;
	print(head);
}

void find_mid(struct node* p)
{
	cout << "�м�ڵ������Ϊ��";
	node* p1, * p2;
	p1 = p2 = p;
	while (1)
	{
		//���ߵ�������������ʱ������ѭ��
		//���������м�ڵ������
		if (p1->next!=NULL&&p1->next->next == NULL)			
		{
			cout << p2->date << "��" << p2->next->date << endl << endl;
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

void judge_circle(struct node* p)//�ж������Ƿ�ɻ�
{
	//ʹ�ÿ���ָ�뷨
	node* fast, * low;
	fast = low = p;
		for (int i = 0;i < 100;i++)
		{
			if (fast->next->next == NULL)
				fast = fast->next->next;
			else
			{
				cout << "�������ɻ���" << endl;
				break;
			}
			low = low->next;
			if (fast == low)
			{
				cout << "������ɻ���" << endl;
				break;
			}
		}
	
}

void reversal(struct node* p)//��ת������
{
	node* p1, * p2, * p3;
	p1 = p->next->next;
	p2 = p->next;
	p3 = p;
	p->next = NULL;//��ͷ�ڵ��Ϊβ�ڵ�
	while (p1->next != NULL)//��ÿһ���ڵ���*next��Ϊָ����һ���ڵ�
	{
		p2->next = p3;
		p3 = p2;
		p2 = p1;
		p1 = p1->next;
	}
	p1->next = p2;
	p2->next = p3;
	//β�ڵ��Ϊͷ�ڵ�
	print(p1);
}

int main()
{
	struct node* p;
	p = creat();
	system("cls");

start:

	system("cls");
	
	cout << "1������������ż����" << endl << "2�������������е�"
		<< endl << "3���ж������Ƿ�ɻ�" << endl << "4��������ת" << endl
		<< "��ѡ����Ҫʵ�ֵĹ��ܣ������Ӧ����ţ�" << endl;
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

	

	
	
	
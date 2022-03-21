# 文档

## 一、问题描述

本周完成的作业为一个单链表和双向链表。其中单链表包括的功能有单链表的奇偶调换、输出单链表的中点、判断链表是否成环和将链表反转。

## 二、思路分析&代码实现

### 1、双向链表

双向链表的结构体中包含了指向下一个节点的next指针和指向上一个节点的last指针。

struct node			//创建结构体
{
	int date;
	node* last;
	node* next;
};

在创建的链表的过程中，利用p1指针开辟新的节点，每创建一个新的节点就将上衣节点的next指针指向该节点再将该节点的last指针指向上一个节点

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



### 2、单链表

单链表每一个节点的结构体中只有数据和指向下一节点的next指针，创建的过程类似双向链表。额外的功能如下：

#### （1）奇偶调换

首先判断相邻连个节点中的数据是否为一奇一偶，若是则调换，若不是，则不做任何改变。判断可以通过将该数字对2取余实现。然后向后向后移动两个节点直至结束即可。

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



#### （2）输出中间节点

可以通过快慢指针的方法判断出一个链表的中间节点的数据。首先，创建一个快指针，在每次循环中移动两个节点，再创建一个慢指针，只移动一个节点。当快指针到达链表末尾时满指针指向中间节点。

需要注意的的是，链表的长度为偶数个时有两个中间节点，而为奇数个时只有一个中间节点。这可以通过快指针来判断。从头节点开始（这个链表中头节点有数据）当快指针的下下节点为空时，则有偶数个数据，那么满指针指向的节点和其下一个节点都是中间节点。当快指针的下一个节点为空，那么慢指针指向的就是中间节点。

而当判断快指针的下一节点或下下节点为空时需要跳出循环！！

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



#### （3）判断链表是否成环

判断方式仍然需要快慢指针。如果一个链表成环，那么当循环次数足够多，一定会出现快指针等于慢指针，而如果一个链表为单项链表，则快慢指针不可能相等。

因此，在程序中循环很多次逐一判断两指针是否相等。

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



#### （4）反转单链表

最先想到的方法是使用头插法建立一个新的链表，然后遍历原链表，将每个数据复制进新的链表中。但可能会比较浪费内存。因此，不采用这种方法。

在我的程序中是把每个节点的next指针改为指向上一个节点。这需要3个指针p1、p2、p3。3个指针分别是对应3个相邻的节点，每次循环将中间节点的next指针改为指向上一个节点，然后整体往后移动一个节点。直到最后一个循环结束时要把最后3个节点相连，并且将第一个节点的next改为NULL。

注：需要3个指针的原因是当修改过一个节点的next的指向后用2个指针无法找到下一个节点。

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



## 三、测试结果

### 1、双向链表

![image-20220320175214216](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220320175214216.png)

### 2、单链表

![image-20220320174822038](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220320174822038.png)

![image-20220320174836094](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220320174836094.png)

![image-20220320174857312](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220320174857312.png)

![image-20220320174913679](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220320174913679.png)

![image-20220320175057937](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220320175057937.png)

![image-20220320175005235](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20220320175005235.png)



## 四、思考和小结

在该项目中判断链表是否成环功能存在逻辑上的漏洞。在我的程序中循环的是有限次数。但不能完全判断在此之后是否会发生快慢指针相等的情况。而程序不能判断无限次，即使程序一直不停的运行也无法说明就一定是单链表。也就是说，如果判断次数有限，不能严格说明是否成环，但是判断次数又不可能无限。

除此之外，其他功能都基本完成。
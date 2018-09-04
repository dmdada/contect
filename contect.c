
#include "contect.h"
void menu()
{
	printf("*******************菜单*******************\n");
	printf("*****1.增加联系人*********2.删除联系人****\n");
	printf("*****3.查找联系人*********4.修改联系人****\n");
	printf("*****5.打印联系人*********6.清空联系人****\n");
	printf("*****7.排序联系人*********0.退出通讯录****\n");
	printf("******************************************\n");
}
void test()
{
	contact my_count;
	init_contest(&my_count);
	int input = 1;
	do
	{
		menu();
		printf("请输入你的选择：");
		scanf("%d",&input);
		switch (input)
		{
		case EXIT:
			free_mem(&my_count);
			break;
		case ADD:
			Add_count(&my_count);
			break;
		case DEL:
			Dle_count(&my_count);
			break;
		case FIND:
			Find_count(&my_count);
			break;
		case CHANGE:
			Change_count(&my_count);
			break;
		case SHOW:
			Show_count(&my_count);
			break;
		case CLS:
			Cls_count(&my_count);
			break;
		case PAIXU:
			Paixu_count(&my_count);
			break;
		default:
			printf("输入错误！\n");
			break;
		}

	} while (input);



}
void init_contest(pcon  contest)
{
	contest->sz = 0;
	contest->human = (S*)malloc(sizeof(S)*NUM);
	memset(contest->human, 0, NUM*sizeof(contest->human));
	contest->capacity = NUM;
}
/*contest->sz = 0;
memset(contest->human, 0, sizeof(contest->human));
}*/

void check_capacity(pcon contest)
{
	if (contest->sz < contest->capacity)
	{
		contest->human = (S *)realloc(contest->human, sizeof(S)*NUM1);
		contest->capacity = contest->capacity + NUM1;
	}

}
void Add_count(pcon contest)//增添函数
{
	if ((contest->sz) >contest->sz)
	{
		printf("通讯录容量已满，不能再添加！");
		return;
	}
	printf("请输入要添加的联系人姓名\n");
	scanf("%s", (contest->human[contest->sz].name));
	printf("请输入要添加的联系人性别\n");
	scanf("%s", contest->human[contest->sz].sex);
	printf("请输入要添加的联系人年龄\n");
	scanf("%d", &contest->human[contest->sz].age);
	printf("请输入要添加的联系人电话\n");
	scanf("%s", contest->human[contest->sz].tele);
	printf("请输入要添加的联系人地址\n");
	scanf("%s", contest->human[contest->sz].addr);
	printf("\n添加成功\n");
	(contest->sz)++;
}
void  Dle_count(pcon contest)//删除函数
{
	if ((contest->sz) == 0)
	{
		printf("该通讯录中没有联系人！\n");
	}
	else
	{

		int i = 0;
		printf("请输入要删除的人的姓名：\n");
		int ret = search(contest);
		if (ret != -1)
		{
			for (i = ret; i < contest->sz; i++)
			{
			contest->human[i] = contest->human[i + 1];
				(contest->sz)--;
			}
			printf("删除成功！\n");
		}
		else
			printf("联系人不存在！\n");
	}
}

int search(pcon contest)//比较函数
{
	int i = 0;
	char name[15];
	scanf("%s", name);
	for (i = 0; i < contest->sz; i++)
	{
		if (strcmp(contest->human[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void Show_count(pcon contest)//显示所有联系人信息  
{
	if ((contest->sz) == 0)
	{
		printf("该通讯录中没有联系人！\n");
	}
	else
	{

		int i = 0;
		printf("    name       sex     age          tel          address         \n");
		for (i = 0; i < contest->sz; i++)
		{
			printf("%8s    %5s    %5d     %8s     %8s \n", (contest->human[i]).name,
				(contest->human[i]).sex,
				(contest->human[i]).age,
				(contest->human[i]).tele,
				(contest->human[i]).addr);
		}
	}
}
void Find_count(pcon contest)//查找联系人
{


	if ((contest->sz) == 0)
	{
		printf("此通讯录中没有联系人！\n");
		return;
	}
	printf("请输入联系人的姓名>");
	int ret = search(contest);
	if (ret != -1)
	{
		printf("你查找的联系人信息为：\n");
		printf("姓名：%s\n", (contest->human[ret]).name);
		printf("性别：%s\n", (contest->human[ret]).sex);
		printf("年龄：%d\n", (contest->human[ret]).age);
		printf("电话：%s\n", (contest->human[ret]).tele);
		printf("地址：%s\n\n", (contest->human[ret]).addr);
	}
	else
		printf("没有找到你要查找的联系人！\n");
}
void Change_count(pcon contest)//修改联系人
{

	if ((contest->sz) == 0)
	{
		printf("此通讯录中没有联系人！\n");
		return;
	}

	printf("请输入要修改联系人的姓名>");

	int ret = search(contest);
	if (ret != -1)
	{
		printf("请输入联系人新的姓名>");
		scanf("%s", (contest->human[ret]).name);
		printf("请输入联系人新的性别>");
		scanf("%s", (contest->human[ret]).sex);
		printf("请输入联系人新的年龄>");
		scanf("%d", &(contest->human[ret]).age);
		printf("请输入联系人新的电话号码>");
		scanf("%s", (contest->human[ret]).tele);
		printf("请输入联系人新的地址>");
		scanf("%s", (contest->human[ret]).addr);
		printf("修改成功\n");
	}
	else printf("此通讯录中此联系人不存在!\n");
}

void Cls_count(pcon contest)//清空通讯录
{
	if ((contest->sz) == 0)
	{
		printf("此通讯录中没有联系人！\n");
		return;
	}
	contest->sz = 0;
	printf("清空完成\n");
}

void Paixu_count(pcon contest)//排序通讯录中所有联系人
{
	S tmp = { 0 };
	int i = 0;
	int j = 0;
	if ((contest->sz) == 0)
	{
		printf("此通讯录中没有联系人！\n");
		return;
	}
	for (i = 0; i < (contest->sz) - 1; i++)
	{
		for (j = 0; j < (contest->sz) - i - 1; j++)
		{
			if (strcmp((contest->human[j]).name, (contest->human[j + 1]).name)>0)
			{
				tmp = contest->human[j];
				contest->human[j] = contest->human[j + 1];
				contest->human[j + 1] = tmp;
			}
		}
	}
	Show_count(contest);

}

void free_mem(pcon contest)
{
	free(contest->human);
	contest->human = NULL;
}



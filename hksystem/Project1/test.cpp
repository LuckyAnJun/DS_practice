#define _CRT_SECURE_NO_WARNINGS
#include"train.h"

int main()
{
	TN* s;//��������server
	int m,n,log=-1;
	UN* u;//�����û���user
	AU* e;
	s = (TN*)malloc(sizeof(TN));
	u = (UN*)malloc(sizeof(UN));
	e = (AU*)malloc(sizeof(AU));//�����ٺ�һ��ͷ��㣬���洢��Ч����
	s->next = NULL;
	u->next = NULL;
	e->next = NULL;//next��ΪNULL
	loadtrain(s);
	loadticket(u);
	loaduser(e);
	system("color F3");//����Ĭ�Ͽ���̨ǰ���ͱ�����ɫ,���Ը����Լ�ϲ������ɫ�޸�
	printf("\n\t-----------------------��ӭ������Ʊ����ϵͳ-----------------------\n");
	printf("\n\t\t\t*********************************\n");
	printf("\n\t\t\t\t1.�����û�\n\t\t\t\t2.���ǹ���Ա\n\t\t\t\t");
	printf("\n\t\t\t*********************************\n\t\t\t");
	printf("��������Ҫִ�еĹ���(1-2)��");
	scanf_s("%d", &m);
	if (m == 1)
	{
		while (log == -1)
		{
			loginmenu();
			log = loginin(e);
		}
		while (1)
		{
			usermenu();
			scanf_s("%d", &n);
			switch (n)
			{
			case 1:
				search(s); break;
			case 2:
				orderTicket(s, u,log); break;
			case 3:
				refundTicket(s, u); break;
			case 4:
				searchticket(u,log); break;
			case 5:
				exit(0); break;
			default:
				continue;//���������continue��������ѭ��
			}
		}
	}
	else if (m==2)
	{
		system("cls");
		int i;
		char key[6] = "88888",key1[6] = "";
		printf("\t���������Ա��Կ����5�δ�����ᣩ��");
		for (i = 1; ;)
		{
			scanf_s("%s", key1,6);
			if (strcmp(key, key1) != 0)
			{
				i++;
				if (i > 5)
				{
					printf("\t��Կ����������࣬�����Զ�����");
					exit(0);
				}
				printf("\t����������������룺");
			}
			else
			{
				printf("\t��Կ��֤�ɹ���\n");
				system("pause");
				break;
			}
		}
		while (1)
		{
			adminmenu();
			scanf_s("%d", &n);
			switch (n)
			{
			case 1:
				luru(s); break;
			case 2:
				search(s); break;
			case 3:
				allp_show(s, u); break;
			case 4:
				updateInfo(s); break;
			case 5:
				deletetrain(s); break;
			case 6:
				exit(0); break;
			default:
				continue;//���������continue��������ѭ��
			}
		}
	}
	return 0;
}
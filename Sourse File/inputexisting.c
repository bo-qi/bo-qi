#include<stdio.h>
#include<string.h>
#include<process.h>
#define N 25
#include"str.h"
#include"setup.h"
#include"inputexisting.h"
#include"query.h"
#include"sort.h"
#include"modify.h"
#include"limit.h"
#include"warehousing.h"
#include"outbound.h"
int main()
{
	int j;
	long a,b;
	char name[N][20];//��¼�ֿ��ļ�·�� 
	setup(name);
	while(1)
	{
		printf("Ŀ¼��\n");
		printf("0 : �˳�����\n1 : ���¼��\n2 : ����ѯ\n3 : �������\n4 : ����޸�\n5 : ����ɾ��\n6 : ���øߵʹ�\n7 : ������\n8 : �������\n9 : ��ⵥ��ѯ\n10 : ���ⵥ��ѯ\n");
		scanf("%d",&j);
		switch(j)
		{	
			case 0:
				exit(0);
			case 1:
				Inputexisting(get(name));
				break;
			case 2:
				query(get(name));
				break;
			case 3:
				sort(get(name));
				break;	
			case 4:
				modify(get(name));
				break;	
			case 5:
				dele(get(name));
				break;
			case 6:
				limit();
				break;
			case 7:
				warehousing(get(name),name);
				break;
			case 8:	
				outbound(get(name),name);
				break;		
			case 9:
				query1(name);
				break;
			case 10:
				query2(name);
				break;	
			default:
				printf("�������!\n");
				break;	
		}
	}
	return 0;
} 

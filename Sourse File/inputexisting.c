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
	char name[N][20];//记录仓库文件路径 
	setup(name);
	while(1)
	{
		printf("目录：\n");
		printf("0 : 退出程序\n1 : 库存录入\n2 : 库存查询\n3 : 库存排序\n4 : 库存修改\n5 : 批量删除\n6 : 设置高低储\n7 : 入库操作\n8 : 出库操作\n9 : 入库单查询\n10 : 出库单查询\n");
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
				printf("输入错误!\n");
				break;	
		}
	}
	return 0;
} 

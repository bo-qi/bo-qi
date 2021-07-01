void query(char *name)
{
	int i=0,n,min,max,m,j,number;
	existing p[200];
	lim q[200];
	char material[20];
	char d[2][15];
	float sum;
	FILE *fp;
	FILE *fp1;
	fp=fopen(name,"r");
	if(fp==NULL)
	{
		printf("仓库打开失败\n");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&p[i],sizeof(existing),1,fp);
		i++;
	}
	n=i-1;
	while(1)
	{
		printf("输入0返回主菜单\n按物料号查询输入1\n按入库日期查询输入2\n显示该库全部信息输入3\n查询库存金额输入4\n按数量查询输入5\n混合查询输入6\n高低储排查输入7\n");
		scanf("%d",&i);
		if(i==1)
		{
			printf("请输入要查询物品的物料号或物料描述:");
			fflush(stdin);
			gets(material);
			printf("库存数\t 物料号\t   物料描述\t      型号规格\t  入库日期\t    单价\n");
			for(i=0;i<n;i++)
			{
				if(strcmp(material,p[i].name)==0 || strcmp(material,p[i].chinese)==0)
				{
					printf("%-9d%-10s%-19s%-12s%-18s%.2f\n",p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,p[i].price);
				}
			}	
		}else if(i==2)
		{
			printf("请输入起始日期:");	
			fflush(stdin);
			scanf("%s",d[0]);
			printf("请输入终止日期:");
			fflush(stdin);
			scanf("%s",d[1]);
			printf("库存数\t 物料号\t   物料描述\t      型号规格\t  入库日期\t    单价\n");
			for(i=0;i<n;i++)
			{
				if(strcmp(p[i].day,d[0])>=0 && strcmp(p[i].day,d[1])<=0)
					printf("%-9d%-10s%-19s%-12s%-18s%.2f\n",p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,p[i].price);
			}
		}else if(i==3)
		{
			printf("库存数\t 物料号\t   物料描述\t      型号规格\t  入库日期\t    单价\n");
			for(i=0;i<n;i++)
			{
				printf("%-9d%-10s%-19s%-12s%-18s%.2f\n",p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,p[i].price);
			}
		}else if(i==0)
		{
			fclose(fp);
			return;
		}else if(i==4)
		{
			sum=0;
			printf("按物料号查询输入1,按入库时间查询输入2\n");
			scanf("%d",&i);
			if(i==1)
			{
				printf("请输入要查询物品的物料号或物料描述: ");
				fflush(stdin);
				scanf("%s",material);
				for(i=0;i<n;i++)
				{
					if(strcmp(material,p[i].name)==0 || strcmp(material,p[i].chinese)==0)
						sum+=p[i].price*p[i].number;
				}
				printf("%s的总金额为%.2f\n",material,sum);
			}else if(i==2)
			{
				printf("请输入起始日期:");	
				fflush(stdin);
				scanf("%s",d[0]);
				printf("请输入终止日期:");
				fflush(stdin);
				scanf("%s",d[1]);
				for(i=0;i<n;i++)
				{
					if(strcmp(p[i].day,d[0])>=0 && strcmp(p[i].day,d[1])<=0)
						sum+=p[i].price*p[i].number;
				}
				printf("%s的总金额为%.2f\n",material,sum);
			}
		}else if(i==5)
		{
			printf("请输入最小数量:");
			scanf("%d",&min);
			printf("请输入最大数量:");
			scanf("%d",&max);
			printf("库存数\t 物料号\t   物料描述\t      型号规格\t  入库日期\t    单价\n");
			for(i=0;i<n;i++)
			{
				if(p[i].number>=min && p[i].number<=max)
					printf("%-9d%-10s%-19s%-12s%-18s%.2f\n",p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,p[i].price);
			}
		}else if(i==6)
		{
			printf("输入\"12\",\"15\",\"25\"\"125\"来选择相应的混合查询功能 : ");
			scanf("%d",&i);
			if(i==12)
			{
				printf("请输入要查询物品的物料号或物料描述:");
				fflush(stdin);
				gets(material);
				printf("请输入起始日期:");	
				fflush(stdin);
				scanf("%s",d[0]);
				printf("请输入终止日期:");
				fflush(stdin);
				scanf("%s",d[1]);
				printf("库存数\t 物料号\t   物料描述\t      型号规格\t  入库日期\t    单价\n");
				for(i=0;i<n;i++)
				{
					if((strcmp(material,p[i].name)==0 || strcmp(material,p[i].chinese)==0) && strcmp(p[i].day,d[0])>=0 && strcmp(p[i].day,d[1])<=0)
						printf("%-9d%-10s%-19s%-12s%-18s%.2f\n",p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,p[i].price);
				}
			}else if(i==15)
			{
				printf("请输入要查询物品的物料号或物料描述:");
				fflush(stdin);
				gets(material);
				printf("请输入最小数量:");
				scanf("%d",&min);
				printf("请输入最大数量:");
				scanf("%d",&max);
				printf("库存数\t 物料号\t   物料描述\t      型号规格\t  入库日期\t    单价\n");
				for(i=0;i<n;i++)
				{
					if((strcmp(material,p[i].name)==0 || strcmp(material,p[i].chinese)==0) && p[i].number>=min && p[i].number<=max)
						printf("%-9d%-10s%-19s%-12s%-18s%.2f\n",p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,p[i].price);
				}
			}else if(i==25)
			{
				printf("请输入起始日期:");	
				fflush(stdin);
				scanf("%s",d[0]);
				printf("请输入终止日期:");
				fflush(stdin);
				scanf("%s",d[1]);
				printf("请输入最小数量:");
				scanf("%d",&min);
				printf("请输入最大数量:");
				scanf("%d",&max);
				printf("库存数\t 物料号\t   物料描述\t      型号规格\t  入库日期\t    单价\n");
				for(i=0;i<n;i++)
				{
					if(strcmp(p[i].day,d[0])>=0 && strcmp(p[i].day,d[1])<=0 && p[i].number>=min && p[i].number<=max)
						printf("%-9d%-10s%-19s%-12s%-18s%.2f\n",p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,p[i].price);
				}
			}else if(i==125)
			{
				printf("请输入要查询物品的物料号或物料描述:");
				fflush(stdin);
				gets(material);
				printf("请输入起始日期:");	
				fflush(stdin);
				scanf("%s",d[0]);
				printf("请输入终止日期:");
				fflush(stdin);
				scanf("%s",d[1]);
				printf("请输入最小数量:");
				scanf("%d",&min);
				printf("请输入最大数量:");
				scanf("%d",&max);
				printf("库存数\t 物料号\t   物料描述\t      型号规格\t  入库日期\t    单价\n");
				for(i=0;i<n;i++)
				{
					if((strcmp(material,p[i].name)==0 || strcmp(material,p[i].chinese)==0) && strcmp(p[i].day,d[0])>=0 && strcmp(p[i].day,d[1])<=0 && p[i].number>=min && p[i].number<=max)
						printf("%-9d%-10s%-19s%-12s%-18s%.2f\n",p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,p[i].price);
				}
			}else 
				printf("不支持该类查询!\n");
		}else if(i==7)
		{
			i=0;
			fp1=fopen("c:\\limit.txt","r");
			while(!feof(fp1))
			{
				fread(&q[i++],sizeof(lim),1,fp1);
			}
			m=i-1;
			printf("库存数\t 物料号\t   物料描述\t      型号规格\t  入库日期\t    单价\n");
			for(j=0;j<m;j++)
			{
				number=0;
				for(i=0;i<n;i++)
				{
					if(strcmp(p[i].name,q[j].name)==0)
						number+=p[i].number;
				}
				if(number<=q[j].min || number>=q[j].max)
				{
					
					for(i=0;i<n;i++)
					{
						if(strcmp(p[i].name,q[j].name)==0)
							printf("%-9d%-10s%-19s%-12s%-18s%.2f\n",p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,p[i].price);
					}
				}	
			}	
			fclose(fp1);
		}	
		printf("输入0返回主菜单,若继续查询输入1\n");
		scanf("%d",&i);
		if(i==1)
			rewind(fp);
		else 
		{
			fclose(fp);
			break;
		}		
	}
}

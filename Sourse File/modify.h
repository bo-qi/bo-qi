void modify(char *name)
{
	char q[20],w[20];
	int k,i,j,n;
	existing p[200];
	FILE *fp;
	while(1)
	{
		k=0;i=0;
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
		printf("输入0返回主菜单,若修改数据输入1，若逐条删除数据输入2 : \n");
		scanf("%d",&i);
		if(i==0)
		{
			fclose(fp);
			return;
		}	
		else if(i==1)
		{
			printf("请输入想要修改物品的物料号或物料描述: ");
			fflush(stdin);
			gets(q);
			printf("请输入入库时间: ");
			fflush(stdin);
			gets(w);
			for(i=0;i<n;i++)
			{
				if((strcmp(q,p[i].name)==0 || strcmp(q,p[i].chinese)==0) && strcmp(w,p[i].day)==0)
				{
					k=1;
					printf("请依次输入一个新的库存数量,物料号,物料描述,型号,入库日期,单价,中间使用空格分隔\n");
					fflush(stdin);
					scanf("%d%s%s%s%s%f",&p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,&p[i].price);
				}
			}
			if(k==0)
				printf("未查询到该物品\n");
			else	
				printf("修改完成\n"); 
		}else if(i==2)
		{
			printf("请输入想要删除的物品的物料号或物料描述:");
			fflush(stdin);
			gets(q);
			printf("请输入入库时间: ");
			fflush(stdin);
			gets(w);
			for(i=0;i<n;i++)
			{
				if((strcmp(q,p[i].name)==0 || strcmp(q,p[i].chinese)==0) && strcmp(w,p[i].day)==0)
				{
					k=1;
					for(j=i;j<n-1;j++)
					{
						p[j]=p[j+1];
					}
					n--;
					break;
				}
			}
			if(k==0)
				printf("未查询到该物品\n");
			else
				printf("删除完成\n");	
		}
		fclose(fp);
		fp=fopen(name,"w");
		fwrite(p,sizeof(existing),n,fp); 
		fclose(fp);
	}	
}
void dele(char *name)
{
	int m,sum,i,n,j,k;
	char d[2][15];
	existing p[200];
	FILE *fp;
	sum=0;
	while(1)
	{
		k=0;i=0;
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
    	printf("请输入起始日期:");	
		fflush(stdin);
		scanf("%s",d[0]);
		printf("请输入终止日期:");
		fflush(stdin);
		scanf("%s",d[1]);
		for(i=0;i<n;i++)
		{
			if(strcmp(p[i].day,d[0])>=0 && strcmp(p[i].day,d[1])<=0)
				sum++;
		}
		for(m=0;m<sum;m++)
		{
			for(i=0;i<n;i++)
			{
				if(strcmp(p[i].day,d[0])>=0 && strcmp(p[i].day,d[1])<=0)
				{
					k=1;
					for(j=i;j<n-1;j++)
					{
						p[j]=p[j+1];
					}
					n--;
					break;
				}
			}
		}
		if(k==0)
			printf("未查询到该物品\n");
		else
			printf("删除完成\n");
		fclose(fp);
		fp=fopen(name,"w");
		fwrite(p,sizeof(existing),n,fp); 
		fclose(fp);			
		printf("输入0返回主菜单，输入1继续删除\n");
		scanf("%d",&i);
		if(i==0)
			return;
	}
}

void outbound(char *name,char name1[][20])
{
	int n,i=0,j,m,k,number;
	char d[2][50];
	existing p[200];
	out o[200];
	FILE *fp,*fp1;
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
	fclose(fp);
	printf("请输入出库外部单号1~10 : ");
	scanf("%d",&i);
	fp1=fopen(name1[i+14],"w");
	i=0;
	printf("请依次输入出库物品的预出数量,物料号,物料描述,型号,单价,中间使用空格分隔\n");
	printf("输入0可结束录入\n"); 
	fflush(stdin);
	while(1)
	{
		scanf("%d",&o[i].number);
		if(o[i].number==0)
			break;
		scanf("%s%s%s%f",o[i].name,o[i].chinese,o[i].specifications,&o[i].price);
		i++;
	}
	m=i;
	printf("请输入出库日期和领料人\n");
	printf("出库日期 : ");
	fflush(stdin);
	gets(o[i].name);
	printf("领料人 : ");
	fflush(stdin);
	gets(o[i].chinese);
	for(j=0;j<m;j++)
	{
		number=o[j].number;
		for(i=0;i<n;i++)
		{
			if(strcmp(p[i].name,o[j].name)==0)
			{
				if(p[i].number>number)
				{
					p[i].number-=number;
					number=0; 
					break;
				}else if(p[i].number<=number)
				{
					number-=p[i].number;
					for(k=i;k<n-1;k++)
						p[k]=p[k+1];
					n--;
				}
			}
		}
		o[j].realnumber=o[j].number-number;
		if(number!=0)
			printf("物料号为%s的%s数量不足,应出%d,实出%d\n",o[j].name,o[j].chinese,o[j].number,o[j].realnumber);
	}
	fwrite(o,sizeof(out),m+1,fp1);
	fclose(fp1);
	fp=fopen(name,"w");
	fwrite(p,sizeof(existing),n,fp);
	fclose(fp);
	printf("操作完成");
}
void query2(char name1[][20])
{
	{
	int i,n;
	FILE *fp;
	out p[200];
	while(1)
	{
		printf("请输入出库外部单号1~10 : ");
		scanf("%d",&i);
		fp=fopen(name1[i+14],"r");
		i=0;
		while(!feof(fp))
		{
			fread(&p[i],sizeof(out),1,fp);
			i++;
		}
		n=i-1;
		printf("应出\t 实出\t 物料号\t   物料描述\t      型号规格\t    单价\n");
		for(i=0;i<n-1;i++)
			printf("%-9d%-8d%-10s%-19s%-14s%.2f\n",p[i].number,p[i].realnumber,p[i].name,p[i].chinese,p[i].specifications,p[i].price);
		printf("出库日期:%s\n领料人:%s\n",p[i].name,p[i].chinese);	
		printf("输入0返回主菜单,输入1继续查询 : ");
		scanf("%d",&i);
		if(i==0)
		{
			fclose(fp);
			return;
		}		
	}	
}
}

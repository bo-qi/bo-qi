void sort(char *name)
{
	int i=0,n,j,k;
	existing q;
	existing p[200];
	FILE *fp;
	fp=fopen(name,"r+");
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
	printf("输入0返回主菜单\n按物料号排序输入1\n按入库日期排序输入2\n按价格排序输入3\n");
	scanf("%d",&i);
	if(i==0)
	{
		return ;
		fclose(fp);
	}	
	else if(i==1)
	{
		for(i=0;i<n-1;i++)//简单选择排序 
		{
			k=i;
			for(j=i;j<n;j++)
			{
				if(strcmp(p[i].name,p[j].name)>0)
					k=j;
			}
			if(i!=k)
			{
				q=p[i];p[i]=p[k];p[k]=q;
			}
		}
	}else if(i==2)
	{
		for(i=0;i<n-1;i++)//简单选择排序 
		{
			k=i;
			for(j=i;j<n;j++)
			{
				if(strcmp(p[i].day,p[j].day)>0)
					k=j;
			}
			if(i!=k)
			{
				q=p[i];p[i]=p[k];p[k]=q;
			}
		}
	}else if(i==3)
	{
		for(i=0;i<n-1;i++)
		{
			k=i;
			for(j=i;j<n;j++)
			{
				if(p[i].price>p[j].price)
					k=j;
			}
			if(k!=i)
				{
					q=p[i];p[i]=p[k];p[k]=q;
				}	
		}
	}else
	{
		printf("错误输入！");exit(0);
	}	
	rewind(fp);
	fwrite(p,sizeof(existing),n,fp); 
	fclose(fp);
	printf("排序完成\n");	
}

void sort(char *name)
{
	int i=0,n,j,k;
	existing q;
	existing p[200];
	FILE *fp;
	fp=fopen(name,"r+");
	if(fp==NULL)
	{
		printf("�ֿ��ʧ��\n");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&p[i],sizeof(existing),1,fp);
		i++;
	}
	n=i-1;
	printf("����0�������˵�\n�����Ϻ���������1\n�����������������2\n���۸���������3\n");
	scanf("%d",&i);
	if(i==0)
	{
		return ;
		fclose(fp);
	}	
	else if(i==1)
	{
		for(i=0;i<n-1;i++)//��ѡ������ 
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
		for(i=0;i<n-1;i++)//��ѡ������ 
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
		printf("�������룡");exit(0);
	}	
	rewind(fp);
	fwrite(p,sizeof(existing),n,fp); 
	fclose(fp);
	printf("�������\n");	
}

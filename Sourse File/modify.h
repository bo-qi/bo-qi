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
			printf("�ֿ��ʧ��\n");
			exit(0);
		}
		while(!feof(fp))
		{
			fread(&p[i],sizeof(existing),1,fp);
			i++;
		}
		n=i-1;
		printf("����0�������˵�,���޸���������1��������ɾ����������2 : \n");
		scanf("%d",&i);
		if(i==0)
		{
			fclose(fp);
			return;
		}	
		else if(i==1)
		{
			printf("��������Ҫ�޸���Ʒ�����ϺŻ���������: ");
			fflush(stdin);
			gets(q);
			printf("���������ʱ��: ");
			fflush(stdin);
			gets(w);
			for(i=0;i<n;i++)
			{
				if((strcmp(q,p[i].name)==0 || strcmp(q,p[i].chinese)==0) && strcmp(w,p[i].day)==0)
				{
					k=1;
					printf("����������һ���µĿ������,���Ϻ�,��������,�ͺ�,�������,����,�м�ʹ�ÿո�ָ�\n");
					fflush(stdin);
					scanf("%d%s%s%s%s%f",&p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,&p[i].price);
				}
			}
			if(k==0)
				printf("δ��ѯ������Ʒ\n");
			else	
				printf("�޸����\n"); 
		}else if(i==2)
		{
			printf("��������Ҫɾ������Ʒ�����ϺŻ���������:");
			fflush(stdin);
			gets(q);
			printf("���������ʱ��: ");
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
				printf("δ��ѯ������Ʒ\n");
			else
				printf("ɾ�����\n");	
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
			printf("�ֿ��ʧ��\n");
			exit(0);
		}
		while(!feof(fp))
		{
			fread(&p[i],sizeof(existing),1,fp);
			i++;
		}
		n=i-1;
    	printf("��������ʼ����:");	
		fflush(stdin);
		scanf("%s",d[0]);
		printf("��������ֹ����:");
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
			printf("δ��ѯ������Ʒ\n");
		else
			printf("ɾ�����\n");
		fclose(fp);
		fp=fopen(name,"w");
		fwrite(p,sizeof(existing),n,fp); 
		fclose(fp);			
		printf("����0�������˵�������1����ɾ��\n");
		scanf("%d",&i);
		if(i==0)
			return;
	}
}

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
		printf("�ֿ��ʧ��\n");
		exit(0);
	}
	while(!feof(fp))
	{
		fread(&p[i],sizeof(existing),1,fp);
		i++;
	}
	n=i-1;
	fclose(fp);
	printf("����������ⲿ����1~10 : ");
	scanf("%d",&i);
	fp1=fopen(name1[i+14],"w");
	i=0;
	printf("���������������Ʒ��Ԥ������,���Ϻ�,��������,�ͺ�,����,�м�ʹ�ÿո�ָ�\n");
	printf("����0�ɽ���¼��\n"); 
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
	printf("������������ں�������\n");
	printf("�������� : ");
	fflush(stdin);
	gets(o[i].name);
	printf("������ : ");
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
			printf("���Ϻ�Ϊ%s��%s��������,Ӧ��%d,ʵ��%d\n",o[j].name,o[j].chinese,o[j].number,o[j].realnumber);
	}
	fwrite(o,sizeof(out),m+1,fp1);
	fclose(fp1);
	fp=fopen(name,"w");
	fwrite(p,sizeof(existing),n,fp);
	fclose(fp);
	printf("�������");
}
void query2(char name1[][20])
{
	{
	int i,n;
	FILE *fp;
	out p[200];
	while(1)
	{
		printf("����������ⲿ����1~10 : ");
		scanf("%d",&i);
		fp=fopen(name1[i+14],"r");
		i=0;
		while(!feof(fp))
		{
			fread(&p[i],sizeof(out),1,fp);
			i++;
		}
		n=i-1;
		printf("Ӧ��\t ʵ��\t ���Ϻ�\t   ��������\t      �ͺŹ��\t    ����\n");
		for(i=0;i<n-1;i++)
			printf("%-9d%-8d%-10s%-19s%-14s%.2f\n",p[i].number,p[i].realnumber,p[i].name,p[i].chinese,p[i].specifications,p[i].price);
		printf("��������:%s\n������:%s\n",p[i].name,p[i].chinese);	
		printf("����0�������˵�,����1������ѯ : ");
		scanf("%d",&i);
		if(i==0)
		{
			fclose(fp);
			return;
		}		
	}	
}
}

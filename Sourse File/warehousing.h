void warehousing(char *name,char name1[][20])
{
	int n,i=0,j;
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
	fp1=fopen(name1[i+4],"w");
	i=0;
	printf("���������������Ʒ������,���Ϻ�,��������,�ͺ�,����,�м�ʹ�ÿո�ָ�\n");
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
	printf("������������ں����볧��\n");
	printf("������� : ");
	fflush(stdin);
	gets(o[i].name);
	printf("���볧�� : ");
	fflush(stdin);
	gets(o[i].chinese);
	fwrite(o,sizeof(out),i+1,fp1);
	fclose(fp1);
	fp=fopen(name,"a");
	for(j=0;j<i;j++,n++)
	{
		strcpy(p[n].name,o[j].name);strcpy(p[n].chinese,o[j].chinese);strcpy(p[n].specifications,o[j].specifications);strcpy(p[n].day,o[i].name);
		p[n].price=o[j].price;p[n].number=o[j].number;
		fwrite(&p[n],sizeof(existing),1,fp);
	}
	fclose(fp);	
	printf("�������!");
}
void query1(char name1[][20])
{
	int i,n;
	FILE *fp;
	out p[200];
	while(1)
	{
		printf("����������ⲿ����1~10 : ");
		scanf("%d",&i);
		fp=fopen(name1[i+4],"r");
		i=0;
		while(!feof(fp))
		{
			fread(&p[i],sizeof(out),1,fp);
			i++;
		}
		n=i-1;
		printf("�����\t ���Ϻ�\t   ��������\t      �ͺŹ��\t    ����\n");
		for(i=0;i<n-1;i++)
			printf("%-9d%-10s%-19s%-14s%.2f\n",p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].price);
		printf("�������:%s\n���볧��:%s\n",p[i].name,p[i].chinese);	
		printf("����0�������˵�,����1������ѯ : ");
		scanf("%d",&i);
		if(i==0)
		{
			fclose(fp);
			return;
		}		
	}	
}

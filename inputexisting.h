void Inputexisting(char *name)//�ֿ�¼�� 
{
	existing p[200];
	unsigned int n=0,i=0;
	FILE *fp;
	fp=fopen(name,"a+");
	if(fp==NULL)
	{
		printf("�ֿ��ʧ��\n");
		exit(0);
	}
	printf("����������������,���Ϻ�,��������,�ͺ�,�������,����,�м�ʹ�ÿո�ָ�\n");
	printf("����0�ɽ���¼��\n"); 
	while(1)
	{
		scanf("%d",&p[n].number);
		if(p[n].number==0)
			break;
		scanf("%s%s%s%s%f",p[n].name,p[n].chinese,p[n].specifications,p[n].day,&p[n].price);
		n++;	
	}
	fwrite(p,sizeof(existing),n,fp);
	printf("����0�������˵�,����1����ʾ��ǰ¼����\n");
	scanf("%d",&n);
	if(n==1)
	{
		i=0;
		rewind(fp);
		while(!feof(fp))
		{
			fread(&p[i],sizeof(existing),1,fp);
			i++;
		}
		printf("�����\t ���Ϻ�\t   ��������\t      �ͺŹ��\t  �������\t    ����\n");
		for(n=0;n<i-1;n++)
		{
			printf("%-9d%-10s%-19s%-12s%-18s%.2f\n",p[n].number,p[n].name,p[n].chinese,p[n].specifications,p[n].day,p[n].price);
			fclose(fp);
		}
	}else if(n==0)
	{
		fclose(fp);
	}	
}

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
		printf("�ֿ��ʧ��\n");
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
		printf("����0�������˵�\n�����ϺŲ�ѯ����1\n��������ڲ�ѯ����2\n��ʾ�ÿ�ȫ����Ϣ����3\n��ѯ���������4\n��������ѯ����5\n��ϲ�ѯ����6\n�ߵʹ��Ų�����7\n");
		scanf("%d",&i);
		if(i==1)
		{
			printf("������Ҫ��ѯ��Ʒ�����ϺŻ���������:");
			fflush(stdin);
			gets(material);
			printf("�����\t ���Ϻ�\t   ��������\t      �ͺŹ��\t  �������\t    ����\n");
			for(i=0;i<n;i++)
			{
				if(strcmp(material,p[i].name)==0 || strcmp(material,p[i].chinese)==0)
				{
					printf("%-9d%-10s%-19s%-12s%-18s%.2f\n",p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,p[i].price);
				}
			}	
		}else if(i==2)
		{
			printf("��������ʼ����:");	
			fflush(stdin);
			scanf("%s",d[0]);
			printf("��������ֹ����:");
			fflush(stdin);
			scanf("%s",d[1]);
			printf("�����\t ���Ϻ�\t   ��������\t      �ͺŹ��\t  �������\t    ����\n");
			for(i=0;i<n;i++)
			{
				if(strcmp(p[i].day,d[0])>=0 && strcmp(p[i].day,d[1])<=0)
					printf("%-9d%-10s%-19s%-12s%-18s%.2f\n",p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,p[i].price);
			}
		}else if(i==3)
		{
			printf("�����\t ���Ϻ�\t   ��������\t      �ͺŹ��\t  �������\t    ����\n");
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
			printf("�����ϺŲ�ѯ����1,�����ʱ���ѯ����2\n");
			scanf("%d",&i);
			if(i==1)
			{
				printf("������Ҫ��ѯ��Ʒ�����ϺŻ���������: ");
				fflush(stdin);
				scanf("%s",material);
				for(i=0;i<n;i++)
				{
					if(strcmp(material,p[i].name)==0 || strcmp(material,p[i].chinese)==0)
						sum+=p[i].price*p[i].number;
				}
				printf("%s���ܽ��Ϊ%.2f\n",material,sum);
			}else if(i==2)
			{
				printf("��������ʼ����:");	
				fflush(stdin);
				scanf("%s",d[0]);
				printf("��������ֹ����:");
				fflush(stdin);
				scanf("%s",d[1]);
				for(i=0;i<n;i++)
				{
					if(strcmp(p[i].day,d[0])>=0 && strcmp(p[i].day,d[1])<=0)
						sum+=p[i].price*p[i].number;
				}
				printf("%s���ܽ��Ϊ%.2f\n",material,sum);
			}
		}else if(i==5)
		{
			printf("��������С����:");
			scanf("%d",&min);
			printf("�������������:");
			scanf("%d",&max);
			printf("�����\t ���Ϻ�\t   ��������\t      �ͺŹ��\t  �������\t    ����\n");
			for(i=0;i<n;i++)
			{
				if(p[i].number>=min && p[i].number<=max)
					printf("%-9d%-10s%-19s%-12s%-18s%.2f\n",p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,p[i].price);
			}
		}else if(i==6)
		{
			printf("����\"12\",\"15\",\"25\"\"125\"��ѡ����Ӧ�Ļ�ϲ�ѯ���� : ");
			scanf("%d",&i);
			if(i==12)
			{
				printf("������Ҫ��ѯ��Ʒ�����ϺŻ���������:");
				fflush(stdin);
				gets(material);
				printf("��������ʼ����:");	
				fflush(stdin);
				scanf("%s",d[0]);
				printf("��������ֹ����:");
				fflush(stdin);
				scanf("%s",d[1]);
				printf("�����\t ���Ϻ�\t   ��������\t      �ͺŹ��\t  �������\t    ����\n");
				for(i=0;i<n;i++)
				{
					if((strcmp(material,p[i].name)==0 || strcmp(material,p[i].chinese)==0) && strcmp(p[i].day,d[0])>=0 && strcmp(p[i].day,d[1])<=0)
						printf("%-9d%-10s%-19s%-12s%-18s%.2f\n",p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,p[i].price);
				}
			}else if(i==15)
			{
				printf("������Ҫ��ѯ��Ʒ�����ϺŻ���������:");
				fflush(stdin);
				gets(material);
				printf("��������С����:");
				scanf("%d",&min);
				printf("�������������:");
				scanf("%d",&max);
				printf("�����\t ���Ϻ�\t   ��������\t      �ͺŹ��\t  �������\t    ����\n");
				for(i=0;i<n;i++)
				{
					if((strcmp(material,p[i].name)==0 || strcmp(material,p[i].chinese)==0) && p[i].number>=min && p[i].number<=max)
						printf("%-9d%-10s%-19s%-12s%-18s%.2f\n",p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,p[i].price);
				}
			}else if(i==25)
			{
				printf("��������ʼ����:");	
				fflush(stdin);
				scanf("%s",d[0]);
				printf("��������ֹ����:");
				fflush(stdin);
				scanf("%s",d[1]);
				printf("��������С����:");
				scanf("%d",&min);
				printf("�������������:");
				scanf("%d",&max);
				printf("�����\t ���Ϻ�\t   ��������\t      �ͺŹ��\t  �������\t    ����\n");
				for(i=0;i<n;i++)
				{
					if(strcmp(p[i].day,d[0])>=0 && strcmp(p[i].day,d[1])<=0 && p[i].number>=min && p[i].number<=max)
						printf("%-9d%-10s%-19s%-12s%-18s%.2f\n",p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,p[i].price);
				}
			}else if(i==125)
			{
				printf("������Ҫ��ѯ��Ʒ�����ϺŻ���������:");
				fflush(stdin);
				gets(material);
				printf("��������ʼ����:");	
				fflush(stdin);
				scanf("%s",d[0]);
				printf("��������ֹ����:");
				fflush(stdin);
				scanf("%s",d[1]);
				printf("��������С����:");
				scanf("%d",&min);
				printf("�������������:");
				scanf("%d",&max);
				printf("�����\t ���Ϻ�\t   ��������\t      �ͺŹ��\t  �������\t    ����\n");
				for(i=0;i<n;i++)
				{
					if((strcmp(material,p[i].name)==0 || strcmp(material,p[i].chinese)==0) && strcmp(p[i].day,d[0])>=0 && strcmp(p[i].day,d[1])<=0 && p[i].number>=min && p[i].number<=max)
						printf("%-9d%-10s%-19s%-12s%-18s%.2f\n",p[i].number,p[i].name,p[i].chinese,p[i].specifications,p[i].day,p[i].price);
				}
			}else 
				printf("��֧�ָ����ѯ!\n");
		}else if(i==7)
		{
			i=0;
			fp1=fopen("c:\\limit.txt","r");
			while(!feof(fp1))
			{
				fread(&q[i++],sizeof(lim),1,fp1);
			}
			m=i-1;
			printf("�����\t ���Ϻ�\t   ��������\t      �ͺŹ��\t  �������\t    ����\n");
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
		printf("����0�������˵�,��������ѯ����1\n");
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

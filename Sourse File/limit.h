void limit()
{
	int n=0;
	FILE *fp;
	lim p[200];
	fp=fopen("c:\\limit.txt","w");
	printf("������������Ʒ����ʹ�������,��ߴ�������,���Ϻ�,�м�ʹ�ÿո�ָ�\n����0�Խ�������\n");
	fflush(stdin);
	while(1)
	{
		scanf("%d",&p[n].min);
		if(p[n].min==0)
			break;	
		scanf("%d%s",&p[n].max,p[n].name);
		n++;	
	}
	fwrite(p,sizeof(lim),n,fp);
	fclose(fp);
	printf("���óɹ�!\n");
}

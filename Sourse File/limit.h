void limit()
{
	int n=0;
	FILE *fp;
	lim p[200];
	fp=fopen("c:\\limit.txt","w");
	printf("请依次输入物品的最低储存数量,最高储存数量,物料号,中间使用空格分隔\n输入0以结束输入\n");
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
	printf("设置成功!\n");
}

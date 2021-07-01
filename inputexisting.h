void Inputexisting(char *name)//仓库录入 
{
	existing p[200];
	unsigned int n=0,i=0;
	FILE *fp;
	fp=fopen(name,"a+");
	if(fp==NULL)
	{
		printf("仓库打开失败\n");
		exit(0);
	}
	printf("请依次输入库存数量,物料号,物料描述,型号,入库日期,单价,中间使用空格分隔\n");
	printf("输入0可结束录入\n"); 
	while(1)
	{
		scanf("%d",&p[n].number);
		if(p[n].number==0)
			break;
		scanf("%s%s%s%s%f",p[n].name,p[n].chinese,p[n].specifications,p[n].day,&p[n].price);
		n++;	
	}
	fwrite(p,sizeof(existing),n,fp);
	printf("输入0返回主菜单,输入1可显示当前录入结果\n");
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
		printf("库存数\t 物料号\t   物料描述\t      型号规格\t  入库日期\t    单价\n");
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

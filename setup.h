void setup(char p[][20])
{
	strcpy(p[0],"c:\\1warehouse.txt");
	strcpy(p[1],"c:\\2warehouse.txt");
	strcpy(p[2],"c:\\3warehouse.txt");
	strcpy(p[3],"c:\\4warehouse.txt");
	strcpy(p[4],"c:\\5warehouse.txt");
	strcpy(p[15],"c:\\1delivery.txt");
	strcpy(p[16],"c:\\2delivery.txt");
	strcpy(p[17],"c:\\3delivery.txt");
	strcpy(p[18],"c:\\4delivery.txt");
	strcpy(p[19],"c:\\5delivery.txt");
	strcpy(p[20],"c:\\6delivery.txt");
	strcpy(p[21],"c:\\7delivery.txt");
	strcpy(p[22],"c:\\8delivery.txt");
	strcpy(p[23],"c:\\9delivery.txt");
	strcpy(p[24],"c:\\10delivery.txt");
	strcpy(p[5],"c:\\1receipt.txt");
	strcpy(p[6],"c:\\2receipt.txt");
	strcpy(p[7],"c:\\3receipt.txt");
	strcpy(p[8],"c:\\4receipt.txt");
	strcpy(p[9],"c:\\5receipt.txt");
	strcpy(p[10],"c:\\6receipt.txt");
	strcpy(p[11],"c:\\7receipt.txt");
	strcpy(p[12],"c:\\8receipt.txt");
	strcpy(p[13],"c:\\9receipt.txt");
	strcpy(p[14],"c:\\10receipt.txt");
}
char *get(char p[][20])
{
	int i;
	printf("ÇëÊäÈëÒª²Ù×÷µÄ²Ö¿â±àºÅ1~5 : ");
	scanf("%d",&i);
	return (p[i-1]);
}

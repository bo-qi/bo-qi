typedef struct
{
	int number;//库存数 
	char name[20];//物料号 
	char chinese[50];//物料描述 
	char specifications[15];//型号规格 
	char day[15];//入库日期 
	float price;//单价
}existing; 
typedef struct
{
	int number;
	int realnumber;
	char name[20];
	char chinese[50];
	char specifications[15];
	float price;
}out;
typedef struct
{
	char name[20];
	int min;//低储 
	int max;//高储 
}lim;

typedef struct
{
	int number;//����� 
	char name[20];//���Ϻ� 
	char chinese[50];//�������� 
	char specifications[15];//�ͺŹ�� 
	char day[15];//������� 
	float price;//����
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
	int min;//�ʹ� 
	int max;//�ߴ� 
}lim;

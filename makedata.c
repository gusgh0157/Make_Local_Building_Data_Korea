#define SOCKET int
#include <stdlib.h>
#include <mysql.h>
#include <time.h>
#include <stdio.h>
#define HOST "customer-management.clmkxspmievh.ap-northeast-2.rds.amazonaws.com"
#define USER "lab401"
#define PASS "00000000"
#define NAME "test"



int main() {
	MYSQL *mysql_conn;
	char tempname[6];
	char query[250] = "INSERT INTO bld_info (bld_id, bld_addr, bld_tel, bld_info, bill_type) VALUES(%s, %s, %s, %s, %s)";
	char bld_id[10];
	char bld_addr[60];
	char bld_tel[100];
	char bld_info[50];
	char bill_type;
	char location[][5] = { "����","��õ","���", "����", "���","�泲","����", "���","�泲","�뱸","���","�λ�","����","����","����","����" };
	char company[][3] = { "KT","SK","LG" };
	int i = 0;

	bld_tel[0] = 0;
	bld_tel[1] = 1;
	bld_tel[2] = 0;
	bld_tel[3] = '-';
	bld_tel[8] = '-';
	bld_tel[13] = NULL;

	srand((unsigned)time(0));

	mysql_conn = mysql_real_connect(mysql_conn, HOST, USER, PASS, NAME, 3306, (char*)NULL, 0);
	
	if (mysql_conn) {
		printf("connect success\n");
	}
	else {
		printf("connect failed\n");
	}

	//��ȭ��ȣ ����
	for (i = 4; i < 13; i++) {
		if (i != 8) {
			bld_tel[i] = rand() % 10;
		}
	}

	//�ּ� ����
	*bld_addr = location[0][rand() % 16];

	//���� ���� ����
	*bld_info = company[0][rand() % 3];

	//���� Ÿ�� ����
	bill_type = rand() % 4;

	//���� ����
	mysql_query(mysql_conn, query, bld_id, bld_addr, bld_tel, bld_info, bill_type);
	printf("INSERT INTO bld_info (bld_id, bld_addr, bld_tel, bld_info, bill_type) VALUES(%s, %s, %s, %s, %s)\n", bld_id, bld_addr, bld_tel, bld_info, bill_type);

	system("pause");
	return 0;
}
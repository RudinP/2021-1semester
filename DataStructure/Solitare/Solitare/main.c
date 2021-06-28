#include <stdio.h>
#include <stdlib.h>
#include<time.h> //������ ����
#include <windows.h> //�ܼ� ȭ�� ����� ��
#define NUM_SHAPE 2

//��=0, ��=1, ��=2, ��=3

//����ڰ� �Է��ϴ� ���� ������ ����
int input; 

//ī�带 ���� ����Ʈ��
typedef struct node_type* node_ptr;

struct node_type {

	int num; //A,2,3,4,5,6,7,8,9,10,J,Q,K
	int shape; //0, 1, 2, 3={ heart,space, clover, diamond}=2 sets
	int show; //0=hide, 1=show
	node_ptr llink, rlink;
};
node_ptr p[10];
node_ptr head;

//�տ� ��� �ִ� ī�带 ���� ���� ����ü
typedef struct hand_stack* hand_ptr;

struct hand_stack {
	int top;
	int shape[26];
	int num[26];
};
hand_ptr hand;

//ī�带 pop�ϱ� ���� �Լ�
void pop_handcard() {
	if (hand->top == -1)
	{
		return;
	}
	else
		hand->top--;
}

//ī�带 push�ϱ� ���� �Լ�. Ʈ���� ī�带 ���ּ� �� ������ ������ �� ����.
void push_handcard(int sh, int num) {
	hand->top++;
	hand->num[hand->top] = num;
	hand->shape[hand->top] = sh;
}

//ī�� �ʱ�ȭ �Լ�
void init_card() {
	srand(time(0));
	int markp[4][13];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
			markp[i][j] = j;

	//ī�� ��� 4���߿� 2�� ���� ����
	int sh1, sh2, sh, num;
	sh1 = rand() % 4;
	do { sh2 = rand() % 4; } while (sh1 == sh2);

	//FBT ���� �Ҵ�
	for (int i = 0; i < 10; i++)
		p[i] = malloc(sizeof(struct node_type));

	head = malloc(sizeof(struct node_type));
	head->llink=p[0];
	head->rlink = p[0];

	//FBT�� ī�� �Ҵ�
	for (int i = 0; i < 10; i++)
	{
		sh = (rand() % 2) ? sh1 : sh2;
		num = rand() % 13;
		if(markp[sh][num] != -1)
		{
			p[i]->num = markp[sh][num];
			markp[sh][num] = -1;
			p[i]->shape = sh;
		}
		else 
		{
			do { 
			sh = (rand() % 2) ? sh1 : sh2;
			num = rand() % 13;
			} while (markp[sh][num] == -1);

			p[i]->num = markp[sh][num];
			markp[sh][num] = -1;
			p[i]->shape = sh;
		}
	}
	//FBT show �ʱ� ����
	for (int i = 0; i <= 5; i++)
		p[i]->show = 0;
	for (int i = 6; i <= 9; i++)
		p[i]->show = 1;

	//hand �ʱ�ȭ
	hand = malloc(sizeof(struct hand_stack));
	hand->top = 15;//26-10=16
	//hand�� ī�� �Ҵ�
	for (int i = 0; i < 16; i++)
	{
		sh = (rand() % 2) ? sh1 : sh2;
		num = rand() % 13;
		if (markp[sh][num] != -1)
		{
			hand->num[i] = markp[sh][num];
			markp[sh][num] = -1;
			hand->shape[i] = sh;
		}
		else
		{
			do {
				sh = (rand() % 2) ? sh1 : sh2;
				num = rand() % 13;
			} while (markp[sh][num] == -1);

			hand->num[i] = markp[sh][num];
			markp[sh][num] = -1;
			hand->shape[i] = sh;
		}
	}

}

//ī�� ����� ǥ���ϱ� ���� �Լ�
char* define_shape(int i) {
	switch (i) {
	case 0:return "��";
	case 1:return "��";
	case 2:return "��";
	case 3:return "��";
	default: return "";
	}
}

//Ʈ���� �ִ� ī���� ���ڸ� ����ڷ� �ٲ� �� ���� �Լ�
char* number(node_ptr p)
{
	
	if (p->num >= 10||p->num==0)
	{
		switch (p->num)
		{
		case 0: {return "A"; }
		case 10: {return "J"; }
		case 11: {return "Q"; }
		case 12: {return "K"; }
		default: return "";
		}
	}
	return "";

}

//�ܼ�â�� ����� ��ǲ 0���� �ʱ�ȭ
void reset_board(){
	input = 0;
	system("cls");
}

//ī�尡 show �������� Ȯ���ϱ� ���� �Լ�
void check() {
	for (int i = 0; i <= 5; i++)
	{
		if (p[i]!=NULL)
		{
			if (p[i]->llink == NULL && p[i]->rlink == NULL)
				p[i]->show = 1;
		}
	}
}
//show_board���� ī�� Ʈ���� ����� �� ���� �Լ�
void showcard(node_ptr p,int i,int j)
{
	if (p)
	{
		if (p->show == 1)
		{
			switch (i) 
			{
				case 0: 
				{
					if(p->num >= 10||p->num==0)
						printf("		    %s%s\n", define_shape(p->shape),number(p));
					else if (p->num < 10 && p->num >= 1)
						printf("		    %s%d\n", define_shape(p->shape), p->num+1);
					break; 
				}
				case 1: 
				{	
					if (j == 1)
					{
						if (p->num >= 10||p->num==0)
							printf("		   %s%s ", define_shape(p->shape), number(p));
						else if (p->num < 10 && p->num >= 1)
							printf("		   %s%d ", define_shape(p->shape), p->num+1);
					}
					else {
						if (p->num >= 10 || p->num == 0)
							printf("%s%s \n", define_shape(p->shape), number(p));
						else if (p->num < 10 && p->num >= 1)
							printf("%s%d \n", define_shape(p->shape), p->num+1);
					}
					break; 
				}
				case 2: 
				{	if (j == 1) 
					{
						if (p->num >= 10 || p->num == 0)
							printf("		  %s%s ", define_shape(p->shape), number(p));
						else if (p->num < 10 && p->num >= 1)
							printf("		  %s%d ", define_shape(p->shape), p->num+1);
					}
					else if (j == 2)
					{
						if (p->num >= 10 || p->num == 0)
							printf("%s%s ", define_shape(p->shape), number(p));
						else if (p->num < 10 && p->num >= 1)
							printf("%s%d ", define_shape(p->shape), p->num+1);
					}
					else 
					{
						if (p->num >= 10 || p->num == 0)
							printf("%s%s \n", define_shape(p->shape), number(p));
						else if (p->num < 10 && p->num >= 1)
							printf("%s%d \n", define_shape(p->shape), p->num+1);
					}
					break; 
				}
				case 3: 
				{
					if (j == 1) 
					{
						if (p->num >= 10 || p->num == 0)
							printf("       %s%s ", define_shape(p->shape), number(p));
						else if (p->num < 10 && p->num >= 1)
							printf("       %s%d ", define_shape(p->shape), p->num+1);
					}
					else if (j == 4) 
					{
						if (p->num >= 10 || p->num == 0)
							printf("%s%s \n", define_shape(p->shape), number(p));
						else if (p->num < 10 && p->num >= 1)
							printf("%s%d \n", define_shape(p->shape), p->num+1);
					}	
					else
					{
						if (p->num >= 10 || p->num == 0)
							printf("%s%s ", define_shape(p->shape), number(p));
						else if (p->num < 10 && p->num >= 1)
							printf("%s%d ", define_shape(p->shape), p->num+1);
					}
					break;
				}
			}
		}
		else
		{
			switch (i)
			{
				case 0: {printf("		    ��\n");  break; }
				case 1:
				{
					if (j == 1)
						printf("		   �� ");
					else
						printf("�� \n");
					break;
				}
				case 2:
				{	if (j == 1)
					printf("		  �� ");
				else if (j == 2)
					printf("�� ");
				else
					printf("�� \n");
				break;
				}
				case 3:
				{
					if (j == 1)
						printf("		  �� ");
					else if (j == 4)
						printf("�� \n");
					else
						printf("�� ");
					break;
				}
			}
		}
	}
	else 
	{
		switch (i)
			{
			case 0: {printf("		      \n");  break; }
			case 1:
			{
				if (j == 1)
					printf("		      ");
				else
					printf("   \n");
				break;
			}
			case 2:
			{	if (j == 1)
				printf("		     ");
			else if (j == 2)
				printf("   ");
			else
				printf("   \n");
			break;
			}
			case 3:
			{
				if (j == 1)
					printf("	  ");
				else if (j == 4)
					printf("   \n");
				else
					printf("   ");
				break;
			}
		}
	}

}


//���� â ��� ���� �Լ�
void show_board() {
	check();
	printf("    0"); showcard(p[0], 0, 1);
	printf("   1 2"); showcard(p[1], 1, 1); showcard(p[2], 1, 2);
	printf("  3 4 5"); showcard(p[3], 2, 1); showcard(p[4], 2 , 2); showcard(p[5], 2, 3);
	printf(" 6 7 8 9"); showcard(p[6], 3, 1); showcard(p[7], 3, 2); showcard(p[8], 3, 3); showcard(p[9], 3, 4);
	printf("\nYou have (%d) cards.\n", (hand->top) + 1);
	printf("=======================================================\n");

	if (hand->top >= 10)
	{
		if (hand->num[hand->top] >= 10|| hand->num[hand->top]==0)
		{
			printf("%s", define_shape(hand->shape[hand->top]));
			switch (hand->num[hand->top]) 
			{
			case 0: {printf("%s ", "A"); break; }
			case 10: {printf("%s ", "J"); break; }
			case 11: {printf("%s ", "Q"); break; }
			case 12: {printf("%s ", "K"); break; }
			default: {break; }
			}
		}
		else if(hand->num[hand->top] < 10 && hand->num[hand->top]>=1)
		{
			printf("%s%d ", define_shape(hand->shape[hand->top]), hand->num[hand->top] + 1);
		}
		for (int i = 0; i <= 9; i++)
			printf("�� ");
	}
	else
	{
		if (hand->num[hand->top] >= 10 || hand->num[hand->top] == 0)
		{
			printf("%s", define_shape(hand->shape[hand->top]));
			switch (hand->num[hand->top])
			{
			case 0: {printf("%s ", "A"); break; }
			case 10: {printf("%s ", "J"); break; }
			case 11: {printf("%s ", "Q"); break; }
			case 12: {printf("%s ", "K"); break; }
			default: {break; }
			}
		}
		else if (hand->num[hand->top] < 10 && hand->num[hand->top] >= 1)
		{
			printf("%s%d ", define_shape(hand->shape[hand->top]), hand->num[hand->top] + 1);
		}
		
		for (int i = 0; i < hand->top; i++)
		{
			printf("�� ");
		}
	}
	printf("\nEnter a number[0..9] to remove (-1 = newcard):");
	printf("\n");
}

//ī�带 ���� �� �ִ� ������ �Ǵ��� Ȯ���ϴ� �Լ�
int valid(int a,int b) {
	if (a - b == 1 || a - b == -1 || (a == 0 && b == 12)|| (a == 12 && b == 0))
		return 1;
	else
		return 0;
}



//Ʈ������ ī�带 ���ִ� �Լ�
void remove_card(int i) {
	if (p[i])
	{
		if (p[i]->show == 1 && valid(hand->num[hand->top], p[i]->num))
		{
			push_handcard(p[i]->shape, p[i]->num);
			p[i] = NULL;
			switch (i)
			{
				case 0: {head= NULL; free(head); break; }
				case 1: {p[0]->llink = NULL; break; }
				case 2: {p[0]->rlink = NULL; break; }
				case 3: {p[1]->llink = NULL; break; }
				case 4: {p[1]->rlink = NULL; p[2]->llink = NULL; break; }
				case 5: {p[2]->rlink = NULL; break; }
				case 6: {p[3]->llink = NULL; break; }
				case 7: {p[3]->rlink = NULL; p[4]->llink = NULL; break; }
				case 8: {p[4]->rlink = NULL; p[5]->llink = NULL; break; }
				case 9: {p[5]->rlink = NULL; break; }
				default: break;
			}
			free(p[i]);
		}
		
		else
			printf("You can't remove that card.\n");
	}
	else
		printf("There's no card to remove.\n");
}

//�����Լ�
void main()
{	
	init_card();
	reset_board();
	while (1)
	{
		show_board();
		scanf("%d", &input);
		if (input == -1)
		{
			pop_handcard(); //if no more card to play(empty stack),you lose.
			if (hand->top == -1)
			{ 
				printf("There's no card anymore. You lost.\n");
				break;
			}

		}
		else if (input >= 0 && input <= 9)
		{
			remove_card(input);
		}
		else 
		{
			printf("Invalid number. Try again.\n");
		}
		if (head==NULL)
		{
			printf("\n You Win. \n");
			break;
		}
			continue;
	}
	system("pause");
}

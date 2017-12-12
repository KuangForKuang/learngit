#include <stdio.h>
#define P1 1
#define P2 -1
#define SIZE 3
#define WIN -1
#define UNWIN 0
#define PEACE 1
#define chkAndPutDwnRow(row, col){\
   for(col = 0; col < SIZE; col++){\
             if(chsman[row][col] == 0){\
                 chsman[row][col] = P2;\
     dsply();\
     return;\
             }\
         }\
  }
#define chkAndPutDwnCol(row, col){\
   for(col = 0; col < SIZE; col++){\
             if(chsman[col][row] == 0){\
                 chsman[col][row] = P2;\
     dsply();\
     return;\
             }\
         }\
  }
#define chkAndPutDwn_Slsh(row, col){\
   if(chsman[row][col] == 0){\
             chsman[row][col] = P2;\
    dsply();\
    return;\
         }\
  }
int chsman[SIZE][SIZE] = {0};
/*��������*/
int enterChsman(int, int);
void dsply(void);
void input1(void);
void input2(void);
void judge(void);
int chkWin(void);
int chkPeace(void);
/*������������*/
int stepFlg = 0;
/*���庯��*/
int enterChsman1(int row, int col)
{
 /*��������*/
 if(row >= SIZE || col >= SIZE)
  return 0;
 /*������ǿյ�*/
 if(chsman[row][col] != 0)
  return 0;
 /*�ǿյ�������*/
 chsman[row][col] = P1;
 
 return 1;
}
int enterChsman2(int row, int col)
{
 /*��������*/
 if(row >= SIZE || col >= SIZE)
  return 0;
 /*������ǿյ�*/
 if(chsman[row][col] != 0)
  return 0;
 /*�ǿյ�������*/
 chsman[row][col] = P2;
 return 1;
}
/*�û�1����*/
void input1(void)
{
    int row, col;
 do{
  scanf("%d%d", &col,&row);

  
        if(enterChsman1(row - 1, col - 1) == 1){
   dsply();
   break;
  }
  else
   printf("�Բ������´�λ���ˣ�\n");
 }while(1);
    return;
}
void input2(void)
{
    int row, col;
 do{
  scanf("%d", &row);
  scanf("%d", &col);
  
        if(enterChsman2(row - 1, col - 1) == 1){
   dsply();
   break;
  }
  else
   printf("�Բ������´�λ���ˣ�\n");
 }while(1);
    return;
}
/*���̽���ʵ��*/
void dsply(void)
{
    int row, col, i;
    /*print the head.*/
 for(i = 0; i < SIZE * 4 + 1; i++)
  printf("-");
 printf("\n");
 /*print the contect.*/
 for(row = 0; row < SIZE; row++){
  printf("|");
  for(col = 0; col < SIZE; col++){
   if(chsman[row][col] == P1) printf(" o |");
   else if(chsman[row][col] == P2) printf(" x |");
   else printf("   |");
  }
  printf("\n");
  /*����*/
  for(i = 0; i < SIZE * 4 + 1; i++)
   printf("-");
  printf("\n");
 }
    return;
}
/*c���ʤ��*/
int chkWin(void)
{
 int i;
 for(i = 0; i < SIZE; i++){
     if(chsman[i][0] + chsman[i][1] + chsman[i][2] == -3 || chsman[0][i] + chsman[1][i] + chsman[2][i] == -3 ||
   chsman[0][0] + chsman[1][1] + chsman[2][2] == -3 || chsman[0][2] + chsman[1][1] + chsman[2][0] == -3){
         return WIN;
     }
 }
 return UNWIN;
}
/*���ƽ��*/
int chkPeace(void)
{
 int row, col;
 int sum = 0;
 for(row = 0; row < SIZE; row++){
     for(col = 0; col < SIZE; col++){
         if(sum += chsman[row][col] == PEACE){
             return PEACE;
         }
     }
 }
 return 0;
}
int main(char* args[])
{
 do{
  /*A����*/
  printf("��A���ӣ�\n"); 
  input1();
  printf("��A again ���ӣ�\n"); 
  input1();
  /*B����*/
  //printf("��B���ӣ�\n");
  //input2();

  if(chkWin() == WIN) break;
  if(stepFlg == 5 && chkPeace() == PEACE){
      printf("Peace!");
   return 0;
  }
 }while(1);
 printf("Hehe....I win this game~ :-p");
    return 0;
}



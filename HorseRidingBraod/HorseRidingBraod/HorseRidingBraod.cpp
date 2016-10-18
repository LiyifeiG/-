/*
*Created 2016 10 14
*Author:Yangfan
*Email:imqqyangfan@gmail.com
*Github:https://www.Github.com/Amnnny
*
*/

#include <cstdio>
#include <cstdlib>
using namespace std;


//�α�����
//C++��� ��������

/////////--------------------------------------------------������Ϣ-------------------------------------------------------
#define STACK_SIZE 100              //�洢�ռ��ʼ������
#define STACKINCREAMENT 10          //�洢�ռ��������
#define N 8                         //���̺��ݴ�С
int weight[N][N];                   //�����Ȩֵ
int Board[N][N][8];                 //������Ȩֵ������Ŵ��߷���ÿ���㶼�а˸�
                                    //����'��'
                                    //����λ��(x , y)  ��Ӧ�߷���Ϊ (i+1 , j-2) , (i+1 , j+2) , (i-1 , j+2) , (i-1 , j-2)
                                    //							  (i-2 , j+1) , (i-2 , j-1) , (i+2 , j-1) , (i+2 , j+1)

///����λ�ýṹ�壬�洢��ǰ��λ��
typedef struct                      
{
	int x_pos_;//Xֵ������
	int y_pos_;//Yֵ������
} PosType;

typedef struct 
{
	int ord;
	PosType seat;          //��ǰ��λ��
	int direction;         //�����һ������
}
ElemType;
///����ջ
typedef struct                 //ջ�д洢���ÿһ������
{
	ElemType *base;            //ջ
	ElemType *top;             //ջ��
	int stacksize;             //ջ�Ĵ�С
}SqStack;


SqStack sq_stack;             //����һ��ȫ�ֱ���ջ  ֮����Դ�ջ����
/////////----------------------------------------------������Ϣ----------------------------------------------------------------

/////////----------------------------------------------��������----------------------------------------------------------------

///��ʼ��һ����ջ
bool InitEmptyStack()
{
	sq_stack.base = static_cast<ElemType *>(malloc(STACK_SIZE * sizeof(ElemType)));
	if (!sq_stack.base) return false;       //�ж��ڴ��Ƿ����ɹ�
	sq_stack.top = sq_stack.base;           //ջ�� = ջ��  ����ջ��
	sq_stack.stacksize = STACK_SIZE;        //(������д��������������ʹ��MAXSIZE �� Cursize�����ܴ�С�͵�ǰ��С �� ������)
	return true;
}

///�鿴ջ����ֵ,����ջ
ElemType GetTopElem()
{
	if (sq_stack.top == sq_stack.base) exit(0);   //���ڽ�����Ϊ�˱�����Ҫд��ջ  ������Ϊ�տ���ֱ���˳�
	return *(sq_stack.top - 1);                   
}

///Ԫ����ջ
void Push(ElemType elem)                   
{
	*sq_stack.top++ = elem;
}

///Ԫ�س�ջ
bool Pop(ElemType *elem)
{
	if (sq_stack.top == sq_stack.base) return false;         //bool��
	*elem = *(--sq_stack.top);
	return true;
}

///�ж�ջ��
bool IsEmpty()                                         //�п�
{
	if (sq_stack.top == sq_stack.base) return true;
	return false;
}

///������߹���·��
void ShowPath()
{
	auto t_stack = sq_stack;                       //����Ҫ��ջ���б�������  ����ʹ����ʱ����ָ��ջ
	int path[N][N] = {};                        
	for (auto i = 0 ; t_stack.top != t_stack.base ; i++)
	{
		//������һ������˼�ǣ�
		//��ջ�ĵײ���ʼ���������Ǵ������ߵĵ�һ����ʼ������Ȼ�����Ӧ��x��y�㣨path��ά���飩�ϸ�ֵ��ǰ�ǵڼ��� 
		//����ջ�׵����λ��Ԫ���ǣ�3��2�����͸�path[3][2]��ֵ 1 ��Ȼ�����һ��λ�ø�ֵ 2
		path[(*t_stack.base).seat.x_pos_][(*t_stack.base).seat.y_pos_] = i + 1;
		++t_stack.base; //ջ��ָ������  ������һ����λ��
	}
	for (auto i = 0 ; i < N ; i ++)             //�����ά����
	{
		printf("\n");
		for (auto j = 0 ; j < N ; j++)
		{
			printf("\t%d" , path[i][j]);
		}
		printf("\n");
	}
}

///�жϵ�ǰλ���Ƿ�Ϸ�
bool Pass(PosType curpos)
{
	auto t_stack = sq_stack;
	if (curpos.x_pos_ < 0 || curpos.x_pos_ > (N - 1) || curpos.y_pos_ < 0 || curpos.y_pos_ > (N - 1)) //�ж�λ���Ƿ�Ϸ�
		return false; 
	for (; t_stack.base != t_stack.top; )                   //�ж���һ���Ƿ��Ѿ��߹�����ջ�����ײ���ʼѭ���Ա�  ��������˵����һ�������Ѿ��߹��ˣ�
	{
		--t_stack.top;
		if (curpos.x_pos_ == (*t_stack.top).seat.x_pos_ && curpos.y_pos_ == (*t_stack.top).seat.y_pos_)
		{
			return false;
		}
	}
	return true;
}

///8����ѡ����
PosType NextPos(PosType curpos , int direction)     //������������һ��switch������һ�����λ�ã�ʹ��һ����ά����������ҵ���Щ�㲢���ܽ�����ɣ�
{
	switch (direction)
	{
		case 1: curpos.x_pos_ += 1 , curpos.y_pos_ -= 2; break;
		case 2: curpos.x_pos_ += 2 , curpos.y_pos_ -= 1; break;
		case 3: curpos.x_pos_ += 2 , curpos.y_pos_ += 1; break;
		case 4: curpos.x_pos_ += 1 , curpos.y_pos_ += 2; break;
		case 5: curpos.x_pos_ -= 1 , curpos.y_pos_ += 2; break;
		case 6: curpos.x_pos_ -= 2 , curpos.y_pos_ += 1; break;
		case 7: curpos.x_pos_ -= 2 , curpos.y_pos_ -= 1; break;
		case 8: curpos.x_pos_ -= 1 , curpos.y_pos_ -= 2; break;
		default: break;
	}
	return curpos;
}

///�����Ȩֵ
void setWeight()                   //���赱ǰ��Ϊa�㣬a����һ������b���c�㣬b����һ�������ĸ������ߵĵط���c����һ���������������ߵģ���b��Ȩֵ��
{
	//���������ÿһ������һ�������ߵĺϷ���ĸ�����ʹ��ȫ�ֱ���weight�洢����
	PosType m;
	ElemType elem;
	for (auto i = 0 ; i < N ; i++)
	{
		for (auto j = 0 ; j < N ; j++)
		{
			elem.seat.x_pos_ = i;
			elem.seat.y_pos_ = j;
			weight[i][j] = 0;
			for (auto k = 0 ; k < 8 ; k++)
			{
				m = NextPos(elem.seat , k + 1);       //��õ�ǰ�����һ����
				if (m.x_pos_ >= 0 && m.y_pos_ >= 0 && m.x_pos_ < N && m.y_pos_ < N)      //�����һ����Ϸ���������Ȩֵ+1
					weight[i][j]++;                                                      //(i , j)����һ�������ƶ����ٸ�����Ϊ����Ȩֵ
			}
		}
	}
}

///����һ����İ˸�λ������
void SortMapByWeight()    
{
	//Board��ά�����������洢������(x,y)���ʱ��ĵ�n����(��(x,y,n))��Ȩֵ��С  Ȼ��ʹ��Ȩֵ��С����
	int arr[8] , min;
	PosType n1 , n2;
	for (auto i = 0 ; i < N ; i++)
	{
		for (auto j = 0 ; j < N ; j++)
		{
			//ǰ����ѭ���������̵�ÿһ���㣬ѭ����������һ�����Ȩֵ�����˸�ֵ���򣬲��Ҵ��뵽���յ�boardȫ�ֱ������
			//�Ҿ��������е��ظ�������  ��ʱ���úøĸ�
			for (auto k = 0 ; k < 8 ; k++)                       //����8����
			{
				n2.x_pos_ = i;
				n2.y_pos_ = j;
				n1 = NextPos(n2 , k + 1);
				if (n1.x_pos_ >= 0 && n1.x_pos_ < N && n1.y_pos_ >= 0 && n1.y_pos_ < N)
				{
					arr[k] = weight[n1.x_pos_][n1.y_pos_];            //��Ȩֵ��ֵ��arr                   
				}
				else
				{
					arr[k] = 0;
				}
			}
			auto s = 0;
			//����
			//�Է�������Ȩֵ�������д���Board
			for (auto f = 0 ; f < 8 ; f++) 
			{
				min = 9;
				for (auto m = 0 ; m < 8 ; m++)
				{
					if (min > arr[m])
					{
						min = arr[m];
						Board[i][j][f] = m;
						s = m;
					}
				}
				arr[s] = 9;   //ѡ������Ϊ9
			}
		}
	}
}


bool HorsePath(PosType start)
{
	auto curpos = start;
	int horsestep = 0 , off;
	ElemType elem = {};
	do
	{
		if (Pass(curpos))   //�����ǰ��λ�úϷ�,�ͽ���һ��ѹ��ջ��
		{
			horsestep++;    
			elem.direction = 0; 
			elem.ord = horsestep;
			elem.seat = curpos;
			Push(elem);  //��ջ
			if (N * N == horsestep) return true;   //���ж��Ƿ��Ѿ�����N*N�������һ�������������ֱ�ӽ���
			off = Board[elem.seat.x_pos_][elem.seat.y_pos_][elem.direction]+1;     //û���Ļ�����һ��
			curpos = NextPos(elem.seat , off);                                    //�����һ����λ�ò��Ҽ���ѭ��
		}
		else              //�����ǰλ�ò��Ϸ�������Ҫ����һ��λ��������
		{
			if (!IsEmpty())    //���Ϊ�յĻ�Ҳ����û����һ��λ���ˣ�����ʼ����λ�þͲ��Ϸ���ʱ��
			{
				while (!IsEmpty() && elem.direction == 8)      //���ջ����directionΪ8����˵����һ����������п��ܵ���һ���������ˣ�����Ҫ������һ����������ң����ܿ�����д���е��ң�
				{
					Pop(&elem);             //��ջ��ֵ�������Ѿ��������ˣ���Ҫ���ݵ����е�λ�ã�
					if (!IsEmpty())     //�жϵ������Ƿ�Ϊ��
					{
						elem = GetTopElem();
						horsestep = elem.ord;
					}
				}
				if (!IsEmpty() && elem.direction < 8)     //���directtionС��8����˵������㻹����������û���Թ�����һһȥ�ԡ�
				{
					Pop(&elem);
					off = Board[elem.seat.x_pos_][elem.seat.y_pos_][++elem.direction];
					curpos = NextPos(elem.seat , off + 1);
					Push(elem);
				}
			}
		}
	}
	while (!IsEmpty());
	printf("�߲�ͨ!");   //һ���ǻ����ϱߵ��ߵ����һ�����������û��˵���߲�ͨ��������ʾ
	return false;
}
/////////----------------------------------------------��������----------------------------------------------------------------

int main(int argc , char **args)
{
	system("color 0b");  //��һ��������cmd���ڵ���ɫ�����Բ���
	PosType start;           //����start�ṹ��Ԫ��
	InitEmptyStack();        //��ʼ��
	printf("������ʼλ��(X , Y):");
	// ReSharper disable once CppDeprecatedEntity
	scanf("%d%d" , &start.x_pos_ , &start.y_pos_);
	setWeight();      //��ÿһ��λ����Ȩֵ
	SortMapByWeight();  //Ȩֵ����
	HorsePath(start);   //�ӳ�ʼλ�ÿ�ʼ��
	ShowPath();     //���
	system("Pause");  //��һ������ͣ���ڣ����Բ���
	return 0;
}

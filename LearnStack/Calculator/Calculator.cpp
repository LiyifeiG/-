/*
 *Created 2016 10 14
 *Author:Yangfan
 *Email:imqqyangfan@gmail.com
 *Github:https://www.Github.com/Amnnny
 */

#include "stack.h"            //��ʵ��ջ
#include <string>
#include <iostream>
#include <ccomplex>
using namespace std;
Stack<char> operator_stack;      //���������ջ
Stack<double> number_stack;      //��������ջ
char32_t operators[] = { '+' , '-' , '*' , '/' , '(' , ')' };
int32_t list_operators[6][6] =                                 ///�������ȼ����ձ�  1��ʾ���ȼ�����  
{
		0 , 0 , -1 , -1 , -1 , -1 ,
		0 , 0 , -1 , -1 , -1 , -1 ,
		1 , 1 ,  0 ,  0 , -1 , -1 ,
		1 , 1 ,  0 ,  0 , -1 , -1 ,
		1 , 1 ,  1 ,  1 ,  0 ,  0 ,
		1 , 1 ,  1 ,  1 ,  0 ,  0
};


string Input();
int ParseStr(string str , string buf_string[]);
double StrToDouble(string str);
int AnalyzingPriority(char operator1 , char operator2);
double Compute(string buf_string[] , int len);
double ComPuteBase(double num1 , char oper , double num2);
void SetNumber();

///�����ַ���(�޿ո�)
string Input()
{
	cout << "Please input a Expression:";
	string str;
	cin >> str;
	return str;
}

///�����ַ��� ת��Ϊstring���� ex:{"32.3" ,"+" ,"4"}
int ParseStr(string str , string buf_string[])
{
	auto index = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if ((str[i] <= '9' && str[i] >= '0') || str[i] == '.')
		{
			buf_string[index] += str[i];
		}
		else
		{
			if (i > 0)
			{
				index++;
			}
			buf_string[index] = str[i];
			if (str[i + 1] <= '9' && str[i + 1] >= '0')
			{
				index++;
			}
		}
	}
	return index + 1;
}

///�����ַ�����ʽ���double����
double StrToDouble(string str)
{
	double integer = 0 ,                  //������������
		decimal = 0;                   //����С������
	int point_index = str.length();       //����С�����λ��
	for (size_t j = 0; j < str.length(); j++)          //�ҵ�С�����λ��
	{
		if (str[j] == '.')
		{
			point_index = j;
			break;
		}
	}
	if (point_index != str.length())                          //����С������
	{
		for (size_t i = point_index + 1; i < str.length(); i++)
		{
			decimal += (str[i] - '0')*pow(10 , point_index - i);
		}
	}
	for (auto i = point_index - 1; i >= 0; i--)                //������������
	{
		integer += (str[i] - '0')*pow(10 , point_index - i - 1);
	}
	return integer + decimal;
}

///�������������ȼ�
int AnalyzingPriority(char operator1 , char operator2)     //�������������ȼ�
{
	auto j = -1 , k = -1;
	for (auto i = 0; i < 6; i++)
	{
		if (operator1 == operators[i]) j = i;
		if (operator2 == operators[i]) k = i;
	}
	return list_operators[j][k];
}

///��ȡ��������ջ������ݺ�һ�����������ݽ��м��㣬���ҽ����ѹ������ջ
void SetNumber()
{
	auto temp_oper = operator_stack.top();
	operator_stack.pop();
	auto num1 = number_stack.top();
	number_stack.pop();
	auto num2 = number_stack.top();
	number_stack.pop();
	number_stack.push(ComPuteBase(num2 , temp_oper , num1));
}

///�Է����õ��ַ���������м���
double Compute(string buf_string[] , int len)
{
	for (auto i = 0; i < len; i++)
	{
		if (buf_string[i].length() > 1 || buf_string[i][0] <= '9' && buf_string[i][0] >= '0')   //���������  ����ת��Ϊ����֮��ѹ��ջ��
		{
			number_stack.push(StrToDouble(buf_string[i]));
		}
		else   //�������
		{
			if (buf_string[i][0] == ')')     //�����ǰ�����Ϊ')'
			{
				while (operator_stack.top() != '(')
				{
					SetNumber();
				}
				operator_stack.pop();
			}
			else if (operator_stack.empty() || operator_stack.top() == '(' || buf_string[i][0] == '('  || AnalyzingPriority(operator_stack.top() , buf_string[i][0]) == -1)
			{
				operator_stack.push(buf_string[i][0]);         //���ջΪ�ջ��߲��������ȼ�����ջ������������ջ
			}
			else
			{
				//ջ����������ȼ����ڵ��ڵ�ǰ�����
				while (AnalyzingPriority(operator_stack.top() , buf_string[i][0]) != -1)
				{
					SetNumber();
					operator_stack.push(buf_string[i][0]);
					break;
				}
			}
		}
	}

	while (!operator_stack.empty())
	{
		SetNumber();
	}
	return number_stack.top();
}

///��������
double ComPuteBase(double num1 , char oper , double num2)
{
	auto result = 0.0;
	switch (oper)
	{
		case '+':result = num1 + num2; break;
		case '-':result = num1 - num2; break;
		case '*':result = num1 * num2; break;
		case '/':
			if (num2 == 0)
			{
				puts("���ִ���!����Ϊ0");
				system("Pause");
				exit(-1);
			}   
			result = num1 / num2;
		 break;
		default:break;
	}
	return result;
}

int main(int argc , char* argv[])
{
	auto str = Input();
	string bufs[100];
	auto len = ParseStr(str , bufs);
	cout << Compute(bufs , len) << endl;
	system("Pause");
	return 0;
}

// WordCount.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "vector"
#include "string"

using namespace std;
void coutchar(string, int);
void coutword(string, int);
void coutline(string, int);
void output(string, int, int, int);


int main()
{
	int charnumber = 0;
	int wordnumber = 0;
	int linenumber = 1;
	int prewordnumber = 0;
	int i = 1;
	int wordstart = 0,wordend=0;
	char ch,prech='32';
	string filename,outputfilename= "2111111111111111111111111";
	string order,order1="2111111111111111111111111",order2="2111111111111111111111111",order3="2111111111111111111111111",order4="2111111111111111111111111",order5="2111111111111111111111111", order6 = "2111111111111111111111111", order7 = "2111111111111111111111111";

	cout << "欢迎使用龙腾计字器，请输入你的命令：\n\t命令格式如下：\n\twc.exe -c file.c  返回文件 file.c 的字符数\n\twc.exe -w file.c  返回文件 file.c 的单词总数\n\twc.exe -l file.c  返回文件 file.c 的总行数\n\twc.exe -o outputFile.txt  将结果输出到指定文件outputFile.txt\n\t如若对同一文件采取多项操作格式命令如下：\n\twc.exe -c -l file.c)\n";
	while (1)
	{
		getline(cin,order);
		int orderwordnumber = 0;


		while (order[i] != '\0')
		{
			if (order[i] == ' ' || order[i] == ',' || order[i] == '\n' || order[i] == '\t'||order[i] == '\0'&&order[i - 1] != 32 && order[i - 1] != ','&&order[i - 1] != '\n'&&order[i - 1] != '\t')
			{
				orderwordnumber++;
				wordend = i;
			}
			if (order[i] != ' ' && order[i] != ',' && order[i] != '\n' && order[i] != '\t'&&order[i + 1] == '\0')
			{
				orderwordnumber++;
				wordend=i+1;
			}
			if (prewordnumber != orderwordnumber)
			{
				prewordnumber = orderwordnumber;
				switch (orderwordnumber)
				{
				case 1:
				{
					for (int j = wordstart, k = 0; j < wordend; j++, k++)
					{
						order1[k] = order[j];
					}
					break;
				}
				case 2:
				{
					for (int j = wordstart, k = 0; j < wordend; j++, k++)
					{
						order2[k] = order[j];
					}
					break;
				}
				case 3:
				{
					for (int j = wordstart, k = 0; j < wordend; j++, k++)
					{
						order3[k] = order[j];
					}
					break;
				}
				case 4:
				{
					for (int j = wordstart, k = 0; j < wordend; j++, k++)
					{
						order4[k] = order[j];
					}
					break;
				}
				case 5:
				{
					for (int j = wordstart, k = 0; j < wordend; j++, k++)
					{
						order5[k] = order[j];
					}
					break;
				}
				case 6:
				{
					for (int j = wordstart, k = 0; j < wordend; j++, k++)
					{
						order6[k] = order[j];
					}
					break;
				}
				case 7:
				{
					for (int j = wordstart, k = 0; j < wordend; j++, k++)
					{
						order7[k] = order[j];
					}
					break;
				}
				default:
					break;
				}
			}
			if (order[i] != ' ' && order[i] != ',' && order[i] != '\n' && order[i] != '\t')
				if(order[i - 1] == 32 || order[i - 1] == ','||order[i - 1] == '\n'||order[i - 1] == '\t')
				{
					wordstart = i;
				}
			
			i++;
		} //将命令按单词分解。
		//将命令分割成单词。


		if (order1.find("wc.exe")!=string::npos)
		{
			if (order2.find("-c") != string::npos || order2.find("-w") != string::npos || order2.find("-l") != string::npos )
				if (order3.find("-c") != string::npos || order3.find("-w") != string::npos || order3.find("-l") != string::npos )
					if (order4.find("-c") != string::npos || order4.find("-w") != string::npos || order4.find("-l") != string::npos)
					{
						filename = order5;
						if (order6.find("-o") != string::npos)
							outputfilename = order7;
					}
					else 
					{ 
						filename = order4; 
						if (order5.find("-o") != string::npos)
							outputfilename = order6;
					}
				else
				{
					filename = order3;
					if (order4.find("-o") != string::npos)
						outputfilename = order5;
				}
			else
			{
				cout << "命令错误，请重新输入：\n";
			}
		}
		else
		{
			cout << "命令错误，请重新输入：\n";
		}//确定命令输入无误。


		for (int j = 0; j < 10; j++)
		{
			if (filename[j] == '1' && filename[j + 1] == '1' && filename[j + 2] == '1' && filename[j + 3] == '1' && filename[j + 4] == '1')
			{
				filename.erase(j);
				break;
			}
		}//提取文件名。
		for (int j = 0; ; j++)
		{
			if (outputfilename[j] == '1' && outputfilename[j + 1] == '1' && outputfilename[j + 2] == '1' && outputfilename[j + 3] == '1' && outputfilename[j + 4] == '1')
			{
				outputfilename.erase(j);
				break;
			}
		}//提取文件名。
		//提取文件名

		ofstream foud;
		ifstream fin;
		charnumber = 0;
		wordnumber = 0;
		linenumber = 1;


		fin.open(filename);
		cout << "文件中内容如下："<<endl;
		while (fin.get(ch))
		{
			cout << ch;
			charnumber++;
			if (ch == ' ' || ch == ',' || ch == '\n' || ch == '\t'&&prech != 32 && prech != ','&&prech != '\n'&&prech != '\t')
			{
				wordnumber++;
			}
			if (ch == '\n')
			{
				linenumber++;
			}
			prech = ch;
		}
		cout << endl;
		if (charnumber == 0)
		{
			wordnumber = 0;
			linenumber = 0;
		}
			//统计字符数，单词数，行数。


		if (ch != ' ' || ch != ',' || ch != '\n' || ch != '\t')
		{
			wordnumber++;
		}
		fin.close();
		
		
		if (order.find("-c") != string::npos)
		{
				coutchar(filename, charnumber);
		}
		if (order.find("-w") != string::npos)
		{
				coutword(filename, wordnumber);
		}
		if (order.find("-l") != string::npos)
		{
				coutline(filename, linenumber);
		}
		fin.open("result.txt");
		while (fin.get(ch))
		{
				cout << ch;
		}
			fin.close();
		if(order.find("-o") != string::npos)
		{
			output(outputfilename, charnumber, wordnumber, linenumber);
		}
		//执行命令
		
		
		foud.open("result.txt");
		foud.close();
		order.empty();
	}
    return 0;
}

void coutchar(string filename1, int a )
{
	ofstream foud;
	ifstream fin;
	char ch;
	foud.open("result.txt",ios_base::out|ios_base::app);
	foud << filename1 << ",字符数：" << a << endl;
	foud.close();
}

void coutword(string filename1, int a)
{
	ofstream foud;
	ifstream fin;
	char ch;
	foud.open("result.txt", ios_base::out | ios_base::app);
	foud << filename1 << ",单词数：" << a << endl;
	foud.close();
}

void coutline(string filename1, int a)
{
	ofstream foud;
	ifstream fin;
	char ch;
	foud.open("result.txt", ios_base::out | ios_base::app);
	foud << filename1 << ",行数：" << a << endl;
	foud.close();
}

void output(string filename1, int a, int b, int c)
{
	ofstream foud;
	ifstream fin;
	char ch;
	foud.open(filename1, ios_base::out | ios_base::app);
	fin.open("result.txt");
	while (fin.get(ch))
	{
		foud << ch;
	}
	foud.close();
	fin.close();
}

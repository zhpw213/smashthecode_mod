/**
 * smash the code $6 o~~~
 * come one
**/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

// ��ʼֵ
char init_c = 'o';
// ������ȷ
char num_ok = 'n'; 
// λ����ȷ
char pos_ok = 'p'; 

// ��ʼ��������� [a,b] rand() % (b-a+1) + a
static int random_num = 0;
// ���²�����
static int key_num = 0;
// λ����ȷ�ۼ�
static int pos_count = 0;
static int pos_count_d[4] = {0};
// ������ȷ�ۼ� 
static int num_count = 0;;

// ���һλ����,scaleΪ�ŵ����ʣ�Ĭ��Ϊ��λ��
void getRandomNum(int scale = 1000)
{
	srand((unsigned)time(NULL));

	key_num = (rand() % (9999-0+1) + 0);
    
    // log
	//cout << "key_num="<<key_num<<endl;
}

// ����������ֵ������4λ���ֵĽ��
bool  checkInput(int n)
{
	bool ret = false;
	int pos[4];
	pos[3] = key_num %10;
	pos[2] = (key_num/10)%10;
	pos[1] = (key_num/100)%10;
	pos[0] = (key_num/1000)%10;

	int i_pos[4];
	i_pos[3] = n%10;
	i_pos[2] = (n/10)%10;
	i_pos[1] = (n/100)%10;
	i_pos[0] = (n/1000)%10;

	pos_count = 0;
	num_count = 0;
	for (int i=0; i<4; i++)
	{
		// clear
		pos_count_d[i] = 0;

		if (i_pos[i] == pos[i])
		{
			pos_count_d[i] = 1;
			pos_count ++;
		}
		for (int j=0; j<4; j++)
		{
			if(i_pos[i] == pos[j])
			{
				num_count ++;
			}
		}
	}
	if (pos_count == 4)
		ret = true;

    // log
	//cout <<"pos_count="<<pos_count<<endl;
	//for (int i=0; i<4; i++)
	//{
	//	cout <<pos_count_d[i];
	//}
	//cout <<endl;

	//cout <<"num_count="<<num_count<<endl;

	return ret;

}

//��� ��ʽ�� ���� | �������ֵ | ��Ƿ���
void output(int count, int ipt)
{
	cout << setfill(' ') << setw(2) << count << " | ";
	cout << setfill('0') << setw(4) << ipt << " | ";

    char c[4];
	// �ж�
    
    int diff_n = num_count - pos_count;
	for (int i = 0; i < 4; i++)
	{
        c[i] = init_c;
        if (pos_count_d[i] == 1)
        {
            c[i] = pos_ok;
        }
	}
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        if (diff_n == 0) break;
        if (diff_n > cnt && pos_count_d[i] != 1)
        {
            c[i] = num_ok;
            cnt++;
        }
    }

	for (int i = 0; i < 4; i++)
	{
		cout << c[i];
	}
	cout << endl;
}


int main()
{
	cout << "** ������4λ���ֽ�����Ϸ��0000-9999��"<<endl;
    cout << "*  ��ʾ:Ĭ���ַ���ʾ :" << init_c << endl;
	cout << "*  ��ʾ:������ȷ(num) : " << num_ok << endl;
    cout << "*  ��ʾ:λ����ȷ(pos) : " << pos_ok << "  �������������ȷ�ĺ���" << endl;
    cout << "*  �ظ����ֻ��ظ����㣬��� 2769������2222 ��ʾΪ nnnn ��4��������ȷ" << endl;
    cout << endl;

	while(true)
	{
		getRandomNum();

		int time_start = (int)time(NULL);

		int k = 0;
		bool r = false;
		for (int i = 0; i < 10; i++)
		{
			cin >> k;
			r = checkInput(k);
			output(i+1,k);
			if (r) break;
		}

		int diff_t = time(NULL) - time_start;
		cout <<"��ʱ:"<<diff_t<<"�룬�Ƿ������һ�֣�y/n:";
		char c;
		cin >> c;
		if (c == 'n' || c == 'N')
			break;
	}
	return 0;
}

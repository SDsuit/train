#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}
//设计联系人的结构体
struct person
{
	string m_Name;//姓名
	int m_Sex=0;//性别 1.男 2.女
	int m_Age=0;//年龄
	string m_Phone;//电话号码
	string m_Address;//家庭住址
};
//设计通讯录的结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct person personArray[MAX];
	//通讯录中当前记录联系人个数
	int m_Size=0;
};
//1.添加联系人
void addPerson(Addressbooks * abs)
{
	//判断通讯录是否已满，满了就不再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//添加具体联系人 

		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name=name;
		//性别
		int sex=0;
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入错误，请重新输入" << endl;
			}
		}
		
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address = address;
		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}

}
//2.显示联系人
void showPerson(Addressbooks* abs)
{
	//判断通讯录中人数是否为0.如果为0，提示记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->m_Size == 0)
	{
		cout << "记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << ( abs->personArray[i].m_Sex == 1?"男":"女" ) << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Address<< endl;
		}
	}
	system("pause");
	system("cls");
}
//检测联系人是否存在，如果存在，返回该联系人具体信息，不存在返回-1
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
//3.删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入你要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//查找到人，要进行删除操作
		for (; ret < abs->m_Size; ret++)
		{
			//数据前移
			abs->personArray[ret] = abs->personArray[ret + 1];
		}
		abs->m_Size--;//更新通讯录中的人员数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//4.查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入你要查找的联系人" << endl;
	string name;
	cin >> name;
	//判断指定联系人是否存在通讯录中
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Address << endl;
	}
	else 
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//5.修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入你要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		int sex = 0;;
		cout << "请输入性别" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				//输入正确，退出循环输入
				break;
			}
			else
			{
				cout << "输入错误，请重新输入" << endl;
			}
		}

		//年龄
		int age = 0;;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//电话
		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//住址
		string address;
		cout << "请输入住址" << endl;
		cin >> address;
		abs->personArray[ret].m_Address = address;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//6.清空联系人
void cleanPerson(Addressbooks* abs)
{
	//将当期联系人数量重置为0，做逻辑清空操作
	abs->m_Size = 0;
	cout << "已清空联系人" << endl;
	system("pause");
	system("cls");
}
int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化当前通讯录中人员个数
	abs.m_Size = 0;
	int select=0;//创建用户输入的变量
	while (true)
	{
		showMenu();//显示菜单
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addPerson(&abs);//利用地址传递可以修改实参;
			break;
		case 2://显示联系人
			showPerson(&abs);
			break;
		case 3://删除联系人
			deletePerson(&abs);
			break;
		case 4://查找联系人
			findPerson(&abs);
			break;
		case 5://修改联系人
			modifyPerson(&abs);
			break;
		case 6://清空联系人
			cleanPerson(&abs);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}
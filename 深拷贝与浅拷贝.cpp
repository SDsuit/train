#include <iostream>
using namespace std;


class person
{
public:
	person()
	{
		cout << "person的默认构造函数调用" << endl;
	}
	person(int age,int height)
	{
		m_Age = age;
		m_Height = new int(height);
		cout<< "person的有参构造函数调用" << endl;
	}
	person(const person& p)
	{
		cout << "person的拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height;编译器默认实现的代码
		//深拷贝操作
		m_Height = new int(*p.m_Height);
	}
	~person()
	{
		//析构代码，将堆区开辟数据做释放操作
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "person的析构函数调用" << endl;
	}
	int m_Age;
	int* m_Height;
};
void test01()
{
	person p1(18,160);
	cout << "p1年龄为 " << p1.m_Age << "  p1身高为 " << *p1.m_Height << endl;

	person p2(p1);
	cout << "p2年龄为 " << p2.m_Age << "  p1身高为 " << *p2.m_Height << endl;



}
int main()
{
	test01();


	system("pause");
	return 0;
}
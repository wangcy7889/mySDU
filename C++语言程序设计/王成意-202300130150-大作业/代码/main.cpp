#include<iostream>
#include"admin.h"
#include"dish.h"
#include"users.h"
int main()
{
START:
	system("cls");
	cout << "**********************************************" << endl;
	cout << "饕在山青！欢迎进入山东大学青岛校区餐厅反馈系统" << endl;
	cout << "请选择以何种身份登录(请输入相应数字)？" << endl;
	int choose;
	cout << "1.系统管理员" << endl;
	cout << "2.学生 / 教师用户" << endl;
	cout << "3.退出" << endl;
	cin >> choose;
	if (choose > 3 || choose <= 0) goto START;
	while (1)
	{
		system("cls");
		switch (choose)
		{
		case 2:
		{
		CHOOSE_USER:
			system("cls");
			cout << "**********************************************" << endl;
			cout << "欢迎使用用户功能(请输入相应数字)：" << endl;
			cout << "1.登陆账号" << endl;
			cout << "2.返回" << endl;
			cout << "3.退出系统" << endl;
			int choose_user;
			cin >> choose_user;
			if (choose_user > 3) goto CHOOSE_USER;
			switch (choose_user)
			{
			case 1:
			{
			USER:
				system("cls");
				cout << "**********************************************" << endl;
				cout << "欢迎登陆饕在山青-山东大学青岛校区餐厅反馈系统！" << endl;
				string name, account, password;
				cout << "请输入姓名拼音（例：张三一，请输入SanyiZhang）:" << endl;
				cin >> name;
				cout << "请输入账号（学号或职工号）：" << endl;
				cin >> account;
				cout << "请输入密码（初始密码为身份证号后六位）：" << endl;
				cin >> password;
				user a1(name, account, password);
				int yyyyy = a1.sign_in();
				if (yyyyy == 1)
				{
					string s = "登陆成功！";
					int xxxxx;
					while (1)
					{
						xxxxx = a1.work(s);
						if (xxxxx == -1)
						{
							cout << "非常抱歉，系统文件被破坏！" << endl;
							system("pause");
							return 0;
						}
						if (xxxxx == 1)
						{
							s = "浏览完毕！";
							continue;
						}
						if (xxxxx == 2)
						{
							s = "查询完毕！";
							continue;
						}
						if (xxxxx == 3)
						{
							s = "提交反馈成功！";
							continue;
						}
						if (xxxxx == 4)
						{
							goto START;
						}
						if (xxxxx == 5)
						{
							break;
						}
						if (xxxxx == 8)
						{
							s = "欢迎回来！";
							continue;
						}

					}
				}
				else
				{
					if (yyyyy == -1)
					{
						cout << "非常抱歉，系统文件被破坏！" << endl;
						system("pause");
						return 0;
					}
					char pd_user;
					cin >> pd_user;
					if (pd_user == 'y')
					{
						goto USER;
					}
					else
					{
						goto START;
					}
				}
				break;
			}
			case 2:
			{
				goto START;
				break;
			}
			case 3:
			{
				choose = 3;
				break;
			}
			default:
			{
				break;
			}
			}
			break;
		}
		case 1:
		{
		CHOOSE_ADMIN:
			system("cls");
			cout << "**********************************************" << endl;
			cout << "欢迎使用管理员功能(请输入相应数字) :" << endl;
			cout << "1.登陆账号" << endl;
			cout << "2.返回" << endl;
			cout << "3.退出系统" << endl;
			int choose_admin;
			cin >> choose_admin;
			if (choose_admin > 3) goto CHOOSE_ADMIN;
			switch (choose_admin)
			{
			case 1:
			{
			ADMIN:
				system("cls");
				cout << "**********************************************" << endl;
				cout << "欢迎登录饕在山青-山东大学青岛校区餐厅反馈系统！" << endl;
				cout << "请输入账号（8位数字）：" << endl;
				string name, password;
				cin >> name;
				cout << "请输入密码（9位数字）：" << endl;
				cin >> password;
				administrator b1(name, password);
				int yyyyy = b1.sign_in();
				if (yyyyy == 1)
				{
					string s = "登陆成功！";
					int xxxxx = 0;
					while (1)
					{
						xxxxx = b1.work(s);

						if (xxxxx == -2)
						{
							goto START;
						}
						if (xxxxx == -1)
						{
							cout << "非常抱歉，系统文件被破坏！" << endl;
							system("pause");
							return 0;
						}
						if (xxxxx == 1)
						{
							s = "管理员添加成功!";
							continue;
						}
						if (xxxxx == 2)
						{
							s = "管理员删除成功!";
							continue;
						}
						if (xxxxx == 3)
						{
							s = "管理员密码修改成功!";
							continue;
						}
						if (xxxxx == 4)
						{
							s = "菜色添加成功！";
							continue;
						}
						if (xxxxx == 5)
						{
							s = "菜色删除成功！";
							continue;
						}
						if (xxxxx == 6)
						{
							s = "查看菜色反馈完毕！";
							continue;
						}
						if (xxxxx == 9) break;
						if (xxxxx == 8)
						{
							s = "欢迎回来！";
							continue;
						}
						if (xxxxx == 7)
						{
							s = "用户添加成功！";
							continue;
						}
						if (xxxxx == 88)
						{
							s = "用户删除成功！";
							continue;
						}
					}
					break;
				}
				else
				{
					if (yyyyy == -1)
					{
						cout << "非常抱歉，系统文件被破坏！" << endl;
						system("pause");
						return 0;
					}
					char pd_user;
					cin >> pd_user;
					if (pd_user == 'y')
					{
						goto ADMIN;
					}
					else
					{
						goto START;
					}
					break;
				}
			}
			case 2:
			{
				goto START;
				break;
			}
			case 3:
			{
				choose = 3;
				break;
			}
			default:
			{
				break;
			}
			}
			break;
		}
		case 3:
		{
			cout << "感谢您的使用！给个好评哦~" << endl;
			system("pause");
			return 0;
		}
		default:
			break;
		}
	}
	return 0;
}
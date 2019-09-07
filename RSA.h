#pragma once
#include<NTL/ZZ.h>
#include<iostream>
#include<ctime>

using namespace std;
using namespace NTL;

NTL_CLIENT

//随机生成512bit的大素数p和q
void get_p_q(ZZ& p, ZZ& q) {
	do {
		SetSeed(to_ZZ((long)time(NULL)));
		RandomPrime(p, 512);
		SetSeed(to_ZZ((long)time(NULL)) * to_ZZ((long)time(NULL)));
		RandomPrime(q, 512);
	} while (p == q);
}


//完成Alice的操作：发送信息并进行数字签名
void Alice(ZZ p, ZZ q, ZZ & n, ZZ & a, ZZ & b, ZZ & x, ZZ & y)
{
	cout << "_Alice_\n";
	ZZ buffer;
	ZZ fn;
	fn = (p - 1) * (q - 1);
	n = p * q;

	do
	{
		SetSeed(to_ZZ((long)time(NULL)));
		RandomLen(a, 1023);
	} while (GCD(a, fn) != 1);

	ZZ b1, b2;
	XGCD(b1, b, b2, a, fn);
	if (b < 0)
		b += fn;
	cout << "input news=";
	cin >> x;
	y = PowerMod(x, a, n);
	cout << "signature=" << y;
}

//选择是否改变Alice信息中的内容
void Oscar(ZZ & x, ZZ & y)
{
	//char q;
	ZZ xx, yy;
	cout << "_Oscar_" << endl;
	cout << "change news or signature(press 0 to give up)" << endl;
	cout << "news=";
	cin >> xx;
	cout << "signature=";
	cin >> yy;

	if (xx != 0)
		x = xx;
	if (yy != 0)
		y = yy;
}

//验证签名
void Bob(ZZ n, ZZ b, ZZ x, ZZ y)
{
	cout << "_Bob_" << endl;
	cout << "Bob get News=" << x << endl << "signature=" << y << endl << "verification result:";
	if (x == PowerMod(y, b, n))
		cout << "SUCCESS";
	else
		cout << "FAILURE";
}


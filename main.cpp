#include<iostream>
#include<NTL/ZZ.h>
#include<ctime>

#include"RSA.h"
#include"ElGamal.h"
#include"certification.h"

using namespace std;
using namespace NTL;

int main()
{
	/*
	//RSA
	cout << "RSA TEST" << endl;
	ZZ p, q, n, a, b, x, y;
	get_p_q(p, q);
	Alice(p, q, n, a, b, x, y);
	cout << endl << endl;
	Oscar(x, y);
	cout << endl;
	Bob(n, b, x, y);
	//cin >> pause;


	//ElGamal
	cout << endl<< endl << "ElGamal TEST" << endl;
	//int pause_;
	//ZZ p, aa, bb, a, x, r, o;
	ZZ  aa, bb,  r, o;
	createkeys(p, aa, bb, a);
	Alice(x, r, o, p, aa, a);
	Oscar(x, r, o);
	Bob(x, r, o, p, aa, bb);
	//cin >> pause_;
	*/

	//certification
	//int _pause;
	ZZ p, q, n, a, b;
	ZZ r_p, r_q, r_n, r_a, r_b;
	ZZ e_p, e_aa, e_bb, e_a;
	get_p_q_3(p, q, 1);
	create_sig_ver(p, q, n, a, b, 1);
	//cout<<"p="<<p<<" q="<<q<<" n="<<n<<" a="<<a<<" b="<<b<<endl;
	Alice(n, b, r_p, r_q, r_n, r_a, r_b, e_p, e_aa, e_bb, e_a);
	Bob(r_n, r_b, e_p, e_aa, e_bb);
	//cin >> _pause;
}
#include <iostream>
using namespace std;

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
using namespace itertools;


template<typename Iterable>
string iterable_to_string(const Iterable& iterable) {
	ostringstream ostr;
	for (auto i: iterable)
		ostr << i << ",";
	return ostr.str();
}

int main()
{
	badkan::TestCase testcase;
	int grade = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	if(signal == 0)
	{
		testcase.setname("range tests");
		{
			int i = 0;
			for(int j: range(0,1000))
			{
				testcase.CHECK_EQUAL(j , i);
				i++;
			}
		}
		{
			char i = 'a';
			for(char j: range('a','z'))
			{
				testcase.CHECK_EQUAL(j , i);
				i++;
			}
		}
		{
			double i = 1.5;
			for(double j: range(1.5,2000.5))
			{
				testcase.CHECK_EQUAL(j , i);
				i++;
			}
		}
		testcase.setname("chain tests");
		{
			int i = 0;
			for(int j: chain(range(0,1000),range(1000,2000)))
			{
				testcase.CHECK_EQUAL(j , i);
				i++;
			}
		}
		{
			char i = 'a';
			for(char j: chain(range('a','p'),range('q','z')))
			{
				testcase.CHECK_EQUAL(j , i);
				i++;
			}
		}

		{
			char i = 'a';
			for(char j: chain(string("abcdefghijk"),string("lmnopqrstuvwxyz")))
			{
				testcase.CHECK_EQUAL(j , i);
				i++;
			}
		}
		{
			char i = 'a';
			for(char j: chain(range('a' , 'k'),string("lmnopqrstuvwxyz")))
			{
				testcase.CHECK_EQUAL(j , i);
				i++;
			}
		}
		testcase.setname("zip tests");
		{
			int i = 0;
			char j = 'a';
			for(auto k: zip(range(1,6) , range('a' , 'f')))
			{
				testcase.CHECK_OUTPUT(k , to_string(i) + "," + to_string(j));
				i++;
				j++;
			}
		}

		{
			int i = 0;
			int j = 7;
			for(auto k: zip(range(1,6) , range(7 , 12)))
			{
				testcase.CHECK_OUTPUT(k , to_string(i) + "," + to_string(j));
				i++;
				j++;
			}
		}
		{
			int i = 'f';
			char j = 'a';
			for(auto k: zip(range('f' , 'k') , range('a' , 'f')))
			{
				testcase.CHECK_OUTPUT(k , to_string(i) + "," + to_string(j));
				i++;
				j++;
			}
		}
		{
			char i = 'a';
			char j = 'h';
			for(auto k: zip(string("abcdefg") , string("hijklmn")))
			{
				testcase.CHECK_OUTPUT(k , to_string(i) + "," + to_string(j));
				i++;
				j++;
			}
		}
		{
			int j = 0;
			char k = 'a';
			int l = 11;
			char m = 'k';
			for(auto i: zip(zip(range(0,10),string("abcdefghij")),zip(range(11,21) , string("klmnopqrst"))))
			{
				testcase.CHECK_OUTPUT(i , to_string(j) + "," + to_string(k) + "," + to_string(l) + "," + to_string(m));
				j++;
				k++;
				l++;
				m++;
			}
		}
		/*testcase.setname("product tests");
		{
			testcase.CHECK_OUTPUT(iterable_to_string(product(range(1,4) , string("hello"))) , "1,h 1,e 1,l 1,l 1,o 2,h 2,e 2,l 2,l 2,o 3,h 3,e 3,l 3,l 3,o");
		}*/
		testcase.setname("powerset tests");
		{
			testcase.CHECK_OUTPUT(iterable_to_string(powerset(range(1,4))) , "{}{1}{2}{1,2}{3}{1,3}{2,3}{1,2,3}");
			
		}
		{
			testcase.CHECK_OUTPUT(iterable_to_string(powerset(chain(range('a','c') , range('x','z') ))) , "{}{a}{b}{a,b}{x}{a,x}{b,x}{a,b,x}{y}{a,y}{b,y}{a,b,y}{x,y}{a,x,y}{b,x,y}{a,b,x,y}");
			
		}
		{
			testcase.CHECK_OUTPUT(iterable_to_string(powerset(string("ab"))) , "{}{a}{b}{a,b}");
			
		}
		{
			testcase.CHECK_OUTPUT(iterable_to_string(powerset(chain(range('a','c') , range('1','3') ))) , "{}{a}{b}{a,b}{1}{a,1}{b,1}{a,b,1}{2}{a,2}{b,2}{a,b,2}{1,2}{a,1,2}{b,1,2}{a,b,1,2}");
			
		}




		grade = testcase.grade();
	}
	else
	{
		testcase.print_signal(signal);
		grade = 0;
	}

	cout << "your grade is: " << grade << endl;
	return 0;
}

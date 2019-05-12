#include <iostream>
using namespace std;

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
using namespace itertools;

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
		{
			auto i = 1;
			for(auto j: chain(range(1,10),string("lmnopqrstuvwxyz")))
			{
				testcase.CHECK_EQUAL(j , i);
				i++;
				if(i == 10)
					i = 'l';
			}
		}
		{
			auto i = 1;
			for(auto j: chain(range(1,10),string("lmnopqrstuvwxyz")))
			{
				testcase.CHECK_EQUAL(j , i);
				i++;
				if(i == 10)
					i = 'l';
			}
		}

		{
			int i = 0;
			char j = 'a';
			for(auto k: zip(range(1,6) , range('a' , 'f')))
			{
				testcase.CHECK_OUTPUT(k , i + "," + j);
				i++;
				j++;
			}
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

#pragma once
#include <utility>
using namespace std;
namespace itertools
{
	template <typename T, typename U>
	class my_pair
	{
	public:
		T first;
		U second;

		my_pair(T f, U s) : first(f), second(s) {}

		friend ostream& operator<<(ostream& os, const my_pair& mp)
		{
			os << mp.first << "," << mp.second;
			return os;
		}
	};
}
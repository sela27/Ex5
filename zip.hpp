#pragma once
#include <utility>
using namespace std;
namespace itertools
{
	template <typename T, typename U>
	class zip
	{
	private:
		T firstContainer;
		U secondContainer;
	public:
		zip(T first, U second) : firstContainer(first), secondContainer(second) {}
		class iterator
		{
		private:
			typename T::iterator first_start;
			typename U::iterator second_start;
		public:
			iterator(typename T::iterator fs, typename U::iterator ss):  first_start(fs),
				second_start(ss) {}
			bool operator!=(iterator const& other)
			{
				return (first_start != other.first_start && second_start != other.second_start);
			}
			iterator& operator++()
			{
				first_start++;
				second_start++;
				return *this;
			}

			pair* const& operator*()
			{
				std::pair<typename T::iterator, typename U::iterator> p;
				p = make_pair(first_start , second_start);
				return *p;
			}
		};

		iterator begin()
		{
			return iterator{firstContainer.begin() , secondContainer.begin()};
		}
		iterator end()
		{
			return iterator{firstContainer.end() , secondContainer.end() };
		}
	};
}
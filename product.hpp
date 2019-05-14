#pragma once
#include "my_pair.hpp"
namespace itertools
{
	/*template <typename T , typename U>
	class product
	{
	private:
		T firstContainer;
		U secondContainer;
	public:
		product(T first, U second) : firstContainer(first), secondContainer(second) {}
		class iterator
		{
		private:
			typename T::iterator first_start;
			typename T::iterator first_end;
			typename U::iterator second_start1;
			typename U::iterator second_start2;
			typename U::iterator second_end;

		public:
			iterator(typename T::iterator fs, typename T::iterator fe, typename U::iterator ss , typename U::iterator se ) : first_start(fs), first_end(fe),
				second_start1(ss), second_start2(ss), second_end(se) {}

			bool operator!=(iterator const& other)
			{
				return ((first_start != other.first_start) || (second_start1 != other.second_start1));
			}
			iterator& operator++()
			{

				if (second_start1 != second_end)
				{
					second_start1++;
					if (second_start1 == second_end)
					{
						if (first_start != first_end)
						{
							first_start++;
							if (first_start != first_end)
							{
								second_start1 = second_start2;
							}
						}
					}
				}
				else
				{
					first_start++;
					second_start1 = second_start2;
				}
				return *this;
			}

			auto const& operator*()
			{
				//std::pair<typename T::iterator*, typename U::iterator*> p = make_pair(*first_start, *second_start);
				//return p;
				//return *first_start + "," + *second_start;
				my_pair mp{ *first_start , *second_start1 };
				//return my_pair(*first_start , *second_start);
				return mp;
			}


		};




		iterator begin()
		{
			return iterator{ firstContainer.begin(),firstContainer.end() ,secondContainer.begin(),secondContainer.end() };
		}
		iterator end()
		{
			return iterator{ firstContainer.end(), firstContainer.end() , secondContainer.end(),secondContainer.end() };
		}

	};*/

	template<typename T1, typename T2>
	class product{
	public:
		product(const T1& a, const T2& b) {}
		int* begin() const { return nullptr; }
		int* end() const { return nullptr; }
	};
}

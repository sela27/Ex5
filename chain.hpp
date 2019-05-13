#pragma once
namespace itertools 
{
	template <typename T , typename U>
	class chain
	{
	private:
		T firstContainer;
		U secondContainer;
	public:
		chain (T first , U second) : firstContainer(first) , secondContainer(second) {}
		class iterator
		{
		private:
			typename T::iterator first_start;
			typename T::iterator first_end;
			typename U::iterator second_start;
		public:
			iterator(typename T::iterator fs , typename T::iterator fe , typename U::iterator ss): first_start(fs) , 
			first_end(fe) , second_start(ss){}


			bool operator!=(iterator const& other)
			{
				if (first_start != first_end)
					return first_start != other.first_start;
				else
					return second_start != other.second_start;
			}

			auto const& operator*() const
			{
				if (first_start != first_end)
					return *first_start;
				else
					return *second_start;
			}

			iterator& operator++()
			{
				if (first_start != first_end)
					first_start++;
				else
					second_start++;
				return *this;
			}

		};

		iterator begin() {
			return iterator{ firstContainer.begin(), firstContainer.end(), secondContainer.begin() };
		}
		iterator end() {
			return iterator{ firstContainer.end(), firstContainer.end(), secondContainer.end() };
		}
	};
}

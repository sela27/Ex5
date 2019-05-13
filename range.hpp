#pragma once
namespace itertools {
	template <typename T>
	class range
	{
	private:
		T _first;
		T _last;
	public:
		range(T first, T last) :_first(first) , _last(last) { }

		class iterator
		{
		private:
			T iter;
		public:
			iterator(T start) : iter(start) {}

			bool operator!=(iterator const& other) const
			{
				return iter != other.iter;
			}

			T const& operator*() const
			{
				return iter;
			}

			iterator& operator++()
			{
				++iter;
				return *this;
			}

			iterator& operator++(int)
			{
				++iter;
				return *this;
			}


		};


		iterator begin() {
			return iterator{ _first };
		}
		iterator end() {
			return iterator{ _last };
		}
	};
}
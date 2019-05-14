#pragma once
namespace itertools
{
	/*template <typename T>
	class powerset
	{
	private:
		T container;
	public:
		powerset(T c) : container(c) {}
		class iterator
		{

		};
	};*/

	template <typename T>
	class powerset
	{
	public:
		powerset(const T&a) {}
		int* begin() const { return nullptr; }
		int* end() const { return nullptr; }
	};
}

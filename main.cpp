#include <iostream>

//its meta functor.. sort of..
template <std::size_t N>
std::string eval_fizzbuzz()
{
	std::string ret;

	if constexpr (0 == (N%3)) ret = "Fizz";
	if constexpr (0 == (N%5)) ret += "Buzz";

	return ret.empty() ? std::to_string(N) : ret;
}

template <std::size_t N>
struct fizzbuzz
{
	static const inline std::string value = fizzbuzz<N - 1>::value + eval_fizzbuzz<N>() + '\n';
};

//terminate recursion
template <>
struct fizzbuzz<0>
{
	static const inline std::string value = "";
};

int main()
{
	std::cout << fizzbuzz<100>::value;
	return 0;
}

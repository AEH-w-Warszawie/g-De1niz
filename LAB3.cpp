#include <vector>
 
std::vector<unsigned int>::iterator findTrivial(std::vector<unsigned int> & v, unsigned int key)
{
	for (auto i = v.begin(); i != v.end(); ++i)
		if (*i == key)
		{
			return i;
		}
	return v.end();
}
 
std::vector<unsigned int>::iterator findBinary(std::vector<unsigned int>& v, unsigned int key)
{
	auto from = v.begin();
	auto to = v.end();
	while (from != to)
	{
		auto middle = from + std::distance(from, to) / 2;
		if (key == *middle)
		{
			return middle;
		}
		else
		{
			if (key < *middle)
			{
				to = middle;
			}
			else
			{
				from = middle + 1;
			}
		}
	}
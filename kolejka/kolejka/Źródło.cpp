#include <iostream>
#include <vector>

int _switch(std::string in);
template<typename T>
void pop_front(std::vector<T>& v);

int main() {

	std::vector<int> queue;
	std::string we;

	while (std::cin >> we) {
		
		if (we == "Enqueue")
		{
			if (queue.size() < 10)
			{
				int temp;
				std::cin >> temp;
				queue.push_back(temp);
				std::cout << "--->" << std::endl;
			}
			else 
			{
				std::cout << "Error: queue is full" << std::endl;
			}
		}
		else if (we == "Dequeue")
		{
			if (!queue.empty())
			{
				std::cout << queue.front() << std::endl;
				pop_front(queue);
			}
			else if (queue.empty())
			{
				std::cout << "Error: queue is empty" << std::endl;
			}
		}
		else if (we == "Print")
		{
			if (!queue.empty())
			{
				std::cout << "Print: ";
				for (int i : queue)
				{
					std::cout << i << " ";
				}
				std::cout << "\n";
			}
			else if (queue.empty())
			{
				std::cout << "Print: Queue is empty" << std::endl;
			}
		}
	}
	return 0;
}
int _switch(std::string in)
{
	if (in == "Enqueue")
	{
		return 1;
	}
	else if (in == "Dequeue")
	{
		return 2;
	}
	else if (in == "Print")
	{
		return 3;
	}
}
template<typename T>
void pop_front(std::vector<T>& v)
{
	if (v.size() > 0)
	{
		v.erase(v.begin());
	}
}
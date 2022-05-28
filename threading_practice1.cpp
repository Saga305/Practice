#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <memory>
#include <random>

constexpr int hthreads = 10;
int array[100000] = {0};


class mythread : public std::thread
{
public:

	mythread(int _start, int _stop) :start(_start), stop(_stop), count(0)
	{
		t = std::shared_ptr<std::thread>(new std::thread([this] { thread_func(); }));
	}

	void join()
	{
		t->join();
	}

	void thread_func()
	{
		for (int i = start; i < stop; i++)
		{
			if (array[i] == 1)
			{
				count++;
			}
		}
	}

	int get_count() const
	{
		return count;
	}
private:
	int count{};
	int start{};
	int stop{};
	std::shared_ptr<std::thread> t{nullptr};
};

void load_array_with_random_values()
{
	int size_of_array = sizeof(array) / sizeof(int);
	std::default_random_engine defEngine(time(0));
	std::uniform_int_distribution<int> intDistro(0, 1);
	int count{ 0 };
	for (int i = 0; i <= size_of_array; i++) {
		array[i] = intDistro(defEngine);
	}

	for (auto& i : array)
	{
		if (i == 1)
		{
			count++;
		}
	}
	std::cout << "Resultant count should be : " << count << std::endl;
	return;
}


int main()
{
	int size_of_array = sizeof(array) / sizeof(int);
	int distance = size_of_array / hthreads;
	int remain = size_of_array % hthreads;
	std::vector<std::shared_ptr<mythread> > tv;
	int result{};
	int index = 0;

	load_array_with_random_values();

	for (int i = 0; i < hthreads; i++)
	{
		tv.push_back(std::shared_ptr<mythread>(new mythread(index, index + distance)));
		index += distance;
	}

	if (remain > 0)
	{
		tv.push_back(std::shared_ptr<mythread>(new mythread(index, index + remain)));
	}

	for (auto& th : tv)
	{
		th->join();
		result += th->get_count();
	}

	std::cout << "Resultant counts: " << result << std::endl;
	return 0;
}

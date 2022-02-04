#include <iostream>


class outher
{
public:
	class inner
	{
	public:
		inner(int a)
		{
			this->a = a;
		}

	protected:
		int a;
	};

	other(int a)
	{
		this->a = a;
	}

	void foo()
	{
		inner in(3);

		std::cout << in.a << std::endl;
	}

	int a;
};


int main()
{
	outher out(2);

	outher::inner in(3);




	return 0;
}

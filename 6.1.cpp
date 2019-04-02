#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

class Veletlen
{
	public:
		Veletlen();
		~Veletlen(){};

		double get();

	private:
		bool van;
		double ertek;
};

Veletlen::Veletlen()
{
	van = false;
	std::srand (std::time(NULL));
};

double Veletlen::get() 
{
	if (!van)
	{
		double u1, u2, v1, v2, w;
			do
			{					//Algorithm starts 
			u1 = std::rand () / (RAND_MAX + 1.0);
			u2 = std::rand () / (RAND_MAX + 1.0);
			v1 = 2 * u1 - 1;
			v2 = 2 * u2 - 1;
			w = v1 * v1 + v2 * v2;
			}
		while (w > 1);

		double r = std::sqrt ((-2 * std::log (w)) / w);
		ertek = r * v2;
		van = !van;

		return r * v1;					//Algorithm ends
	}
	else
	{
	van = !van;
	return ertek;
	}
};

int main ()
{
	Veletlen rnd;

	for(int i=0; i<10; ++i)
	{
		std::cout << rnd.get() << std::endl;
	};
}





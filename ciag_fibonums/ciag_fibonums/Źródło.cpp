#include<iostream>
long long int x, y, z, v;
void fibo_nums(long long int n, long long int fib[]);
int main()
{
	int m;
	long long int matrix[100]; //m<=100
	long long int fib[2] = { 0 };

	std::cin >> m;
	for (int i = 0; i < m; i++)
	{
		std::cin >> matrix[i];
	}
	for (int i = 0; i < m; i++) 
	{
		fibo_nums(matrix[i], fib);
		std::cout << fib[0] << std::endl;
	}
	return 0;
}
void fibo_nums(long long int n, long long int fib[])
{
	if (n == 0)
	{
		fib[0] = 0; 
		fib[1] = 1;
		return;
	}
	fibo_nums((n / 2), fib);
	x = fib[0];             //fib n
	y = fib[1];           //fib n+1
	z = 2 * y - x;		//z=2*1-0 = 2
	if (z < 0) //2<0 -> 2=(0*2)modulo 10^9+7
	{
		z += 1000000007;
	}
	z = (x * z) % 1000000007;      //fib 2n
	v = (x * x + y * y) % 1000000007;  //fib 2n+1
	if (n % 2 == 0)
	{
		fib[0] = z;
		fib[1] = v;
	}
	else
	{
		fib[0] = v;
		fib[1] = z + v;
	}
}

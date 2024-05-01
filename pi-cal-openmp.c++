#include <iostream>
using namespace std;

// Function to find estimated
// value of PI using Monte
// Carlo algorithm
void monteCarlo(int N, int K)
{

	// Stores X and Y coordinates
	// of a random point
	double x, y;

	// Stores distance of a random
	// point from origin
	double d;

	// Stores number of points
	// lying inside circle
	int pCircle = 0;

	// Stores number of points
	// lying inside square
	int pSquare = 0;
	int i = 0;

// Parallel calculation of random
// points lying inside a circle
#pragma omp parallel firstprivate(x, y, d, i) reduction(+ : pCircle, pSquare) num_threads(K)
	{
	
		// Initializes random points
		// with a seed
		srand48((int)time(NULL));

		for (i = 0; i < N; i++)
		{
		
			// Finds random X co-ordinate
			x = (double)drand48();

			// Finds random X co-ordinate
			y = (double)drand48();

		
			d = ((x * x) + (y * y));

			if (d <= 1) 
			{
			
				pCircle++;
			}
		
		
			pSquare++;
		}
	}

	double pi = 4.0 * ((double)pCircle / (double)(pSquare));

	cout << "Final Estimation of Pi = "<< pi;
}

int main()
{

	int N = 100000;
	int K = 8;

	monteCarlo(N, K);
}


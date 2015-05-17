#include <stdlib.h>
#include <iostream>
#include <queue>
#include <array>
#include <cmath>


using namespace std;


int* RadixSort(int* input, int size, int k = -1)
{
	for(int ak=0; ak<k; ak++)
	{
		int ik = pow(10,ak);
			//iterate over each digit
		array<queue<int>,10> bins;

		//push element into the correct box
		//based on digit 'ik'
		for(int ia = 0; ia < size; ia++) //O(n)
		{
			int temp = input[ia];
			bins[(temp /ik) %10].push(temp);
		}

		//re-create 'input' from bins (Copy)
		int count = 0;
		for(int ui =0; ui<10; ui++) 
		{
			for(int uj = bins[ui].size();uj>0;uj--) //O(n)
			{	
				input[count++] = bins[ui].front();
				bins[ui].pop();

			}
		}	
	}
	return input;
}


//O(k*(n+n))
queue<int> RadixSort(queue<int> input, int size, int k = -1)
{
	//If the max size is not known, then search for it.
	if(k <= 0)
	{
		int max = input.front();
		for(int ui =0; ui<size; ui++)
		{
			if(input.front() > max)
				max = input.front();
			//Recycle to the back of the queue
			input.push(input.front());
			input.pop();
		}
		//We only need the number of digits.
		k = ceil(log(k));
	}

	//iterate over each digit
	for(int ik = 1; ik < k; ik *=10) //O(K)
	{
		array<queue<int>,10> bins;

		//push element into the correct box
		//based on digit 'ik'
		for(int ia = 0; ia < size; ia++) //O(n)
		{
			int temp = input.front();
			bins[(temp /ik) %10].push(temp);
			input.pop();
		}

		//re-create 'input' from bins (Copy)
		for(int ui =0; ui<10; ui++) 
		{
			for(int uj = bins[ui].size();uj>0;uj--) //O(n)
			{	
				input.push(bins[ui].front());
				bins[ui].pop();
			}
		}	
	}
	return input;
}

int main()
{

	int input[10] = {36, 9, 0, 25, 1 ,49, 64, 16, 81, 4};
	/*queue<int> input2;
	for(int ui=0;ui<10;ui++)
		input2.push(input[ui]);

	int size = 10;
	int k = 100;
	queue<int>output = RadixSort(input2, size, k);
	for(int ui=output.size();ui>0;ui--)
	{
		cout << output.front() << endl;
		output.pop();
	}
*/
	int * output = RadixSort(input, 10, 2);
	for( int ui=0; ui < 10; ui++)
	{
		cout << output[ui] << endl;
	}
	return 0;
}
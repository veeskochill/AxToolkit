#include <stdlib.h>
#include <iostream>

#include <queue>
#include <array>


using namespace std;

//O(k*(n+n))
queue<int> RadixSort(queue<int> input, int size, int k)
{
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
	queue<int> input2;
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

	return 0;
}
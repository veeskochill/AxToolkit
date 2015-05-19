#include <stdlib.h>
#include <iostream>
#include <queue>
#include <array>
#include <cmath>

#include <cstring>
#include <map>


using namespace std;
string* RadixSort(string* input, int size, int k = -1)
{
	for(int ak=k-1; ak >=0; ak--)
	{
		map<char, queue<string>> bins;
		for(int ia =0; ia < size; ia++)
		{
			string temp = input[ia];
			if(temp.size() > ak)
			{
				bins[temp.at(ak)].push(temp);
				cout << temp.at(ak) << " " << bins[temp.at(ak)].back() << endl;
			}
			else
			{
				bins['a'].push(temp);
				cout << 'a' <<  " " << bins['a'].back() << endl;
			}
		}
		int count =0;
		cout << endl;
		for(map<char, queue<string>>::iterator ui=bins.begin(); ui!=bins.end(); ui++)
		{
			cout << ui->first << ": ";
			while(ui->second.size())
			{
				input[count++] = ui->second.front();
				cout << ui->second.front() << " ";
				ui->second.pop();
			}
			cout << endl;
		}
		cout << endl;
	}
}

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
		cout << endl;

		int count = 0;
		for(int ui =0; ui<10; ui++) 
		{
			if(bins[ui].size())
			{
				cout << endl;
				cout << ui << ":";
			}
			for(int uj = bins[ui].size();uj>0;uj--) //O(n)
			{	
				input[count] = bins[ui].front();
				cout << input[count] << " ";
				bins[ui].pop();
				count++;
			}
		}
		cout << endl;
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

	string inputstring[] = {"spin", "golf", "go", "road", "rick", "spy", "spit"};
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
	string* output = RadixSort(inputstring, 7, 4);
	for( int ui=0; ui < 7; ui++)
	{
		cout << inputstring[ui] << endl;
	}
	
	return 0;
}
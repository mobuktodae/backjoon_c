#include<iostream>
#include<stack>

using namespace std;

int main()
{
	int n;
	cin >> n;
	stack<int> s;
	int snumber = 1;
	int arr[100001] = { 0 };
	int i;
	char arr2[200000] = {0};
	int check = 0;

	for (i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		arr[i] = number;
	} 

	int oneton = 1;
	for (i = 0; i < n; i++)
	{
		while(1) 
		{
			if (oneton <= n)
			{
				if ((!s.empty()) && (s.top() == arr[i])) {
					arr2[check++] = '-';
					s.pop();
					break;
				}
				else {
					arr2[check++] = '+';
					s.push(oneton++);
				}
			}
			else { 
				if (s.top() != arr[i])
					break;
				arr2[check++] = '-';
				s.pop();
				break;
			}
			
		}


	}



	if (!s.empty())
		cout << "NO\n";
	else
	{
		for (int i = 0; i < check; i++)
		{
			cout << arr2[i] << "\n";
		}
	}

	return 0;
}
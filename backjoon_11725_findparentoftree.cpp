#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, a, b;
	int parent[100001] = { 0 };
	int count = 0;
	queue<int> q;
	cin >> n;
	vector<int> *tree = new vector<int>[n+1];
	

	//�ᱹ tree�� �׷����� �����̱� ������ �׷����� �����ϴ� ������� ������ش�. 
	for (int i = 1; i < n; i++)
	{
 		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	bool visited[100001] = { false };
	visited[1] = true;


	q.push(1);

	while (!q.empty())
	{
		int front = q.front();
		q.pop();

		for (int i = 0; i < tree[front].size(); i++)
		{
			if (!visited[tree[front][i]])
			{
				q.push(tree[front][i]);
				visited[tree[front][i]] = true;
				parent[tree[front][i]] = front;
				count++;
			}
		}
		if (count == n-1)
			break;
	}

	for (int i = 2; i <= n; i++)
		cout << parent[i] << "\n";

	return 0;

}

// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void sort_2_3(int* arr, int p, int q) {
	int num = q - p + 1;
	if (num == 2) {
		cout << "sort_2_3 2:" << arr[p] << "," << arr[p + 1] << endl;
		if (arr[p] > arr[p + 1]) {
			int tmp = arr[p];
			arr[p] = arr[p + 1];
			arr[p + 1] = tmp;
		}
		cout << "sort_2_3 2:" << arr[p] << "," << arr[p + 1] << endl;
	}
	else if (num == 3) {
		cout << "sort_2_3 3:" << arr[p] << "," << arr[p + 1] << "," << arr[p + 2] << endl;
		int Min = arr[p];
		int Max = arr[p];
		int min_i = 0;
		int max_i = 0;
		for (int index = 0; index < 3; index++) {
			if (arr[p + index] < Min) {
				Min = arr[p + index];
				min_i = index;
			}
			else if (arr[p + index] > Max) {
				Max = arr[p + index];
				max_i = index;
			}
		}
		int Mid = arr[p + 3 - min_i - max_i];
		arr[p] = Min;
		arr[p + 1] = Mid;
		arr[p + 2] = Max;
		cout << "sort_2_3 3:" << arr[p] << "," << arr[p + 1] << "," << arr[p + 2] << endl;
	}
	else {
		//cout<<num<<endl;
	}
}

void Merge(int* arr, int p, int q) {
	cout << "merge:" << p << "," << q << endl;
	for (int i = p; i <= q; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	int n = q - p + 1;
	int num = int(sqrt(n));
	//开辟暂存空间
	int i = 0;
	vector<vector<int> > tmps(num);
	for (; i < num - 1; i++) {
		tmps[i].resize(num + 1);
	}
	tmps[i].resize(n - i * num + 1);

	//初始化数据
	for (i = 0; i < num - 1; i++) {
		int j = 0;
		for (; j < num; j++) {
			tmps[i][j] = arr[p + i * num + j];
		}
		tmps[i][j] = INT_MAX;
	}
	int in = 0;
	for (; in < n - i * num; in++)
		tmps[i][in] = arr[p + i * num + in];
	tmps[i][in] = INT_MAX;

	cout << "初始化数据：" << endl;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < tmps[i].size(); j++) {
			cout << tmps[i][j] << " ";
		}
		cout << endl;
	}
	cout << "初始化数据." << endl;

	//每行标记
	int poses[num];
	for (int i = 0; i < num; i++) {
		poses[i] = 0;
	}
	//比较
	int Min = tmps[0][0];
	int index_row = 0;
	for (i = p; i <= q; i++) {
		for (int j = 0; j < num; j++) {
			if (tmps[j][poses[j]] < Min) {
				Min = tmps[j][poses[j]];
				index_row = j;
			}
		}
		arr[i] = tmps[index_row][poses[index_row]];
		Min = tmps[index_row][poses[index_row] + 1];
		poses[index_row]++;
	}
	for (int i = p; i <= q; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void sqrt_n_sort(int* arr, int p, int q) {
	cout << "deviation" << endl;
	int n = q - p + 1;
	int num = int(sqrt(n));
	if (num > 1) {
		int i = 0;
		for (; i < num - 1; i++) {
			cout << p + num * i << "," << p + num * (i + 1) - 1 << endl;
			sqrt_n_sort(arr, p + num * i, p + num * (i + 1) - 1);
			//sort_2_3(arr, p + num*i, p + num*(i+1) - 1);
		}
		cout << p + num * i << "," << q << endl;
		sqrt_n_sort(arr, p + num * i, q);
		//sort_2_3(arr, p + num*i, q);
		Merge(arr, p, q);
	}
	else {
		sort_2_3(arr, p, q);
	}
}

int main()
{
	int arr[17] = { 3,9,11,25,18,21,19,7,6,19,22,15,19,24,2,1,16 };
	sqrt_n_sort(&arr[0], 0, 16);

	//cout<<"begin:"<<endl;
	for (int i = 0; i < 17; i++) {
		cout << arr[i] << " " << endl;
	}
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

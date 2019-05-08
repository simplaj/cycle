// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void sort_2_3(int* arr, int p, int q) {
	int n2 = q - p + 1;
	if (n2 == 2) {
		//cout << "两个元素排序：" << arr[p] << "," << arr[p + 1] << endl;
		if (arr[p] > arr[p + 1]) {
			int tmp = arr[p];
			arr[p] = arr[p + 1];
			arr[p + 1] = tmp;
		}
		cout << "二元排序:" << arr[p] << "," << arr[p + 1] << endl;
	}
	else if (n2 == 3) {
		//cout << "三个元素排序:" << arr[p] << "," << arr[p + 1] << "," << arr[p + 2] << endl;
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
		cout << "三元排序:" << arr[p] << "," << arr[p + 1] << "," << arr[p + 2] << endl;
	}
	else {
		//cout<<n2<<endl;
	}
}

void Merge(int* arr, int p, int q) {
	cout << "合并:" << p << "," << q << endl;
	for (int i = p; i <= q; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	int n = q - p + 1;
	int n2 = int(sqrt(n));
	//开辟暂存空间
	int i = 0;
	vector<vector<int> > tmps(n2);
	for (; i < n2 - 1; i++) {
		tmps[i].resize(n2 + 1);
	}
	tmps[i].resize(n - i * n2 + 1);

	//初始化数据
	for (i = 0; i < n2 - 1; i++) {
		int j = 0;
		for (; j < n2; j++) {
			tmps[i][j] = arr[p + i * n2 + j];
		}
		tmps[i][j] = INT_MAX;
	}
	int in = 0;
	for (; in < n - i * n2; in++)
		tmps[i][in] = arr[p + i * n2 + in];
	tmps[i][in] = INT_MAX;

	cout << "分治：" << endl;
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < tmps[i].size(); j++) {
			cout << tmps[i][j] << " ";
		}
		cout << endl;
	}
	//cout << "初始化数据." << endl;

	//每行标记
	vector<int> locs(n2);
	for (int i = 0; i < n2; i++) {
		locs[i] = 0;
	}
	//比较
	int Min = tmps[0][0];
	int index_col = 0;
	for (i = p; i <= q; i++) {
		for (int j = 0; j < n2; j++) {
			if (tmps[j][locs[j]] < Min) {
				Min = tmps[j][locs[j]];
				index_col = j;
			}
		}
		arr[i] = tmps[index_col][locs[index_col]];
		Min = tmps[index_col][locs[index_col] + 1];
		locs[index_col]++;
	}
	cout << "分治排序："<<endl;
	for (int i = p; i <= q; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void sqrt_n_sort(int* arr, int p, int q) {
	//cout << "deviation" << endl;
	int n = q - p + 1;
	int n2 = int(sqrt(n));
	if (n2 > 1) {
		int i = 0;
		for (; i < n2 - 1; i++) {
			//cout << p + n2 * i << "," << p + n2 * (i + 1) - 1 << endl;
			sqrt_n_sort(arr, p + n2 * i, p + n2 * (i + 1) - 1);
			//sort_2_3(arr, p + n2*i, p + n2*(i+1) - 1);
		}
		//cout << p + n2 * i << "," << q << endl;
		sqrt_n_sort(arr, p + n2 * i, q);
		//sort_2_3(arr, p + n2*i, q);
		Merge(arr, p, q);
	}
	else {
		sort_2_3(arr, p, q);
	}
}

int main()
{
	int arr[17] = { 45,46,85,1,56,45,35,69,36,14,57,59,8,4,6,12,32};
	sqrt_n_sort(&arr[0], 0, 16);

	cout<<"结果输出:"<<endl;
	int i = 0;
	for (; i < 16; i++) {
		cout << arr[i] << "," ;
	}
	cout << arr[i] << endl;
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

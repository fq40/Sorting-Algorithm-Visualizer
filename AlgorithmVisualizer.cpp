// AlgorithmVIsualizer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "AlgorithmExecutor.h"
#include <string>
#include <iostream>
#include <ctime>
#include <thread>
using namespace std;



int main(int argc, char* args[])
{
	SDL_Event e;
	//根据当前时间获取随机种子
	//Gain random seed by current time
	srand(time(NULL));
	//用户输入的 窗口宽度，窗口高度，矩形数量，算法选择
	//the width & height of the window, the amount of rectangle,algorithm selection of user
	int res_x,res_y,rectamount,AlgoSelection;
	Visualizer *v = nullptr;
	AlgorithmExecutor *sort1 = nullptr;
	while (v == nullptr) {
		cout << "Please input the size of window：" << endl;
		cout << "(16：9 recommended，e.g 1280x720 etc，input should be separated by space)" << endl;
		while (cin >> res_x >> res_y) {
			if (res_x < 5 || res_x>1920 || res_y < 5 || res_y>1080) {
				cout << "illegal input"<<endl;
				continue;
			}
			else {
				cout << "Please input the amount of rectangles to be sorted：" << endl;
				cout << "（range：2 - " << res_x / 2 << ")" << endl;
				while (cin >> rectamount) {
					if (rectamount<2||rectamount>(res_x/2)) {
						cout << "illegal input" << endl;
						continue;
					}
					else {
						v = new Visualizer(res_x, res_y, rectamount,&e);
						
						cout << "Please select a sorting algorithm：" << endl;
						cout << "1. Bubble sort 冒泡排序" << endl;
						cout << "2. Selection sort 选择排序" << endl;
						cout << "3. Insertion sort 插入排序" << endl;
						cout << "4. Shell sort 希尔排序" << endl;
						cout << "5. Quick sort 快速排序" << endl;
						while (cin >> AlgoSelection) {
							switch (AlgoSelection)
							{
							case 1:
								sort1 = new BubbleSort(v);
								break;
							case 2:
								sort1 = new SelectionSort(v);
								break;
							case 3:
								sort1 = new InsertionSort(v);
								break;
							case 4:
								sort1 = new ShellSort(v);
								break;
							case 5:
								sort1 = new QuickSort(v);
								break;
							default:
								sort1 = nullptr;
								break;
							}
							if (sort1 == nullptr) {
								cout << "illegal input" << endl;
								continue;
							}
							else {
								sort1->Execute();
								cout << "Comparaton times：" << sort1->CompareTime << "Swap times：" << sort1->SwapTime << endl << endl;
								delete v;
								v = nullptr;
								delete sort1;
								sort1 = nullptr;
								break;
							}
						}
						break;
					}
				}
				break;
			}
		}		
	}
	return 0;
}


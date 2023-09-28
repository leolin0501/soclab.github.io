

//用於測試 Multiplication.h 中的 multip_2num 函式的測試程式（testbench）。該測試程式通過將不同的整數對傳遞給 multip_2num 函式，並檢查其返回值是否等於相應的整數乘積，來測試 multip_2num 函式的正確性。
#include <iostream>
#include "Multiplication.h"//以便在程式中使用標頭檔"Multiplication.h"相關的定義和宣告。

using namespace std;

int main(int argc, char *argv[])
{
	int i, j;
	int pass = 1; //用於記錄測試是否通過，初始值為 1，表示通過。
	int n32Multip; //用於存儲 multip_2num 函式的返回值，即整數乘積。

	cout << ">> Start test!" << endl;//使用 cout 將開始測試的訊息輸出到終端。

	for(i = 1; i < 10; i++) {//持續繼續下一輪的迴圈，直到測試完所有整數對。
		cout << "------------------------" << endl;
		for(j = 1; j < 10; j++) {
			multip_2num(i, j, &n32Multip);//在迴圈內部，使用 multip_2num 函式計算 i 和 j 的乘積，並將結果存儲在 n32Multip 中。

			cout << i << " * " << j << " = " << n32Multip << endl;//使用 cout 將計算結果輸出到終端，包括 i、j 和 n32Multip 的值。
			if(n32Multip != (i * j)) {//檢查計算結果是否等於 i * j，如果不等於，則將 pass 設置為 0，表示測試未通過。
				pass = 0;
			}
		}
	}
	cout << "------------------------" << endl;//測試完成後，輸出分隔線和測試結果訊息。

	if(!pass) {
		cout << ">> Test failed!" << endl;//最終檢查 pass 的值，如果為 0，表示測試未通過，輸出測試失敗的訊息，並返回錯誤碼 1。如果 pass 仍然為 1，表示測試通過，輸出測試通過的訊息，並返回正確碼 0。
		return 1;
	}

	cout << ">> Test passed!" << endl;
	cout << "------------------------" << endl;
	return 0;
}


/*cout << ">> Start test!" << endl;

cout：cout 是 C++ 標準程式庫中的標準輸出流，用於向終端窗口輸出資訊。

<<：這是輸出流運算子，用於將右側的內容輸出到左側的流中。在這個情況下，它將字串 ">> Start test!" 輸出到 cout 流中。

">> Start test!"：這是要輸出的字串，它包含了訊息內容。

endl：endl 是 C++ 標準程式庫中的標準輸出結束符號，它表示換行並刷新輸出緩衝區。當 endl 被使用時，它會將之前的內容輸出到終端，然後換行。這有助於確保訊息被立即顯示在終端窗口中。*/
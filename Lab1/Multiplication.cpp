
#include "Multiplication.h" //以便在程式中使用標頭檔"Multiplication.h"相關的定義和宣告

void multip_2num(int32_t n32In1, int32_t n32In2, int32_t* pn32ResOut) //它接受兩個32位整數 (n32In1 和 n32In2) 作為輸入，並接受一個指向32位整數的指針 (pn32ResOut) 作為輸出。
{

//#pragma HLS INTERFACE 指令，它們用於定義接口屬性。
//#pragma HLS：這是 Vivado HLS 工具支援的指示性指令的開始。
//INTERFACE：這部分指定了這個指令是用來設置函式的介面屬性。
#pragma HLS INTERFACE s_axilite port=pn32ResOut //這個指令指定 pn32ResOut 參數用來傳遞一個32位整數的結果，作為 AXI Lite (一種硬體協定)接口的一部分，這是一種用於訪問外部硬體的標準接口。
#pragma HLS INTERFACE s_axilite port=n32In2 //這兩個指令指定 n32In2 和 n32In1 參數用來接收輸入的整數值，也作為 AXI Lite 接口的一部分。
#pragma HLS INTERFACE s_axilite port=n32In1//這行程式碼執行兩個輸入整數 n32In1 和 n32In2 的乘法運算，然後將結果存儲在指針 pn32ResOut 指向的位置。


//下面這行是用於指定函式的控制信號介面的設定，特別是用於控制硬體加速器的開始和停止。
//"ap_ctrl_none"是xilinx的保留字元，指令告訴Vivado HLS不生成開始和停止硬體加速器的控制邏輯。如果在synthesis時需要硬體加速器，那麼需要這些控制信號來適當地開始和停止硬體運行。如果沒有這些控制信號，可能會導致硬體加速器無法正確啟動或停止，從而導致錯誤。
//Vivado HLS可能會根據指令的依賴關係生成硬體邏輯。如果移除 ap_ctrl_none，可能會影響到指令的依賴關係，導致錯誤。
//跑C simulation、Csynthesis時要註解，cosimulation再解註解。
//port=return 中的 port 是一個合法的識別符號，用於指定你想要針對的函式參數，而 return 則是函式的返回值。這是 Vivado HLS 中的一種常見用法，用於指示你想要配置的介面屬性是與函式的返回值相關的。
#pragma HLS INTERFACE ap_ctrl_none port=return 



	*pn32ResOut = n32In1 * n32In2;

	return;
}


//依賴關係：硬體元件或指令之間的相互關係
//1.數據依賴關係：這種依賴關係發生在當一個元件需要使用另一個元件的輸出數據時。
//2.控制依賴關係：這種依賴關係與硬體的控制流程有關。當一個元件的操作受到另一個元件的控制信號或控制命令的影響時
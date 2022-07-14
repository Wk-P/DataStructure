#pragma once

// 对称矩阵 symmetric_matrix

/*  关于 [0][0] 至 [n][n] 对角线对称 保留左下角数据 
	从而寻找a[i][j] 所对应的线性存储的 a[k]值
*/


int _index(int (*array)[], int fst_s, int sec_s, int fst_index, int sec_index) {
	/*
	*	--param--
		fst_s: 第一维数组长度（行数）
		sec_s: 第二维数组长度（列数）
		fst_index: 第一维数组下标
		sec_index: 第二维数组下标
	*/
	return ((fst_index - 1) * fst_index)/2 + sec_index;
}

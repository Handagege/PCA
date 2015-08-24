/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// NumFormulaTree.h 用于声明数值表达树(NFT)的头文件
//
// 版本：v1.0 - 2013.08.08 by 冯扬(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_NUM_FORMULA_TREE_H
#define _FENGYOUNG_API_NUM_FORMULA_TREE_H

#include <iostream>
#include <map>
#include <string>
using namespace std;
#include <stdint.h>

namespace fengyoung
{

// 节点类型枚举
enum ENumFormulaNodeType
{
	_NUM_VALUE,		// 数值
	_NUM_DIM,		// 单位
	_UNKNOWN		// 未知类型
};


// 类名：NumFormulaNode
// 说明：数值表达树的节点类
class NumFormulaNode
{
public:
	// 构造函数 & 析构函数
	NumFormulaNode();
	NumFormulaNode(const ENumFormulaNodeType eType, const int32_t nVal);
	virtual ~NumFormulaNode();

public:
	ENumFormulaNodeType m_eType;// 节点类型
	int32_t m_nVal;					// 节点数据
	NumFormulaNode* m_pParent;	// 父节点指针
	NumFormulaNode* m_pLeft;	// 左子节点指针
	NumFormulaNode* m_pRight;	// 右子节点指针
};


// 类名：NumFormulaTree
// 说明：数值表达树，用于转换和存储中文的数值表达式
class NumFormulaTree
{
public:
	// 构造函数 & 析构函数
	NumFormulaTree();
	virtual ~NumFormulaTree();

	// 函数名：Release
	// 说明：释放当前数值表达树的内容
	void Release();

	// 函数名：ReadFromNumString
	// 说明：从字符串中读取数值，解析到当前数值表达树中
	// 参数：
	//	[IN] strNum - 中文数值字符串
	//	[IN] sNum - 中文数值字符串
	//	[IN] nLen - 中文数值字符串长度
	void ReadFromNumString(string& strNum);
	void ReadFromNumString(const char* sNum, const int32_t nLen);

	// 函数名：GetNumValue
	// 说明：获取当前树表示的数值
	// 返回值：当前树表示的数值
	int32_t GetNumValue();

	// 函数名：GetRoot
	// 说明：获取根节点
	// 返回值：当前数值表达树的根节点
	NumFormulaNode* GetRoot();

	// 函数名：PrintTheTree
	// 说明：打印数值表达树
	// 参数：
	//	[IN|OUT] os - 输出流
	//	[IN] pStartNode - 待打印的树的根节点，如果为NULL，则打印当前完整的树
	//	[IN] nLevel - 待打印的子树的根节点所处的层次
	// 返回值：插入成功返回true，失败返回false
	void PrintTheTree(ostream& os, NumFormulaNode* pStartNode = NULL, int32_t nLevel = 0);

private:
	// 函数名：InsertSubTree
	// 说明：向树中插入一个子树，该子树作为指定节点（插入点）的子树
	// 参数：
	//	[IN] pSubTree - 待插入的子树
	//	[IN] pWhere - 插入点
	//	[IN] bLeft - 待插入子树作为插入点节点的左子树标识
	// 返回值：插入成功返回true，失败返回false
	bool InsertSubTree(NumFormulaTree* pSubTree, NumFormulaNode* pWhere, const bool bLeft = true);

	// 函数名：InsertNodeAsParent
	// 说明：向树中插入一个节点，该节点作为指定节点（插入点）的子节点
	// 参数：
	//	[IN] pNode - 待插入的节点
	//	[IN] pWhere - 插入点
	//	[IN] bLeft - 待插入节点作为插入点节点的左子标识
	// 返回值：插入成功返回true，失败返回false
	bool InsertNodeAsChild(NumFormulaNode* pNode, NumFormulaNode* pWhere, const bool bLeft = true);

	// 函数名：InsertNodeAsParent
	// 说明：向树中插入一个节点，该节点作为指定节点（插入点）的父节点
	// 参数：
	//	[IN] pNode - 待插入的节点
	//	[IN] pWhere - 插入点
	//	[IN] bLeft - 插入点节点作为待插入节点的左子标识
	// 返回值：插入成功返回true，失败返回false
	bool InsertNodeAsParent(NumFormulaNode* pNode, NumFormulaNode* pWhere, const bool bLeft = true);

	// 向树中插入数值（0~9）
	void Insert_NumValue(NumFormulaNode*& pCurrNode, const int32_t nNumVal); 

	// 向树中插入“十”（“十”在中文数中可能是一个单位，也可能既有单位也有数值的功能）
	void Insert_Ten(NumFormulaNode*& pCurrNode, const int32_t nNumVal); 

	// 向树中插入单位（包括1、10、100、1000、10000、100000000等）
	void Insert_Dim(NumFormulaNode*& pCurrNode, const int32_t nDimVal); 

	// 函数名：GetNumValue
	// 说明：获取一个子树的数值（绝对值）
	// 参数：
	// 	[IN] pStartNode - 子树的根节点
	// 返回值：以pStartNode为根节点的子树代表的数值
	int32_t GetNumValue(NumFormulaNode* pStartNode);

	// 函数名：HRelease
	// 说明：释放一个以pNode为根节点的子树
	// 参数：
	//	[IN] pNode - 待释放子树的根节点
	void HRelease(NumFormulaNode* pNode);

private:
	char m_cSign;				// 正负号
	NumFormulaNode* m_pRoot;	// 根节点

	///////////////////////////////////////////////
	// Static operations and variables
public:
	// 按照默认模式初始化数值编码
	static void InitNumCodeAsDefualt();

	// 通过汉字查询数值码
	static int32_t QueryNumCode(const char* sSingleNum);

	// 通过汉字查询正负号编码
	static char QuerySign(const char* sSingleSign);

	static map<string, int> m_mapNumCode;	// 数值编码（汉字 -> 阿拉伯数字）
	static map<string, char> m_mapSign;		// 正负号编码（汉字 -> 正负号）
};

}

#endif /* _FENGYOUNG_API_NUM_FORMULA_TREE_H */



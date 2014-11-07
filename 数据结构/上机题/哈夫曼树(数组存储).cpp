#include <iostream>

using namespace std;

struct Huffman
{
	char data;
	int weight,parent,lchild,rchild;
};

//创建有n个权值的哈夫曼树，在树内开辟空间，并返回头指针
Huffman * CreateHuffmanTree(const int n);
//fst存储最小的，sec存储次小的,在前n个里面寻找
void Find(Huffman ht[],int n,int & fst,int & sec);

int main()
{
	Huffman *ht;
	int n = 0;

	cout<<"请输入有多少个权值：";
	cin>>n;
	ht = CreateHuffmanTree(n);

    cout<<"序号\t数据\t双亲\t权值\t左孩子\t右孩子\n";
	for (int i = 1;i < 2 * n;i++) {
		cout<<i<<":\t"<<ht[i].data<<"\t"
			<<ht[i].parent<<"\t"
			<<ht[i].weight<<"\t"
			<<ht[i].lchild<<"\t"
			<<ht[i].rchild<<endl;
	}

	return 0;
}

Huffman * CreateHuffmanTree(const int n)
{
	Huffman *ht = new Huffman[2 * n];//2n-1个元素，0号不用
	int i = 0;

	for (i = 1;i < 2 * n;i++) {
		ht[i].data = '#';
		ht[i].lchild = ht[i].parent = ht[i].rchild = 0;
	}

	cout<<"请依次输入字母：";
	for (i = 1;i <= n;i++) {
		cin>>ht[i].data;
	}
	cout<<"请依次输入权值：";
	for (i = 1;i <= n;i++) {
		cin>>ht[i].weight;
	}

	int fst = 0,sec = 0;
	for (i = n + 1;i < 2 * n;i++) {
		Find(ht,i - 1,fst,sec);
		ht[fst].parent = ht[sec].parent = i;//给叶节点赋父节点
		ht[i].lchild = fst;
		ht[i].rchild = sec;
		ht[i].weight = ht[fst].weight + ht[sec].weight;
	}

	return ht;
}

void Find(Huffman ht[],int n,int & fst,int & sec)
{
	int i = 0;

    for (i = 1;i <= n && ht[i].parent;i++);
    fst = i;

	for (i = fst + 1; i <= n;i++) {
		if (!ht[i].parent && ht[fst].weight > ht[i].weight) {
			fst = i;
		}
	}

	for (i = 1;(i <= n && ht[i].parent) || i == fst;i++);
	sec = i;
	
	for (i = sec + 1; i <= n;i++) {
		if (!ht[i].parent && ht[sec].weight > ht[i].weight && i != fst) {
			sec = i;
		}
	}
	
	cout<<fst<<" "<<sec<<endl;
}


#include <iostream>
#include <string>
using namespace std;
void postOrder(string preorder, string inorder);
int main() {
    cout << "请输入前序遍历序列：" << endl;
    string pre;
    string in;
    cin >> pre;
    cout << "请输入中序遍历序列：" << endl;
    cin >> in;
    cout << "得到后序遍历序列为：" << endl;
    postOrder(pre, in);
    cout << endl;
    return 0;
}

void postOrder(string preorder,string inorder) {//由先序遍历+中序遍历序列，递归实现后序遍历 (LRN)
    int len = preorder.length();
    if (len == 0)
        return;
    if (len == 1) {  //单个结点
        cout << preorder[0];
        return;
    }
    int pos = inorder.find(preorder[0]);// 查找根节点在中序序列中的位置，通过根节点划分左右子树
    // 类似于后序遍历过程
    postOrder(preorder.substr(1, pos), inorder.substr(0, pos));//后序遍历左子树
    postOrder(preorder.substr(pos + 1, len - pos - 1),
              inorder.substr(pos + 1, len - pos - 1));//后序遍历右子树，pos从0开始，所以len-pos-1
    cout << preorder[0];    //最后输出根节点
}
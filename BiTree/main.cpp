#include <iostream>
#include <string>
using namespace std;
void postOrder(string preorder, string inorder);
int main() {
    cout << "������ǰ��������У�" << endl;
    string pre;
    string in;
    cin >> pre;
    cout << "����������������У�" << endl;
    cin >> in;
    cout << "�õ������������Ϊ��" << endl;
    postOrder(pre, in);
    cout << endl;
    return 0;
}

void postOrder(string preorder,string inorder) {//���������+����������У��ݹ�ʵ�ֺ������ (LRN)
    int len = preorder.length();
    if (len == 0)
        return;
    if (len == 1) {  //�������
        cout << preorder[0];
        return;
    }
    int pos = inorder.find(preorder[0]);// ���Ҹ��ڵ������������е�λ�ã�ͨ�����ڵ㻮����������
    // �����ں����������
    postOrder(preorder.substr(1, pos), inorder.substr(0, pos));//�������������
    postOrder(preorder.substr(pos + 1, len - pos - 1),
              inorder.substr(pos + 1, len - pos - 1));//���������������pos��0��ʼ������len-pos-1
    cout << preorder[0];    //���������ڵ�
}
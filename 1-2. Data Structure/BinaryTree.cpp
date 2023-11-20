#include <iostream>

using namespace std;

//노드 구조체: 링크 표현법 
struct node {
	int data; //데이터는 저장할 데이터 형태에 따라 변경
	node* left;
	node* right;
};
//bst구조체: 
struct bst
{
	node* root = nullptr;
	node* find(int value)
	{
		return find_impl(root, value);
	}
//find impl함수
private:
	node* find_impl(node* current, int value)
	{	
		//포인터 변수는 if문에서 boolean변수로 변환되어 null pointer는 false로, non-null pointer는 true로 변환된다.
		if (!current) //null pointer라면 NULL을 반환
		{
			cout << "\n";
			return NULL; //?
		}
		//current가 가르키는 data의 값이 찾으려는 value와 값이 같은 경우
		if (current->data == value)
		{
			cout << value << "을(를) 찾았습니다." << "\n";
			return current;
		}
		if (value < current->data) // value값이 현재 노드 왼쪽에 있는 경우
		{
			cout << current->data << "에서 왼쪽으로 이동: "; //포인터가 가르키는 곳에 있는 값이 출력된다.
			return find_impl(current->left, value); //재귀적으로 작동
		}
		//value 값이 현재 노드 오른쪽에 있는 경우
		cout << current->data << "에서 오른쪽으로 이동: ";
		return find_impl(current->right, value);
	}
//insert 함수
public:
	void insert(int value)
	{
		if (!root)
			//new: 포인터 변수명 = new 타입; 으로 작성  / delete 포인터변수명; 으로 작성, root가 존재하지 않을 경우 새로운 root를 생성
			root = new node{ value, NULL, NULL };
		else
			insert_impl(root, value);
	}
private:
	void insert_impl(node* current, int value) //삽입할 곳을 찾는다, 비어있으면 삽입, 이미 다른 노드가 있다면 삽입함수 재귀 호출
	{
		if (value < current->data) //내가 가르킨 곳의 데이터보다 넣을 값이 작은 경우
		{
			if (!current->left) //비어있다면 삽입
				current->left = new node{ value, NULL, NULL };
			else //비어있지 않다면 타고 내려감(재귀)
				insert_impl(current->left, value);
		}
		else //가르킨 곳의 데이터보다 넣을 값이 큰 경우
		{
			if (!current->right) //오른쪽이 비어있다면 삽입
				current->right = new node{ value, NULL, NULL };
			else //오른쪽에 값이 있다면 타고 내려감(재귀)
				insert_impl(current->right, value);
		}
	}
//중위 순회
public:
	void inorder()
	{
		inorder_impl(root); //루트부터 탐색 시작
	}
	void preorder()
	{
		preorder_impl(root);
	}
	void postorder()
	{
		postorder_impl(root);
	}
private:
	void inorder_impl(node* start)
	{
		if (!start)
			return;
		inorder_impl(start->left); //왼쪽 서브 트리 방문
		cout << start->data << " "; //현재 노드 출력
		inorder_impl(start->right); //오른쪽 서브 트리 방문
	}
	void preorder_impl(node* start)
	{
		if (!start)
			return;
		cout << start->data << " "; //현재 노드 출력
		inorder_impl(start->left); //왼쪽 서브 트리 방문
		inorder_impl(start->right); //오른쪽 서브 트리 방문
	}
	void postorder_impl(node* start)
	{
		if (!start)
			return;
		inorder_impl(start->left); //왼쪽 서브 트리 방문
		inorder_impl(start->right); //오른쪽 서브 트리 방문
		cout << start->data << " "; //현재 노드 출력
	}
public:
	node* successor(node* start) 
		//노드 삭제 시 후속 노드를 찾는 작업: 삭제 노드보다 크지만 삭제 노드와 가장 가까운 노드 찾기.
		//현재 삭제한 노드의 오른쪽에 있는 노드 중 가장 왼쪽 노드를 찾는다.
	{
		//auto 자동 지역변수 자료형: 
		auto current = start->right; 
		while (current && current->left) //현재 포인터가 가르키는 값은 있으면서 왼쪽 노드가 존재할 경우
			current = current->left; //계속 왼쪽으로
		return current;
	}
//원소 삭제
	void deleteValue(int value)
	{
		root = delete_impl(root, value);
	}
private:
	node* delete_impl(node* start, int value)
	{
		if (!start) //못 찾은 경우 NULL
			return NULL;
		if (value < start->data) //왼쪽으로
			start->left = delete_impl(start->left, value);
		else if (value > start->data) //오른쪽으로
			start->right = delete_impl(start->right, value);
		else //현재 삭제할 노드의 오른쪽에 있는 노드 중 가장 왼쪽 노드를 찾는다.
		{      //삭제: 자식 노드 없을 때 / 자식 노드 하나 있을 때 / 자식 노드 두 개 있을 때
			if (!start->left) // 자식 노드가 전혀 없거나, 왼쪽 자식 노드가 없는 경우
			{
				auto tmp = start->right;
				delete start;
				return tmp;
			}
			if (!start->right) //오른쪽 자식 노드만 없는 경우
			{
				auto tmp = start->left;
				delete start;
				return tmp;
			}
			//자식 노드가 둘 다 있는 경우
			auto succNode = successor(start);
			start->data = succNode->data;

			//오른쪽 서브 트리에서 후속(successor)을 찾아 삭제
			start->right = delete_impl(start->right, succNode->data);
		}
		return start;
	}
};

int main()
{
	bst tree;
	tree.insert(12);
	tree.insert(10);
	tree.insert(20);
	tree.insert(8);
	tree.insert(11);
	tree.insert(15);
	tree.insert(28);
	tree.insert(4);
	tree.insert(2);

	//cout << "중위 순회: ";
	//tree.inorder(); //BST의 모든 원소를 오름차순으로 출력한다.
	//cout << "\n";
	cout << "전위 순회: ";
	tree.preorder(); //BST의 모든 원소를 오름차순으로 출력한다.
	cout << "\n";
	//cout << "후위 순회: ";
	//tree.postorder(); //BST의 모든 원소를 오름차순으로 출력한다.
	//cout << "\n";

	tree.deleteValue(12);

	//cout << "12를 삭제한 후 중위 순회: ";
	//tree.inorder(); //BST의 모든 원소를 오름차순으로 출력합니다.
	cout << "12를 삭제한 후 전위 순회: ";
	tree.preorder();
    //	cout << "12를 삭제한 후 후위 순회: ";
	//tree.postorder();
	cout << "\n";

	if (tree.find(12))
		cout << "원소 12는 트리에 있습니다." << "\n";
	else
		cout << "원소 12는 트리에 없습니다." << "\n";
}
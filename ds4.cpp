#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
int N, M;
struct node{
	int val;
	int size;
	int height;
	node* left;
	node* right;
};

node* make_node(int x) {
	node* n = new node();
	n->val = x;
	n->left = n->right = NULL;
	n->size = 1;
	n->height = 0;
	return n;
}

node* get_min(node* root){
	while(root->left != NULL)
		root = root->left;
	return root;
}

bool find(node* root, int x){
	if(root == NULL){
		return false;
	}
	else if(root->val == x){
		return true;
	}
	else if(root->val > x){
		return find(root->left, x);
	}
	else if(root->val < x){
		return find(root->right, x);
	}
	return false;
}

int height(node* root){
	if(root == NULL)return 0;
	return root->height;
}
int nsize(node* root){
	if(root == NULL)return 0;
	return root->size;
}

int get_height(node* root){
	if(root == NULL)return 0;
	return 1 + max(height(root->left), height(root->right));
}
int get_size(node* root){
	if(root == NULL)return 0;
	return 1 + (nsize(root->left) + nsize(root->right));
}

node* rot_left(node* root){
	node* r = root->right;
	root->right = root->right->left;
	r->left = root;
	root->height = get_height(root);
	root->size = get_size(root);
	r->height = get_height(r);
	r->size = get_size(r);
	return r;
}
node* rot_right(node* root){
	node* r= root->left;
	root->left = root->left->right;
	r->right = root;
	root->height = get_height(root);
	root->size = get_size(root);
	r->height = get_height(r);
	r->size = get_size(r);
	return r;
}
int diff(node* left, node* right){
	return height(left) - height(right);
}
node* insert(node* root, int x){
	if(root == NULL){
		root = make_node(x);
	}
	else if(root->val > x){
		root->left = insert(root->left, x);
	}
	else if(root->val <= x){
		root->right = insert(root->right, x);
	}
	//commence rotations
	int d = diff(root->left, root->right);
	if(d > 1){ //left side is larger
		if(height(root->left->left) >= height(root->left->right)){
			//right rot
			root = rot_right(root);
		}else{
			root->left = rot_left(root->left);
			root = rot_right(root);
		}
       	}else if(d < -1){ 
		if(height(root->right->right) >= height(root->right->left)){
			root = rot_left(root);
		}else{
			root->right = rot_right(root->right);
			root = rot_left(root);
		}
       	}
	root->height = get_height(root);
	root->size = get_size(root);
	return root;
}
node* del(node* root, int x){
	if(root == NULL)return root;
	if(root->val > x){
		root->left = del(root->left, x);
	}
	else if(root->val < x){
		root->right = del(root->right, x);
	}
	else{
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
		}
		else if(root->left == NULL){
			node* temp = root;
			root = root->right;
			delete temp;
		}else if(root->right == NULL){
			node* temp = root;
			root = root->left;
			delete temp;
		}
		else{
			node* temp = get_min(root->right);
			root->val = temp->val;
			root->right = del(root->right ,temp->val);
		}
		if(root == NULL)return root;
	}
	int d = diff(root->left, root->right);
	if(d > 1){ //left side is larger
		if(height(root->left->left) >= height(root->left->right)){
			//right rot
			root = rot_right(root);
		}else{
			root->left = rot_left(root->left);
			root = rot_right(root);
		}
       	}else if(d < -1){ 
		if(height(root->right->right) >= height(root->right->left)){
			root = rot_left(root);
		}else{
			root->right = rot_right(root->right);
			root = rot_left(root);
		}
       	}
	root->height = get_height(root);
	root->size = get_size(root);
	return root;
}
int ksmallest(int k, node* root){
	if(root == NULL)
		return -123;
	if(nsize(root->left) + 1> k){
		return ksmallest(k, root->left);
	}
	else
		if(nsize(root->left) +1 == k)return root->val;
	else
		return ksmallest(k - nsize(root->left) - 1, root->right);
}

int indexof(node* root, int x, int sum){
	if(root == NULL)return -1;
	if(root->val > x){
		return indexof(root->left, x, sum);
	}
	if(root->val < x){
		return indexof(root->right, x, sum + nsize(root->left) + 1);
	}
	if(root-> val == x){
		return sum + nsize(root->left) + 1;
	}
	return -1;
}
int at_index(node *root, int k) {
  while (root) {
    if (nsize(root->left) + 1 == k) {
      return root->val;
    } else if (k > nsize(root->left)) {
      k = k - (nsize(root->left) + 1);
      root = root->right;
    } else {
      root = root->left;
    }
  }
  return -1;
}

bool right_find(node* root, int x) {
  if (root == NULL) return false;
  if (root->val == x) return true;
  return right_find(root->right, x);
}

int index_of(node* root, int x) {
  int s = 0;
  while (root) {
    if (root->left && root->left->val == x) {
      root = root->left;
    } else if (right_find(root->left, x)) {
      s += nsize(root->left) - nsize(root->left->right);
      root = root->left->right;
    } else if (root->val == x) {
      s += nsize(root->left);
      return s;
    } else if (x < root->val) {
      root = root->left;
    } else {
      s += nsize(root->left) + 1;
      root = root->right;
    }
  }
	return -2;
}

void inorder(node* root){
	if(root == NULL)return;
	inorder(root->left);
	cout << root->val<< " ";
	inorder(root->right);
}
int main(){
	//cin.tie(0);
	//cin.sync_with_stdio(0);
	cin >> N >> M;
	node* root = NULL;
	int a;
	for(int i = 0; i < N; i++){
		cin >> a;
		root = insert(root, a);
	}
	char op;
	int v, ans = 0;
	for(int i = 0; i < M; i++){
		cin >> op >> v;
		v = v^ ans;
		if(op =='I')
			root = insert(root, v);
		if(op == 'R')
			root = del(root, v);
		if(op == 'S'){
			ans = ksmallest(v, root);
			cout << ans <<'\n';
		}
		if(op == 'L'){
			ans = index_of(root, v) + 1;
			cout << ans << '\n';
		}
	}
	inorder(root);
	
}
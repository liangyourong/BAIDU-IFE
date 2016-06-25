#include<stdio.h>
#include<stdlib.h>
#define ERROR {puts("Error");return(1);}
// ERROR用于处理程序的运行错误
typedef struct BiTNode  // 二叉树要用的结构体
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
BiTree Create()  // 创建二叉树
{
	char ch;
	BiTree T;
	ch=getchar();
	if( ch == '#' )
		T=NULL;
	else
	{
		if( ! ( T = (BiTNode * )malloc( sizeof( BiTNode ) ) ) )
			exit( 0 );
		T->data = ch;
		T->lchild = Create();
		T->rchild = Create();
	}
	return T;
}
int preorder( BiTree T )  // 先序遍历二叉树
{
	if( T )
	{
		printf( "%c" , T->data );
		if( preorder( T->lchild ) )ERROR
			if( preorder( T->rchild ) )ERROR
	}
	return 0;
}
int inorder( BiTree T )  // 中序遍历二叉树
{
	if( T )
	{
		if( preorder( T->lchild ) )ERROR
			printf( "%c" , T->data );
		if( preorder( T->rchild ) )ERROR
	}
	return 0;
}
int postorder( BiTree T )  // 后序遍历二叉树
{
	if( T )
	{
		if( preorder( T->lchild ) )ERROR
			if( preorder( T->rchild ) )ERROR
				printf( "%c" , T->data );
	}
	return 0;
}
int sumleaf( BiTree T )  // 求二叉树叶子数
{
	if( ! T )
		return 0;
	else
		if( T->lchild || T->rchild )
			return( sumleaf( T->lchild ) + sumleaf( T->rchild ) );
		else
			return 1;
}
int themax( int a, int b )  // 返回两个整数中较大的一个
{
	if( a>b )
		return a;
	else 
		return b;
}
int Depth( BiTree T )  // 求二叉树的深度
{
	if( !T )
		return 0;
	else
		return( 1 + themax( Depth( T->lchild ), Depth( T->rchild ) ) );
}
bool bebalance(BiTNode *root)
{
	if(root==NULL)
		return true;
	int ld=Depth(root->lchild);
	int lr=Depth(root->rchild);
	int di=abs(ld-lr);
	if(di>1)                 //根节点平衡
		return false;
	return bebalance(root->lchild)&&bebalance(root->rchild);  //左右子树平衡
}
int main( int argc , char *argv[] )  // 测试用的主函数
{
	BiTree T=Create();  // 创建树
	{ // 先序遍历
		printf("先序遍历:");
		if( preorder( T ) )
		{
			puts("ERROE!");
			return 0;
		}
		else
			printf("\n");
	} // End_preorder. 
	{ // 中序遍历
		printf("中序遍历:");
		if( inorder( T ) )
		{
			puts("ERROE!");
			return 0;
		}
		else
			printf("\n");
	} // End_inorder. 
	{ // 后序遍历
		printf("后序遍历:");
		if( postorder( T ) )
		{
			puts("ERROE!");
			return 0;
		}
		else
			printf("\n");
	} // End_postorder. 
	printf( "The tree has %d leaves.\n" , sumleaf( T ) );   // 算叶子数 
	printf( "The Depth of the tree is %d.\n" , Depth( T ) );  // 求树的深度 system( "pause" );
	if(bebalance(T))
		printf("the tree is balanced\n");
	else
		printf("the tree is unbalanced\n");
	return 0;
}
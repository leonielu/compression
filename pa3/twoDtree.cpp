
/**
 *
 * twoDtree (pa3)
 * slight modification of a Kd tree of dimension 2.
 * twoDtree.cpp
 * This file will be used for grading.
 *
 */

#include "twoDtree.h"

/* given */
twoDtree::Node::Node(pair<int,int> ul, pair<int,int> lr, RGBAPixel a)
	:upLeft(ul),lowRight(lr),avg(a),left(NULL),right(NULL)
	{}

/* given */
twoDtree::~twoDtree(){
	clear();
}

/* given */
twoDtree::twoDtree(const twoDtree & other) {
	copy(other);
}

/* given */
twoDtree & twoDtree::operator=(const twoDtree & rhs){
	if (this != &rhs) {
		clear();
		copy(rhs);
	}
	return *this;
}
/**
    * Constructor that builds a twoDtree out of the given PNG.
    * Every leaf in the tree corresponds to a pixel in the PNG.
    * Every non-leaf node corresponds to a rectangle of pixels 
    * in the original PNG, represented by an (x,y) pair for the 
    * upper left corner of the rectangle and an (x,y) pair for 
    * lower right corner of the rectangle. In addition, the Node
    * stores a pixel representing the average color over the 
    * rectangle. 
    *
    * Every node's left and right children correspond to a partition
    * of the node's rectangle into two smaller rectangles. The node's
    * rectangle is split by the horizontal or vertical line that 
    * results in the two smaller rectangles whose sum of squared 
    * differences from their mean is as small as possible.
    *
    * The left child of the node will contain the upper left corner
    * of the node's rectangle, and the right child will contain the
    * lower right corner.
    *
   * This function will build the stats object used to score the 
   * splitting lines. It will also call helper function buildTree.
    */
// twoDtree::twoDtree(PNG & imIn){ 
//     int width = imIn.width();
//     int height = imIn.height();
//     stats my_stat = stats(imIn);
//     pair<int,int> ul = make_pair(0,0);
//     pair<int,int> lr = make_pair(width-1,height-1);
//     int x1= ul.first;
//     int y1= ul.second;
//     int x2 = lr.first;
//     int y2 = lr.second;
    

//     root = buildTree(my_stat,ul,lr);
//     }


/**
   * Private helper function for the constructor. Recursively builds
   * the tree according to the specification of the constructor.
   * @param s Contains the data used to split the rectangles
   * @param ul upper left point of current node's rectangle.
   * @param lr lower right point of current node's rectangle.
   */
// twoDtree::Node * twoDtree::buildTree(stats & s, pair<int,int> ul, pair<int,int> lr) {
// 	/* your code here */

// 	//horizontal
// 	int x1= ul.first;
// 	int y1= ul.second;

// 	int x2= lr.first;
// 	int y2= lr.second;
	
// 	if(x1==x2&&y1==y2){
// 		return new Node(ul,lr,s.getAvg(ul,lr));
// 	}

// 	Node* currentNode =  new Node(ul,lr,s.getAvg(ul,lr));
// 	// std::cout<< "node upper left: ("<<currentNode->upLeft.first<<", "<<currentNode->upLeft.second<<")  "<<
// 	//          "node lower right: ("<<currentNode->lowRight.first<<", "<<currentNode->lowRight.second<<")  " <<std::endl;
	
// 	// std::cout<< "****************************************************************"<<std::endl;

// 	int newX= 0;
// 	int newY= 0;

// 	long sumScoreHorzontal=	9223372036854775807;
// 	long sumScoreVertical=	9223372036854775807;

// //horizontal
// 	for (int i=0;i<y2-y1;i++){
// 		long temp= s.getScore(ul,make_pair(x2,y1+i)) + s.getScore(make_pair(x1,y1+i+1),lr);
		
// 		if (temp<sumScoreHorzontal){
// 			sumScoreHorzontal= temp;
// 			newY=y1+i;
// 		}
// 	}
// //vertical 

// 	for (int j=0;j<x2-x1;j++){
		
// 		long temp= s.getScore(ul,make_pair(x1+j,y2)) + s.getScore(make_pair(x1+j+1,y1),lr);
// 		if (temp<sumScoreVertical){
// 			sumScoreVertical= temp;
// 			newX=x1+j;
// 		}	
// 	} 
	
// 	pair<int,int> newLR=ul;
//     pair<int,int> newUL=lr;
	
// 	if(sumScoreHorzontal<sumScoreVertical){
// 		//lr is (x2,newY) ul is(x1,newY+1) //take horizontal 
// 		 newLR=make_pair (x2,newY);
// 		 newUL=make_pair (x1,newY+1);
		
// 	} else{
// 		//lr is (newX,y2) ul is(newX+1,y1)
// 		newLR=make_pair (newX,y2);
// 		newUL=make_pair (newX+1,y1);
// 	} 

// 	 currentNode->left = buildTree(s,  ul, newLR);
// 	 currentNode->right = buildTree(s, newUL, lr);

// 	 return currentNode;
// }


twoDtree::twoDtree(PNG & imIn){
    /* your code here */
    height= imIn.height();
    width= imIn.width();
    
	//std::cout<< "width : "<<height <<std::endl;
	//std::cout<< "height : "<<width <<std::endl;

    stats mystats=stats(imIn);
    pair<int,int> pair0=make_pair (0,0);
    pair<int,int> pair1=make_pair (width-1,height-1);
   
    
    root=buildTree(mystats, pair0, pair1);
    
    
}



twoDtree::Node * twoDtree::buildTree(stats & s, pair<int,int> ul, pair<int,int> lr) {
	/* your code here */

	//horizontal
	int x1= ul.first;
	int y1= ul.second;

	int x2= lr.first;
	int y2= lr.second;
	
	if(x1==x2&&y1==y2){
		return new Node(ul,lr,s.getAvg(ul,lr));
	}

	Node* currentNode =  new Node(ul,lr,s.getAvg(ul,lr));
	// std::cout<< "node upper left: ("<<currentNode->upLeft.first<<", "<<currentNode->upLeft.second<<")  "<<
	//          "node lower right: ("<<currentNode->lowRight.first<<", "<<currentNode->lowRight.second<<")  " <<std::endl;
	
	// std::cout<< "******************************************************************"<<std::endl;

	int newX= 0;
	int newY= 0;

	long sumScoreHorzontal=	9223372036854775807;
	long sumScoreVertical=	9223372036854775807;

//horizontal
	for (int i=0;i<y2-y1;i++){
		long temp= s.getScore(ul,make_pair(x2,y1+i)) + s.getScore(make_pair(x1,y1+i+1),lr);
		
		if (temp<sumScoreHorzontal){
			sumScoreHorzontal= temp;
			newY=y1+i;
		}
	}
//vertical 

	for (int j=0;j<x2-x1;j++){
		
		long temp= s.getScore(ul,make_pair(x1+j,y2)) + s.getScore(make_pair(x1+j+1,y1),lr);
		if (temp<sumScoreVertical){
			sumScoreVertical= temp;
			newX=x1+j;
		}	
	} 
	
	pair<int,int> newLR=ul;
    pair<int,int> newUL=lr;
	
	if(sumScoreHorzontal<=sumScoreVertical){
		//lr is (x2,newY) ul is(x1,newY+1) //take horizontal 
		 newLR=make_pair (x2,newY);
		 newUL=make_pair (x1,newY+1);
		
	} else{
		//lr is (newX,y2) ul is(newX+1,y1)
		newLR=make_pair (newX,y2);
		newUL=make_pair (newX+1,y1);
	} 

	 currentNode->left = buildTree(s,  ul, newLR);
	 currentNode->right = buildTree(s, newUL, lr);

	 return currentNode;
}





 /**
    * Render returns a PNG image consisting of the pixels
    * stored in the tree. may be used on pruned trees. Draws
    * every leaf node's rectangle onto a PNG canvas using the 
    * average color stored in the node.
    */
// PNG twoDtree::render(){
// 	/* your code here */
   

// }


PNG twoDtree::render(){
	/* your code here */
	PNG im= PNG(width,height);

	renderTree(im, root);

	return im;
}


void twoDtree::renderTree(PNG & im, Node* croot){
	//std::cout<<"in render helper? "<<std::endl; 
	if (!croot)
        return;
     
    // if node is leaf node, set pixel
    if (!croot->left && !croot->right)
	{  
		//std::cout<<"goto leaf? "<<std::endl; 
		pair<int,int> ul=croot->upLeft; 
        pair<int,int> lr= croot->lowRight;

	 for (int y = ul.second; y <= lr.second; y++) {
        for (int x = ul.first; x <= lr.first; x++) {
	
	
            *im.getPixel(x,y)=croot->avg;
        }
    }
        return;
    }
	
    // if left child exists, check for leaf 
       renderTree(im, croot->left);
    // if right child exists, check for leaf 
       renderTree(im, croot->right);
    
    }

/*
    *  Prune function trims subtrees as high as possible in the tree.
    *  A subtree is pruned (cleared) if at least pct of its leaves are within 
    *  tol of the average color stored in the root of the subtree. 
    *  Pruning criteria should be evaluated on the original tree, not 
    *  on a pruned subtree. (we only expect that trees would be pruned once.)
    *  
   * You may want a recursive helper function for this one.
    */
void twoDtree::prune(double pct, int tol){
	/* your code here */
    pruneHelper(pct,tol,root);
    


}

void twoDtree::pruneHelper(double pct, int tol, Node * node){
    RGBAPixel a = node->avg;
    int leaves = getLeafCount(node);
    // prune the tree
    if (getPercent(node,a,leaves,tol)>=pct){
         clearTree(node->left);
         clearTree(node->right);
        node->left = NULL;
        node->right = NULL;
    }
    else {
        pruneHelper(pct,tol,node->left);
        pruneHelper(pct,tol,node->right);
    }
}

int twoDtree::getLeafCount(Node * node)
{
  if(node == NULL)       
    return 0;
  if(node->left == NULL && node->right==NULL)      
    return 1;            
  else
    return getLeafCount(node->left)+
           getLeafCount(node->right);      
}

double twoDtree::getPercent(Node * node, RGBAPixel a, int leaves, int tol){
    int count = 0;
    if (node == NULL) return (double) count/leaves;
    // it's a leaf node
    if (node->left == NULL && node->right == NULL){
        //d = (r - r')^2 + (g - g')^2 + (b - b')^2
        double variance = (node->avg.r-a.r)*(node->avg.r-a.r) + (node->avg.g-a.g)*(node->avg.g-a.g) + (node->avg.b-a.b)*(node->avg.b-a.b);
        if (variance<=tol){
            count++;
        }
        return  (double)count/(double)leaves;
    }
    else{
        return getPercent(node->left, a, leaves,tol) + getPercent(node->right,a,leaves,tol);
    }

}
/**
    * Destroys all dynamically allocated memory associated with the
    * current twoDtree class. Complete for PA3.
   * You may want a recursive helper function for this one.
    */
void twoDtree::clear() {
	/* your code here */
	clearTree(root);
}

void twoDtree::clearTree(Node *croot){
	if(croot==NULL)
		return;
	
	clearTree(croot->left);
	clearTree(croot->right);
	if(croot->left!=NULL) croot->left=NULL;
	if(croot->right!=NULL) croot->right=NULL;		
	delete(croot);
	croot=NULL;
	
 }
/**
   * Copies the parameter other twoDtree into the current twoDtree.
   * Does not free any memory. Called by copy constructor and op=.
   * You may want a recursive helper function for this one.
   * @param other The twoDtree to be copied.
   */
// void twoDtree::copy(const twoDtree & orig){
//        height = orig.height; 
//        width = orig.width; 

//        // preorder: vist, left, right
//        root = helper(orig.root);

       
      
// }

// twoDtree::Node * twoDtree::helper(Node * newroot){
//     if (newroot == NULL) return NULL;

//     root = new Node(newroot->upLeft, newroot->lowRight, newroot->avg);

//     root->left = helper(newroot->left);
//     root->right = helper(newroot->right);
//     return root;

// }

void twoDtree::copy(const twoDtree & orig){
	/* your code here */
	Node* original = orig.root;
	height= orig.height;
	width= orig.width;

	root= copyTree(original);
}

twoDtree::Node * twoDtree:: twoDtree::copyTree(Node* original){

	 Node* new_root;
     if(original!=NULL){
         new_root=new Node(original->upLeft,original->lowRight,original->avg);
         new_root->left=copyTree(original->left);
         new_root->right=copyTree(original->right);
     } 
	 else return NULL;
     return new_root;
} //end copyTree 

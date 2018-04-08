
// File:        main.cpp
// Author:      cheeren
// Date:        2018-02-25
// Description: Partial test of PA3 functionality
//              Reads Point data from external files
//              Produces PNG images of the point sets


#include "twoDtree.h"
#include "cs221util/RGBAPixel.h"
#include "cs221util/PNG.h"

using namespace cs221util;
using namespace std;



int main()
{

	// read in image
	PNG origIm1;
	origIm1.readFromFile("images/stanley-totem-poles.png");
	PNG origIm2;
	origIm2.readFromFile("images/ubc-totem-poles.png");
	PNG origIm3;
	origIm3.readFromFile("images/remb.png");
	PNG origIm4;
	origIm4.readFromFile("images/rosa.png");

	
   
//    stats mystats=stats(origIm1);
//     // cout<<"red"<<endl;
//     // cout<<(int)origIm1.getPixel(0,0)->r<<endl;
// 	// cout<<(int)origIm1.getPixel(0,1)->r<<endl;
// 	// cout<<(int)origIm1.getPixel(1,0)->r<<endl;
// 	// cout<<(int)origIm1.getPixel(1,1)->r<<endl;
// 	// cout<<"green"<<endl;
// 	// cout<<(int)origIm1.getPixel(0,0)->g<<endl;
// 	// cout<<(int)origIm1.getPixel(0,1)->g<<endl;
// 	// cout<<(int)origIm1.getPixel(1,0)->g<<endl;
// 	// cout<<(int)origIm1.getPixel(1,1)->g<<endl;
// 	// cout<<"blue"<<endl;
// 	// cout<<(int)origIm1.getPixel(0,0)->b<<endl;
// 	// cout<<(int)origIm1.getPixel(0,1)->b<<endl;
// 	// cout<<(int)origIm1.getPixel(1,0)->b<<endl;
// 	// cout<<(int)origIm1.getPixel(1,1)->b<<endl;

// cout<<(int)origIm1.getPixel(1,1)->r<<endl;
// cout<<(int)origIm1.getPixel(1,2)->r<<endl;
// cout<<(int)origIm1.getPixel(2,1)->r<<endl;
// cout<<(int)origIm1.getPixel(2,2)->r<<endl;
// cout<<(int)origIm1.getPixel(1,1)->g<<endl;
// cout<<(int)origIm1.getPixel(1,2)->g<<endl;
// cout<<(int)origIm1.getPixel(2,1)->g<<endl;
// cout<<(int)origIm1.getPixel(2,2)->g<<endl;
// cout<<(int)origIm1.getPixel(1,1)->b<<endl;
// cout<<(int)origIm1.getPixel(1,2)->b<<endl;
// cout<<(int)origIm1.getPixel(2,1)->b<<endl;
// cout<<(int)origIm1.getPixel(2,2)->b<<endl;

// pair<int,int> pair0 = make_pair (1,0);
// pair<int,int> pair1 = make_pair(3,4);


//    long myArea=mystats.rectArea(pair0, pair1);
//    std::cout<< "myRecArea :"<< myArea<< "  ||expected : "<<std::endl;
   
//     //RGBAPixel myAvg=mystats.getSum('r',pair0, pair1);
//     int  mySumRed=mystats.getSum('r',pair0, pair1);
//     int  mySumGreen=mystats.getSum('g',pair0, pair1);
//     int  mySumBlue=mystats.getSum('b',pair0, pair1);
//     std::cout<< "my sum Red :"<< mySumRed<<"  ||expected :  576  "<<std::endl;
//     std::cout<< "my sum Green :"<< mySumGreen<<"  ||expected : 632  "<<std::endl;
//     std::cout<< "my sum Blue :"<< mySumBlue<<"  ||expected : 736   " <<std::endl;

// 	 int  mySumRedsq=mystats.getSumSq('r',pair0, pair1);
//     int  mySumGreensq=mystats.getSumSq('g',pair0, pair1);
//     int  mySumBluesq=mystats.getSumSq('b',pair0, pair1);
//     std::cout<< "my sum Red^2:"<< mySumRedsq<<"  ||expected :  82948  "<<std::endl;
//     std::cout<< "my sum Green^2:"<< mySumGreensq<<"  ||expected : 99860  "<<std::endl;
//     std::cout<< "my sum Blue^2:"<< mySumBluesq<<"  ||expected : 135428   " <<std::endl;

// 	RGBAPixel myAvg=mystats.getAvg(pair0, pair1);
//     int  myAvgRed=myAvg.r;
//     int  myAvgGreen=myAvg.g;
//     int  myAvgBlue=myAvg.b;
//     std::cout<< "myAvg Red :"<< myAvgRed<<"  ||expected :    "<<std::endl;
//     std::cout<< "myAvg Green :"<< myAvgGreen<<"  ||expected :    "<<std::endl;
//     std::cout<< "myAvg Blue :"<< myAvgBlue<<"  ||expected :    "<<std::endl;


// 	long myScore=mystats.getScore(pair0, pair1);
//     std::cout<< "myScore :"<< myScore<<"  ||expected : 12   "<<std::endl;
    




// 	for (int x=1; x<3;x++){
// 		for (int y=1;  y<3;y++){
// 			cout<<(int)mystats.sumRed[x][y]<<endl;
// 		}
// 	}

	

	// cout<<origImq.getPixel(0,0)->r<<endl;
	// cout<<origImq.getPixel(0,0)->r<<endl;
	// cout<<origImq.getPixel(0,0)->r<<endl;
	// cout<<origImq.getPixel(0,0)->r<<endl;
	// cout<<origImq.getPixel(0,0)->r<<endl;

    // pair<int,int> p0 = make_pair (0,0);
	// pair<int,int> p1 = make_pair(0,1);
	// pair<int,int> p2 = make_pair(0,2);
	// pair<int,int> p3 = make_pair(1,0);
	// pair<int,int> p4 = make_pair(1,1);
	// pair<int,int> p5 = make_pair(1,2);
	// pair<int,int> p6 = make_pair(2,0);
	// pair<int,int> p7 = make_pair(2,1);
	// pair<int,int> p8 = make_pair(2,2);


	
	
	

    
    //int myScore=0;
	
    
    // long myArea=mystats.rectArea(pair0, pair1);
    // std::cout<< "myRecArea :"<< myArea<< "  ||expected : 100"<<std::endl;
    
    // long myScore=mystats.getScore(pair0, pair1);
    // std::cout<< "myScore :"<< myScore<<"  ||expected :    "<<std::endl;
    
    // RGBAPixel myAvg=mystats.getAvg(pair0, pair1);
    // int  myAvgRed=myAvg.r;
    // int  myAvgGreen=myAvg.g;
    // int  myAvgBlue=myAvg.b;
    // std::cout<< "myAvg Red :"<< myAvgRed<<"  ||expected :    "<<std::endl;
    // std::cout<< "myAvg Green :"<< myAvgGreen<<"  ||expected :    "<<std::endl;
    // std::cout<< "myAvg Blue :"<< myAvgBlue<<"  ||expected :    "<<std::endl;
    
    
    // long mySumRed=mystats.getSum('r',pair0, pair1);
    // std::cout<< "mySumRed :"<< mySumRed<< "  ||expected : "<<std::endl;

	


	// use it to build a twoDtree
	twoDtree t1(origIm1);
	cout<<t1.width<<endl;
	cout<<t1.height<<endl;
	twoDtree tCopy1(t1);
    twoDtree t2(origIm2);
    twoDtree tCopy2(t2);
	twoDtree t3(origIm3);
	twoDtree tCopy3(t3);
	twoDtree t4(origIm4);
	twoDtree tCopy4(t4);
	cout<<t1.width<<endl;
	cout<<tCopy1.width<<endl;



	

	// prune the twoDtree
	// where at least 100*X% of pixels are within Y of mean
	tCopy1.prune(0.95, 10000); 
    tCopy2.prune(0.95, 10000); 
	tCopy3.prune(0.95, 3000); 
	tCopy4.prune(0.95, 3000); 
	
	//render the twoDtree
	PNG ppic1 = tCopy1.render();
    PNG ppic2 = tCopy2.render();
    PNG ppic3 = tCopy3.render();
	PNG ppic4 = tCopy4.render();

	

	ppic1.writeToFile("images/prunedstanleytotem.png");
	ppic2.writeToFile("images/prunedubctotem.png");
	ppic3.writeToFile("images/prunedremb.png");
	ppic4.writeToFile("images/prunedrosa.png");






  return 0;
}


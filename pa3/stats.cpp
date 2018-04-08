#include "stats.h"
#include <cmath>
#include <stdio.h>      
#include <stdlib.h>    
#include <cstdlib>




// vector< vector< long >> sumRed;
// 	vector< vector< long >> sumGreen;
// 	vector< vector< long >> sumBlue;
// 	vector< vector< long >> sumsqRed;
// 	vector< vector< long >> sumsqGreen;
// 	vector< vector< long >> sumsqBlue;

// private helper
/* returns the sums of all pixel values across given color channel.
	* useful in computing the score of a rectangle
	* PA3 function
	* @param channel is one of r, g, or b
	* @param ul is (x,y) of the upper left corner of the rectangle 
	* @param lr is (x,y) of the lower right corner of the rectangle */
	long stats::getSum(char channel, pair<int,int> ul, pair<int,int> lr){
	long sum = 0;
	int x1 = ul.first;
    int y1 = ul.second;
    int x2 = lr.first;
    int y2 = lr.second;
    //cout<<abs(x1-1,0)<<endl;
    //cout<<min(y2-1,0)<<endl;

			if (channel == 'r'){
                if (x1==0&&y1==0) sum = sumRed[x2][y2];
                else if (x1==0) sum = sumRed[x2][y2] - sumRed[x2][y1-1];
                else if (y1==0) sum = sumRed[x2][y2]-sumRed[x1-1][y2];
                else 
                sum = sumRed[x2][y2]-sumRed[x1-1][y2]-sumRed[x2][y1-1]+sumRed[x1-1][y1-1];
                
            }
            else if (channel == 'g'){
                if (x1==0&&y1==0) sum = sumGreen[x2][y2];
                else if (x1==0) sum = sumGreen[x2][y2] - sumGreen[x2][y1-1];
                else if (y1==0) sum = sumGreen[x2][y2]-sumGreen[x1-1][y2];
                else sum = sumGreen[x2][y2]-sumGreen[x1-1][y2]-sumGreen[x2][y1-1]+sumGreen[x1-1][y1-1];
            }
            else{
                if (x1==0&&y1==0) sum = sumBlue[x2][y2];
                else if (x1==0) sum = sumBlue[x2][y2] - sumBlue[x2][y1-1];
                else if (y1==0) sum = sumBlue[x2][y2]-sumBlue[x1-1][y2];
                else sum = sumBlue[x2][y2]-sumBlue[x1-1][y2]-sumBlue[x2][y1-1]+sumBlue[x1-1][y1-1];
            }
            
	return sum;
	}



// long stats::getSum(char channel, pair<int,int> ul, pair<int,int> lr){
//     long result=0;
    
//     int ux=ul.first;
//     int uy=ul.second;
//     int lx=lr.first;
//     int ly=lr.second;
    
//     if (ux==0 && uy==0){
//         if(channel=='r')
//             result= sumRed[ly][lx];
//         if(channel=='g')
//             result= sumGreen[ly][lx];
//         if(channel=='b')
//             result= sumBlue[ly][lx];
        
//         return result;
//     }
    
//     if (ux==0 && uy!=0){
//         if(channel=='r')
//             result= sumRed[ly][lx]-sumRed[uy-1][lx];
//         if(channel=='g')
//             result= sumGreen[ly][lx]-sumGreen[uy-1][lx];
//         if(channel=='b')
//             result= sumBlue[ly][lx]-sumBlue[uy-1][lx];
        
//         return result;
//     }
    
//     if (ux!=0 && uy==0){
//         if(channel=='r')
//             result= sumRed[ly][lx]-sumRed[ly][ux-1];
//         if(channel=='g')
//             result= sumGreen[ly][lx]-sumGreen[ly][ux-1];
//         if(channel=='b')
//             result= sumBlue[ly][lx]-sumBlue[ly][ux-1];
        
//         return result;
//     }
    
//     //handle cases
//     if(channel=='r')
//         result= sumRed[ly][lx]-sumRed[uy-1][lx]-sumRed[ly][ux-1]+sumRed[uy-1][ux-1];
//     if(channel=='g')
//         result= sumGreen[ly][lx]-sumGreen[uy-1][lx]-sumGreen[ly][ux-1]+sumGreen[uy-1][ux-1];
//     if(channel=='b')
//         result= sumBlue[ly][lx]-sumBlue[uy-1][lx]-sumBlue[ly][ux-1]+sumBlue[uy-1][ux-1];
    
//     return result;
// }


    // private helper
	/* returns the sums of squares of all pixel values a
    cross all color channels.
	* useful in computing the score of a rectangle
	* PA3 function
	* @param channel is one of r, g, or b
	* @param ul is (x,y) of the upper left corner of the rectangle 
	* @param lr is (x,y) of the lower right corner of the rectangle */
	long stats::getSumSq(char channel, pair<int,int> ul, pair<int,int> lr){
        long sum = 0;
	int x1 = ul.first;
    int y1 = ul.second;
    int x2 = lr.first;
    int y2 = lr.second;
        if (channel == 'r'){
                if (x1==0&&y1==0) sum = sumsqRed[x2][y2];
                else if (x1==0) sum = sumsqRed[x2][y2] - sumsqRed[x2][y1-1];
                else if (y1==0) sum = sumsqRed[x2][y2]-sumsqRed[x1-1][y2];
                else 
                sum = sumsqRed[x2][y2]-sumsqRed[x1-1][y2]-sumsqRed[x2][y1-1]+sumsqRed[x1-1][y1-1];
                
            }
            else if (channel == 'g'){
                if (x1==0&&y1==0) sum = sumsqGreen[x2][y2];
                else if (x1==0) sum = sumsqGreen[x2][y2] - sumsqGreen[x2][y1-1];
                else if (y1==0) sum = sumsqGreen[x2][y2]-sumsqGreen[x1-1][y2];
                else sum = sumsqGreen[x2][y2]-sumsqGreen[x1-1][y2]-sumsqGreen[x2][y1-1]+sumsqGreen[x1-1][y1-1];
            }
            else{
                if (x1==0&&y1==0) sum = sumsqBlue[x2][y2];
                else if (x1==0) sum = sumsqBlue[x2][y2] - sumsqBlue[x2][y1-1];
                else if (y1==0) sum = sumsqBlue[x2][y2]-sumsqBlue[x1-1][y2];
                else sum = sumsqBlue[x2][y2]-sumsqBlue[x1-1][y2]-sumsqBlue[x2][y1-1]+sumsqBlue[x1-1][y1-1];
            }
		return sum;
	}

    // constructor
	// initialize the private vectors so that, for each color,  entry 
	// (x,y) is the cumulative sum of the the color values from (0,0)
	// to (x,y). Similarly, the sumSq vectors are the cumulative
	// sum of squares from (0,0) to (x,y).
	stats::stats(PNG & im){
	int width = (int)im.width();
	int height = (int)im.height();
	sumRed = vector< vector < long > > (width, vector <long> (height));

    sumGreen = vector< vector < long > > (width, vector <long> (height));
    
    sumBlue = vector< vector < long > > (width, vector <long> (height));
    sumsqRed = vector< vector < long > > (width, vector <long> (height));
    sumsqGreen= vector< vector < long > > (width, vector <long> (height));
    sumsqBlue = vector< vector < long > > (width, vector <long> (height));


    
	for (int i = 0; i<width; i++){
		for (int j=0; j<height;j++){
            // initialize the entry at (width i, height j)
            long r = (long)(im.getPixel(i,j)->r);
            long g = (long)(im.getPixel(i,j)->g);
            long b = (long)(im.getPixel(i,j)->b);
    
            if (i==0&&j==0){
                sumRed[0][0] = r;
                sumGreen[0][0] = g;
                sumBlue[0][0] = b;
                sumsqRed[0][0] = r*r;
                sumsqGreen[0][0] = g*g;
                sumsqBlue[0][0] = b*b;
            }
            else if (i==0){
                sumRed[i][j] = sumRed[i][j-1]+r;
                sumGreen[i][j] = sumGreen[i][j-1] + g;
                sumBlue[i][j] = sumBlue[i][j-1] + b;
                sumsqRed[i][j] = sumsqRed[i][j-1] + r*r;
                sumsqGreen[i][j] = sumsqGreen[i][j-1] + g*g;
                sumsqBlue[i][j] = sumsqBlue[i][j-1] + b*b;
            }
            else if (j==0){
                sumRed[i][j] = sumRed[i-1][j]+r;
                sumGreen[i][j] = sumGreen[i-1][j] + g;
                sumBlue[i][j] = sumBlue[i-1][j] + b;
                sumsqRed[i][j] = sumsqRed[i-1][j] + r*r;
                sumsqGreen[i][j] = sumsqGreen[i-1][j] + g*g;
                sumsqBlue[i][j] = sumsqBlue[i-1][j] + b*b;
            }

    
            // normally
            else{
                sumRed[i][j] = r + sumRed[i][j-1]+sumRed[i-1][j]-sumRed[i-1][j-1];;
                sumGreen[i][j] = g + sumGreen[i][j-1]+sumGreen[i-1][j]-sumGreen[i-1][j-1];
                sumBlue[i][j] = b + sumBlue[i][j-1]+sumBlue[i-1][j]-sumBlue[i-1][j-1];
                sumsqRed[i][j] = r*r + sumsqRed[i][j-1]+sumsqRed[i-1][j]-sumsqRed[i-1][j-1];
                sumsqGreen[i][j] = g*g + sumsqGreen[i][j-1]+sumsqGreen[i-1][j]-sumsqGreen[i-1][j-1];
                sumsqBlue[i][j] = b*b + sumsqBlue[i][j-1]+sumsqBlue[i-1][j]-sumsqBlue[i-1][j-1];

                }

		}
	}
	}
//     stats::stats(PNG & im){
//     int width=im.width();
//     int height=im.height();
    
//     sumRed = vector< vector < long > > (height, vector <long> (width));
//     sumBlue= vector< vector < long > > (height, vector <long> (width));
//     sumGreen= vector< vector < long > > (height, vector <long> (width));
    
//     sumsqRed = vector< vector < long > > (height, vector <long> (width));
//     sumsqBlue= vector< vector < long > > (height, vector <long> (width));
//     sumsqGreen= vector< vector < long > > (height, vector <long> (width));
    
//     RGBAPixel* origion= im.getPixel(0,0);
    
//     sumRed[0][0]=origion->r;
//     sumGreen[0][0]=origion->g;
//     sumBlue[0][0]=origion->b;
    
//     sumsqRed[0][0]=(origion->r)*(origion->r);
//     sumsqGreen[0][0]=(origion->g)*(origion->g);
//     sumsqBlue[0][0]=(origion->b)*(origion->b);
    
//     for (int y=1; y<height-1;y++){
//         for (int x=1;x<width-1;x++){ //now the pixel is(x,y)
//             RGBAPixel* temp= im.getPixel(x,y);
//              sumRed[y][x]=temp->r+sumRed[y][x-1]+sumRed[y-1][x]-sumRed[y-1][x-1];
//              sumGreen[y][x]=temp->g+sumGreen[y][x-1]+sumGreen[y-1][x]-sumGreen[y-1][x-1];
//              sumBlue[y][x]=temp->b+sumBlue[y][x-1]+sumBlue[y-1][x]-sumBlue[y-1][x-1];
            
//             sumsqRed[y][x]=(temp->r)*(temp->r)+sumRed[y][x-1]+sumRed[y-1][x]-sumRed[y-1][x-1];
//             sumsqGreen[y][x]=(temp->g)*(temp->g)+sumGreen[y][x-1]+sumGreen[y-1][x]-sumGreen[y-1][x-1];
//             sumsqBlue[y][x]=(temp->b)*(temp->b)+sumBlue[y][x-1]+sumBlue[y-1][x]-sumBlue[y-1][x-1];
//         }
//     }
    
// }

	// given a rectangle, compute its sum of squared deviations from 
    // mean, over all color channels. Will be used to make split when
	// building tree.
	/* @param ul is (x,y) of the upper left corner of the rectangle 
	* @param lr is (x,y) of the lower right corner of the rectangle */
	long stats::getScore(pair<int,int> ul, pair<int,int> lr){
    int area = rectArea(ul,lr);

    //RGBAPixel average_pixel = getAvg(ul,lr);
    long var_r = getSumSq('r',ul,lr) - getSum('r',ul,lr)*getSum('r',ul,lr)/area;
    long var_g = getSumSq('g',ul,lr) - getSum('g',ul,lr)*getSum('g',ul,lr)/area;
    long var_b = getSumSq('b',ul,lr) - getSum('b',ul,lr)*getSum('b',ul,lr)/area;
    return var_r + var_g + var_b;



	}

	// given a rectangle, return the average color value over the 
	// rectangle as a pixel.
	/* Each color component of the pixel is the average value of that 
	* component over the rectangle.
	* @param ul is (x,y) of the upper left corner of the rectangle 
	* @param lr is (x,y) of the lower right corner of the rectangle */
	RGBAPixel stats::getAvg(pair<int,int> ul, pair<int,int> lr){
	long red_total = getSum('r',ul,lr);
    long green_total = getSum('g',ul,lr);
    long blue_total = getSum('b',ul,lr);
    long area = rectArea(ul,lr);
    int red = (int) red_total/area;
    int green = (int) green_total/area;
    int blue = (int) blue_total/area;
    return RGBAPixel(red, green, blue);



	}

	// given a rectangle, return the number of pixels in the rectangle
	/* @param ul is (x,y) of the upper left corner of the rectangle 
	* @param lr is (x,y) of the lower right corner of the rectangle */
	long stats::rectArea(pair<int,int> ul, pair<int,int> lr){
	return ((lr.first-ul.first)+1)*((lr.second-ul.second)+1);
	}

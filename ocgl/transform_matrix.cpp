#include <iostream>
#include <graphics.h>
#include <cmath>
#include <windows.h>
using namespace std;

int main()
{
	initwindow(800,800,"graphics");
	
	int mat_sol[4][3]; // for storing the solution of the scaling matrix matrix.
	mat_sol[0][0]=0;
    mat_sol[0][1]=0;
    mat_sol[0][2]=0;
    mat_sol[1][0]=0;
    mat_sol[1][1]=0;
    mat_sol[1][2]=0;
    mat_sol[2][0]=0;
    mat_sol[2][1]=0;
    mat_sol[2][2]=0;
    mat_sol[3][0]=0;
    mat_sol[3][1]=0;
    mat_sol[3][2]=0;
    
    int mat1_sol[4][3]; // for storing the solution of the translation  matrix 2.
	mat1_sol[0][1]=0;
    mat1_sol[0][2]=0;
    mat1_sol[1][0]=0;
    mat1_sol[1][1]=0;
    mat1_sol[1][2]=0;
    mat1_sol[2][0]=0;
    mat1_sol[2][1]=0;
    mat1_sol[2][2]=0;
    mat1_sol[3][0]=0;
    mat1_sol[3][1]=0;
    mat1_sol[3][2]=0;
    
    int mat2_sol[4][3]; // for storing the solution of rotation matrix 3.
	mat2_sol[0][1]=0;
    mat2_sol[0][2]=0;
    mat2_sol[1][0]=0;
    mat2_sol[1][1]=0;
    mat2_sol[1][2]=0;
    mat2_sol[2][0]=0;
    mat2_sol[2][1]=0;
    mat2_sol[2][2]=0;
    mat2_sol[3][0]=0;
    mat2_sol[3][1]=0;
    mat2_sol[3][2]=0;
    
	// for section of the window in 4 parts.
	int mid=400;
	line(0,400,800,400);
	line(400,0,400,800);
	
	int x1,y1,x2,y2,x3,y3,x4,y4;
	
	cout<<"Enter the co-ordinate of the polygon "<<endl;
	cin>>x1>>y1;
	
	cout<<"Enter the co-ordinate of the polygon "<<endl;
	cin>>x2>>y2;
	
	cout<<"Enter the co-ordinate of the polygon "<<endl;
	cin>>x3>>y3;
	
	cout<<"Enter the co-ordinate of the polygon "<<endl;
	cin>>x4>>y4;
	
	int mat[4][3];  // original matrix
	
	mat[0][0]=x1;
    mat[0][1]=y1;
    mat[0][2]=1;
    mat[1][0]=x2;
    mat[1][1]=y2;
    mat[1][2]=1;
    mat[2][0]=x3;
    mat[2][1]=y3;
    mat[2][2]=1;
    mat[3][0]=x4;
    mat[3][1]=y4;
    mat[3][2]=1;
    
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x4,y4);
	line(x4,y4,x1,y1);
	
	int mat_1[3][3];
	int sx,sy;
	cout<<"Enter the value of the sx "<<endl;
	cin>>sx;
	
	cout<<"Enter the value of the sy "<<endl;
	cin>>sy;
	
    mat_1[0][0]=sx;
    mat_1[0][1]=0;
    mat_1[0][2]=0;
    
    mat_1[1][0]=0;
    mat_1[1][1]=sy;
    mat_1[1][2]=0;
    
    mat_1[2][0]=0;
    mat_1[2][1]=0;
    mat_1[2][2]=1;
    
    // for multiplication of the matrix
    
    for (int i=0;i<4;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		for(int k=0;k<3;k++)
    		{
    			mat_sol[i][j]+=mat[i][k]*mat_1[k][j];
			}
		}
	}
	
	// scaled object
	
	line(mid+mat_sol[0][0],mid-mat_sol[0][1],mid+mat_sol[1][0],mid-mat_sol[1][1]);
	line(mid+mat_sol[1][0],mid-mat_sol[1][1],mid+mat_sol[2][0],mid-mat_sol[2][1]);
	line(mid+mat_sol[2][0],mid-mat_sol[2][1],mid+mat_sol[3][0],mid-mat_sol[3][1]);
	line(mid+mat_sol[3][0],mid-mat_sol[3][1],mid+mat_sol[0][0],mid-mat_sol[0][1]);
	
	// for translation matrix
	int tx,ty;
    cout<<"Enter the co_ordinates of the tx "<<endl;
    cin>>tx;
    
    cout<<"Enter the co-ordinates of the ty "<<endl;
    cin>>ty;
    
	int matx[3][3];
	matx[0][0]=1;
    matx[0][1]=0;
    matx[0][2]=0;
    
    matx[1][0]=0;
    matx[1][1]=1;
    matx[1][2]=0;
    
    matx[2][0]=tx;
    matx[2][1]=ty;
    matx[2][2]=1;
    
    // for multiplication matrix
    
    for (int i=0;i<4;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		for(int k=0;k<3;k++)
    		{
    			mat1_sol[i][j]+=mat[i][k]*matx[k][j];
			}
		}
	}
	
    line(mid+mat1_sol[0][0],mid+mat1_sol[0][1],mid+mat1_sol[1][0],mid+mat1_sol[1][1]);
	line(mid+mat1_sol[1][0],mid+mat1_sol[1][1],mid+mat1_sol[2][0],mid+mat1_sol[2][1]);
	line(mid+mat1_sol[2][0],mid+mat1_sol[2][1],mid+mat1_sol[3][0],mid+mat1_sol[3][1]);
	line(mid+mat1_sol[3][0],mid+mat1_sol[3][1],mid+mat1_sol[0][0],mid+mat1_sol[0][1]);
	
	//for rotate the polygon
	int ang;
	cout<<"Enter the angle of rotation "<<endl;
	cin>>ang;
	
	float rmat[3][3];
	rmat[0][0]=cos((3.14/180)*ang);
	rmat[0][1]=sin((3.14/180)*ang);
	rmat[0][2]=0;
	
	rmat[1][0]=-sin(3.14/180)*(ang);
	rmat[1][1]=cos((3.14/180)*ang);
	rmat[1][2]=0;
	
	rmat[2][0]=0;
	rmat[2][1]=0;
	rmat[2][2]=1;
	
	// for multiplication matrix
    
    for (int i=0;i<4;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		for(int k=0;k<3;k++)
    		{
    			mat2_sol[i][j]+=mat[i][k]*rmat[k][j];
			}
		}
	}
	
	line(mid-mat2_sol[0][0],mid+mat2_sol[0][1],mid-mat2_sol[1][0],mid+mat2_sol[1][1]);
	line(mid-mat2_sol[1][0],mid+mat2_sol[1][1],mid-mat2_sol[2][0],mid+mat2_sol[2][1]);
	line(mid-mat2_sol[2][0],mid+mat2_sol[2][1],mid-mat2_sol[3][0],mid+mat2_sol[3][1]);
	line(mid-mat2_sol[3][0],mid+mat2_sol[3][1],mid-mat2_sol[0][0],mid+mat2_sol[0][1]);

	getch();
	return 0;	
}

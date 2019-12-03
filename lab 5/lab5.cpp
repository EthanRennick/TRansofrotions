// lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrix3.h"
#include "Vector3.h"
#include "Quaternion.h"

int main()
{
	Vector3 vectorUno = { 0,2,-5 };
	Vector3 vectorDos = { -2,-2,-5 };
	Vector3 vectorTres = { 2,-2,-5 }; //rotate
	std::cout << vectorUno.Length() << std::endl;
	std::cout << vectorDos.LengthSquared() << std::endl;

	Matrix3 matrotate;
	vectorTres.Rotate(vectorTres, 23.21);
	std::cout << vectorTres.ToString() << std::endl;

	std::cout << matrotate.toString() << std::endl;
	matrotate.RotationZ(23.21);
	std::cout << matrotate.toString() << std::endl;

	Vector3 vectorOne{};
	Vector3 vectorTwo{};
	Vector3 vectorThree{};

	//addition
	vectorOne = { 1.1,2.2,-0.0 };
	vectorTwo = { 3.3,4.4, -5.5 };
	vectorThree = vectorOne + vectorTwo;
	std::cout << "[4.4     ,6.6     ,-5.5     ]" << std::endl;
	std::cout << vectorThree.ToString() << std::endl;
	std::cout << "addition " << std::endl;
	std::cout << "----------------------------" << std::endl;

	//subtraction
	vectorOne = { 2.0,4.2,-0.0 };
	vectorTwo = { 3.3,4.4, -5.5 };
	vectorThree = vectorOne - vectorTwo;
	std::cout << "[-1.3     ,-0.2     ,5.5     ]" << std::endl;
	std::cout << vectorThree.ToString() << std::endl;
	std::cout << "subtraction " << std::endl;
	std::cout << "----------------------------" << std::endl;


	//multiply (by scalar)
	vectorOne = { 80.0,-4.2,-0.0 };
	vectorThree = vectorOne * 2;
	std::cout << "[160.0     ,-8.4     ,-0.0    ]" << std::endl;
	std::cout << vectorThree.ToString() << std::endl;
	std::cout << "Multiplication ( * 2 )" << std::endl;
	std::cout << "----------------------------" << std::endl;

	// plus equals +=
	vectorOne = { 10.0,9.0,-4.0 };
	vectorThree = { 4.6, 7.6, 5.6 };
	vectorTwo = vectorThree + vectorOne;
	std::cout << "[14.6     ,15.6    ,1.6  ]" << std::endl;
	std::cout << vectorTwo.ToString() << std::endl;
	std::cout << "Plus Equals +=" << std::endl;
	std::cout << "----------------------------" << std::endl;

	// minus equals -=
	vectorOne = { 10.0,9.0,-4.0 };
	vectorThree = { 4.6, 7.6, 5.6 };
	vectorTwo = vectorThree - vectorOne;
	std::cout << "[-5.4     ,-1.4    ,9.6  ]" << std::endl;
	std::cout << vectorTwo.ToString() << std::endl;
	std::cout << "Minus Equals -=" << std::endl;
	std::cout << "----------------------------" << std::endl;


	// negative of a vector 
	vectorThree = { 4.90, 31.43, -5.0 };
	vectorThree = -vectorThree;
	std::cout << "[-4.90     ,-31.43   ,5.0  ]" << std::endl;
	std::cout << vectorThree.ToString() << std::endl;
	std::cout << "Negative of vector" << std::endl;
	std::cout << "----------------------------" << std::endl;

	//negate x
	vectorThree = { -89.4, 3.0, -0.0 };
	vectorThree.operator-();
	std::cout << "[89.4     ,3.0   ,-0.0  ]" << std::endl;
	std::cout << vectorThree.ToString() << std::endl;
	std::cout << "Negate of X" << std::endl;
	std::cout << "----------------------------" << std::endl;


	
	//length
	vectorThree = { 4.0, 1.0, 4.5 };
	std::cout << "[    6.10...      ]" << std::endl;
	std::cout << vectorThree.Length() << std::endl;
	std::cout << "length  " << std::endl;
	std::cout << "----------------------------" << std::endl;

	//length squared
	vectorThree = { 3.0, 4.0, 5.0 };
	std::cout << "[50 ]" << std::endl;
	std::cout << vectorThree.LengthSquared() << std::endl;
	std::cout << "length squared " << std::endl;
	std::cout << "----------------------------" << std::endl;

	//Normalise a vector
	vectorThree = { 5.4, 4.0 , 8.90 };
	std::cout << "[   0.49... , 0.35... , 0.798...  (approx)   ]" << std::endl;
	vectorThree.Normalise();
	std::cout << vectorThree.ToString() << std::endl;
	std::cout << " Normalisation " << std::endl;
	std::cout << "----------------------------" << std::endl;


	////rotate a vector
	//vectorThree = { 5.4, 4.0 , 8.90 };
	//std::cout << "[  -5.4, -4.0, .8.9]" << std::endl;
	//vectorThree.Rotate(vectorThree, 180);
	//std::cout << vectorThree.ToString() << std::endl;
	//std::cout << " Rotate a vector " << std::endl;
	//std::cout << "----------------------------" << std::endl;


	//declare my matrices for testing with
	Matrix3 matrixOne; //matrix one for testing with
	matrixOne = { 4.0, 2.0, 1.0,
				  7.0, 8.0, 9.0,
				  1.0, 3.0, 4.0 }; //made up values
	Matrix3 matrixTwo; //second matrix used for testing
	matrixTwo = { 1.0,2.0,3.0,
				 2.0,3.0,4.0,
				 6.0,7.0,8.0 }; //made up values

	Matrix3 matrixThree; //a third matrix for testing

	//To string function and layout look
	//layout was more or less the same as myvector3 layouts, just altered
	std::cout << "----------------------------\nTesting the 'to string' function \n"; //out put testing -> declare the function running
	std::cout << "I expect that the matrix will output normally \n"; //-> what i expect to happen
	std::string result; //call matrix to string -> variable creating
	result = matrixOne.toString(); //set result to the string variable -> output result to screen
	std::cout << result; //display result 
	std::cout << "----------------------------" << std::endl; // -> lines to break up code

	//Simple Arithmetic 

	//addition of matrices
	std::cout << "Matrices Addition" << std::endl; //addiding matrices together
	std::cout << "We expect \n3,3,3\n6,6,6\n11,11,11 \n"; //the answer for the problem presented below
	matrixOne = { 1.0, 1.0, 1.0,
				  2.0, 2.0, 2.0,
				  6.0, 6.0, 6.0 }; //adding these gives the answer abovr
	matrixTwo = { 2.0, 2.0, 2.0,
				  4.0, 4.0, 4.0,
				  5.0, 5.0, 5.0 };
	matrixThree = matrixOne + matrixTwo; //ask computer to add them
	std::cout << matrixThree.toString(); //display what the computer got and compare to my answer
	std::cout << "----------------------------" << std::endl;

	//subtracting two matrices
	std::cout << "Matrices Subtraction" << std::endl; //subtracting matrices from each other
	std::cout << "We expect \n-1,-1,-1\n-2,-2,-2\n1,1,1 \n"; //the answer for the problem presented below
	matrixOne = { 1.0, 1.0, 1.0,
				  2.0, 2.0, 2.0,
				  6.0, 6.0, 6.0 }; //subtracting these gives the answer shown earlier
	matrixTwo = { 2.0, 2.0, 2.0,
				  4.0, 4.0, 4.0,
				  5.0, 5.0, 5.0 };
	matrixThree = matrixOne - matrixTwo; //ask computer to do some subtraction on them
	std::cout << matrixThree.toString(); //display what the computer got and compare to my answer
	std::cout << "----------------------------" << std::endl;

	//multiplying two matrices
	//aided by this sitehttps://matrix.reshish.com/multCalculation.php
	std::cout << "Matrices multiplication" << std::endl; //multiplying matrices by each other
	std::cout << "We should get \n11,11,11\n22,22,22\n66,66,66 \n"; //the answer for the problem presented below
	matrixOne = { 1.0, 1.0, 1.0,
				  2.0, 2.0, 2.0,
				  6.0, 6.0, 6.0 }; //multiplying these components gives the answer above
	matrixTwo = { 2.0, 2.0, 2.0,
				  4.0, 4.0, 4.0,
				  5.0, 5.0, 5.0 };
	matrixThree = matrixOne * matrixTwo; //ask computer to do multiply the matrices
	std::cout << matrixThree.toString(); //display what the computer got and compare to my answer
	std::cout << "----------------------------" << std::endl;

	//multiplying a matrix by a vector
	//aided by this sitehttps://matrix.reshish.com/multCalculation.php
	std::cout << "Matrix multiplication by a vector" << std::endl; //multiply from each other
	std::cout << "We ought to get \n12\n24\n72\n"; //the answer expected for the problem beneath
	matrixOne = { 1.0, 1.0, 1.0,
				  2.0, 2.0, 2.0,
				  6.0, 6.0, 6.0 }; //multiplying these components by vector one, defined below, gives the answer above

	vectorOne = { 3.0,4.0,5.0 };
	vectorTwo = (matrixOne * vectorOne); //ask computer to do multiply the matrix by vector one
	std::cout << vectorTwo.ToString() << "\n"; //display what the computer got and compare to my answer
	std::cout << "----------------------------" << std::endl;

	//multiplying a matrix by a scaler (double)
	std::cout << "Matrix multiplication by a scaler" << std::endl; //multiply matrix by a scaler
	std::cout << "We ought to get:\n2.5,2.5,2.5\n5,5,5 \n15,15,15 \n"; //the answer expected for the problem beneath
	matrixOne = { 1.0, 1.0, 1.0,
				  2.0, 2.0, 2.0,
				  6.0, 6.0, 6.0 }; //multiplying these components by the double variable, defined below, gives the answer above
	double scaler = 2.5;   // -> 2.5 * 1 = 2.5      2.5 * 2 = 5,   2.5* 6 = 15
	matrixThree = (matrixOne * scaler); //ask computer to do multiply the matrix by the double scaler
	std::cout << matrixThree.toString() << "\n"; //display what the computer got and compare to my answer
	std::cout << "----------------------------" << std::endl;

	//the three tricky bits inbetween

	//the transpose of a matrix
	std::cout << "Matrix transpose" << std::endl; //the transpose of a matrix
	std::cout << "We ought to get:\n6,2,3\n6,4,3 \n3,2,8\n"; //the answer expected for the problem shown 
	matrixOne = { 6.0, 6.0, 3.0,
		2.0, 4.0, 2.0,
		3.0, 3.0, 8.0 }; //the rows are essentially switched, so the top row -> first column, the 2nd row -> the 2nd col, so on
	matrixTwo = matrixOne.Transpose(matrixOne);
	std::cout << matrixOne.toString() << "is transposed to: \n"; //display matrix one for reference
	std::cout << matrixTwo.toString() << "\n"; //display what the computer got and compare to my answer
	std::cout << "----------------------------" << std::endl;


	//the determinant of a matrix
	std::cout << "Matrix determinant" << std::endl; //the determinant of a matrix
	std::cout << "We ought to get:\ndet = \n"; //the answer expected for the problem shown 
	matrixOne = { -3.0, 4.0, 5.0,
				  1.0, 2.0, 3.0,
				  3.0, -5.0, -6.0 };
	double determinantResult;
	determinantResult = matrixOne.Determinant(matrixOne);
	std::cout << matrixOne.toString() << "The determinant is: \n"; //display matrix one for reference
	std::cout << determinantResult << "\n"; //display what the computer got and compare to my answer
	std::cout << "----------------------------" << std::endl;

	//The row of a matrix
	std::cout << "Matrix rows" << std::endl; //rows of a matrix
	std::cout << "We ought to get:\nR0 = 5.0, 6.0, 6.0\nR1 = -3.0, -2.0, -9.0 \nR2 = 4.0, 2.0, -0.0 \n"; //the answer expected for the problem beneath
	matrixOne = { 5.0, 6.0, 6.0, //row 1
				-3.0, -2.0, -9.0,//row 2
				4.0, 2.0, -0.0 };//row 3
	int rowChosen = 0; //user picks a row to view
	std::cout << "Please pick a row to look at -> 0, 1 or 2. \n"; //asks user which row to view
	std::cin >> rowChosen; //input row to view
	vectorOne = matrixOne.Row(rowChosen); //gets the row corresponding to user choice
	std::cout << vectorOne.ToString() << "\n"; //display what the computer got and compare to my answer
	std::cout << "----------------------------" << std::endl;

	//The Columns of a matrix
	std::cout << "Matrix Cols" << std::endl; //cols of a matrix
	std::cout << "We ought to get:\nC0 = 5.0, -3.0, 4.0\nC1 = 6.0, -2.0, 2.0 \nC2 = 6.0, -9.0, -0.0 \n"; //the answer expected for the problem beneath
	matrixOne = { 5.0, 6.0, 6.0,
				 -3.0, -2.0, -9.0,
				  4.0, 2.0, -0.0 };
	//  col 1  col 2  col 3
	int colChosen = 0; //user picks a col to view
	std::cout << "Please pick a column to look at -> 0, 1 or 2. \n"; //asks user which col to view
	std::cin >> colChosen; //input col to view
	vectorOne = matrixOne.Column(colChosen); //gets the col corresponding to user choice
	std::cout << vectorOne.ToString() << "\n"; //display what the computer got and compare to my answer
	std::cout << "----------------------------" << std::endl;

	//The rotation of z axis
	std::cout << "Matrix rotation: Z" << std::endl; //rotating z axis of a matrix
	std::cout << "We ought to get:\n -0.41...,0.909...,0.0 \n -.909...,-.416,0.0\n 0.0 ,0.0 ,1.0 (approx)\n"; //the answer expected for the problem beneath
	matrixOne = { 3.0, 3.0, 5.0,
				-7.0, 2.0, -1.0,
				4.0, -2.0, -0.5 };
	matrixTwo = matrixOne.RotationZ(2); //rotates the z axis by 2 radians
	std::cout << matrixTwo.toString() << "\n"; //display what the computer got and compare to my answer
	std::cout << "----------------------------" << std::endl;


	//The rotation of y axis
	std::cout << "Matrix rotation: Y" << std::endl; //rotate the y axis of my matrix
	std::cout << "We ought to get:\n .960..., 0.0, .279...\n 0.0,1.0,0.0\n -.279, 0.0, .96... (approx)\n"; //the answer expected for the problem beneath
	matrixOne = { 3.0,0.0, 5.0,
		-1.0, 3.0, 1.0,
		-6.0, -5.0, 99.5 };
	matrixTwo = matrixOne.RotationY(6); //rotates the y axis by 6 radians
	std::cout << matrixTwo.toString() << "\n"; //display what the computer got and compare to my answer
	std::cout << "----------------------------" << std::endl;


	//The rotation of x axis
	std::cout << "Matrix rotation: X" << std::endl; //rotate the x axis of my matrix
	std::cout << "We ought to get:\n 1.0,0.0,0.0 \n 0.0, -.84..., -.544\n 0.0,.544...,-.839... (approx)\n"; //the answer expected for the problem beneath
	matrixOne = { 33.0,10.0, 15.0,
		11.0, -1.0, -1.0,
		66.0, -2.7, 19.43 };
	matrixTwo = matrixOne.RotationX(10); //rotates the x axis by 10 radians
	std::cout << matrixTwo.toString() << "\n"; //display what the computer got and compare to my answer
	std::cout << "----------------------------" << std::endl;

	//The scaling of a matrix
	std::cout << "Matrix scaling" << std::endl; //scale the matrix via scale value
	std::cout << "We ought to get:\n4,0,0\n0,4,0\n0,0,4\n"; //the answer expected for the problem beneath
	matrixOne = { -1.0,2.0, -3.0,
				4.0, -5.0, 6.0,
				-7.0, 8.0,-9.0 };
	double scaleValue = 4.0; //value i will scale by
	matrixTwo = matrixOne.Scale(4,5); //scales the matrix via the scale value above
	std::cout << matrixTwo.toString() << "\n"; //display what the computer got and compare to my answer
	std::cout << "----------------------------" << std::endl;




	return 0;
}

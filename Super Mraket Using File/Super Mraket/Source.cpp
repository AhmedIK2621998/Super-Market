#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;
class products
{
private:
	int p_nom;
	string p_name;
	float p_price, p_Qty;
public:
	void create() {
		cout << "**************************Hello CustomerIn Super Market****************" << endl;
		cout << "Enter the Product Number : " << endl ; cin >> p_nom;
		cout << "Enter the Product Name : "    << endl ; cin >> p_name;
		cout << "Enter the Product Price : "   << endl ; cin >> p_price;
		cout << "Enter the Product Quantity : "<< endl ; cin >> p_Qty;
	}
	void Show() {
		cout << "The Product Number is : \t" << p_nom << endl;
		cout << "The Product Name is : \t" << p_name << endl;
		cout << "The Product Price is : \t" << p_price << endl;
		cout << "The Product Quantity is : \t" << p_Qty <<endl;
	}
	int pnom() { return p_nom; }
	string pName() { return p_name; }
	float P_price() { return p_price; }
	float p_Quantity(){ return p_Qty; }
};
products pro;
fstream fp;
void write_product() {
	fp.open("Market.txt", ios::out | ios::app);
	pro.create();
	fp.write((char*)&pro,sizeof(products));
	fp.close();
	cout << "\n\n The Product was Created \n";
	_getch();
}
void Display_products() {
	cout << "All Products Infromation : \n\n";
	fp.open("Market.txt", ios::in);
	while (fp.read((char*)&pro, sizeof(products))) {
		pro.Show();
		cout << "\n\n**************************************\n";
		_getch();
	}
	fp.close();
	_getch();
}
void serach_products(int num) {
	int flag = 0;
	fp.open("Market.txt", ios::in);
	while (fp.read((char*)&pro, sizeof(products)));
		{
			if (pro.pnom() == num) {
				pro.Show();
				flag = 1;
			}
		}
		fp.close();
		_getch(); 
		if (flag == 0) {
			cout << "\n\n The Product is Not Soterd /n ";
		}
}
void Delete_products() {
	int num;
	cout << "Please Enter The Number Of Product You Want to Delete :  ";cin >> num;
	fp.open("Market.txt", ios::in | ios::out);
	fstream fp1;
	fp1.open("Replace.txt", ios::out);
	fp.seekg(0, ios::beg);
	while (fp.read((char*)&pro, sizeof(products)))
	{
		if (pro.pnom() != num) {
		 fp1.write((char*)&pro, sizeof(products));
		}
	}
	fp1.close();
	fp.close();
	remove("Market.txt");
	cout << "\n\n The Products Was Deleted \n\n";
	_getch();
}
void about_me() {
	cout << "\t\t\t\t\tMy First Project ";
	cout << "\n\n\t\t\t\t\tSuper Market";
	cout << "\n\n\t\t\t\t\tProject";
	cout << "\n\n\t\t\t\tIt MADE BY: Ahmed Ibrahim\n";
	cout << "\n\n\t\t\t\t*******************Good Luck*****************************\n";
	_getch();

}

void main()
{
	////********************THAT IS INTROUDUCTION TO READ AND WRITE FROM FILE************
	////ifstream myfile;              //read from file
	////ofstream myfile;         //write from file
	//  fstream  myfile;            // read & write from file
	//
	//// *********This is write in file**********
	//  myfile.open("Market.txt",ios::out|ios::app);
	//  myfile << "Hello In Super Market" << endl;
	//  myfile << "This is Made by Ahmed Ibrahim Kamal Farag" << endl;
	//  myfile.close();
   //  //**********This is read from file*********
	//  myfile.open("Market.txt");
	//  cout << myfile.rdbuf();
	//  myfile.close();
	char ch;
	about_me();
	do{
	cout << "\n\n\n\n The Main Menu";
	cout << "\n\n\t1.Create Product";
	cout << "\n\n\t2.Desplay All Product";
	cout << "\n\n\t3.Search about Product";
	cout << "\n\n\t4.Delete Product";
	cout << "\n\n\t5.View Product Menu";
	cout << "\n\n\t6.Exit";
	cout << "\n\nPlease Enter the Choice from(1-6) ";
	ch = _getch();
	switch (ch){
		case '1':
			write_product();
			break;
		case'2':
			Display_products();
			break;
		case'3':
			int num;
			cout << "\n\nEnter the number to Search : \t";cin >> num;
			serach_products(num);
			break;
		case'4':
			Delete_products();
			break;
		case'5':
			exit(0);
		default :
			cout << "Error";
			exit(0);
	}
	} while (ch != 6);
}
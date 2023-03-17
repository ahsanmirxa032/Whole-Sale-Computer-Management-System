#include<iostream>					
#include<ctime>						   
#include<stdlib.h>					  
#include<conio.h>					 
#include<fstream>
#include<windows.h>
#include<cstring>
using namespace std;			//Log In System Details			// UserName=Team IQ
int choice;								  					   //  Password=123
int quantity,price;											  //   Backup Email=abc123@gmail.com
int Grand_Total;
ofstream fout ("Bill.txt",ios::app);
inline int Bill(int Quantity=0,int Price=0)
{
	return Quantity*Price;		
}
 inline void pricing(int QUANTITY,int Amount)
{
	Grand_Total+=Bill(QUANTITY,Amount);
	cout<<"Grand Total is:"<<Grand_Total;
}
inline void Time()
{
	time_t tt;
	struct tm*ti;
	time (&tt);
	ti=localtime(&tt);
	cout<<"\nKindly pay your bill"<<endl;
	cout<<"\nThank you for visiting us.\nYour time of visit is:\n\t\t"<<asctime(ti);
	fout<<"\n\nThank you for visiting us.\nYour time of visit is:\n\t\t"<<asctime(ti);
}
struct data{
	string name,nverify;
	string password,pverify;
	string mail,mverify;
};
inline void Login()
{
	data login;
	login.name="Team IQ";
	login.password="123";
	login.mail="abc123@gmail.com";
	username:
	cout<<"Enter UserName"<<endl;
	getline(cin,login.nverify);
		system("cls");
	if(login.name==login.nverify)
	{
		int count=0;
		password:
		cout<<"Enter Password"<<endl;
		getline(cin,login.pverify);
		system("cls");
		if(login.password==login.pverify)
		{
			system("cls");	
		}
		else
		{
			count++;
			if(count<3)
			{
			cout<<"You have entered the wrong password,\n"
			"Again Enter the right password"<<endl;
			cout<<"\nBe careful,only "<<3-count<<" attempt left"<<endl;
			goto password;
			}
			else if(count>2)
			{
				forgotpassword:
			cout<<"Probably you have forgot your password,\n"
			"Do you want to make a new password"<<endl;
			cout<<"Press 1 to create a new password\n"
			"OR\n"
			"Press 2 to login again"<<endl;
			choice=getche();
			system("cls");
			switch(choice)
				{
					case '1':
					cout<<"You was provided with an email account,\n"
					"You can use that email to reset your password\n"
					"Press 'y' to reset the password"<<endl;
					choice=getche();
					system("cls");
					if(choice=='y')
					{
						int ecount=0;
						email:
					cout<<"Enter your e-mail"<<endl;
					getline(cin,login.mverify);
						system("cls");
					if(login.mail==login.mverify)
					{
						cout<<"Enter a new password"<<endl;
						getline(cin,login.password);
						cout<<"\nRe enter the same password again"<<endl;
						getline(cin,login.pverify);
							system("cls");
						if(login.pverify==login.password)
						{
							goto username;
						}
						else
						{
							cout<<"Your password does not match.Kindly enter the same password"<<endl;
							goto email;
						}
					}
					else
					{
						ecount++;
						if(ecount<3)
						{
							cout<<"You entered a wrong email\n"
							"Kindly enter a correct email"<<endl;
							cout<<"Be careful,only "<<3-ecount<<" attempt left."<<endl;
							goto email;
						}
						else
						{
							cout<<"System feels you suspected."<<endl;
							cout<<"Program Exited"<<endl;
							abort();
						}
					}
					}
					else
					{
						cout<<"You entered the wrong choice\n"
						"Prgram exited"<<endl;
						abort();
					}
					break;
					
					case '2':
					goto username;
					break;
					default:
						cout<<"You entered the wrong choice\n"
						"Again select the choice"<<endl;
						goto forgotpassword;
				}
			}
		}
	}
	else
	{
		cout<<"You entered the wrong username\n"
		"Enter username again"<<endl;
		goto username;
	}
}
inline void perchase(string product,int amount)
{
	cout<<"\nDo you want to buy this product?"<<endl;
	cout<<"Press 'y' to perchase this product:\n"
	"press any key to go to choice menu:"<<endl;
	choice=getche();
	system("cls");
	if(choice=='y')
	{
		cout<<"Enter number of articles you want to buy:"<<endl;
		cin>>quantity;
		pricing(quantity,amount);
		cout<<"Your current bill is:\n"<<amount;
		fout<<"\n\t"<<product<<"\t\t"<<quantity<<"\t\t\t"<<price<<"\t\t"<<quantity*price<<endl;
		system("cls");
	}
				
}
inline void PRODUCTS()
{
	string Product;
menu:
	cout<<"\t\t\t\t<-------Welcome to Generation Genius------->"<<endl;
	cout<<"We are dealing with the products of follwing brands."<<endl;		//Menu
	cout<<"1: Apple Notebooks"<<endl;
	cout<<"2: Dell"<<endl;
	cout<<"3: HP"<<endl;
	cout<<"4: To Exit"<<endl;
	cout<<"Kindly Select any brand of your choice with its index"<<endl;
	choice=getche();
	system("cls");
	switch(choice)
		{
		case '1':
			MacBooks:
		cout<<"We have the follwing Apple Notebook models for you\n"
		"1: MacBook Air (2017)\n"
		"2: MacBook Air (M1,2020)\n\n"
		"3: MacBook Pro(1TB SSD)\n"
		"4: MacBook Pro 13\" (M1)\n"
		"5: MacBook Pro 13\" (Two Thunderbolts 3 ports, 2017)\n"		//Apple NoteBook Models
		"6: MacBook Pro 14\" (Three Thunderbolts 4 ports)\n"
		"7: MacBook Pro MVVK2\n"
		"8: MacBook Pro 2021"<<endl;
		cout<<"\nKindly select your choice"<<endl;
		choice=getche();
		system("cls");
		switch(choice)
			{
				case '1':
					price=102000;
					Product="MacBook Air (2017)       ";
				cout<<"\n\nMacBook Air (2017)\n\t"
				"13.3\" (diagonal) LED-backlit widescreen display\n\t"
				"Up to 2.2GHz dual-core Intel Core i7 processor\n\t"
				"128GB PCIe-based SSB(Configurable to 256GB or 512GB SSD)\n\t"		//Specs
				"Turbo Boost upto 3.2GHz,with 4MB shared L3 cache\n\t"
				"2.96 pounds\n"
				"\tRs. 102,000 only"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'b' to go to MacBook section:"<<endl;
				cout<<"\nPress 'm' to go back to main menu:\n"
				"Or \nPress any key to exit:"<<endl;				
				choice=getche();
				system("cls");
				if(choice=='b')
				{
					goto MacBooks;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case '2':
					price=189500;
					Product="MacBook Air (M1, 2020)    ";
				cout<<"\n\nMacBook Air (M1, 2020)\n\t"
				"Touch ID\n\t"
				"13.3\" (diagonal) LED-backlit Retina display\n\t"		
				"Apple M1 chip\n\t"
				"256GB SSD\n\t"
				"8 core CPU\n\t"		
				"No optical drive\n\t"
				"Two Thunderbolt/USB 4 ports"
				"2.8 pounds\n\t"
				"Rs:189,500"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'b' to go to MacBook section:"<<endl;
				cout<<"\nPress 'm' to go back to main menu:\n"
				"Or \nPress any key to exit:"<<endl;
				choice=getche();
				system("cls");
				if(choice=='b')
				{
					goto MacBooks;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case '3':
					price=289900;
					Product="MacBook Pro (1TB SSD)     ";
				cout<<"\n\nMacBook Pro (1TB SSD)\n\t"
				"Touch ID\n\t"
				"13.3\" (diagonal) LED-backlit Retina display\n\t"
				"Up to 2.0GHz quad-core Intel Core i5 processor(10th Generation)\n\t"
				"Fingerprint\n\t"
				"16GB RAM\n\t"
				"Intel Integrated Graphics\n\t"
				"3.02 pounds\n"
				"\tRs. 289,900 only"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'b' to go to MacBook section:"<<endl;
				cout<<"\nPress 'm' to go back to main menu:\n"
				"Or \nPress any key to exit:"<<endl;
				choice=getche();
				system("cls");
				if(choice=='b')
				{
					goto MacBooks;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case '4':
					price=360999;
					Product="MacBook Pro 13\"(M1,2020)";
				cout<<"\n\nMacBook Pro 13\" (M1,2020)\n\t"
				"Touch Bar and Touch ID\n\t"
				"13.3\" (diagonal) LED-backlit Retina display\n\t"
				"Apple M1 chip 16GB\n\t"
				"01-TB SSD\n\t"
				"3.0 pounds\n"
				"\tRs. 360,999 only"<<endl;
					perchase(Product,price);
				cout<<"\nPress 'b' to go to MacBook section:"<<endl;
				cout<<"\nPress 'm' to go back to main menu:\n"
				"Or \nPress any key to exit:"<<endl;
				choice=getche();
				system("cls");
				if(choice=='b')
				{
					goto MacBooks;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case '5': 
						price= 200990;
						Product="MacBook Pro 13(2017)     ";
				cout<<"\n\nMacBook Pro 13  (2017)\n\t"
				"13.3\" display (diagonal) LED-backlit Retina display\n\t"
				"Up to 2.3GHz dual-core Intel Core i5 processor\n\t"
				"256GB SSD\n\t"
				"3.0 pounds\n\t"
				"Battery life	10 hours\n"
				"\tRs.  200,990 only"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'b' to go to MacBook section:"<<endl;
				cout<<"\nPress 'm' to go back to main menu:\n"
				"Or \nPress any key to exit:"<<endl;
				choice=getche();
				system("cls");
				if(choice=='b')
				{
					goto MacBooks;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case '6':
						price=419900;
						Product="MacBook Pro 14\"          ";
				cout<<"\n\nMacBook Pro 14\" (Three Thunderbolt 4 ports)\n\t"
				"Touch Bar and Touch ID\n\t"
				"13.3\" (diagonal) LED-backlit Retina display\n\t"
				"8 core CPU,14-core GPU\n\t"
				"512GB SSD storage\n\t"
				"16GB unified memory\n\t"
				"SDXC card slot\n\t"
				"Rs. 419900"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'b' to go to MacBook section:"<<endl;
				cout<<"\nPress 'm' to go back to main menu:\n"
				"Or \nPress any key to exit:"<<endl;
				choice=getche();
				system("cls");
				if(choice=='b')
				{
					goto MacBooks;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case '7':
						price=493999;
						Product="MacBook Pro  MVVK2       ";
				cout<<"\n\nMacBook Pro  MVVK2\n\t"
				"Touch Bar and Touch ID \n\t"
				"16\" (diagonal) LED-backlit Retina display\n\t"
				"Intel UHD Graphics 630\n\t"
				"8-core Intel Core i9 processor(9th Generation)\n\t"
				"16GB RAM\n\t"
				"1TB SSD\n\t"
				"Upto 11 hour Battery Time\n\t"
				"Force Touch trackpad\n\t"
				"Rs. 493,999"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'b' to go to MacBook section:"<<endl;
				cout<<"\nPress 'm' to go back to main menu:\n"
				"Or \nPress any key to exit:"<<endl;
				choice=getche();
				system("cls");
				if(choice=='b')
				{
					goto MacBooks;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case '8':
					price=519000;
					Product="MacBook Pro 2021         ";
				cout<<"\n\nMacBook Pro 2021\"\n\t"
				"16.2 inch Retina display\n\t"
				"10 Core CPU\n\t"
				"16 Core GPU\n\t"
				"16 GB RAM\n\t"
				"512 GB SSD\n\t"
				"Touch ID\n\t"
				"price=519000"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'b' to go to MacBook section:"<<endl;
				cout<<"\nPress 'm' to go back to main menu:\n"
				"Or \nPress any key to exit:"<<endl;
				choice=getche();
				system("cls");
				if(choice=='b')
				{
					goto MacBooks;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				default:
					system("cls");
					cout<<"\nProbably you entered the wrong choice.Please try again!"<<endl;
					cout<<"\nPress 'b' to go to MacBook section:"<<endl;
					cout<<"\nPress 'm' to go back to main menu:\n"
					"Or \nPress any key to exit:"<<endl;
					choice=getche();
					system("cls");
					if(choice=='b')
					{
						goto MacBooks;
					}
					else if(choice=='m')
					{
						goto menu;
					}
					else
					cout<<"You entered the Wrong choice"<<endl;
					cout<<"Program Exited"<<endl; 
					exit;
					break;
			}	//end braces of nested macbook switch
		break;	//Break of MacBook Section
		case '2':
			Dell:
		cout<<"We have the following Dell Laptops for you\n"
		"1:Dell inspiron 15 5510\n"
		"2:Dell inspiron 15 3501\n"
		"3:Dell inspiron 15 3511\n\n"
		
		"4:Dell Vostro 15 3500\n\n"
		
		"5:Dell Latitude 15 3520 \n"
		"6:Dell Latitude 14 5400\n"
		"7:Dell Latitude 14 7400\n"
		"8:Dell Latitude 15 3520\n\n"
		
		"9:Dell XPS 13 9310\n\n"
		
		"10:Dell G15 5515"<<endl;
		cout<<"\nKindly select your choice then press ENTER:"<<endl;
		cin>>choice;
		system("cls");
		switch(choice)
			{
				case 1:
					price=156500;
					Product="Dell inspiron 15 5510    ";
				cout<<"\n\nDell inspiron 15 5510 \n\t"
				"Core i5 11th Gen\n\t"
				"8GB RAM\n\t"
				"Reader W10\n\t"
				"256GB SSD \n\t"
				"Rs.156,500 \n\t"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'd' to go to Dell section:"<<endl;
				cout<<"Press 'm' to go back to main menu:"<<endl;
				cout<<"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='d')
				{
					goto Dell;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 2:
					price=157500;
					Product="Dell inspiron 15 3501    ";
				cout<<"\n\nDell inspiron 15 3501 \n\t"
				"Core i7 11th Gen\n\t"
				"8GB RAM\n\t"
				"512GB SSD++Optional HDD\n\t"
				"NVIDIA GEFORCE MX330 GDDR5 \n\t"
				"Rs.157,500n\t"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'd' to go to Dell section:"<<endl;
				cout<<"Press 'm' to go back to main menu:"<<endl;
				cout<<"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='d')
				{
					goto Dell;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 3:
					price=133500;
					Product="Dell inspiron 15 3511    ";
				cout<<"\n\nDell inspiron 15 3511\n\t"
				"Core i5 11th Gen\n\t"
				"8GB to 32GB RAM\n\t"
				"512GB to 1TB SSD\n\t"
				"2GB NVIDIA GEFORCE MX350 GDDR5 GC\n\t"
				"Rs.133,500\n\t"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'd' to go to Dell section:"<<endl;
				cout<<"Press 'm' to go back to main menu:"<<endl;
				cout<<"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='d')
				{
					goto Dell;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 4:
					price=146500;
					Product="Dell Vostro 15 3500      ";
				cout<<"\n\nDell Vostro 15 3500\n\t"
				"Core i7 11th Gen\n\t"
				"8GB to 32GB RAM\n\t"
				"1TB HDD +Optional SSD\n\t"
				"2GB NVIDIA GEFORCE MX330 GDDR5 \n\t"
				"Rs.146,500\n\t"<<endl;	
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'd' to go to Dell section:"<<endl;
				cout<<"Press 'm' to go back to main menu:"<<endl;
				cout<<"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='d')
				{
					goto Dell;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 5:
					price=138500;
					Product="Dell Latitude 15 3520    ";
				cout<<"\n\nDell Latitude 15 3520 \n\t"
				"Core i5 11th Gen \n\t"
				"8GB RAM\n\t"
				"256GB SSD \n\t"
				"Intel iris xe graphics\n\t"
				"Rs.138,500\n\t"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'd' to go to Dell section:"<<endl;
				cout<<"Press 'm' to go back to main menu:"<<endl;
				cout<<"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='d')
				{
					goto Dell;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 6:
					price=101900;
					Product="Dell Latitude 14 5400    ";
				cout<<"\n\nDell Latitude 14 5400\n\t"
				"Core i7 8th Gen\n\t"
				"8GB RAM\n\t"
				"256GB SSD\n\t"
				"Backlit KB VGA port\n\t"
				"Rs.101,900\n\t"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'd' to go to Dell section:"<<endl;
				cout<<"Press 'm' to go back to main menu:"<<endl;
				cout<<"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='d')
				{
					goto Dell;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 7:
					price=96900;
					Product="Dell Latitude 14 7400    ";
				cout<<"\n\nDell Latitude 14 7400\n\t"
				"Core i5 8th Gen\n\t"
				"8GB RAM\n\t"
				"256GB SSD\n\t"
				"Reader VGA port\n\t"
				"Rs.96,900\n\t"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'd' to go to Dell section:"<<endl;
				cout<<"Press 'm' to go back to main menu:"<<endl;
				cout<<"Or:\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='d')
				{
					goto Dell;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 8:
					price=185000;
					Product="Dell Latitude 15 3520    ";
				cout<<"\n\nDell Latitude 15 3520\n\t"
				"Core i7 11th Gen\n\t"
				"8GB RAM\n\t"
				"256GB SSD \n\t"
				"Reader VGA port\n\t"
				"Rs.185,000\n\t"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'd' to go to Dell section:"<<endl;
				cout<<"Press 'm' to go back to main menu:"<<endl;
				cout<<"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='d')
				{
					goto Dell;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 9:
					price=238000;
					Product="Dell XPS 13 9310         ";
				cout<<"\n\nDell XPS 13 9310\n\t"
				"Core i7 11th Gen\n\t"
				"8GB RAM\n\t"
				"256GB SSD\n\t"
				"Touchscreen infinity edge\n\t"
				"Rs.238,000\n\t"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'd' to go to Dell section:"<<endl;
				cout<<"Press 'm' to go back to main menu:"<<endl;
				cout<<"Or:\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='d')
				{
					goto Dell;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 10:
					price=202999;
					Product="Dell G15 5515            ";
				cout<<"\n\nDell G15 5515\n\t"
				"AMD Ryzen 7(Ryzen gaming edition)\n\t"
				"8GB to 32GB RAM\n\t"
				"512GB to 1TB SSD \n\t"
				"5800H Octa Core processor\n\t"
				"Rs.202,999\n\t"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'd' to go to Dell section:"<<endl;
				cout<<"Press 'm' to go back to main menu:"<<endl;
				cout<<"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='d')
				{
					goto Dell;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				default:
					system("cls");
					cout<<"\nProbably you entered the wrong choice.Please try again!"<<endl;
					cout<<"\nPress 'd' to go to Dell section:"<<endl;
					cout<<"Press 'm' to go back to main menu:"<<endl;
					cout<<"Or\n"
					"Press any key to exit"<<endl;
					choice=getche();
					system("cls");
					if(choice=='d')
					{
						goto Dell;
					}
					else if(choice=='m')
					{
						goto menu;
					}
					else
					cout<<"	You entered the Wrong choice"<<endl;
					cout<<"Program Exited"<<endl; 
					exit;
					break;
			}	//End braces of nested swatch of  Dell Switch
		 break;	//Break of Dell Section
		 case '3':
			HP:
		cout<<"We have the follwing HP laptop models for you\n\t"
			"1:OMEN Laptop-16z-c000\n\t"
			"2:OMEN Laptop-17t-ck000\n\t"
			"3:OMEN Laptop-17-ck0010nr\n\t"
			"4:OMEN Laptop- 15z-en100\n\n\t"
			
			"5:HP ENVY 15 ED1078ms\n\t"
			"6:HP ENVY BD0063dx\n\t"
			"7:HP ENVY 15 EE0003ca\n\t"
			"8:HP ENVY 13T AQ100\n\t"
			"9:HP ENVY ED1003ca\n\t"
			"10:Hp ENVY 13m BD0033\n\t"
			"11:HP ENVY 15 EE003CA\n\t"
			"12:HP ENVY 15 ED100\n\t"
			"13:HP ENVY 13 Ba1040X\n\n\t"
			
			"14:HP Probook 450\n\t"
			"15:HP Probook 455\n\t"
			"16:HP Probook 450 G8 \n\n\t"
			
			"17:HP EliteBook 850\n\t"
			"18:HP EliteBook 840\n\n\t"
			
			"19:HP Pavilion 15 EC2052AX\n\t"
			"20:HP Pavilion 15 EH1070WM\n\t"<<endl;
		cout<<"Kindly select your choice then press ENTER:"<<endl;
		cin>>choice;
		system("cls");
		switch(choice)
			{
				case 1:
					price=168000;
					Product="OMEN Laptop-16z-c000     "; 
				cout<<"\n\nOMEN Laptop-16z-c000\n\t"
				"Windows 11 Home \n\t"
				"AMD Ryzen 5 processor \n\t"
				"NVIDIA GeForce GTX 1650 Laptop GPU (4 GB)\n\t"
				"8 GB memory; 512 GB SSD storage\n\t"
				"Rs. 168,000 "<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 2:
					price=335000;
					Product="OMEN Laptop-17t-ck000    ";
				cout<<"\n\nOMEN Laptop-17t-ck000\n\t"
				"Windows 11 Home \n\t"
				"11th Gen Intel Core i7 processor\n\t"
				"NVIDIA GeForce RTX 3070 Laptop GPU (8 GB)\n\t"
				"16 GB memory; 512 GB SSD storage\n\t"
				"Rs.335000\n\t"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 3:
					price=380000;
					Product="OMEN Laptop-17-ck0010nr  ";
				cout<<"\n\nOMEN Laptop-17-ck0010nr\n\t"
				"Windows 10 Home \n\t"
				"11th Generation Intel Core i7 processo\n\t"
				"NVIDIA GeForce RTX 3060 Laptop GPU (6 GB GDDR6 dedicated)\n\t"
				"16 GB memory; 512 GB SSD storage \n\t"	
				"Rs. 380,000 \n\t"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 4:
					price=3860000;
					Product="OMEN Laptop-15z-en100    ";
				cout<<"\n\nOMEN Laptop-15z-en100\n\t"	
				"Windows 11 Home \n\t"
				"AMD Ryzen 7 processor\n\t"
				"NVIDIA GeForce RTX 3060 (6 GB)\n\t"
				"8 GB memory; 512 GB SSD storage\n\t"
				"Rs.3860000 \n\t"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 5:
					price=225000;
					Product="HP ENVY 15 ED1078ms      ";
				cout<<"\n\nHP ENVY 15 ED1078ms\n\t"
				"Core i7 11th Generation\n\t"
				"8GB RAM \n\t"
				"Screen: 15.5\"\n\t"
				"OS: Windows 10\n\t"
				"Storage: 512GB SSD\n\t"
				"Speed: Upto 4.7 Ghz\n\t"
				"Rs.225,000\n";    
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 6:
					price=150000;
					Product="HP ENVY BD0063dx         ";
				cout<<"\n\nHP ENVY BD0063dx\n\t"
				"Core i5 11th generation\n\t"
				"8GB RAM\n\t"
				"Storage: 256GB SSD\n\t"
				"Screen: 13.3\"\n\t"
				"OS: Windows 10\n\t"
				"Rs.150,000"<<endl;		
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 7:
					price=206999;
					Product="HP Envy 15 EE0003ca      ";
				cout<<"\n\nHP Envy 15 EE0003ca\n\t"
				"AMD Ryzen 7 4700U Processor\n\t"
				"RAM: 8GB\n\t"
				"Storage: 1TB SSD\n\t"
				"Screen: 15.6\"\n\t"
				"OS: Windows 10\n\t";
				"Rs.206,999\n";				
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 8:
					price=154000;
					Product="HP ENVY 13T AQ100        ";
				cout<<"\n\nHP ENVY 13T AQ100\n\t"
				"Intel Core i7 10th Generation\n\t"
				"RAM: 8GB\n\t"
				"Storage: 256GB\n\t"
				"Screen: 13.3\"\n\t"
				"OS: Windows 10\n\t"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 9:
					price=229999;
					Product="HP ENVY ED1003ca         ";
				cout<<"\n\nHP ENVY ED1003ca\n\t"
				"Core i7 11th Generation \n\t"
				"RAM: 16GB\n\t"
				"Storage: TB SSD\n\t"
				"OS: Windows 10\n\t"
				"Rs.229,999"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 10:
					price=182000;
					Product="HP ENVY 13m BD0033       ";
				cout<<"\n\nHP ENVY 13m BD0033\n\t"
				"Core i7 11th Generation\n\t"
				"RAM: 8GB\n\t"
				"Storage: 512GB SSD\n\t"
				"Screen:13.3\"\n\t"
				"OS:Windows 10\n\t"
				"Rs.182,000"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 11:
					price=207000;
					Product="HP ENVY 15 EE003CA       ";
				cout<<"\n\nHP ENVY 15 EE003CA\n\t"
				"HP ENVY 15 EE003CA\n\t"
				"RAM: 8GB\n\t"
				"Storage: 1TB SSD\n\t"
				"OS: Windows 10\n\t"
				"Screen: 15.6\"\n\t"
				"Rs.207,000"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 12:
					price=234000;
					Product="HP Envy 15 ED100         ";
				cout<<"\n\nHP Envy 15 ED100\n\t"
				"Core i7 11th Generation \n\t"
				"RAM: 8GB\n\t"
				"Storage: 512GB SSD\n\t"
				"OS: Genuine Windows 10 Home\n\t"
				"Screen: 15.6\"\n\t"
				"Rs.234,000"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 13:
					price=242999;
					Product="HP ENVY 13 Ba1040        ";
				cout<<"\n\nHP ENVY 13 Ba1040\n\t"
				"i7 11th Generation \n\t"
				"RAM: 16GB\n\t"
				"Storage: 512GB SSD\n\t"
				"OS: Windows 10 Home\n\t"
				"Screen: 13.3\"\n\t"
				"Rs.242,999"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 14:
					price=168000;
					Product="HP Probook 450           ";
				cout<<"\n\nHP Probook 450\n\t"
				"Core i5 11th Generation\n\t"
				"RAM: 8GB\n\t"
				"Storage: 512GB SSD\n\t"
				"OS: DOS\n\t"
				"Screen: 15.6\"\n\t"
				"Rs.168,000"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 15:
					price=113000;
					Product="HP Probook 455           ";
				cout<<"\n\nHP Probook 455\n\t"
				"AMD Ryzen 5\n\t"
				"RAM: 8GB\n\t"
				"Storage: 256GB SSD\n\t"
				"OS: DOS\n\t"
				"Screen: 15.6\"\n\t"
				"Rs.113,000"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 16:
					price=151000;
					Product="HP Probook 450 G8        ";
				cout<<"\n\nHP Probook 450 G8\n\t"
				"Core i5 11th Generation\n\t"
				"RAM: 8GB\n\t"
				"Storage: 512GB SSD\n\t"
				"OS: Windows 10\n\t"
				"Screen: 15.6\"\n\t"
				"Rs.151,000"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 17:
					price=182000;
					Product="HP EliteBook 850         ";
				cout<<"\n\nHP EliteBook 850\n\t"
				"Core i5 11th Generation\n\t"
				"RAM: 8GB\n\t"
				"Storage: 512GB SSD\n\t"
				"OS: DOS\n\t"
				"Screen: 15.6\"\n\t"
				"Rs.182,000"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 18:
					price=200000;
					Product="HP EliteBook 840         ";
				cout<<"\n\nHP EliteBook 840\n\t"
				"Core i5 11th Generation\n\t"
				"RAM: 8GB\n\t"
				"Storage: 512GB SSD\n\t"
				"OS: DOS\n\t"
				"Screen: 14\"\n\t"
				"Rs.200,000"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 19:
					price=209999;
					Product="HP Pavilion 15 EC2052AX  ";
				cout<<"\n\nHP Pavilion 15 EC2052AX\n\t"
				"AMD Ryzen 7\n\t"
				"RAM: 16GB\n\t"
				"Storage: 512GB SSD\n\t"
				"OS: Windows 10\n\t"
				"Screen: 15.6\"\n\t"
				"Rs.209,999"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				case 20:
					price=142000;
					Product="HP Pavilion 15 EH1070WM  ";
				cout<<"\n\nHP Pavilion 15 EH1070WM\n\t"
				"AMD Ryzen 7 5700U \n\t"
				"RAM: 8GB\n\t"
				"Storage: 512GB SSD\n\t"
				"OS: Windows 10 Home\n\t"
				"Screen: 15.6\"\n\t"
				"Rs.142,000"<<endl;
					perchase(Product,price);
				cout<<"\nYour current bill is: "<<Grand_Total;
				cout<<"\nPress 'h' to go to HP section:"<<endl;
				cout<<"Press 'm' to go back to main menu:\n"
				"Or\n"
				"Press any key to exit"<<endl;
				choice=getche();
				system("cls");
				if(choice=='h')
				{
					goto HP;
				}
				else if(choice=='m')
				{
					goto menu;	
				}
				else 
				exit;
				break;
				default:
					system("cls");
					cout<<"\nProbably you entered the wrong choice.Please try again!"<<endl;
					cout<<"\nPress 'h' to go to HP section:"<<endl;
					cout<<"Press 'm' to go back to main menu:\n"
					"Or\n"
					"Press any key to exit"<<endl;
					choice=getche();
					system("cls");
					if(choice=='h')
					{
						goto HP;
					}
					else if(choice=='m')
					{
						goto menu;
					}
					else
					cout<<"	You entered the Wrong choice"<<endl;
					cout<<"Program Exited"<<endl; 
					exit;
					break;				
				}	//End Braces of Nested Switch of HP section
		case '4':
			cout<<"You Quit the Program"<<endl;
			goto Exit;
		default:
			system("cls");
			cout<<"You Entered the Wrong Choice\n";
			cout<<"Press 'm' to go to main menu:\n"
			"or\n"
			"Press any key to exit:"<<endl;
			choice=getche();
				system("cls");
			if(choice=='y')
			{
				goto menu;
			}
			else
			Exit:
			exit;
			
		}//end braces of main switch

}
void Intro()
{
	
string Intro="\n\n\n\n\n\t\t\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"
	"\t\t\t\t\t\t%||%\tA PROJECT BY:\t\t\t\t\t\t%||%\n"
	"\t\t\t\t\t\t%||%\t\t\t\t\t\t\t\t%||%\n"
	"\t\t\t\t\t\t%||%\tMuhammad Ahsan  \t\t21-ARID_737\t\t%||%\n"
	"\t\t\t\t\t\t%||%\tAiza Gul\t\t\t21-ARID_698\t\t%||%\n"
	"\t\t\t\t\t\t%||%\tHaseeb Ur Rehman\t\t21-ARID_715\t\t%||%\n"
	"\t\t\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";

	for(int i=0;i<Intro.size();i++)
	{
		Sleep(10);
		cout<<Intro[i];
	}
	cout<<"\n\n\n\nPress any Key to continue:"<<endl;
	getch();
	system("cls");
}
int main()
{
	Intro();
	char comment[500];
	string customer_name,contact;
			Login();
		system("cls");
	cout<<"Enter customer name:"<<endl;
	getline(cin,customer_name);
		system("cls");
	cout<<"Enter contact number:"<<endl;
	getline(cin,contact);
		system("cls");
	fout<<"________________________________________________________________________________________________________________________________________________________________________"<<endl;
	fout<<"\n\t\t\t\t\t\t\t\t\t\t<====GENERATION GENIUS====>"<<endl;
	fout<<"\n\t\t\t\t\t\t\t\t==========================================================="<<endl;
	fout<<"\t\t\t\t\t\t\t\t\tCustomer Name:\t\t\t"<<customer_name<<"\t"<<endl;
	fout<<"\t\t\t\t\t\t\t\t\tContact No:   \t\t\t"<<contact<<"\t"<<endl;
	fout<<"\t\t\t\t\t\t\t\t==========================================================="<<endl;
	fout<<"\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	fout<<"|\t"<<"Product Name"<<"\t\t|\t\t"<<"Quantity"<<"\t|\t"<<"Price"<<"\t|\tTotal Price"<<endl;	//Filing 
	fout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			PRODUCTS();
		cout<<customer_name<<",Your total bill is: "<<Grand_Total<<endl;
		fout<<"\n\t"<<customer_name<<",Your Total bill is:\t\t"<<Grand_Total<<endl;
		cout<<"\nIf you want to write a review about our service:\n"
		"Press 'y':\n"
		"Or"<<endl;
		cout<<"Press any key to exit:"<<endl;
		choice=getche();
		system("cls");
		if(choice=='y')
		{
			cout<<"Add a '.' sign at the end of your code then press Enter to exit."<<endl;
			cin.get(comment,1000,'.');
				system("cls");
			fout<<"\n~~~~~~~~~~~~~~~~"<<endl;
			fout<<"CUSTOMER REVIEW:"<<comment;
		}
		else
		{
			exit;
		}
		{
			Time();
		}

		return 0;
}
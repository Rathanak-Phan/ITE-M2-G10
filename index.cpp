#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <stdlib.h>

using namespace std;

class product {
	private:
	    int code, qty;
	    char name[20];
	    float price;
	
	public:
	    int getCode() {
	        return code;
	    }
	
	    char *getName() {
	        return name;
	    }

    void Input() {
        cout << "Input Code  = ";
        cin >> code;
        cout << "Input Name  = ";
        cin.ignore();
        cin.getline(name, 20);
        cout << "Input Qty   = ";
        cin >> qty;
        cout << "Input Price = ";
        cin >> price;
    }

    double Total() {
        return price * qty;
    }

    int Discount() {
        if (Total() >= 1 && Total() <= 10) {
            return 10;
        } else if (Total() > 10 && Total() <= 20) {
            return 20;
        } else if (Total() > 20 && Total() <= 30) {
            return 30;
        } else {
            return 40; 
        }
    }

    double Payment() {
        return Total() - (Total() * Discount()) / 100;
    }

    void Output() {
        cout << setw(14) << code
            << setw(14) << name
            << setw(13) << qty
            << setw(14) << price << "$"
            << setw(14) << Total() << "$"
            << setw(16) << Discount() << "%"
            << setw(16) << Payment() << "$"<< endl;
            cout<<"|--------------|-------------|------------|--------------|--------------|----------------|--------------------------|"<<endl;
    }

};

void Head_List() {
	cout<<"|-------------------------------------------------------------------------------------------------------------------|"<<endl;
    cout << setw(14) << "Code"
         << setw(14) << "Name"
         << setw(13) << "Qty"
         << setw(15) << "Price"
         << setw(15) << "Total"
         << setw(17) << "Discount"
         << setw(17) << "Payment"
         << endl;
    cout<<"|--------------|-------------|------------|--------------|--------------|----------------|--------------------------|"<<endl;     
}

void Option() {
    cout << "\n__________________|Group-10|__________________" << endl;
    cout << "| 1,  Write                                   |" << endl;
    cout << "| 2,  Read                                    |" << endl;
    cout << "| 3,  Search                                  |" << endl;
    cout << "| 4,  Update                                  |" << endl;
    cout << "| 5,  Remove                                  |" << endl;
    cout << "| 6,  Insert                                  |" << endl;
    cout << "| 7,  Sort                                    |" << endl;
    cout << "| 8,  ....                                    |" << endl;
    cout << "| 9,  Clear Screen                            |" << endl;
    cout << "| 10, Information                             |" << endl;
    cout << "| 11, Off system                              |" << endl;
    cout << "|_____________________________________________|" << endl;
}

void Information(){
	cout<<"|-----------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"|=========================Infermation technology of engineering (ITE)-M2-Group:10===========================|"<<endl;
	cout<<"|      Member-Group: 1, ...............                                                                     |"<<endl;
	cout<<"|                    2, ...............                                                                     |"<<endl;
	cout<<"|                    3, ...............                                                                     |"<<endl;
	cout<<"|                    4, ...............                                                                     |"<<endl;
	cout<<"|                    5, ...............                                                                     |"<<endl;
	cout<<"|===========================================================================================================|"<<endl;
	cout<<"|                                                                                                           |"<<endl;
	cout<<"|   About:                                                                                                  |"<<endl;
	cout<<"|                                #            # # # #          # # #                                        |"<<endl;
	cout<<"|                               # #           #       #      #       #                                      |"<<endl;
	cout<<"|                              #   #          #        #    #                                               |"<<endl;
	cout<<"|                             #     #         #       #     #                                               |"<<endl;
	cout<<"|                            #       #        # # # #       #                                               |"<<endl;
	cout<<"|                           # # # # # #       #       #     #                                               |"<<endl;
	cout<<"|                          #           #      #        #    #                                               |"<<endl;
	cout<<"|                         #             #     #       #      #       #                                      |"<<endl;
	cout<<"|                        #               #    # # # #          # # #                                        |"<<endl;
	cout<<"|                                                                                                           |"<<endl;
	cout<<"|                                                                                                           |"<<endl;
	cout<<"|-----------------------------------------------------------------------------------------------------------|"<<endl;
}

int main() {
    product pro;    //// Assuming `product` is a user-defined type
    int i, n, op;
    fstream group10;

    RUPP:
        Option();
        cout << "Please Choose One Option = "; cin >> op;

        switch (op){
            case 1:{
                // Write products to file
                group10.open("book_store.bin", ios::out | ios::binary|ios::app);
                if (!group10) {
                    cout << "Error! creating file...!" << endl;
                    exit(0);
                }
                cout << "Input number of products = "; cin >> n;
                for (i = 0; i < n; i++) {
                    cout << "\n___________Product #" << i + 1 << "___________" << endl;
                    pro.Input();
                    group10.write((char*)&pro, sizeof(pro));
                }
                group10.close();
                
                break;
            }
            case 2:{
                // Read products from file
                group10.open("book_store.bin", ios::in | ios::binary | ios::app);
                if (!group10) {
                    cout << "Error! in opening file...!" << endl;
                    exit(0);
                }
                Head_List();
                while (group10.read((char*)&pro, sizeof(pro))) {
//                	cout<<"-------------------------------------------------------------------------------------------------------------------"<<endl;
                    pro.Output();
                }
                group10.close();
                
                break;
            }
            case 3:{
                // Search product by name
                
                
                break;
            }
            case 4:{
            	//update by search code
                
			    
			    break;
            }
            case 5:{
            	//remove by search code
            	
			    
				break;
			}
			case 6:{
				//insert by code
				
			    
				break;
			}
			case 7:{
				

				break;
			}
			case 8:{
				
				
				break;
			}
			case 9:{
				system("cls");
				break;
			}
			case 10:{
				Information();
				break;
			}
			case 11:{
				exit(0);
				break;
			}
			default:
                cout << "Invalid choice. Please try again.\n";
        }

        goto RUPP; // to loop back to the menu
    return 0;
}

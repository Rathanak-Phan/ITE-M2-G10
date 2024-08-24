#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Product {
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
        cout << "Input Code = ";cin >> code;
        cout << "Input Name = ";cin.ignore();cin.getline(name, 20);
        cout << "Input Qty = ";cin >> qty;
        cout << "Input Price = ";cin >> price;
    }

    double Total() {
        return price * qty;
    }

    int Discount() {
        if (Total() >= 1 && Total() <= 10) {
            return 10;
        } 
        else if (Total() > 10 && Total() <= 20) {
            return 20;
        } 
        else if (Total() > 20 && Total() <= 30) {
            return 30;
        }
        else {
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
    }

};

void Header() {
    cout << setw(14) << "Code"
         << setw(14) << "Name"
         << setw(13) << "Qty"
         << setw(15) << "Price"
         << setw(15) << "Total"
         << setw(17) << "Discount"
         << setw(17) << "Payment"
         << endl;
}

void Option() {
    cout << "\n_______________|...Shop...|_______________" << endl;
    cout << "1. Write" << endl;
    cout << "2. Read" << endl;
    cout << "3. Search" << endl;
    cout << "4. Update" << endl;
    cout << "5. Remove" << endl;
    cout << "6. Insert" << endl;
    cout << "7. Sort" << endl;
    cout << "8. Append" << endl;
    cout << "___________________________________________" << endl;
}


int main() {
    Product product;    //// Assuming `product` is a user-defined type
    int i, n, op;
    fstream group10;

    RUPP:
        Option();
        cout << "Please Choose One Option = "; cin >> op;

        switch (op) {
            case 1: {
                // Write products to file
                group10.open("product.bin", ios::out | ios::binary);
                if (!group10) {
                    cout << "Error! creating file...!" << endl;
                    exit(0);
                }
                cout << "Input number of products = "; cin >> n;
                for (i = 0; i < n; i++) {
                    cout << "\n___________Product #" << i + 1 << "___________" << endl;
                    product.Input();
                    group10.write((char*)&product, sizeof(product));
                }
                group10.close();
                break;
            }
            case 2: {
                // Read products from file
                group10.open("product.bin", ios::in | ios::binary);
                if (!group10) {
                    cout << "Error! in opening file...!" << endl;
                    exit(0);
                }
                Header();
                while (group10.read((char*)&product, sizeof(product))) {
                    product.Output();
                }
                group10.close();
                break;
            }
            case 3: {
                // Search product by name,id,...
                break;
            }
            case 4:{
                //
               break;
            }
            //............................
            case 9:{
                //exit programm
            }
        }

        goto RUPP; // to loop back to the menu
    return 0;
}
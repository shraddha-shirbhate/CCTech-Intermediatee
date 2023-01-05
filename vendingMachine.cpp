#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

class Inventory{
	struct products{
		string name;
		float price;
		int quantity;
	};
	products inv[3];

public:
	Inventory();
	string getAvailableProducts();
	string getProductName(int i);
	int getQuantity(int i);
	int getCost(int i);
	int getSelectedItemSize();
	bool hasInv();
};

Inventory::Inventory(){
	inv[0].name = "cola";
	inv[0].price = 100;
	inv[0].quantity = 10;

	inv[1].name = "chips";
	inv[1].price = 50;
	inv[1].quantity = 10;

	inv[2].name = "candy";
	inv[2].price = 65;
	inv[2].quantity = 10;
}
string Inventory::getAvailableProducts()
{
	ostringstream oss;
	string str;
	oss << "\nProducts Available\n";

	for (int i = 0; i < (sizeof(inv) / sizeof(*inv)); i++){
		oss << (i) << ") " << inv[i].name << ": $" << inv[i].price << "\n";
	}

	return str = oss.str();
}
bool Inventory::hasInv(){
	int val = 0;
	for (int i = 0; i < (sizeof(inv) / sizeof(*inv)); i++){
		val += inv[i].quantity;
	}
	if (val > 0){
		return 1;
	}
	else{
		return 0;
	}
}
int Inventory::getSelectedItemSize(){
	return (sizeof(inv) / sizeof(*inv));
}

int Inventory::getCost(int i){
	return inv[i].price;
}
string Inventory::getProductName(int i){
	return inv[i].name;
}
int Inventory::getQuantity(int i){
	try{
		return inv[i].quantity;
	}
	catch (exception ex){
		return -1;
	}
}

class Money{
private:
	unsigned int Quarter;
	unsigned int Dime;
	unsigned int Nickel;

public:
	int totalAmount;
	int maxTotalAvailableAmount();
	unsigned int amountInsertedbyCustomer();
	unsigned int totalAmountofInsertedCoins();
	void exactChange();
};
int Money::maxTotalAvailableAmount(){
	return 100;
}
unsigned int Money::amountInsertedbyCustomer()
{
	Nickel = Dime = Quarter = 0;
	cout << "********************************************************************" << endl;
	cout << "|| Alert!Enter only valid coins(5-Nickel or 10-Dime or 25-Quarter)||" << endl;
	cout << "********************************************************************" << endl;
	cout << "Insert Coin: ";
	string coin;
	while (getline(cin, coin))
	{
		cout << "Insert coin or Enter Done : ";
		if (coin == "done"){
			cout << endl;
			break;
		}else if (coin == "5"){
			Nickel++;
		}
		else if (coin == "10"){
			Dime++;
		}
		else if (coin == "25"){
			Quarter++;
		}
		else if (coin != "5" || coin != "10" || coin != "25"){
			cout << "Invalid coin" << endl;
		}

		totalAmount = (Nickel * 5) + (Dime * 10) + (Quarter * 25);   
	}
	return totalAmount;
}


void driverFunction(){
    Inventory inv;
	Money m;

	int itemQuantity;
	int totalCoinsInserted = m.amountInsertedbyCustomer();
	cout << "Total inserted amount : " << totalCoinsInserted << " cents" << endl;
	int money = m.maxTotalAvailableAmount();

	int Choice;

	cout << "=======================================" << endl;
	cout << "Welcome! Please select the Product.\t" << endl;
	cout << "=======================================" << endl;

	while (inv.hasInv()){
		cout << inv.getAvailableProducts();
		cin >> Choice;
		if (Choice > inv.getSelectedItemSize() || Choice < 0){
			cout << "Invalid Selection\n";
		}
		else{
			if(inv.getQuantity(Choice) < 0){
				cout<<"Item is outof stock."<<endl;
			}
			else if (inv.getQuantity(Choice) > 0){
				int cost = inv.getCost(Choice);
				cout<<"Enter Quantity: ";
				cin>>itemQuantity;
				
				cout << (inv.getQuantity(Choice) - itemQuantity) << " " << inv.getProductName(Choice) << " left" << endl;

				cout << "cost of "<<itemQuantity<<" "<<inv.getProductName(Choice)<<" is: " << cost*itemQuantity << " cents"<<endl;
				
				int remainingBalance = (totalCoinsInserted - (cost*itemQuantity));
				if (remainingBalance < 0){
					cout << "you do not have suffcicient balance to make this purchase." << endl;
					break;
				}
				else if (remainingBalance > 0){
					if (remainingBalance > money){
						cerr << "Vending Machine does not have EXACT change of :" << abs(((cost*itemQuantity)) - totalCoinsInserted) << " cents" << endl;
						cerr << "Please insert EXACT change of: " << (cost*itemQuantity) << " cents" << endl;						
					}
					else{
						cout << "please take remaining " << remainingBalance << " cents back. " << endl;
						break;
					}
				}
			}else{
				cout << "\nNo " << inv.getProductName(Choice) << "left\n";
			}
		}
	}
	cout<<"\n***Thank You for Shopping. Please come back!!***\n";
}

int main(){
	driverFunction();
	return 0;
}
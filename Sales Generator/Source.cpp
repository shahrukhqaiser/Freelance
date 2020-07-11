#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

char* getStringFromBuffer(char* buffer)
{
	int length = strlen(buffer) + 1;
	char* temp = new char[length];
	strcpy_s(temp, length, buffer);

	return temp;
}

string getCurrentDate()
{
	char* buffer = nullptr;
	time_t now = time(0);
	tm* tPtr = localtime(&now);

	int day = (tPtr->tm_mday);
	int month = (tPtr->tm_mon) + 1;
	int year = (tPtr->tm_year) + 1900;

	string  Day = to_string(day);
	string Month = to_string(month);
	string Year = to_string(year);

	string Date = Day + '/' + Month + '/' + Year;


	return Date;


}

int countSales;
int countItems;
int countCustomers;
int countReceipts;

class Item
{
	int Item_SKU;
	char* Description;
	float Price;
	int AvailableQuantity;
	string CreationDate;

public:

	friend class POS;
	friend class SalesLineItem;
	friend class Sale;

	Item()
	{
		Item_SKU = 0;
		Description = nullptr;
		Price = 0;
		AvailableQuantity = 0;

	}
	void addNewItem(int ItemSKU, char* description, float price, int Quantity)
	{
		Item_SKU = ItemSKU;
		Description = getStringFromBuffer(description);
		Price = price;
		AvailableQuantity = Quantity;
		CreationDate = getCurrentDate();

		cout << "Item Information successfully saved\n";


	}
	static void addNewItem(Item**& Items)
	{
		bool found= false;
		bool Error = true;
		int ItemSKU = 0;
		
		while (Error != false)
		{
			cout << "Enter Item_SKU\n";
			cin >> ItemSKU;
			for (int i = 0; i < countItems && found == false; i++)
			{
				if (Items[i] != nullptr)
				{
					if (Items[i]->Item_SKU == ItemSKU)
					{
						cout << "Item  with this SKU already exists\n";
						found = true;
					}
				}
			}
			if (found != true)
				Error = false;
			else
				found = false;
		}
		cin.ignore();

		Error = true;

		char description[200];
		
		while (Error != false)
		{
			cout << "Enter Description\n";
			cin.getline(description, 200);
			if (description[0] != '\0')
				Error = false;
			else
				cout << "This field can not be left empty. Try again\n";
		}
		
		Error = true;
		float price = 0;
		while (Error != false)
		{
			cout << "Enter Price\n";
			cin >> price;
			if (price > 0)
				Error = false;
			else
				cout << "Price has to be greater than 0";
		}

		Error = true;
		int quantity = 0;
		
		while (Error != false)
		{
			cout << "Enter Quantity\n";
			cin >> quantity;
			if (quantity > 0)
				Error = false;
			else
				cout << "Quantity has to be greater than 0";
		}

			bool insert = false;
			for (int i = 0; i < countItems; i++)
			{
				if (Items[i] == nullptr)
				{
					Items[i] = new Item;
					Items[i]->addNewItem(ItemSKU, description, price, quantity);
					insert = true;
				}
			}
			if (insert == false)
			{
				Items[countItems] = new Item;
				Items[countItems]->addNewItem(ItemSKU, description, price, quantity);
				countItems++;
			}
	}
	static void updateItem(Item**& items)
	{
		Item* modify = findItem(items);
		if (modify != nullptr)
		{
			cin.ignore();
			cout << "Enter the information you want to modify. Leave blank if you don't want to change anything\n";
			char input[200];
			cout << "Enter Item_SKU\n";
			cin.getline(input, 200);
			if (input[0] != '\0')
			{
				modify->Item_SKU = atoi(input);
			}
			cout << "Enter Item Description\n";
			cin.getline(input, 200);
			if (input[0] != '\0')
			{
				modify->Description = getStringFromBuffer(input);
			}

			cout << "Enter Item Price\n";
			cin.getline(input, 200);
			if (input[0] != '\0')
			{
				modify->Price = atof(input);
			}

			cout << "Enter Item Quantity\n";
			cin.getline(input, 200);
			if (input[0] != '\0')
			{
				modify->AvailableQuantity = atoi(input);
			}
			cout << endl;
			cout << "Item details updated\n";


		}
		else
			cout << "Item not found\n";
	}
	static void findItems(Item**& items)
	{
		char Description[200];
		char ItemSKU[200];
		int SKU;
		char Price[200];
		float price;
		char Quantity[200];
		int quantity;
		string creationDate;

		cout << "Enter the information you want to search with. Leave the rest blank\n";
		cin.ignore();
		cout << "Enter Item SKU\n";
		cin.getline(ItemSKU, 200);
		if (ItemSKU[0] != '\0')
			SKU = atoi(ItemSKU);
		cout << "Enter Item Description\n";
		cin.getline(Description, 200);

		cout << "Enter Item Price\n";
		cin.getline(Price, 200);
		if (Price[0] != '\0')
			price = atof(Price);

		cout << "Enter Item Quantity\n";
		cin.getline(Quantity, 200);
		if (Quantity[0] != '\0')
			quantity = atoi(Quantity);

		cout << "Enter Creation Date\n";
		 getline(cin,creationDate);
		
		cout << "ItemSKU\t\tDescription\t\tPrice\t\tQuantity\t\tCreation Date\n";
		for (int i = 0; i < countItems; i++)
		{
			bool print = false;
			if (items[i] != nullptr)
			{
				if (ItemSKU[0] != '\0')
				{
					if (SKU== items[i]->Item_SKU)
					{
						print = true;
					}
				}
				if (Description[0] != '\0')
				{
					if (strcmp(Description, items[i]->Description) == 0)
					{
						print = true;
					}
				}

				if (Price[0] != '\0')
				{
					if (price == items[i]->Price)
					{
						print = true;
					}
				}

				if (Quantity[0] != '\0')
				{
					if (quantity == items[i]->AvailableQuantity)
					{
						print = true;
					}
				}
				if (creationDate[0] != '\0')
				{
					if (creationDate == items[i]->CreationDate)
					{
						print = true;
					}

				}

				if (print == true)
					cout << items[i]->Item_SKU << "\t" << items[i]->Description << "\t" << items[i]->Price << "\t" << items[i]->AvailableQuantity << "\t"<<items[i]->CreationDate << endl;
			}
		}
		cout << endl << endl;
	}
	static Item* findItem(Item**& items)
	{
		cout << "Enter Item_SKU\n";
		int ItemSKU = 0;
		cin >> ItemSKU;
		bool flag = false;
		Item* found = nullptr;

		for (int i = 0; i < countItems && flag == false; i++)
		{
			if (items[i] != nullptr)
			{
				if (items[i]->Item_SKU == ItemSKU)
				{
					flag = true;
					found = items[i];
					items[i]->printItemDetails();
				}
			}
		}

		return found;
	}
	static void removeItem(Item**& items)
	{
		cout << "Enter Item_SKU\n";
		int ItemSKU = 0;
		cin >> ItemSKU;
		bool flag = false;


		for (int i = 0; i < countItems && flag == false; i++)
		{
			if (items[i] != nullptr)
			{
				if (items[i]->Item_SKU == ItemSKU)
				{
					flag = true;
					delete items[i];
					items[i] = nullptr;
					
					cout << "\nItem removed successfully\n";
				}
			}
		}
		if (flag == false)
		{

			cout << "\nItem not found\n";
		}


	}

	void printItemDetails()
	{
		cout << "\t\t\t Item Details\n\n";
		cout << "Item_SKU:" <<Item_SKU << "\nDescription:" <<Description << "\nPrice:" <<Price << "\nQuantity:" <<AvailableQuantity << endl << endl;
	}
	~Item()
	{
		if (Description != nullptr)
			delete[]Description;
		Description = nullptr;
	}
};



class Customer
{
private:
	char* CNIC;
	char* Name;
	char* Address;
	char* Phone;
	char* Email;
	int Type;
	float Balance;

protected:
	float SalesLimit;
public:
	friend class POS;
	friend class Sale;


	Customer()
	{
		CNIC = nullptr;
		Name = nullptr;
		Address = nullptr;
		Phone = nullptr;
		Email = nullptr;
		Type = 0;
		Balance = 0;
	}
	void addNewCustomer(char* CNIC, char* Name, char* Address, char* Phone, char* Email, int Type, float balance)
	{
		this->CNIC = getStringFromBuffer(CNIC);
		this->Name = getStringFromBuffer(Name);
		this->Address = getStringFromBuffer(Address);
		this->Phone = getStringFromBuffer(Phone);
		this->Email = getStringFromBuffer(Email);
		this->Type = Type;
		this->Balance = balance;

		cout << "Customer Information successfully saved\n";

	}
	static void addNewCustomer(Customer**& Customers);
	static void updateCustomer(Customer**& customers)
	{
		Customer* modify = findCustomer(customers);
		if (modify != nullptr)
		{
			cout << "Enter the information you want to modify. Leave blank if you don't want to change anything\n";
			char input[200];

			cout << "Enter Customer CNIC\n";
			cin.getline(input, 200);
			if (input[0] != '\0')
			{
				modify->CNIC = getStringFromBuffer(input);
			}
			cout << "Enter Customer Name\n";
			cin.getline(input, 200);
			if (input[0] != '\0')
			{
				modify->Name = getStringFromBuffer(input);
			}

			cout << "Enter Customer Address\n";
			cin.getline(input, 200);
			if (input[0] != '\0')
			{
				modify->Address = getStringFromBuffer(input);
			}

			cout << "Enter Customer Phone Number\n";
			cin.getline(input, 200);
			if (input[0] != '\0')
			{
				modify->Phone = getStringFromBuffer(input);
			}

			cout << "Enter Customer Email\n";
			cin.getline(input, 200);
			if (input[0] != '\0')
			{
				modify->Email = getStringFromBuffer(input);
			}

			cout << "\nCustomer details updated\n";
		}
		else
		{
			cout << "\nCustomer not found\n";
		}
	}
	static void findCustomers(Customer**&customers)
	{
		char CNIC[200];
		char Name[200];
		char Phone[200];
		char Email[200];
		
		cout << "Enter the information you want to search with. Leave the rest blank\n";
		cin.ignore();
		cout << "Enter Customer CNIC\n";
		cin.getline(CNIC, 200);
		
		cout << "Enter Customer Name\n";
		cin.getline(Name, 200);
		
		cout << "Enter Customer Phone Number\n";
		cin.getline(Phone, 200);
		
		cout << "Enter Customer Email\n";
		cin.getline(Email, 200);
		
		cout << "CNIC\t\tName\t\tPhone\t\tEmail\n";
		for (int i = 0; i < countCustomers; i++)
		{
			bool print = false;
			if (customers[i] != nullptr)
			{
				if (CNIC[0] != '\0')
				{
					if (strcmp(CNIC, customers[i]->CNIC) == 0)
					{
						print = true;
					}
				}
				if (Name[0] != '\0')
				{
					if (strcmp(Name, customers[i]->Name) == 0)
					{
						print = true;
					}
				}

				if (Phone[0] != '\0')
				{
					if (strcmp(Phone, customers[i]->Phone) == 0)
					{
						print = true;
					}
				}

				if (Email[0] != '\0')
				{
					if (strcmp(Email, customers[i]->Email) == 0)
					{
						print = true;
					}
				}

				if(print == true)
				cout << customers[i]->CNIC << "\t" << customers[i]->Name << "\t" << customers[i]->Phone << "\t" << customers[i]->Email << "\t" << endl;
			}
		}
		cout << endl << endl;
	}
	
	static Customer* findCustomer(Customer**& customers)
	{
		cin.ignore();
		cout << "Enter Customer CNIC\n";
		char CNIC[100];
		cin.getline(CNIC, 200);

		bool flag = false;
		Customer* found = nullptr;

		for (int i = 0; i < countCustomers && flag == false; i++)
		{
			if (customers[i] != nullptr)
			{
				if (strcmp(customers[i]->CNIC, CNIC) == 0)
				{
					flag = true;
					found = customers[i];
					found->printCustomerDetails();
				}
			}
		}

		return found;
	}
	static void removeCustomer(Customer**& customers)

	{
		cin.ignore();
		cout << "Enter Customer CNIC\n";
		char CNIC[100];
		cin.getline(CNIC, 100);
		bool flag = false;


		for (int i = 0; i < countCustomers && flag == false; i++)
		{
			if (customers[i] != nullptr)
			{
				if (strcmp(customers[i]->CNIC, CNIC) == 0)
				{
					flag = true;
					delete customers[i];
					customers[i] = nullptr;
					
					cout << "\nCustomer removed successfully\n";
				}
			}
		}
		if (flag == false)
		{
			cout << "\nCustomer not found\n";
		}


	}

	virtual double getDiscount() = 0;

	void printCustomerDetails()
	{
		cout << "\n\n\t\t\tCustomer Details\n\n";
		cout << "CNIC:" << CNIC << "\nName:" << Name << "\nEmail:" << Email << "\nPhone:" << Phone << "\nSalesLimit:" << SalesLimit << "\nBalacne:" << Balance << "\n\n\n";
	}
	virtual ~Customer()
	{
		if (CNIC != nullptr)
			delete[]CNIC;
		CNIC = nullptr;

		if (Name != nullptr)
			delete[]Name;
		Name = nullptr;

		if (Address != nullptr)
			delete[]Address;
		Address = nullptr;

		if (Phone != nullptr)
			delete[]Phone;
		Phone = nullptr;

		if (Email != nullptr)
			delete[]Email;
		Email = nullptr;
	}
};


class silverCustomers :public Customer
{
public:
	silverCustomers()
	{
		SalesLimit = 40000;
	}
	double getDiscount()
	{
		return 0;
	}
	~silverCustomers()
	{}
};

class goldCustomers :public Customer
{
public:
	double discount;

	goldCustomers()
	{
		SalesLimit = 100000;
		discount = 0.03;
	}
	double getDiscount()
	{
		return discount;
	}

	~goldCustomers()
	{}
};

class platinumCustomers :public Customer
{
public:
	double discount;

	platinumCustomers()
	{
		discount = 0.05;
		SalesLimit = 250000;
	}
	double getDiscount()
	{
		return discount;
	}
	~platinumCustomers()
	{}
};

void Customer::addNewCustomer(Customer**& Customers)
{
	char CNIC[200];
	char Name[200];
	char Address[200];
	char Phone[200];
	char Email[200];
	int Type;
	float Balance;
	bool repeat = false;
	bool Error = true;
	cin.ignore();

	while (Error != false)
	{
		cout << " Enter CNIC\n";
		cin.getline(CNIC, 200);
		if (CNIC[0] != '\0')
			Error = false;
		else
			cout << "This field cannot be left empty\n";

		if (Error == false)
		{
			for (int i = 0; i < countCustomers && repeat == false; i++)
			{
				if (Customers[i] != nullptr)
				{
					if (strcmp(Customers[i]->CNIC, CNIC) == 0)
					{
						repeat = true;
						
						cout << "\nCustomer with this CNIC already exists\n";
					}
				}
			}
			if (repeat == true)
			{
				Error = true;
				repeat = false;
			}
		}
	}

	Error = true;

	while (Error != false)
	{
		cout << " Enter Name\n";
		cin.getline(Name, 200);
		if (Name[0] != '\0')
			Error = false;
		else
			cout << "This field cannot be left empty\n";
	}

	Error = true;
	while (Error != false)
	{
		cout << " Enter Address\n";
		cin.getline(Address, 200);
		if (Address[0] != '\0')
			Error = false;
		else
			cout << "This field cannot be left empty\n";
	}
	
	Error = true;
	while (Error != false)
	{
		cout << " Enter Phone\n";
		cin.getline(Phone, 200);
		if (Phone[0] != '\0')
			Error = false;
		else
			cout << "This field cannot be left empty\n";
	}

	Error = true;
	while (Error != false)
	{
		cout << " Enter Email\n";
		cin.getline(Email, 200);
		if (Email[0] != '\0')
			Error = false;
		else
			cout << "This field cannot be left empty\n";
	}

	Error = true;

	while (Error != false)
	{
		cout << "Enter Customer Type(0,1,2 for Silver,Gold,Platinum resepctively)\n";
		cin >> Type;
		if (Type != 0 && Type != 1 && Type != 2)
		{
			cout << "Invalid type. Tpye 0,1,2 ONLY\n";
		}
		else
		{
			Error = false;
		}
	}

	cout << "Enter Customer Balance\n";
	cin >> Balance;

		bool insert = false;
		for (int i = 0; i < countCustomers; i++)
		{
			if (Customers[i] == nullptr)
			{
				if (Type == 0)
					Customers[i] = new silverCustomers;
				else if (Type == 1)
					Customers[i] = new goldCustomers;
				else if (Type == 2)
					Customers[i] = new platinumCustomers;

				Customers[i]->addNewCustomer(CNIC, Name, Address, Phone, Email, Type, Balance);
				insert = true;
			}
		}
		if (insert == false)
		{
			if (Type == 0)
				Customers[countCustomers] = new silverCustomers;
			else if (Type == 1)
				Customers[countCustomers] = new goldCustomers;
			else if (Type == 2)
				Customers[countCustomers] = new platinumCustomers;
			Customers[countCustomers]->addNewCustomer(CNIC, Name, Address, Phone, Email, Type, Balance);
			countCustomers++;
		}
}

class Sale;
class Receipt;
class SalesLineItem
{
	int LineNo;
	Sale* sale;
	Item* item;
	int Quantity;
public:

	friend class POS;
	friend class Sale;
	SalesLineItem()
	{
		LineNo = 0;
		sale = nullptr;
		item = nullptr;
		Quantity = 0;
	}
	void addNewSalesLineItem(Sale* Sale, Item* Item, int quantity, int LineNumber)
	{
		LineNo = LineNumber;
		sale = Sale;
		item = Item;
		Quantity = quantity;
	}
	~SalesLineItem()
	{
	}
};
class Sale
{
	int SaleID;
	Customer* customer;
	SalesLineItem** line;
	int lineCount;
	Receipt* receipt;
	string date;
	int status;
	float total;

public:
	friend class POS;
	friend class Receipt;
	Sale()
	{
		SaleID = countSales;
		customer = nullptr;
		line = new SalesLineItem * [10];
		receipt = nullptr;
		date = getCurrentDate();
		status = 0;
		total = 0;
	}
	void addNewItem(Item*& item)
	{
		if (item != nullptr)
		{
			bool flag = false;
			int quantity = 0;

			while (flag == false)
			{
				cout << "Enter Quantitiy\n";
				cin >> quantity;


				if (quantity > 0 && quantity <= item->AvailableQuantity)
				{
					flag = true;
					line[lineCount] = new SalesLineItem;
					line[lineCount]->addNewSalesLineItem(this, item, quantity, lineCount);
					line[lineCount]->item->AvailableQuantity = line[lineCount]->item->AvailableQuantity - line[lineCount]->Quantity;

					total = total + item->Price * line[lineCount]->Quantity;
					lineCount++;
					printSale();
				}
				else
				{
					cout << "Enter a valid quantity. (Greater than 0 and within available quantity)\n";
				}
			}

		}
		else
			cout << "No item exists with the given SKU\n";
	}
	void endSale(bool& exit)
	{
			if (checkEmpty() == false)
			{
				if (customer->SalesLimit >= total)
				{
					customer->SalesLimit = customer->SalesLimit - total;
					printSale();
					countSales++;
					exit = true;
				}
				else
				{
					cout << "Sorry, you've exceeded your sales limit for today. Kindly remove a few items\n";
				}
			}
			else
				cout << "You currently have no items in your cart\n";
	}
	void removeItem()
	{
		if (checkEmpty() == false)
		{
			cout << "Enter Item_SKU of item you wish to remove from your current sale\n";
			int ItemSKU = 0;
			cin >> ItemSKU;
			for (int i = 0; i < lineCount; i++)
			{
				if (line[i] != nullptr)
					if (line[i]->item != nullptr)
						if (line[i]->item->Item_SKU == ItemSKU)
						{
							float amountReturned = line[i]->item->Price * line[i]->Quantity;

							total = total - amountReturned;
							line[i]->item->AvailableQuantity = line[i]->item->AvailableQuantity + line[i]->Quantity;

							delete line[i];
							line[i] = nullptr;
						}
			}
		}
		else
			cout << "You currently have no items in your cart\n";

	}
	void cancelSale(bool& exit)
	{
		if (line != nullptr)
		{
			for (int i = 0; i < lineCount; i++)
			{
				if (line[i] != nullptr)
				{
					line[i]->item->AvailableQuantity = line[i]->item->AvailableQuantity + line[i]->Quantity;
				}
			}
		}
		exit = true;
		delete this;
	}

	bool checkEmpty()
	{
		bool flag = true;

		if (line != nullptr)
		{
			for (int i = 0; i < lineCount; i++)
			{
				if (line[i] != nullptr)
				{
					flag = false;
				}
			}
		}

		return flag;
	}

	SalesLineItem* checkItemRepeat(Item* item)
	{
		SalesLineItem* obj = nullptr;
		if (line != nullptr)
		{
			for (int i = 0; i < lineCount; i++)
			{
				if (line[i]->item == item)
				{
					obj = line[i];
				}
			}
		}

		return obj;
	}
	void printSale()
	{
		cout << "Sales ID:" << SaleID << endl;
		cout << "Date:" << date << endl;
		cout << endl;
		cout << customer->Name<<endl;
		cout << customer->CNIC<<endl;
		cout << "CustomerType:";
		if (customer->Type == 0)
			cout << "Silver Customer\n";
		else if (customer->Type == 1)
			cout << "Gold Customer\n";
		else if (customer->Type == 2)
			cout << "Platinum Customer\n";

		cout << endl << endl;

		cout << "Item_SKU\t\t\tDescription\t\t\tQuantity\t\t\tAmount\n";
		for (int i = 0; i < lineCount; i++)
		{

			if (line[i] != nullptr)
			{
				cout << line[i]->item->Item_SKU << "\t";
				cout << line[i]->item->Description << "\t";
				cout << line[i]->Quantity << "\t";
				cout << line[i]->item->Price << endl;
			}
		}

		cout << "Total Amount:"<<total << endl << endl;
	}

	~Sale()
	{
		customer = nullptr;
		if (line != nullptr)
		{
			for (int i = 0; i < lineCount; i++)
			{
				if (line[i] != nullptr)
				{
					delete line[i];
					line[i] = nullptr;
				}
			}
			delete[]line;
			line = nullptr;
		}
		receipt = nullptr;
	}
};





class Receipt
{
	int ReceiptNo;
	string ReceiptDate;
	Sale* sale;
	float Amount;

public:

	friend class POS;
	Receipt()
	{
		ReceiptNo = -1;
		sale = nullptr;
		Amount = 0;
	}
	~Receipt()
	{
	}
	void makeReceipt(Sale* sale)
	{
		ReceiptDate = getCurrentDate();
		ReceiptNo = countReceipts;
		this->sale = sale;
		Amount = sale->total;
	}
};


class POS
{
	Item** Items;

	Customer** Customers;

	Sale** Sales;

	Receipt** Receipts;



public:
	friend class Item;
	friend class Customer;
	friend class Receipt;
	friend class Sale;
	POS()
	{
		Items = new Item * [100];
		countItems = 0;
		Customers = new Customer * [100];
		countCustomers = 0;
		Sales = new Sale * [100];
		countSales = 0;
		Receipts = new Receipt * [100];
		countReceipts = 0;
	}
	void mainMenu()
	{
		char input;
		bool exit = false;
		while (exit == false)
		{
			cout << "1 - Manage Items\n2 - Manage Customers\n3 - Make New Sale\n4 - Make Payment\n5 - Exit\n";
			cin >> input;
			if (input == '1')
			{
				system("pause");
				system("cls");
				itemsMenu();

			}
			else if (input == '2')
			{
				system("pause");
				system("cls");
				customersMenu();
			}

			else if (input == '3')
			{
				system("pause");
				system("cls");
				Customer* customer = Customer::findCustomer(Customers);
				if (customer != nullptr)
				{
					Sales[countSales] = new Sale;
					Sales[countSales]->customer = customer;
					makeASale();
				}
				else
					cout << "No customer exists with mentioned CNIC\n";

			}

			else if (input == '4')
			{
				system("pause");
				system("cls");
				makePayment();
				system("pause");
				system("cls");
			}

			else if (input == '5')
			{
				system("pause");
				system("cls");
				exit = true;
			}

			else
			{
				cout << "Invalid input. Try again";
			}
		}
	}
	void itemsMenu()

	{
		char input;
		bool exit = false;
		while (exit == false)
		{
			cout << "1 - Add new Item\n2 - Update Item details\n3 - Find Items\n4 - Remove Existing Item\n5 - Back to Main Menu\n";
			cin >> input;

			if (input == '1')
			{
				system("pause");
				system("cls");
				Item::addNewItem(Items);
				system("pause");
				system("cls");
			}
			else if (input == '2')
			{
				system("pause");
				system("cls");
				Item::updateItem(Items);
				system("pause");
				system("cls");
			}

			else if (input == '3')
			{
				system("pause");
				system("cls");
				Item::findItems(Items);
				system("pause");
				system("cls");

			}

			else if (input == '4')
			{
				system("pause");
				system("cls");
				Item::removeItem(Items);
				system("pause");
				system("cls");
			}

			else if (input == '5')
			{
				system("pause");
				system("cls");
				exit = true;
			}

			else
			{
				cout << "Invalid input. Try again";
			}
		}
	}
	void customersMenu()
	{
		char input;
		bool exit = false;
		while (exit == false)
		{
			cout << "1 - Add New Customer\n2 - Update Customer Information\n3 - Search Customer\n4 - Remove Customer\n5 - Return to Main Menu\n";
			cin >> input;
			if (input == '1')
			{
				system("pause");
				system("cls");
				Customer::addNewCustomer(Customers);
				system("pause");
				system("cls");
			}
			else if (input == '2')
			{
				system("pause");
				system("cls");
				Customer::updateCustomer(Customers);
				system("pause");
				system("cls");
			}

			else if (input == '3')
			{
				system("pause");
				system("cls");
				Customer::findCustomers(Customers);
				system("pause");
				system("cls");
			}

			else if (input == '4')
			{
				system("pause");
				system("cls");
				Customer::removeCustomer(Customers);
				system("pause");
				system("cls");
			}

			else if (input == '5')
			{
				system("pause");
				system("cls");
				exit = true;
			}

			else
			{
				system("pause");
				system("cls");
				cout << "Invalid input. Try again";
				system("pause");
				system("cls");
			}
		}
	}
	void makeASale()
	{
		char input;
		bool exit = false;
		while (exit == false)
		{
			cout << "1 - Enter New Item\n2 - End Sale\n3 - Remove an existing Item from the current sale\n4 - Cancel Sale (Return to Main Menu)\n";
			cin >> input;
			if (input == '1')
			{
				system("pause");
				system("cls");
				Item* item = Item::findItem(Items);
				Sales[countSales]->addNewItem(item);
				system("pause");
				system("cls");
			}
			else if (input == '2')
			{
				system("pause");
				system("cls");
				Sales[countSales]->endSale(exit);
				system("pause");
				system("cls");
			}

			else if (input == '3')
			{
				system("pause");
				system("cls");
				Sales[countSales]->removeItem();
				system("pause");
				system("cls");
			}

			else if (input == '4')
			{
				system("pause");
				system("cls");
				Sales[countSales]->cancelSale(exit);
				Sales[countSales] = nullptr;
				system("pause");
				system("cls");
			}

			else
			{
				cout << "Invalid input. Try again";
			}
		}
	}
	void makePayment()
	{
		int ID = 0;
		cout << "Enter Sales ID\n";
		cin >> ID;

		bool found = false;

		for (int i = 0; i < countSales; i++)
		{
			if (Sales[i]->SaleID == ID)
			{
				found = true;
				if (Sales[i]->status == 0)
				{
					
					cout << "Customer Name:" << Sales[i]->customer->Name << endl;
					cout << "Total Sales Amount:" << Sales[i]->total << endl;
					cout << "Discount:" << Sales[i]->customer->getDiscount()*100<<"%"<<endl;
					Sales[i]->total = Sales[i]->total - (Sales[i]->total * Sales[i]->customer->getDiscount());
					cout << "Total Amount after Discount:"<<Sales[i]->total<<endl;
					cout << "Deducting payment from your balance...\n";
					system("pause");
					if (Sales[i]->customer->Balance >= Sales[i]->total)
					{
						Sales[i]->customer->Balance = Sales[i]->customer->Balance - Sales[i]->total;
						Sales[i]->status = 1;
						if (Sales[i]->receipt == nullptr)
						{
							Receipts[countReceipts] = new Receipt;
							Receipts[countReceipts]->makeReceipt(Sales[i]);
							Sales[i]->receipt = Receipts[countReceipts];
							countReceipts++;
						}

						cout << "Transaction Successful\n";
					}
					else
						cout << "You have insufficent balance. Transaction failed\n";
				}
				else
					cout << "This Sale has already been paid for\n";
			}
		}
		if (found == false)
		{
			cout << "No sale found against this Sale ID\n";
		}

	}


	void updateFiles()
	{
		ofstream fout;
		fout.open("Items.txt");
		for (int i = 0; i < countItems; i++)
		{
			if (Items[i] != nullptr)
			{
				fout << Items[i]->Item_SKU << ";" << Items[i]->Description << ";" << Items[i]->Price << ";" << Items[i]->AvailableQuantity << ";" << Items[i]->CreationDate << endl;
			}
		}
		fout.close();

		fout.open("Customers.txt");
		for (int i = 0; i < countCustomers; i++)
		{
			if (Customers[i] != nullptr)
				fout << Customers[i]->CNIC << ";" << Customers[i]->Name << ";" << Customers[i]->Address << ";" << Customers[i]->Phone << ";" << Customers[i]->Email << ";" << Customers[i]->Type << ";" << Customers[i]->Balance << ";" << Customers[i]->SalesLimit << endl;
		}
		fout.close();

		fout.open("Sales.txt");
		for (int i = 0; i < countSales; i++)
		{
			if (Sales[i] != nullptr)
			{
				fout << Sales[i]->SaleID << ";" << Sales[i]->customer->CNIC << ";";
				if (Sales[i]->receipt != nullptr)
					fout << Sales[i]->receipt->ReceiptNo;
				fout << ";";
				fout << Sales[i]->date << ";";
				if (Sales[i]->status == 0)
					fout << "Pending";
				else if (Sales[i]->status == 1)
					fout << "Completed";
				fout << ";\n";

			}
		}
		fout.close();

		fout.open("Receipts.txt");
		for (int i = 0; i < countReceipts; i++)
		{
			if (Receipts[i] != nullptr)
			{
				fout << Receipts[i]->ReceiptNo << ";" << Receipts[i]->ReceiptDate << ";" << Receipts[i]->sale->SaleID << ";" << Receipts[i]->Amount << endl;
			}
		}
		fout.close();


	}
	~POS()
	{
		if (Items != nullptr)
		{
			for (int i = 0; i < countItems; i++)
			{
				if (Items[i] != nullptr)
				{
					delete Items[i];
					Items[i] = nullptr;
				}
			}

			delete[]Items;
		}

		if (Customers != nullptr)
		{
			for (int i = 0; i < countCustomers; i++)
			{
				if (Customers[i] != nullptr)
				{
					delete Customers[i];
					Customers[i] = nullptr;
				}

			}

			delete[]Customers;
		}

		if (Receipts != nullptr)
		{
			for (int i = 0; i < countReceipts; i++)
			{
				if (Receipts[i] != nullptr)
				{
					delete Receipts[i];
					Receipts[i] = nullptr;
				}
			}

			delete[]Receipts;
		}

		if (Sales != nullptr)
		{
			for (int i = 0; i < countSales; i++)
			{
				if (Sales[i] != nullptr)
				{
					delete Sales[i];
					Sales[i] = nullptr;
				}
			}
		}
	}

};

int main()
{
	{
		POS pos;
		pos.mainMenu();
		pos.updateFiles();
	}


	return 0;
}